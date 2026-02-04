#ifndef VULKAN_METAL_H_
#define VULKAN_METAL_H_ 1

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



// VK_EXT_metal_surface is a preprocessor guard. Do not pass it to API calls.
#define VK_EXT_metal_surface 1
#ifdef __OBJC__
@class CAMetalLayer;
#else
typedef void CAMetalLayer;
#endif

#define VK_EXT_METAL_SURFACE_SPEC_VERSION 1
#define VK_EXT_METAL_SURFACE_EXTENSION_NAME "VK_EXT_metal_surface"
typedef VkFlags VkMetalSurfaceCreateFlagsEXT;
typedef struct VkMetalSurfaceCreateInfoEXT {
    VkStructureType                 sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT);
    const void*                     pNext VK_CPP11_DEFAULT(nullptr);
    VkMetalSurfaceCreateFlagsEXT    flags;
    const CAMetalLayer*             pLayer;
} VkMetalSurfaceCreateInfoEXT;

typedef VkResult (VKAPI_PTR *PFN_vkCreateMetalSurfaceEXT)(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMetalSurfaceEXT(
    VkInstance                                  instance,
    const VkMetalSurfaceCreateInfoEXT*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT& pCreateInfo, VkSurfaceKHR* pSurface)
{
    return vkCreateMetalSurfaceEXT(instance, &pCreateInfo, nullptr, pSurface);
}
#endif
#endif
#endif


// VK_EXT_metal_objects is a preprocessor guard. Do not pass it to API calls.
#define VK_EXT_metal_objects 1
#ifdef __OBJC__
@protocol MTLDevice;
typedef __unsafe_unretained id<MTLDevice> MTLDevice_id;
#else
typedef void* MTLDevice_id;
#endif

#ifdef __OBJC__
@protocol MTLCommandQueue;
typedef __unsafe_unretained id<MTLCommandQueue> MTLCommandQueue_id;
#else
typedef void* MTLCommandQueue_id;
#endif

#ifdef __OBJC__
@protocol MTLBuffer;
typedef __unsafe_unretained id<MTLBuffer> MTLBuffer_id;
#else
typedef void* MTLBuffer_id;
#endif

#ifdef __OBJC__
@protocol MTLTexture;
typedef __unsafe_unretained id<MTLTexture> MTLTexture_id;
#else
typedef void* MTLTexture_id;
#endif

typedef struct __IOSurface* IOSurfaceRef;
#ifdef __OBJC__
@protocol MTLSharedEvent;
typedef __unsafe_unretained id<MTLSharedEvent> MTLSharedEvent_id;
#else
typedef void* MTLSharedEvent_id;
#endif

#define VK_EXT_METAL_OBJECTS_SPEC_VERSION 2
#define VK_EXT_METAL_OBJECTS_EXTENSION_NAME "VK_EXT_metal_objects"

typedef enum VkExportMetalObjectTypeFlagBitsEXT {
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_DEVICE_BIT_EXT = 0x00000001,
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_COMMAND_QUEUE_BIT_EXT = 0x00000002,
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_BUFFER_BIT_EXT = 0x00000004,
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_TEXTURE_BIT_EXT = 0x00000008,
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_IOSURFACE_BIT_EXT = 0x00000010,
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_SHARED_EVENT_BIT_EXT = 0x00000020,
    VK_EXPORT_METAL_OBJECT_TYPE_FLAG_BITS_MAX_ENUM_EXT = 0x7FFFFFFF
} VkExportMetalObjectTypeFlagBitsEXT;
typedef VkFlags VkExportMetalObjectTypeFlagsEXT;
typedef struct VkExportMetalObjectCreateInfoEXT {
    VkStructureType                       sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT);
    const void*                           pNext VK_CPP11_DEFAULT(nullptr);
    VkExportMetalObjectTypeFlagBitsEXT    exportObjectType;
} VkExportMetalObjectCreateInfoEXT;

typedef struct VkExportMetalObjectsInfoEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
} VkExportMetalObjectsInfoEXT;

typedef struct VkExportMetalDeviceInfoEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    MTLDevice_id       mtlDevice;
} VkExportMetalDeviceInfoEXT;

