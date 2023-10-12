# ~~~
# Copyright 2022-2023 The Khronos Group Inc.
# Copyright 2022-2023 Valve Corporation
# Copyright 2022-2023 LunarG, Inc.
#
# SPDX-License-Identifier: Apache-2.0
# ~~~

# Test the non-API headers provided by this repo
# NOTE: For us testing just means that these header files compile
# with reasonable warnings.

message(STATUS "${PROJECT_NAME} = ${PROJECT_VERSION}")

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

if (MSVC)
    add_compile_options(
        /W4
        /permissive-
        /WX
    )
endif()

# vk_icd.h
add_library(vk_icd MODULE vk_icd.c)
target_link_libraries(vk_icd PRIVATE Vulkan::Headers)

# vk_layer.h
add_library(vk_layer MODULE vk_layer.c)
target_link_libraries(vk_layer PRIVATE Vulkan::Headers)

if (NOT TARGET Vulkan-Headers)
    message(FATAL_ERROR "Backcompat for Vulkan-Headers target broken!")
endif()
