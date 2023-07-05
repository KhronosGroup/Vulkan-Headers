cmake_minimum_required(VERSION 3.14.2)

project(TEST_VULKAN_HEADERS_ADD_SUBDIRECTORY_SUPPORT LANGUAGES C)

add_subdirectory(../../ ${CMAKE_CURRENT_BINARY_DIR}/headers)

if (NOT TARGET Vulkan::Headers)
    message(FATAL_ERROR "Vulkan::Headers target not defined")
endif()

# Consuming vulkan-headers via add_subdirectory should NOT add installation code to the parent CMake project.
if (DEFINED CMAKE_INSTALL_INCLUDEDIR)
    message(FATAL_ERROR "CMAKE_INSTALL_INCLUDEDIR was defined!")
endif()

add_library(foobar STATIC)

target_link_libraries(foobar PRIVATE Vulkan::Headers)

target_sources(foobar PRIVATE
    ../vk_icd.c
    ../vk_layer.c
)
