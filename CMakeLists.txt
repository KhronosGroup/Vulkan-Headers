# ~~~
# Copyright 2018-2023 The Khronos Group Inc.
# Copyright 2018-2023 Valve Corporation
# Copyright 2018-2023 LunarG, Inc.
#
# SPDX-License-Identifier: Apache-2.0
# ~~~
cmake_minimum_required(VERSION 3.22.1)

# NOTE: Parsing the version like this is suboptimal but neccessary due to our release process:
# https://github.com/KhronosGroup/Vulkan-Headers/pull/346
#
# As shown a more robust approach would be just to add basic test code to check the project version.
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

project(VULKAN_HEADERS LANGUAGES C CXX VERSION ${VK_VERSION_STRING})

# options for Vulkan-Headers
option(VULKAN_HEADERS_ENABLE_TESTS "Test Vulkan-Headers" ${PROJECT_IS_TOP_LEVEL})
option(VULKAN_HEADERS_ENABLE_INSTALL "Install Vulkan-Headers" ${PROJECT_IS_TOP_LEVEL})
option(VK_NO_PROTOTYPES "Remove function prototypes" OFF)
# options for Vulkan-Hpp
option(VULKAN_HPP_ENABLE_MODULE "Enables building of the Vulkan C++20 module; requires minimum CMake version 3.28" OFF)
option(VULKAN_HPP_ENABLE_MODULE_STD "Enables building of the Vulkan C++20 module with import std; requires minimum CMake version 3.30" OFF)
# options for Vulkan-Hpp compile definitions (see https://github.com/KhronosGroup/Vulkan-Hpp/tree/main?tab=readme-ov-file#configuration-options for details)
option(VULKAN_HPP_DISABLE_ENHANCED_MODE "Disable all enhanced functionality apart from scoped enums, bitmasks, default initialization and vk::StructureChain" OFF)
option(VULKAN_HPP_DISPATCH_LOADER_DYNAMIC "Select the dynamic (ON) or static (OFF) dispatch loader (defaults to VK_NO_PROTOTYPES)" ${VK_NO_PROTOTYPES})
option(VULKAN_HPP_FLAGS_MASK_TYPE_AS_PUBLIC "Change the m_mask access modifier in vk::Flags to public" OFF)
option(VULKAN_HPP_HANDLES_MOVE_EXCHANGE "Enable 'm_handle = exchange( rhs.m_handle, {} )' in move constructors" OFF)
option(VULKAN_HPP_NO_CONSTRUCTORS "Remove constructors from structs and unions to enable C++20 designated initializers" OFF)
option(VULKAN_HPP_NO_EXCEPTIONS "Do not throw exceptions when vulkan functions return an error code" OFF)
option(VULKAN_HPP_NO_NODISCARD_WARNINGS "Remove C++17 [[nodiscard]] from function signatures that return something" OFF)
option(VULKAN_HPP_NO_SETTERS "Remove setters for structs and unions" OFF)
option(VULKAN_HPP_NO_SMART_HANDLE "Remove the vk::UniqueHandle helper class" OFF)
option(VULKAN_HPP_NO_SPACESHIP_OPERATOR "Remove the C++20 <=> (spaceship) operator" OFF)
option(VULKAN_HPP_NO_TO_STRING "Remove inclusion of vulkan_to_string.hpp from vulkan.hpp" OFF)
option(VULKAN_HPP_NO_WIN32_PROTOTYPES "Remove HINSTANCE, LoadLibraryA and other symbols, which are declared if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL is enabled on Win32" OFF)
option(VULKAN_HPP_RAII_NO_EXCEPTIONS "Do not throw exceptions when vulkan functions from vk::raii return an error code." OFF)
option(VULKAN_HPP_SMART_HANDLE_IMPLICIT_CAST "Enable implicit casts from vk::UniqueHandle and vk::SharedHandle to their matching vk::Handle" OFF)
option(VULKAN_HPP_TYPESAFE_CONVERSION "Enable copy constructors for non-dispatchable handles" ON)
option(VULKAN_HPP_USE_REFLECT "Adds reflect function to structures, which returns an iterable tuple" OFF)

