#ifndef VULKAN_SCI_H_
#define VULKAN_SCI_H_ 1

/*
** Copyright 2015-2021 The Khronos Group Inc.
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



#define VK_NV_external_sci_sync 1
#define VK_NV_EXTERNAL_SCI_SYNC_SPEC_VERSION 2
#define VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME "VK_NV_external_sci_sync"

typedef enum VkSciSyncClientTypeNV {
    VK_SCI_SYNC_CLIENT_TYPE_SIGNALER_NV = 0,
    VK_SCI_SYNC_CLIENT_TYPE_WAITER_NV = 1,
    VK_SCI_SYNC_CLIENT_TYPE_SIGNALER_WAITER_NV = 2,
    VK_SCI_SYNC_CLIENT_TYPE_MAX_ENUM_NV = 0x7FFFFFFF
} VkSciSyncClientTypeNV;

typedef enum VkSciSyncPrimitiveTypeNV {
    VK_SCI_SYNC_PRIMITIVE_TYPE_FENCE_NV = 0,
    VK_SCI_SYNC_PRIMITIVE_TYPE_SEMAPHORE_NV = 1,
    VK_SCI_SYNC_PRIMITIVE_TYPE_MAX_ENUM_NV = 0x7FFFFFFF
} VkSciSyncPrimitiveTypeNV;
typedef struct VkExportFenceSciSyncInfoNV {
    VkStructureType      sType;
    const void*          pNext;
    NvSciSyncAttrList    pAttributes;
} VkExportFenceSciSyncInfoNV;

typedef struct VkImportFenceSciSyncInfoNV {
    VkStructureType                      sType;
    const void*                          pNext;
    VkFence                              fence;
    VkExternalFenceHandleTypeFlagBits    handleType;
    void*                                handle;
} VkImportFenceSciSyncInfoNV;

typedef struct VkFenceGetSciSyncInfoNV {
    VkStructureType                      sType;
    const void*                          pNext;
    VkFence                              fence;
    VkExternalFenceHandleTypeFlagBits    handleType;
} VkFenceGetSciSyncInfoNV;

typedef struct VkSciSyncAttributesInfoNV {
    VkStructureType             sType;
    const void*                 pNext;
    VkSciSyncClientTypeNV       clientType;
    VkSciSyncPrimitiveTypeNV    primitiveType;
} VkSciSyncAttributesInfoNV;

typedef struct VkExportSemaphoreSciSyncInfoNV {
    VkStructureType      sType;
    const void*          pNext;
    NvSciSyncAttrList    pAttributes;
} VkExportSemaphoreSciSyncInfoNV;

typedef struct VkImportSemaphoreSciSyncInfoNV {
    VkStructureType                          sType;
    const void*                              pNext;
    VkSemaphore                              semaphore;
    VkExternalSemaphoreHandleTypeFlagBits    handleType;
    void*                                    handle;
} VkImportSemaphoreSciSyncInfoNV;

typedef struct VkSemaphoreGetSciSyncInfoNV {
    VkStructureType                          sType;
    const void*                              pNext;
    VkSemaphore                              semaphore;
    VkExternalSemaphoreHandleTypeFlagBits    handleType;
} VkSemaphoreGetSciSyncInfoNV;

typedef struct VkPhysicalDeviceExternalSciSyncFeaturesNV {
    VkStructureType    sType;
    void*              pNext;
    VkBool32           sciSyncFence;
    VkBool32           sciSyncSemaphore;
    VkBool32           sciSyncImport;
    VkBool32           sciSyncExport;
} VkPhysicalDeviceExternalSciSyncFeaturesNV;

typedef VkResult (VKAPI_PTR *PFN_vkGetFenceSciSyncFenceNV)(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle);
typedef VkResult (VKAPI_PTR *PFN_vkGetFenceSciSyncObjNV)(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle);
typedef VkResult (VKAPI_PTR *PFN_vkImportFenceSciSyncFenceNV)(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo);
typedef VkResult (VKAPI_PTR *PFN_vkImportFenceSciSyncObjNV)(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo);
typedef VkResult (VKAPI_PTR *PFN_vkGetPhysicalDeviceSciSyncAttributesNV)(VkPhysicalDevice physicalDevice, const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo, NvSciSyncAttrList pAttributes);
typedef VkResult (VKAPI_PTR *PFN_vkGetSemaphoreSciSyncObjNV)(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo, void* pHandle);
typedef VkResult (VKAPI_PTR *PFN_vkImportSemaphoreSciSyncObjNV)(VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceSciSyncFenceNV(
    VkDevice                                    device,
    const VkFenceGetSciSyncInfoNV*              pGetSciSyncHandleInfo,
    void*                                       pHandle);

VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceSciSyncObjNV(
    VkDevice                                    device,
    const VkFenceGetSciSyncInfoNV*              pGetSciSyncHandleInfo,
    void*                                       pHandle);

VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceSciSyncFenceNV(
    VkDevice                                    device,
    const VkImportFenceSciSyncInfoNV*           pImportFenceSciSyncInfo);

VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceSciSyncObjNV(
    VkDevice                                    device,
    const VkImportFenceSciSyncInfoNV*           pImportFenceSciSyncInfo);

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSciSyncAttributesNV(
    VkPhysicalDevice                            physicalDevice,
    const VkSciSyncAttributesInfoNV*            pSciSyncAttributesInfo,
    NvSciSyncAttrList                           pAttributes);

VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreSciSyncObjNV(
    VkDevice                                    device,
    const VkSemaphoreGetSciSyncInfoNV*          pGetSciSyncInfo,
    void*                                       pHandle);

VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreSciSyncObjNV(
    VkDevice                                    device,
    const VkImportSemaphoreSciSyncInfoNV*       pImportSemaphoreSciSyncInfo);
#endif


#define VK_NV_external_memory_sci_buf 1
#define VK_NV_EXTERNAL_MEMORY_SCI_BUF_SPEC_VERSION 1
#define VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME "VK_NV_external_memory_sci_buf"
typedef struct VkExportMemorySciBufInfoNV {
    VkStructureType     sType;
    const void*         pNext;
    NvSciBufAttrList    pAttributes;
} VkExportMemorySciBufInfoNV;

typedef struct VkImportMemorySciBufInfoNV {
    VkStructureType                       sType;
    const void*                           pNext;
    VkExternalMemoryHandleTypeFlagBits    handleType;
    NvSciBufObj                           handle;
} VkImportMemorySciBufInfoNV;

typedef struct VkMemoryGetSciBufInfoNV {
    VkStructureType                       sType;
    const void*                           pNext;
    VkDeviceMemory                        memory;
    VkExternalMemoryHandleTypeFlagBits    handleType;
} VkMemoryGetSciBufInfoNV;

typedef struct VkMemorySciBufPropertiesNV {
    VkStructureType    sType;
    const void*        pNext;
    uint32_t           memoryTypeBits;
} VkMemorySciBufPropertiesNV;

typedef struct VkPhysicalDeviceExternalSciBufFeaturesNV {
    VkStructureType    sType;
    const void*        pNext;
    VkBool32           sciBufImport;
    VkBool32           sciBufExport;
} VkPhysicalDeviceExternalSciBufFeaturesNV;

typedef VkResult (VKAPI_PTR *PFN_vkGetMemorySciBufNV)(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo, NvSciBufObj* pHandle);
typedef VkResult (VKAPI_PTR *PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV)(VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType, NvSciBufObj handle, VkMemorySciBufPropertiesNV* pMemorySciBufProperties);
typedef VkResult (VKAPI_PTR *PFN_vkGetPhysicalDeviceSciBufAttributesNV)(VkPhysicalDevice physicalDevice, NvSciBufAttrList pAttributes);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemorySciBufNV(
    VkDevice                                    device,
    const VkMemoryGetSciBufInfoNV*              pGetSciBufInfo,
    NvSciBufObj*                                pHandle);

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    NvSciBufObj                                 handle,
    VkMemorySciBufPropertiesNV*                 pMemorySciBufProperties);

VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSciBufAttributesNV(
    VkPhysicalDevice                            physicalDevice,
    NvSciBufAttrList                            pAttributes);
#endif


#define VK_NV_external_sci_sync2 1
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSemaphoreSciSyncPoolNV)
#define VK_NV_EXTERNAL_SCI_SYNC_2_SPEC_VERSION 1
#define VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME "VK_NV_external_sci_sync2"
typedef struct VkPhysicalDeviceExternalSciSync2FeaturesNV {
    VkStructureType    sType;
    void*              pNext;
    VkBool32           sciSyncFence;
    VkBool32           sciSyncSemaphore2;
    VkBool32           sciSyncImport;
    VkBool32           sciSyncExport;
} VkPhysicalDeviceExternalSciSync2FeaturesNV;

typedef struct VkSemaphoreSciSyncPoolCreateInfoNV {
    VkStructureType    sType;
    const void*        pNext;
    NvSciSyncObj       handle;
} VkSemaphoreSciSyncPoolCreateInfoNV;

typedef struct VkSemaphoreSciSyncCreateInfoNV {
    VkStructureType             sType;
    const void*                 pNext;
    VkSemaphoreSciSyncPoolNV    semaphorePool;
    const NvSciSyncFence*       pFence;
} VkSemaphoreSciSyncCreateInfoNV;

typedef struct VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV {
    VkStructureType    sType;
    const void*        pNext;
    uint32_t           semaphoreSciSyncPoolRequestCount;
} VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV;

typedef VkResult (VKAPI_PTR *PFN_vkCreateSemaphoreSciSyncPoolNV)(VkDevice device, const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphoreSciSyncPoolNV* pSemaphorePool);
typedef void (VKAPI_PTR *PFN_vkDestroySemaphoreSciSyncPoolNV)(VkDevice device, VkSemaphoreSciSyncPoolNV semaphorePool, const VkAllocationCallbacks* pAllocator);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    const VkSemaphoreSciSyncPoolCreateInfoNV*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphoreSciSyncPoolNV*                   pSemaphorePool);

VKAPI_ATTR void VKAPI_CALL vkDestroySemaphoreSciSyncPoolNV(
    VkDevice                                    device,
    VkSemaphoreSciSyncPoolNV                    semaphorePool,
    const VkAllocationCallbacks*                pAllocator);
#endif

#ifdef __cplusplus
}
#endif

#endif
