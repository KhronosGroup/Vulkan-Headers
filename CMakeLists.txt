# ~~~
# Copyright (c) 2018-2022 Valve Corporation
# Copyright (c) 2018-2022 LunarG, Inc.
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
cmake_minimum_required(VERSION 3.10.2)

# Written as a function to minimize variable scope
# Only VK_VERSION_STRING will be returned to the PARENT_SCOPE
function(vlk_get_header_version)
    set(vulkan_core_header_file "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan_core.h")
    if (NOT EXISTS ${vulkan_core_header_file})
        message(FATAL_ERROR "Couldn't find vulkan_core.h!")
    endif()

    file(READ ${vulkan_core_header_file} ver)

    # Get the major/minor version
    if (ver MATCHES "#define[ ]+VK_HEADER_VERSION_COMPLETE[ ]+VK_MAKE_API_VERSION\\([ ]*[0-9]+,[ ]*([0-9]+),[ ]*([0-9]+),[ ]*VK_HEADER_VERSION[ ]*\\)")
        set(VK_VERSION_MAJOR "${CMAKE_MATCH_1}")
        set(VK_VERSION_MINOR "${CMAKE_MATCH_2}")
    else()
        message(FATAL_ERROR "Couldn't get major/minor version")
    endif()

    # Get the patch version
    if (ver MATCHES "#define[ ]+VK_HEADER_VERSION[ ]+([0-9]+)")
        set(VK_HEADER_VERSION "${CMAKE_MATCH_1}")
    else()
        message(FATAL_ERROR "Couldn't get the patch version")
    endif()

    set(VK_VERSION_STRING "${VK_VERSION_MAJOR}.${VK_VERSION_MINOR}.${VK_HEADER_VERSION}" PARENT_SCOPE)
endfunction()
vlk_get_header_version()

project(Vulkan-Headers LANGUAGES C VERSION ${VK_VERSION_STRING})
message(STATUS "${PROJECT_NAME} = ${PROJECT_VERSION}")

add_library(Vulkan-Headers INTERFACE)
target_include_directories(Vulkan-Headers INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
add_library(Vulkan::Headers ALIAS Vulkan-Headers)

add_library(Vulkan-Registry INTERFACE)
target_include_directories(Vulkan-Registry INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/registry>)
add_library(Vulkan::Registry ALIAS Vulkan-Registry)

# https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html
string(COMPARE EQUAL ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR} PROJECT_IS_TOP_LEVEL)

if (PROJECT_IS_TOP_LEVEL)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)

    # Location registry files will be installed to
    set(VLK_REGISTRY_DIR "${CMAKE_INSTALL_DATADIR}/vulkan")

    # Install header files
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vk_video" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    # Install registry files
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/registry" DESTINATION ${VLK_REGISTRY_DIR} USE_SOURCE_PERMISSIONS)

    set(export_name "VulkanHeadersConfig")
    set(namespace "Vulkan::")
    set(cmake_files_install_dir ${CMAKE_INSTALL_DATADIR}/cmake/VulkanHeaders/)

    # Set EXPORT_NAME for consistency with established names. The CMake generated ones won't work.
    set_target_properties(Vulkan-Headers PROPERTIES EXPORT_NAME "Headers")
    set_target_properties(Vulkan-Registry PROPERTIES EXPORT_NAME "Registry")

    # Add find_package() support
    target_include_directories(Vulkan-Headers INTERFACE $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
    install(TARGETS Vulkan-Headers EXPORT ${export_name})

    target_include_directories(Vulkan-Registry INTERFACE $<INSTALL_INTERFACE:${VLK_REGISTRY_DIR}/registry>)
    install(TARGETS Vulkan-Registry EXPORT ${export_name})

    install(EXPORT ${export_name} NAMESPACE ${namespace} DESTINATION ${cmake_files_install_dir})
    export(TARGETS Vulkan-Headers NAMESPACE ${namespace} FILE ${export_name}.cmake)

    set(config_version "${CMAKE_CURRENT_BINARY_DIR}/${export_name}Version.cmake")

    # Add find_package() versioning support
    if(${CMAKE_VERSION} VERSION_LESS "3.14.0")
        write_basic_package_version_file(${config_version} COMPATIBILITY SameMajorVersion)
    else()
        write_basic_package_version_file(${config_version} COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)
    endif()

    install(FILES ${config_version} DESTINATION ${cmake_files_install_dir})
endif()
