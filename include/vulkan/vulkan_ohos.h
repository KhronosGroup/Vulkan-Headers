#ifndef VULKAN_OHOS_H_
#define VULKAN_OHOS_H_ 1

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



// VK_OHOS_external_memory is a preprocessor guard. Do not pass it to API calls.
#define VK_OHOS_external_memory 1
struct OH_NativeBuffer;
#define VK_OHOS_EXTERNAL_MEMORY_SPEC_VERSION 1
#define VK_OHOS_EXTERNAL_MEMORY_EXTENSION_NAME "VK_OHOS_external_memory"
typedef struct VkNativeBufferUsageOHOS {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_NATIVE_BUFFER_USAGE_OHOS);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint64_t           OHOSNativeBufferUsage;
} VkNativeBufferUsageOHOS;

typedef struct VkNativeBufferPropertiesOHOS {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_NATIVE_BUFFER_PROPERTIES_OHOS);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceSize       allocationSize;
    uint32_t           memoryTypeBits;
} VkNativeBufferPropertiesOHOS;

typedef struct VkNativeBufferFormatPropertiesOHOS {
    VkStructureType                  sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_NATIVE_BUFFER_FORMAT_PROPERTIES_OHOS);
    void*                            pNext VK_CPP11_DEFAULT(nullptr);
    VkFormat                         format;
    uint64_t                         externalFormat;
    VkFormatFeatureFlags             formatFeatures;
    VkComponentMapping               samplerYcbcrConversionComponents;
    VkSamplerYcbcrModelConversion    suggestedYcbcrModel;
    VkSamplerYcbcrRange              suggestedYcbcrRange;
    VkChromaLocation                 suggestedXChromaOffset;
    VkChromaLocation                 suggestedYChromaOffset;
} VkNativeBufferFormatPropertiesOHOS;

typedef struct VkImportNativeBufferInfoOHOS {
    VkStructureType            sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_NATIVE_BUFFER_INFO_OHOS);
    const void*                pNext VK_CPP11_DEFAULT(nullptr);
    struct OH_NativeBuffer*    buffer;
} VkImportNativeBufferInfoOHOS;

typedef struct VkMemoryGetNativeBufferInfoOHOS {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_MEMORY_GET_NATIVE_BUFFER_INFO_OHOS);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceMemory     memory;
} VkMemoryGetNativeBufferInfoOHOS;

typedef struct VkExternalFormatOHOS {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_OHOS);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint64_t           externalFormat;
} VkExternalFormatOHOS;

typedef VkResult (VKAPI_PTR *PFN_vkGetNativeBufferPropertiesOHOS)(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties);
typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryNativeBufferOHOS)(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(
    VkDevice                                    device,
    const struct OH_NativeBuffer*               buffer,
    VkNativeBufferPropertiesOHOS*               pProperties);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(
    VkDevice                                    device,
    const VkMemoryGetNativeBufferInfoOHOS*      pInfo,
    struct OH_NativeBuffer**                    pBuffer);
#endif
#endif


// VK_OHOS_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_OHOS_surface 1
typedef struct NativeWindow OHNativeWindow;
#define VK_OHOS_SURFACE_SPEC_VERSION      1
#define VK_OHOS_SURFACE_EXTENSION_NAME    "VK_OHOS_surface"
typedef VkFlags VkSurfaceCreateFlagsOHOS;
typedef struct VkSurfaceCreateInfoOHOS {
    VkStructureType             sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_OHOS);
    const void*                 pNext VK_CPP11_DEFAULT(nullptr);
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

#ifdef __cplusplus
}
#endif

#endif
