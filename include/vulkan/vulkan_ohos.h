#ifndef VULKAN_OHOS_H_
#define VULKAN_OHOS_H_ 1

/*
** Copyright 2015-2025 The Khronos Group Inc.
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



// VK_OHOS_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_OHOS_surface 1
typedef struct NativeWindow OHNativeWindow;
#define VK_OHOS_SURFACE_SPEC_VERSION      1
#define VK_OHOS_SURFACE_EXTENSION_NAME    "VK_OHOS_surface"
typedef VkFlags VkSurfaceCreateFlagsOHOS;
typedef struct VkSurfaceCreateInfoOHOS {
    VkStructureType             sType;
    const void*                 pNext;
    VkSurfaceCreateFlagsOHOS    flags;
    OHNativeWindow*             window;
} VkSurfaceCreateInfoOHOS;

typedef VkResult (VKAPI_PTR *PFN_vkCreateSurfaceOHOS)(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(
    VkInstance                                  instance,
    const VkSurfaceCreateInfoOHOS*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);
#endif
#endif


// VK_OHOS_native_buffer is a preprocessor guard. Do not pass it to API calls.
#define VK_OHOS_native_buffer 1
struct OHBufferHandle;
#define VK_OHOS_NATIVE_BUFFER_SPEC_VERSION 1
#define VK_OHOS_NATIVE_BUFFER_EXTENSION_NAME "VK_OHOS_native_buffer"

typedef enum VkSwapchainImageUsageFlagBitsOHOS {
    VK_SWAPCHAIN_IMAGE_USAGE_SHARED_BIT_OHOS = 0x00000001,
    VK_SWAPCHAIN_IMAGE_USAGE_FLAG_BITS_MAX_ENUM_OHOS = 0x7FFFFFFF
} VkSwapchainImageUsageFlagBitsOHOS;
typedef VkFlags VkSwapchainImageUsageFlagsOHOS;
typedef struct VkNativeBufferOHOS {
    VkStructureType           sType;
    const void*               pNext;
    struct OHBufferHandle*    handle;
} VkNativeBufferOHOS;

typedef struct VkSwapchainImageCreateInfoOHOS {
    VkStructureType                   sType;
    const void*                       pNext;
    VkSwapchainImageUsageFlagsOHOS    usage;
} VkSwapchainImageCreateInfoOHOS;

typedef struct VkPhysicalDevicePresentationPropertiesOHOS {
    VkStructureType    sType;
    const void*        pNext;
    VkBool32           sharedImage;
} VkPhysicalDevicePresentationPropertiesOHOS;

typedef VkResult (VKAPI_PTR *PFN_vkGetSwapchainGrallocUsageOHOS)(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage);
typedef VkResult (VKAPI_PTR *PFN_vkAcquireImageOHOS)(VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence);
typedef VkResult (VKAPI_PTR *PFN_vkQueueSignalReleaseImageOHOS)(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainGrallocUsageOHOS(
    VkDevice                                    device,
    VkFormat                                    format,
    VkImageUsageFlags                           imageUsage,
    uint64_t*                                   grallocUsage);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireImageOHOS(
    VkDevice                                    device,
    VkImage                                     image,
    int32_t                                     nativeFenceFd,
    VkSemaphore                                 semaphore,
    VkFence                                     fence);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSignalReleaseImageOHOS(
    VkQueue                                     queue,
    uint32_t                                    waitSemaphoreCount,
    const VkSemaphore*                          pWaitSemaphores,
    VkImage                                     image,
    int32_t*                                    pNativeFenceFd);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
