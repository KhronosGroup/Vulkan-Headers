#ifndef VULKAN_GGP_H_
#define VULKAN_GGP_H_ 1

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



// VK_GGP_stream_descriptor_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_GGP_stream_descriptor_surface 1
#define VK_GGP_STREAM_DESCRIPTOR_SURFACE_SPEC_VERSION 1
#define VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME "VK_GGP_stream_descriptor_surface"
typedef VkFlags VkStreamDescriptorSurfaceCreateFlagsGGP;
typedef struct VkStreamDescriptorSurfaceCreateInfoGGP {
    VkStructureType                            sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP);
    const void*                                pNext VK_CPP11_DEFAULT(nullptr);
    VkStreamDescriptorSurfaceCreateFlagsGGP    flags;
    GgpStreamDescriptor                        streamDescriptor;
} VkStreamDescriptorSurfaceCreateInfoGGP;

typedef VkResult (VKAPI_PTR *PFN_vkCreateStreamDescriptorSurfaceGGP)(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateStreamDescriptorSurfaceGGP(
    VkInstance                                  instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP& pCreateInfo, VkSurfaceKHR* pSurface)
{
    return vkCreateStreamDescriptorSurfaceGGP(instance, &pCreateInfo, nullptr, pSurface);
}
#endif
#endif
#endif


// VK_GGP_frame_token is a preprocessor guard. Do not pass it to API calls.
#define VK_GGP_frame_token 1
#define VK_GGP_FRAME_TOKEN_SPEC_VERSION   1
#define VK_GGP_FRAME_TOKEN_EXTENSION_NAME "VK_GGP_frame_token"
typedef struct VkPresentFrameTokenGGP {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    GgpFrameToken      frameToken;
} VkPresentFrameTokenGGP;


#ifdef __cplusplus
}
#endif

#endif
