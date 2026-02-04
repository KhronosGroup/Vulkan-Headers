#ifndef VULKAN_IOS_H_
#define VULKAN_IOS_H_ 1

/*
** Copyright 2015-2026 The Khronos Group Inc.
**
** SPDX-License-Identifier: Apache-2.0
*/

/*
** This header is generated from the Khronos Vulkan XML API Registry.
**
*/


#ifdef __cplusplus
extern "C" {
#endif



// VK_MVK_ios_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_MVK_ios_surface 1
#define VK_MVK_IOS_SURFACE_SPEC_VERSION   3
#define VK_MVK_IOS_SURFACE_EXTENSION_NAME "VK_MVK_ios_surface"
typedef VkFlags VkIOSSurfaceCreateFlagsMVK;
typedef struct VkIOSSurfaceCreateInfoMVK {
    VkStructureType               sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK);
    const void*                   pNext VK_CPP11_DEFAULT(nullptr);
    VkIOSSurfaceCreateFlagsMVK    flags;
    const void*                   pView;
} VkIOSSurfaceCreateInfoMVK;

typedef VkResult (VKAPI_PTR *PFN_vkCreateIOSSurfaceMVK)(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK& pCreateInfo, VkSurfaceKHR* pSurface)
{
    return vkCreateIOSSurfaceMVK(instance, &pCreateInfo, nullptr, pSurface);
}
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
