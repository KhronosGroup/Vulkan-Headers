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

project(Vulkan-Headers LANGUAGES C VERSION 1.3.238)

add_library(Vulkan-Headers INTERFACE)
target_include_directories(Vulkan-Headers INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
add_library(Vulkan::Headers ALIAS Vulkan-Headers)

add_library(Vulkan-Registry INTERFACE)
target_include_directories(Vulkan-Registry INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/registry>)
add_library(Vulkan::Registry ALIAS Vulkan-Registry)

# https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html
string(COMPARE EQUAL ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR} PROJECT_IS_TOP_LEVEL)

if (PROJECT_IS_TOP_LEVEL)
    option(BUILD_TESTS "Build the tests" OFF)
    if (BUILD_TESTS)
        add_subdirectory(tests)
    endif()

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
