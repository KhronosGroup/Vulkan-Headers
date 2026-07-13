# ~~~
# Copyright 2022-2023 The Khronos Group Inc.
# Copyright 2022-2023 Valve Corporation
# Copyright 2022-2023 LunarG, Inc.
#
# SPDX-License-Identifier: Apache-2.0
# ~~~

# Test add_subdirectory suppport
add_test(NAME integration.add_subdirectory
    COMMAND ${CMAKE_CTEST_COMMAND}
        --build-and-test ${CMAKE_CURRENT_LIST_DIR}/integration
                         ${CMAKE_CURRENT_BINARY_DIR}/add_subdirectory
        --build-generator ${CMAKE_GENERATOR}
        --build-options
            -DFIND_PACKAGE_TESTING=OFF
)

set(test_install_dir "${CMAKE_CURRENT_BINARY_DIR}/install")
add_test(NAME integration.install
    COMMAND ${CMAKE_COMMAND} --install ${VULKAN_HEADERS_BINARY_DIR} --prefix ${test_install_dir} --config $<CONFIG>
)

# Test find_package suppport
add_test(NAME integration.find_package
    COMMAND ${CMAKE_CTEST_COMMAND}
        --build-and-test ${CMAKE_CURRENT_LIST_DIR}/integration
                         ${CMAKE_CURRENT_BINARY_DIR}/find_package
        --build-generator ${CMAKE_GENERATOR}
        --build-options
            -DFIND_PACKAGE_TESTING=ON
            -DCMAKE_PREFIX_PATH=${test_install_dir}
)

# Installing comes before testing
set_tests_properties(integration.find_package PROPERTIES DEPENDS integration.install)

# Verify that every public header compiles standalone (i.e. that each one includes
# everything it needs and doesn't just rely on being pulled in after some other header).
#
# The header list is globbed so newly added headers are picked up automatically. Headers
# that are known not to be self-contained are excluded from compilation individually via
# SKIP_LINTING below, rather than omitted from the FILE_SET, so they still show up here
# and don't silently fall out of the verification as the headers evolve.
file(GLOB_RECURSE vk_headers_verify_headers CONFIGURE_DEPENDS LIST_DIRECTORIES false
    "${VULKAN_HEADERS_SOURCE_DIR}/include/vulkan/*.h"
    "${VULKAN_HEADERS_SOURCE_DIR}/include/vulkan/*.hpp"
    "${VULKAN_HEADERS_SOURCE_DIR}/include/vk_video/*.h"
)
list(SORT vk_headers_verify_headers)

add_library(vk_headers_verify INTERFACE)
set_target_properties(vk_headers_verify PROPERTIES LINKER_LANGUAGE C)
target_sources(vk_headers_verify INTERFACE
    FILE_SET HEADERS
    BASE_DIRS "${VULKAN_HEADERS_SOURCE_DIR}/include"
    FILES ${vk_headers_verify_headers}
)

# WSI headers (vulkan_win32.h, vulkan_xcb.h, vulkan_wayland.h, ...) are deliberately
# skipped: vulkan.h itself includes their platform prerequisites (e.g. <windows.h>) before
# including them, so they're sub-headers of vulkan.h, not standalone headers.
set(vk_headers_verify_platform_headers
    vulkan_android.h
    vulkan_directfb.h
    vulkan_fuchsia.h
    vulkan_ggp.h
    vulkan_ios.h
    vulkan_macos.h
    vulkan_metal.h
    vulkan_ohos.h
    vulkan_screen.h
    vulkan_ubm.h
    vulkan_vi.h
    vulkan_wayland.h
    vulkan_win32.h
    vulkan_xcb.h
    vulkan_xlib.h
    vulkan_xlib_xrandr.h
)

# vulkan_beta.h cannot be included on its own: it relies on types (VkStructureType,
# VkBool32, ...) that are defined in vulkan_core.h, which vulkan.h includes first.
set(vk_headers_verify_detail_headers
    vulkan_beta.h
)

# None of the *.hpp headers below are designed to be included on their own either:
# they're pulled in automatically by including vulkan.hpp (vulkan_hpp_macros.hpp,
# vulkan_enums.hpp, vulkan_to_string.hpp, vulkan_handles.hpp, vulkan_structs.hpp, and
# vulkan_funcs.hpp, alongside vulkan.h), so verifying vulkan.hpp standalone already
# covers them and there's no need to verify them individually.
set(vk_headers_verify_hpp_headers
    vulkan_enums.hpp
    vulkan_funcs.hpp
    vulkan_handles.hpp
    vulkan_hpp_macros.hpp
    vulkan_structs.hpp
    vulkan_to_string.hpp
)

foreach(header IN LISTS vk_headers_verify_platform_headers vk_headers_verify_detail_headers vk_headers_verify_hpp_headers)
    set_source_files_properties("${VULKAN_HEADERS_SOURCE_DIR}/include/vulkan/${header}" PROPERTIES SKIP_LINTING ON)
endforeach()

set_target_properties(vk_headers_verify PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

# CMake always sets EXCLUDE_FROM_ALL on the generated all_verify_interface_header_sets
# target, so a plain build never compiles it; this explicit --target build is the only
# way to run the verification.
add_test(NAME headers.verify_standalone
    COMMAND ${CMAKE_COMMAND} --build ${VULKAN_HEADERS_BINARY_DIR} --target all_verify_interface_header_sets --config $<CONFIG>
)
