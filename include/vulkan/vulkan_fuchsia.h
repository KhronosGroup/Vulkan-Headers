#ifndef VULKAN_FUCHSIA_H_
#define VULKAN_FUCHSIA_H_ 1

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



// VK_FUCHSIA_imagepipe_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_FUCHSIA_imagepipe_surface 1
#define VK_FUCHSIA_IMAGEPIPE_SURFACE_SPEC_VERSION 1
#define VK_FUCHSIA_IMAGEPIPE_SURFACE_EXTENSION_NAME "VK_FUCHSIA_imagepipe_surface"
typedef VkFlags VkImagePipeSurfaceCreateFlagsFUCHSIA;
typedef struct VkImagePipeSurfaceCreateInfoFUCHSIA {
    VkStructureType                         sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA);
    const void*                             pNext VK_CPP11_DEFAULT(nullptr);
    VkImagePipeSurfaceCreateFlagsFUCHSIA    flags;
    zx_handle_t                             imagePipeHandle;
} VkImagePipeSurfaceCreateInfoFUCHSIA;

typedef VkResult (VKAPI_PTR *PFN_vkCreateImagePipeSurfaceFUCHSIA)(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);
#endif
#endif


// VK_FUCHSIA_external_memory is a preprocessor guard. Do not pass it to API calls.
#define VK_FUCHSIA_external_memory 1
#define VK_FUCHSIA_EXTERNAL_MEMORY_SPEC_VERSION 1
#define VK_FUCHSIA_EXTERNAL_MEMORY_EXTENSION_NAME "VK_FUCHSIA_external_memory"
typedef struct VkImportMemoryZirconHandleInfoFUCHSIA {
    VkStructureType                       sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA);
    const void*                           pNext VK_CPP11_DEFAULT(nullptr);
    VkExternalMemoryHandleTypeFlagBits    handleType;
    zx_handle_t                           handle;
} VkImportMemoryZirconHandleInfoFUCHSIA;

typedef struct VkMemoryZirconHandlePropertiesFUCHSIA {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           memoryTypeBits;
} VkMemoryZirconHandlePropertiesFUCHSIA;

typedef struct VkMemoryGetZirconHandleInfoFUCHSIA {
    VkStructureType                       sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA);
    const void*                           pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceMemory                        memory;
    VkExternalMemoryHandleTypeFlagBits    handleType;
} VkMemoryGetZirconHandleInfoFUCHSIA;

typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryZirconHandleFUCHSIA)(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkMemoryGetZirconHandleInfoFUCHSIA*   pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandlePropertiesFUCHSIA(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    zx_handle_t                                 zirconHandle,
    VkMemoryZirconHandlePropertiesFUCHSIA*      pMemoryZirconHandleProperties);
#endif
#endif


// VK_FUCHSIA_external_semaphore is a preprocessor guard. Do not pass it to API calls.
#define VK_FUCHSIA_external_semaphore 1
#define VK_FUCHSIA_EXTERNAL_SEMAPHORE_SPEC_VERSION 1
#define VK_FUCHSIA_EXTERNAL_SEMAPHORE_EXTENSION_NAME "VK_FUCHSIA_external_semaphore"
typedef struct VkImportSemaphoreZirconHandleInfoFUCHSIA {
    VkStructureType                          sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA);
    const void*                              pNext VK_CPP11_DEFAULT(nullptr);
    VkSemaphore                              semaphore;
    VkSemaphoreImportFlags                   flags;
    VkExternalSemaphoreHandleTypeFlagBits    handleType;
    zx_handle_t                              zirconHandle;
} VkImportSemaphoreZirconHandleInfoFUCHSIA;

typedef struct VkSemaphoreGetZirconHandleInfoFUCHSIA {
    VkStructureType                          sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA);
    const void*                              pNext VK_CPP11_DEFAULT(nullptr);
    VkSemaphore                              semaphore;
    VkExternalSemaphoreHandleTypeFlagBits    handleType;
} VkSemaphoreGetZirconHandleInfoFUCHSIA;

typedef VkResult (VKAPI_PTR *PFN_vkImportSemaphoreZirconHandleFUCHSIA)(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);
typedef VkResult (VKAPI_PTR *PFN_vkGetSemaphoreZirconHandleFUCHSIA)(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle);
#endif
#endif


// VK_FUCHSIA_buffer_collection is a preprocessor guard. Do not pass it to API calls.
#define VK_FUCHSIA_buffer_collection 1
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBufferCollectionFUCHSIA)
#define VK_FUCHSIA_BUFFER_COLLECTION_SPEC_VERSION 2
#define VK_FUCHSIA_BUFFER_COLLECTION_EXTENSION_NAME "VK_FUCHSIA_buffer_collection"
typedef VkFlags VkImageFormatConstraintsFlagsFUCHSIA;

typedef enum VkImageConstraintsInfoFlagBitsFUCHSIA {
    VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA = 0x00000001,
    VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA = 0x00000002,
    VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA = 0x00000004,
    VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA = 0x00000008,
    VK_IMAGE_CONSTRAINTS_INFO_PROTECTED_OPTIONAL_FUCHSIA = 0x00000010,
    VK_IMAGE_CONSTRAINTS_INFO_FLAG_BITS_MAX_ENUM_FUCHSIA = 0x7FFFFFFF
} VkImageConstraintsInfoFlagBitsFUCHSIA;
typedef VkFlags VkImageConstraintsInfoFlagsFUCHSIA;
typedef struct VkBufferCollectionCreateInfoFUCHSIA {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    zx_handle_t        collectionToken;
} VkBufferCollectionCreateInfoFUCHSIA;

