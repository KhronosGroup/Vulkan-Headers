# ~~~
# Copyright 2022-2023 The Khronos Group Inc.
# Copyright 2022-2023 Valve Corporation
# Copyright 2022-2023 LunarG, Inc.
#
# SPDX-License-Identifier: Apache-2.0
# ~~~

# Forward the toolchain to the integration tests when testing the C++ named modules, as `import std` must be built with the same toolchain.
# VULKAN_HEADERS_ENABLE_MODULE is always forwarded last so that the test argument is never empty when the module is disabled.
set(module_build_options
    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    "-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}"
    -DCMAKE_CXX_STDLIB_MODULES_JSON=${CMAKE_CXX_STDLIB_MODULES_JSON}
)

# Test add_subdirectory support
add_test(NAME integration.add_subdirectory
    COMMAND ${CMAKE_CTEST_COMMAND}
        --build-and-test ${CMAKE_CURRENT_LIST_DIR}/integration
                         ${CMAKE_CURRENT_BINARY_DIR}/add_subdirectory
        --build-generator ${CMAKE_GENERATOR}
        --build-options
            -DFIND_PACKAGE_TESTING=OFF
            "$<$<TARGET_EXISTS:Vulkan-HppModule>:${module_build_options};>-DVULKAN_HEADERS_ENABLE_MODULE=$<TARGET_EXISTS:Vulkan-HppModule>"
    COMMAND_EXPAND_LISTS
)

set(test_install_dir "${CMAKE_CURRENT_BINARY_DIR}/install")
add_test(NAME integration.install
    COMMAND ${CMAKE_COMMAND} --install ${VULKAN_HEADERS_BINARY_DIR} --prefix ${test_install_dir} --config $<CONFIG>
)

# Test find_package support
add_test(NAME integration.find_package
    COMMAND ${CMAKE_CTEST_COMMAND}
        --build-and-test ${CMAKE_CURRENT_LIST_DIR}/integration
                         ${CMAKE_CURRENT_BINARY_DIR}/find_package
        --build-generator ${CMAKE_GENERATOR}
        --build-options
            -DFIND_PACKAGE_TESTING=ON
            -DCMAKE_PREFIX_PATH=${test_install_dir}
            "$<$<TARGET_EXISTS:Vulkan-HppModule>:${module_build_options};>-DVULKAN_HEADERS_ENABLE_MODULE=$<TARGET_EXISTS:Vulkan-HppModule>"
    COMMAND_EXPAND_LISTS
)

# Installing comes before testing
set_tests_properties(integration.find_package PROPERTIES DEPENDS integration.install)
