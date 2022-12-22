# ~~~
# Copyright (c) 2022 LunarG, Inc.
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

set(vulkan_core_header_file "${PROJECT_SOURCE_DIR}/include/vulkan/vulkan_core.h")
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

set(VK_VERSION_STRING "${VK_VERSION_MAJOR}.${VK_VERSION_MINOR}.${VK_HEADER_VERSION}")

if (NOT ${VK_VERSION_STRING} STREQUAL ${PROJECT_VERSION})
    message(FATAL_ERROR "Project version is ${PROJECT_VERSION} but should be ${VK_VERSION_STRING}!")
endif()

# Test the non-API headers provided by this repo
# NOTE: For us testing just means that these header files compile
# with reasonable warnings.

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(${CMAKE_C_COMPILER_ID} MATCHES "(GNU|Clang)")
    add_compile_options(
        -Wpedantic
        -Wall
        -Wextra
        -Werror
    )
endif()

# vk_icd.h
add_executable(vk_icd vk_icd.c)
target_link_libraries(vk_icd PRIVATE Vulkan::Headers)

# vk_layer.h
add_library(vk_layer MODULE vk_layer.c)
target_link_libraries(vk_layer PRIVATE Vulkan::Headers)

# vk_sdk_platform.h
add_executable(vk_sdk_platform vk_sdk_platform.c)
target_link_libraries(vk_sdk_platform PRIVATE Vulkan::Headers)