# set up Vulkan-Headers
add_library(Vulkan-Headers INTERFACE)
add_library(Vulkan::Headers ALIAS Vulkan-Headers)
target_include_directories(Vulkan-Headers INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
if (VK_NO_PROTOTYPES)
	target_compile_definitions(Vulkan-Headers INTERFACE "VK_NO_PROTOTYPES")
endif()

# set up Vulkan-Hpp
add_library(Vulkan-Hpp INTERFACE)
add_library(Vulkan::Hpp ALIAS Vulkan-Hpp)
target_link_libraries(Vulkan-Hpp INTERFACE Vulkan-Headers)
# set up Vulkan-Hpp compile definitions
if (VULKAN_HPP_DISABLE_ENHANCED_MODE)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_DISABLE_ENHANCED_MODE")
endif()
if (VULKAN_HPP_DISPATCH_LOADER_DYNAMIC)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_DISPATCH_LOADER_DYNAMIC")
    if (NOT VK_NO_PROTOTYPES)
        message(WARNING "VK_NO_PROTOTYPES disabled while using VULKAN_HPP_DISPATCH_LOADER_DYNAMIC, consider enabling both")
    endif()
endif()
if (VULKAN_HPP_USE_REFLECT)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_USE_REFLECT")
endif()
if (NOT VULKAN_HPP_TYPESAFE_CONVERSION)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_TYPESAFE_CONVERSION=0")
endif()
if (VULKAN_HPP_HANDLES_MOVE_EXCHANGE)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_HANDLES_MOVE_EXCHANGE")
endif()
if (VULKAN_HPP_FLAGS_MASK_TYPE_AS_PUBLIC)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_FLAGS_MASK_TYPE_AS_PUBLIC")
endif()
if (VULKAN_HPP_SMART_HANDLE_IMPLICIT_CAST)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_SMART_HANDLE_IMPLICIT_CAST")
endif()
if (VULKAN_HPP_NO_SETTERS)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_SETTERS")
endif()
if (VULKAN_HPP_NO_TO_STRING)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_TO_STRING")
endif()
if (VULKAN_HPP_NO_EXCEPTIONS)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_EXCEPTIONS")
endif()
if (VULKAN_HPP_NO_CONSTRUCTORS)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_CONSTRUCTORS")
endif()
if (VULKAN_HPP_NO_SMART_HANDLE)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_SMART_HANDLE")
endif()
if (VULKAN_HPP_RAII_NO_EXCEPTIONS)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_RAII_NO_EXCEPTIONS")
endif()
if (VULKAN_HPP_NO_WIN32_PROTOTYPES)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_WIN32_PROTOTYPES")
endif()
if (VULKAN_HPP_NO_NODISCARD_WARNINGS)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_NODISCARD_WARNINGS")
endif()
if (VULKAN_HPP_NO_SPACESHIP_OPERATOR)
	target_compile_definitions(Vulkan-Hpp INTERFACE "VULKAN_HPP_NO_SPACESHIP_OPERATOR")
endif()

if (VULKAN_HPP_ENABLE_MODULE)
    # check for compiler support
    if ((CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND (MSVC_VERSION GREATER_EQUAL "1941")) OR
        # clang-cl doesn't currently support modules
        (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"
            AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "16.0"
            AND (NOT CMAKE_C_COMPILER_FRONTEND_VARIANT MATCHES "MSVC")
            AND (NOT CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS STREQUAL CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS-NOTFOUND)) OR
        (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "14.0")
    )
        # check for CMake support
        if(VULKAN_HPP_ENABLE_MODULE_STD AND CMAKE_VERSION VERSION_LESS "3.30")
            message(FATAL_ERROR "Vulkan-Hpp: C++20 module with import std requires CMake 3.30 or later")
        elseif (CMAKE_VERSION VERSION_LESS "3.28")
            message(FATAL_ERROR "Vulkan-Hpp: C++20 module requires CMake 3.28 or later")
        endif()
        
        # set up Vulkan-HppModule
        add_library(Vulkan-HppModule)
        add_library(Vulkan::HppModule ALIAS Vulkan-HppModule)
        target_sources(Vulkan-HppModule
            PUBLIC
            FILE_SET module TYPE CXX_MODULES FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan/vulkan.cppm")
        set_target_properties(Vulkan-HppModule PROPERTIES
            CXX_STANDARD_REQUIRED ON # CXX version is a hard requirement for modules
            CXX_EXTENSIONS OFF) # Clang's module support can be broken with extensions enabled
        if (VULKAN_HPP_ENABLE_MODULE_STD)
            target_compile_features(uses_std
                PRIVATE   cxx_std_23
                INTERFACE cxx_std_20) # only C++20 is required to consume this module
            set_target_properties(Vulkan-HppModule PROPERTIES CXX_MODULE_STD ON)
        else()
            target_compile_features(Vulkan-HppModule PUBLIC cxx_std_20)
        endif()
        target_link_libraries(Vulkan-HppModule PUBLIC Vulkan::Hpp)
    else()
        message(FATAL_ERROR "Vulkan-Hpp: C++20 module support is requested but was disabled due to lacking compiler support on this platform")
    endif()
endif()

if (VULKAN_HEADERS_ENABLE_TESTS)
    enable_testing() # This is only effective in the top level CMakeLists.txt file.
    add_subdirectory(tests)
endif()

if (VULKAN_HEADERS_ENABLE_INSTALL)
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
