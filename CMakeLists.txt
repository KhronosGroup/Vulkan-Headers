# ~~~
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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

# CMake project initialization ---------------------------------------------------------------------------------------------------
# This section contains pre-project() initialization, and ends with the project() command.

cmake_minimum_required(VERSION 3.10.2)

# NONE = this project has no language toolchain requirement.
project(Vulkan-Headers NONE)
set(VERSION_STRING "1.1.127")

option(VULKAN_HEADERS_SKIP_INSTALL "Skip install" OFF)

# User-interface declarations ----------------------------------------------------------------------------------------------------
# This section contains variables that affect development GUIs (e.g. CMake GUI and IDEs), such as option(), folders, and variables
# with the CACHE property.

include(GNUInstallDirs)

if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # Windows: if install locations not set by user, set install prefix to "<build_dir>\install".
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE)
endif()

# --------------------------------------------------------------------------------------------------------------------------------

# define exported targets for nested project builds to consume
add_library(Vulkan-Headers INTERFACE)
target_include_directories(Vulkan-Headers INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
add_library(Vulkan::Headers ALIAS Vulkan-Headers)

add_library(Vulkan-Registry INTERFACE)
target_include_directories(Vulkan-Registry INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/registry>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_DATADIR}/vulkan>
)
add_library(Vulkan::Registry ALIAS Vulkan-Registry)

# Installation
if(NOT VULKAN_HEADERS_SKIP_INSTALL)
  set(config_install_dir "${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}/cmake")
  
  set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
  
  set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
  set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
  set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
  set(namespace "${PROJECT_NAME}::")
  
  include(CMakePackageConfigHelpers)
  write_basic_package_version_file(
      "${version_config}"
      VERSION ${VERSION_STRING}
      COMPATIBILITY AnyNewerVersion
  )
  
  configure_package_config_file(
      "cmake/Config.cmake.in"
      "${project_config}"
      INSTALL_DESTINATION "${config_install_dir}"
  )
  
  install(
      TARGETS Vulkan-Headers Vulkan-Registry
      EXPORT "${TARGETS_EXPORT_NAME}"
      LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
      ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
      RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
      INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
  
  install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/registry" DESTINATION ${CMAKE_INSTALL_DATADIR}/vulkan)
  
  install(
      FILES "${project_config}" "${version_config}"
      DESTINATION "${config_install_dir}"
  )
  
  install(
      EXPORT "${TARGETS_EXPORT_NAME}"
      NAMESPACE "${namespace}"
      DESTINATION "${config_install_dir}"
  )

  # uninstall target
  if(NOT TARGET uninstall)
      configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
                     "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
                     IMMEDIATE
                     @ONLY)
      add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
  endif()
endif()
