/*
 * Copyright 2025 The Khronos Group Inc.
 * Copyright 2025 Valve Corporation
 * Copyright 2025 LunarG, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
import vulkan_hpp;
#include <string>

int test_instance()
{
    vk::InstanceCreateInfo instanceCreateInfo({}, nullptr);
    vk::Instance instance = vk::createInstance(instanceCreateInfo);
    instance.destroy();
    return 0;
}