#ifndef VULKAN_SCREEN_H_
#define VULKAN_SCREEN_H_ 1

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



// VK_QNX_screen_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_QNX_screen_surface 1
#define VK_QNX_SCREEN_SURFACE_SPEC_VERSION 1
#define VK_QNX_SCREEN_SURFACE_EXTENSION_NAME "VK_QNX_screen_surface"
typedef VkFlags VkScreenSurfaceCreateFlagsQNX;
typedef struct VkScreenSurfaceCreateInfoQNX {
    VkStructureType                  sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX);
    const void*                      pNext VK_CPP11_DEFAULT(nullptr);
    VkScreenSurfaceCreateFlagsQNX    flags;
    struct _screen_context*          context;
    struct _screen_window*           window;
} VkScreenSurfaceCreateInfoQNX;

typedef VkResult (VKAPI_PTR *PFN_vkCreateScreenSurfaceQNX)(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateScreenSurfaceQNX(
    VkInstance                                  instance,
    const VkScreenSurfaceCreateInfoQNX*         pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceScreenPresentationSupportQNX(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct _screen_window*                      window);
#endif
#endif


// VK_QNX_external_memory_screen_buffer is a preprocessor guard. Do not pass it to API calls.
#define VK_QNX_external_memory_screen_buffer 1
#define VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_SPEC_VERSION 1
#define VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME "VK_QNX_external_memory_screen_buffer"
typedef struct VkScreenBufferPropertiesQNX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceSize       allocationSize;
    uint32_t           memoryTypeBits;
} VkScreenBufferPropertiesQNX;

typedef struct VkScreenBufferFormatPropertiesQNX {
    VkStructureType                  sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX);
    void*                            pNext VK_CPP11_DEFAULT(nullptr);
    VkFormat                         format;
    uint64_t                         externalFormat;
    uint64_t                         screenUsage;
    VkFormatFeatureFlags             formatFeatures;
    VkComponentMapping               samplerYcbcrConversionComponents;
    VkSamplerYcbcrModelConversion    suggestedYcbcrModel;
    VkSamplerYcbcrRange              suggestedYcbcrRange;
    VkChromaLocation                 suggestedXChromaOffset;
    VkChromaLocation                 suggestedYChromaOffset;
} VkScreenBufferFormatPropertiesQNX;

typedef struct VkImportScreenBufferInfoQNX {
    VkStructureType           sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX);
    const void*               pNext VK_CPP11_DEFAULT(nullptr);
    struct _screen_buffer*    buffer;
} VkImportScreenBufferInfoQNX;

typedef struct VkExternalFormatQNX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint64_t           externalFormat;
} VkExternalFormatQNX;

typedef struct VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           screenBufferImport;
} VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX;

typedef VkResult (VKAPI_PTR *PFN_vkGetScreenBufferPropertiesQNX)(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetScreenBufferPropertiesQNX(
    VkDevice                                    device,
    const struct _screen_buffer*                buffer,
    VkScreenBufferPropertiesQNX*                pProperties);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
