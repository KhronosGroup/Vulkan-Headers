cmake_minimum_required(VERSION 3.14.2)

project(TEST_VULKAN_HEADERS_ADD_SUBDIRECTORY_SUPPORT LANGUAGES C)

add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/headers)

if (NOT TARGET Vulkan::Headers)
    message(FATAL_ERROR "Vulkan::Headers target not defined")
endif()

# By default installation for a subproject should be disabled.
# This makes it easier to consume for most projects.
# Consuming the vulkan-headers via add_subdirectory and installing
# them is the more niche use case.
if (VULKAN_HEADERS_INSTALL)
    message(FATAL_ERROR "VULKAN_HEADERS_INSTALL should be OFF!")
endif()

add_library(foobar STATIC)

target_link_libraries(foobar PRIVATE Vulkan::Headers)

target_sources(foobar PRIVATE
    ../vk_icd.c
    ../vk_layer.c
)
