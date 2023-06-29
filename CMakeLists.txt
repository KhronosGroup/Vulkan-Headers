# ~~~
# Copyright (c) 2018-2023 Valve Corporation
# Copyright (c) 2018-2023 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~
cmake_minimum_required(VERSION 3.15...3.25)

function(vlk_get_header_version)
    set(vulkan_core_header_file "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_core.h")
    if (NOT EXISTS ${vulkan_core_header_file})
        message(FATAL_ERROR "Couldn't find vulkan_core.h!")
    endif()

    file(READ ${vulkan_core_header_file} ver)

    if (ver MATCHES "#define[ ]+VK_HEADER_VERSION_COMPLETE[ ]+VK_MAKE_API_VERSION\\([ ]*[0-9]+,[ ]*([0-9]+),[ ]*([0-9]+),[ ]*VK_HEADER_VERSION[ ]*\\)")
        set(MAJOR_VERSION "${CMAKE_MATCH_1}")
        set(MINOR_VERSION "${CMAKE_MATCH_2}")
    else()
        message(FATAL_ERROR "Couldn't get major/minor version")
    endif()

    if (ver MATCHES "#define[ ]+VK_HEADER_VERSION[ ]+([0-9]+)")
        set(PATCH_VERSION "${CMAKE_MATCH_1}")
    else()
        message(FATAL_ERROR "Couldn't get the patch version")
    endif()

    set(VK_VERSION_STRING "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}" PARENT_SCOPE)
endfunction()
vlk_get_header_version()

project(VULKAN_HEADERS LANGUAGES C VERSION ${VK_VERSION_STRING})

add_library(Vulkan-Headers INTERFACE)
add_library(Vulkan::Headers ALIAS Vulkan-Headers)
target_include_directories(Vulkan-Headers INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

if (CMAKE_VERSION VERSION_LESS "3.21")
    # https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html
    string(COMPARE EQUAL ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR} PROJECT_IS_TOP_LEVEL)
endif()

if (PROJECT_IS_TOP_LEVEL)
    option(BUILD_TESTS "Build the tests")
    if (BUILD_TESTS)
        add_subdirectory(tests)
    endif()
endif()

option(VULKAN_HEADERS_INSTALL "Install Vulkan Headers" ${PROJECT_IS_TOP_LEVEL})
if (VULKAN_HEADERS_INSTALL)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)

    set(VLK_REGISTRY_DIR "${CMAKE_INSTALL_DATADIR}/vulkan")

    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vk_video" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    # Preserve source permissions https://github.com/KhronosGroup/Vulkan-Headers/issues/336
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/registry" DESTINATION ${VLK_REGISTRY_DIR} USE_SOURCE_PERMISSIONS)

    set(cmake_files_install_dir ${CMAKE_INSTALL_DATADIR}/cmake/VulkanHeaders/)

    set_target_properties(Vulkan-Headers PROPERTIES EXPORT_NAME "Headers")

    install(TARGETS Vulkan-Headers EXPORT VulkanHeadersTargets INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    install(EXPORT VulkanHeadersTargets FILE VulkanHeadersTargets.cmake NAMESPACE "Vulkan::" DESTINATION ${cmake_files_install_dir})

    set(vulkan_headers_config "${CMAKE_CURRENT_BINARY_DIR}/VulkanHeadersConfig.cmake")
    set(VULKAN_HEADERS_REGISTRY_DIRECTORY "${VLK_REGISTRY_DIR}/registry")

    configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/VulkanHeadersConfig.cmake.in ${vulkan_headers_config}
        INSTALL_DESTINATION ${cmake_files_install_dir}
        PATH_VARS VULKAN_HEADERS_REGISTRY_DIRECTORY
        NO_SET_AND_CHECK_MACRO
        NO_CHECK_REQUIRED_COMPONENTS_MACRO
    )

    set(config_version "${CMAKE_CURRENT_BINARY_DIR}/VulkanHeadersConfigVersion.cmake")

    write_basic_package_version_file(${config_version} COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)

    install(FILES ${config_version} ${vulkan_headers_config} DESTINATION ${cmake_files_install_dir})
endif()
