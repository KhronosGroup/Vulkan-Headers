# ~~~
# Copyright (c) 2022-2023 LunarG, Inc.
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
target_compile_definitions(vk_sdk_platform PRIVATE VK_SDK_PLATFORM_SUPRRESS_DEPRECATION_WARNING)