typedef struct VkExportMetalCommandQueueInfoEXT {
    VkStructureType       sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT);
    const void*           pNext VK_CPP11_DEFAULT(nullptr);
    VkQueue               queue;
    MTLCommandQueue_id    mtlCommandQueue;
} VkExportMetalCommandQueueInfoEXT;

typedef struct VkExportMetalBufferInfoEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceMemory     memory;
    MTLBuffer_id       mtlBuffer;
} VkExportMetalBufferInfoEXT;

typedef struct VkImportMetalBufferInfoEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    MTLBuffer_id       mtlBuffer;
} VkImportMetalBufferInfoEXT;

typedef struct VkExportMetalTextureInfoEXT {
    VkStructureType          sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT);
    const void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkImage                  image;
    VkImageView              imageView;
    VkBufferView             bufferView;
    VkImageAspectFlagBits    plane;
    MTLTexture_id            mtlTexture;
} VkExportMetalTextureInfoEXT;

typedef struct VkImportMetalTextureInfoEXT {
    VkStructureType          sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT);
    const void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkImageAspectFlagBits    plane;
    MTLTexture_id            mtlTexture;
} VkImportMetalTextureInfoEXT;

typedef struct VkExportMetalIOSurfaceInfoEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    VkImage            image;
    IOSurfaceRef       ioSurface;
} VkExportMetalIOSurfaceInfoEXT;

typedef struct VkImportMetalIOSurfaceInfoEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    IOSurfaceRef       ioSurface;
} VkImportMetalIOSurfaceInfoEXT;

typedef struct VkExportMetalSharedEventInfoEXT {
    VkStructureType      sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT);
    const void*          pNext VK_CPP11_DEFAULT(nullptr);
    VkSemaphore          semaphore;
    VkEvent              event;
    MTLSharedEvent_id    mtlSharedEvent;
} VkExportMetalSharedEventInfoEXT;

typedef struct VkImportMetalSharedEventInfoEXT {
    VkStructureType      sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT);
    const void*          pNext VK_CPP11_DEFAULT(nullptr);
    MTLSharedEvent_id    mtlSharedEvent;
} VkImportMetalSharedEventInfoEXT;

typedef void (VKAPI_PTR *PFN_vkExportMetalObjectsEXT)(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkExportMetalObjectsEXT(
    VkDevice                                    device,
    VkExportMetalObjectsInfoEXT*                pMetalObjectsInfo);
#endif
#endif


// VK_EXT_external_memory_metal is a preprocessor guard. Do not pass it to API calls.
#define VK_EXT_external_memory_metal 1
#define VK_EXT_EXTERNAL_MEMORY_METAL_SPEC_VERSION 1
#define VK_EXT_EXTERNAL_MEMORY_METAL_EXTENSION_NAME "VK_EXT_external_memory_metal"
typedef struct VkImportMemoryMetalHandleInfoEXT {
    VkStructureType                       sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT);
    const void*                           pNext VK_CPP11_DEFAULT(nullptr);
    VkExternalMemoryHandleTypeFlagBits    handleType;
    void*                                 handle;
} VkImportMemoryMetalHandleInfoEXT;

typedef struct VkMemoryMetalHandlePropertiesEXT {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           memoryTypeBits;
} VkMemoryMetalHandlePropertiesEXT;

typedef struct VkMemoryGetMetalHandleInfoEXT {
    VkStructureType                       sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT);
    const void*                           pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceMemory                        memory;
    VkExternalMemoryHandleTypeFlagBits    handleType;
} VkMemoryGetMetalHandleInfoEXT;

typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryMetalHandleEXT)(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle);
typedef VkResult (VKAPI_PTR *PFN_vkGetMemoryMetalHandlePropertiesEXT)(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandleEXT(
    VkDevice                                    device,
    const VkMemoryGetMetalHandleInfoEXT*        pGetMetalHandleInfo,
    void**                                      pHandle);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkGetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT& pGetMetalHandleInfo, void** pHandle)
{
    return vkGetMemoryMetalHandleEXT(device, &pGetMetalHandleInfo, pHandle);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandlePropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHandle,
    VkMemoryMetalHandlePropertiesEXT*           pMemoryMetalHandleProperties);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
