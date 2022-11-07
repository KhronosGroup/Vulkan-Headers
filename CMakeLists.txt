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
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.cmake)

project(Vulkan-Headers LANGUAGES C VERSION ${VK_VERSION_STRING})
message(STATUS "${PROJECT_NAME} = ${PROJECT_VERSION}")

add_library(Vulkan-Headers INTERFACE)
target_include_directories(Vulkan-Headers INTERFACE $<BUILD_INTERFACE:"${CMAKE_CURRENT_SOURCE_DIR}/include">)
add_library(Vulkan::Headers ALIAS Vulkan-Headers)

add_library(Vulkan-Registry INTERFACE)
target_include_directories(Vulkan-Registry INTERFACE $<BUILD_INTERFACE:"${CMAKE_CURRENT_SOURCE_DIR}/registry">)
add_library(Vulkan::Registry ALIAS Vulkan-Registry)

# https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html
string(COMPARE EQUAL ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR} PROJECT_IS_TOP_LEVEL)

option(VULKAN_HEADERS_INSTALL "Install Vulkan Headers" ${PROJECT_IS_TOP_LEVEL})

if (VULKAN_HEADERS_INSTALL)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/install.cmake)
endif()
