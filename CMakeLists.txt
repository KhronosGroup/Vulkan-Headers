# ~~~
# Copyright 2018-2023 The Khronos Group Inc.
# Copyright 2018-2023 Valve Corporation
# Copyright 2018-2023 LunarG, Inc.
#
# SPDX-License-Identifier: Apache-2.0
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

    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)

    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vk_video" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    # Preserve source permissions https://github.com/KhronosGroup/Vulkan-Headers/issues/336
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/registry" DESTINATION "${CMAKE_INSTALL_DATADIR}/vulkan" USE_SOURCE_PERMISSIONS)

    set_target_properties(Vulkan-Headers PROPERTIES EXPORT_NAME "Headers")

    install(TARGETS Vulkan-Headers EXPORT VulkanHeadersConfig INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(EXPORT VulkanHeadersConfig NAMESPACE "Vulkan::" DESTINATION "share/cmake/VulkanHeaders")

    set(version_config "${CMAKE_CURRENT_BINARY_DIR}/generated/VulkanHeadersConfigVersion.cmake")
    write_basic_package_version_file("${version_config}" COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)
    install(FILES "${version_config}" DESTINATION "share/cmake/VulkanHeaders")
endif()