typedef struct VkImportMemoryBufferCollectionFUCHSIA {
    VkStructureType              sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA);
    const void*                  pNext VK_CPP11_DEFAULT(nullptr);
    VkBufferCollectionFUCHSIA    collection;
    uint32_t                     index;
} VkImportMemoryBufferCollectionFUCHSIA;

typedef struct VkBufferCollectionImageCreateInfoFUCHSIA {
    VkStructureType              sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA);
    const void*                  pNext VK_CPP11_DEFAULT(nullptr);
    VkBufferCollectionFUCHSIA    collection;
    uint32_t                     index;
} VkBufferCollectionImageCreateInfoFUCHSIA;

typedef struct VkBufferCollectionConstraintsInfoFUCHSIA {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           minBufferCount;
    uint32_t           maxBufferCount;
    uint32_t           minBufferCountForCamping;
    uint32_t           minBufferCountForDedicatedSlack;
    uint32_t           minBufferCountForSharedSlack;
} VkBufferCollectionConstraintsInfoFUCHSIA;

typedef struct VkBufferConstraintsInfoFUCHSIA {
    VkStructureType                             sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA);
    const void*                                 pNext VK_CPP11_DEFAULT(nullptr);
    VkBufferCreateInfo                          createInfo;
    VkFormatFeatureFlags                        requiredFormatFeatures;
    VkBufferCollectionConstraintsInfoFUCHSIA    bufferCollectionConstraints;
} VkBufferConstraintsInfoFUCHSIA;

typedef struct VkBufferCollectionBufferCreateInfoFUCHSIA {
    VkStructureType              sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA);
    const void*                  pNext VK_CPP11_DEFAULT(nullptr);
    VkBufferCollectionFUCHSIA    collection;
    uint32_t                     index;
} VkBufferCollectionBufferCreateInfoFUCHSIA;

typedef struct VkSysmemColorSpaceFUCHSIA {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           colorSpace;
} VkSysmemColorSpaceFUCHSIA;

typedef struct VkBufferCollectionPropertiesFUCHSIA {
    VkStructureType                  sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA);
    void*                            pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t                         memoryTypeBits;
    uint32_t                         bufferCount;
    uint32_t                         createInfoIndex;
    uint64_t                         sysmemPixelFormat;
    VkFormatFeatureFlags             formatFeatures;
    VkSysmemColorSpaceFUCHSIA        sysmemColorSpaceIndex;
    VkComponentMapping               samplerYcbcrConversionComponents;
    VkSamplerYcbcrModelConversion    suggestedYcbcrModel;
    VkSamplerYcbcrRange              suggestedYcbcrRange;
    VkChromaLocation                 suggestedXChromaOffset;
    VkChromaLocation                 suggestedYChromaOffset;
} VkBufferCollectionPropertiesFUCHSIA;

typedef struct VkImageFormatConstraintsInfoFUCHSIA {
    VkStructureType                         sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA);
    const void*                             pNext VK_CPP11_DEFAULT(nullptr);
    VkImageCreateInfo                       imageCreateInfo;
    VkFormatFeatureFlags                    requiredFormatFeatures;
    VkImageFormatConstraintsFlagsFUCHSIA    flags;
    uint64_t                                sysmemPixelFormat;
    uint32_t                                colorSpaceCount;
    const VkSysmemColorSpaceFUCHSIA*        pColorSpaces;
} VkImageFormatConstraintsInfoFUCHSIA;

typedef struct VkImageConstraintsInfoFUCHSIA {
    VkStructureType                               sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA);
    const void*                                   pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t                                      formatConstraintsCount;
    const VkImageFormatConstraintsInfoFUCHSIA*    pFormatConstraints;
    VkBufferCollectionConstraintsInfoFUCHSIA      bufferCollectionConstraints;
    VkImageConstraintsInfoFlagsFUCHSIA            flags;
} VkImageConstraintsInfoFUCHSIA;

typedef VkResult (VKAPI_PTR *PFN_vkCreateBufferCollectionFUCHSIA)(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection);
typedef VkResult (VKAPI_PTR *PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo);
typedef VkResult (VKAPI_PTR *PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo);
typedef void (VKAPI_PTR *PFN_vkDestroyBufferCollectionFUCHSIA)(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_vkGetBufferCollectionPropertiesFUCHSIA)(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferCollectionFUCHSIA(
    VkDevice                                    device,
    const VkBufferCollectionCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferCollectionFUCHSIA*                  pCollection);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionImageConstraintsFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkImageConstraintsInfoFUCHSIA*        pImageConstraintsInfo);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionBufferConstraintsFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkBufferConstraintsInfoFUCHSIA*       pBufferConstraintsInfo);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferCollectionFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    const VkAllocationCallbacks*                pAllocator);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferCollectionPropertiesFUCHSIA(
    VkDevice                                    device,
    VkBufferCollectionFUCHSIA                   collection,
    VkBufferCollectionPropertiesFUCHSIA*        pProperties);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
