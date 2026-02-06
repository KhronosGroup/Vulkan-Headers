#ifndef VULKAN_BETA_H_
#define VULKAN_BETA_H_ 1

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



// VK_KHR_portability_subset is a preprocessor guard. Do not pass it to API calls.
#define VK_KHR_portability_subset 1
#define VK_KHR_PORTABILITY_SUBSET_SPEC_VERSION 1
#define VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME "VK_KHR_portability_subset"
typedef struct VkPhysicalDevicePortabilitySubsetFeaturesKHR {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           constantAlphaColorBlendFactors;
    VkBool32           events;
    VkBool32           imageViewFormatReinterpretation;
    VkBool32           imageViewFormatSwizzle;
    VkBool32           imageView2DOn3DImage;
    VkBool32           multisampleArrayImage;
    VkBool32           mutableComparisonSamplers;
    VkBool32           pointPolygons;
    VkBool32           samplerMipLodBias;
    VkBool32           separateStencilMaskRef;
    VkBool32           shaderSampleRateInterpolationFunctions;
    VkBool32           tessellationIsolines;
    VkBool32           tessellationPointMode;
    VkBool32           triangleFans;
    VkBool32           vertexAttributeAccessBeyondStride;
} VkPhysicalDevicePortabilitySubsetFeaturesKHR;

typedef struct VkPhysicalDevicePortabilitySubsetPropertiesKHR {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           minVertexInputBindingStrideAlignment;
} VkPhysicalDevicePortabilitySubsetPropertiesKHR;



// VK_AMDX_shader_enqueue is a preprocessor guard. Do not pass it to API calls.
#define VK_AMDX_shader_enqueue 1
#define VK_AMDX_SHADER_ENQUEUE_SPEC_VERSION 2
#define VK_AMDX_SHADER_ENQUEUE_EXTENSION_NAME "VK_AMDX_shader_enqueue"
#define VK_SHADER_INDEX_UNUSED_AMDX       (~0U)
typedef struct VkPhysicalDeviceShaderEnqueueFeaturesAMDX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           shaderEnqueue;
    VkBool32           shaderMeshEnqueue;
} VkPhysicalDeviceShaderEnqueueFeaturesAMDX;

typedef struct VkPhysicalDeviceShaderEnqueuePropertiesAMDX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           maxExecutionGraphDepth;
    uint32_t           maxExecutionGraphShaderOutputNodes;
    uint32_t           maxExecutionGraphShaderPayloadSize;
    uint32_t           maxExecutionGraphShaderPayloadCount;
    uint32_t           executionGraphDispatchAddressAlignment;
    uint32_t           maxExecutionGraphWorkgroupCount[3];
    uint32_t           maxExecutionGraphWorkgroups;
} VkPhysicalDeviceShaderEnqueuePropertiesAMDX;

typedef struct VkExecutionGraphPipelineScratchSizeAMDX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceSize       minSize;
    VkDeviceSize       maxSize;
    VkDeviceSize       sizeGranularity;
} VkExecutionGraphPipelineScratchSizeAMDX;

typedef struct VkExecutionGraphPipelineCreateInfoAMDX {
    VkStructureType                           sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX);
    const void*                               pNext VK_CPP11_DEFAULT(nullptr);
    VkPipelineCreateFlags                     flags;
    uint32_t                                  stageCount;
    const VkPipelineShaderStageCreateInfo*    pStages;
    const VkPipelineLibraryCreateInfoKHR*     pLibraryInfo;
    VkPipelineLayout                          layout;
    VkPipeline                                basePipelineHandle;
    int32_t                                   basePipelineIndex;
} VkExecutionGraphPipelineCreateInfoAMDX;

typedef union VkDeviceOrHostAddressConstAMDX {
    VkDeviceAddress    deviceAddress;
    const void*        hostAddress;
} VkDeviceOrHostAddressConstAMDX;

typedef struct VkDispatchGraphInfoAMDX {
    uint32_t                          nodeIndex;
    uint32_t                          payloadCount;
    VkDeviceOrHostAddressConstAMDX    payloads;
    uint64_t                          payloadStride;
} VkDispatchGraphInfoAMDX;

typedef struct VkDispatchGraphCountInfoAMDX {
    uint32_t                          count;
    VkDeviceOrHostAddressConstAMDX    infos;
    uint64_t                          stride;
} VkDispatchGraphCountInfoAMDX;

typedef struct VkPipelineShaderStageNodeCreateInfoAMDX {
      VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX);
    const void*          pNext VK_CPP11_DEFAULT(nullptr);
    const char*          pName;
    uint32_t             index;
} VkPipelineShaderStageNodeCreateInfoAMDX;

typedef VkResult (VKAPI_PTR *PFN_vkCreateExecutionGraphPipelinesAMDX)(VkDevice                                        device, VkPipelineCache pipelineCache, uint32_t                                        createInfoCount, const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos, const VkAllocationCallbacks*    pAllocator, VkPipeline*               pPipelines);
typedef VkResult (VKAPI_PTR *PFN_vkGetExecutionGraphPipelineScratchSizeAMDX)(VkDevice                                        device, VkPipeline                                      executionGraph, VkExecutionGraphPipelineScratchSizeAMDX*        pSizeInfo);
typedef VkResult (VKAPI_PTR *PFN_vkGetExecutionGraphPipelineNodeIndexAMDX)(VkDevice                                        device, VkPipeline                                      executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX*  pNodeInfo, uint32_t*                                       pNodeIndex);
typedef void (VKAPI_PTR *PFN_vkCmdInitializeGraphScratchMemoryAMDX)(VkCommandBuffer                                 commandBuffer, VkPipeline                                      executionGraph, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize);
typedef void (VKAPI_PTR *PFN_vkCmdDispatchGraphAMDX)(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, const VkDispatchGraphCountInfoAMDX*             pCountInfo);
typedef void (VKAPI_PTR *PFN_vkCmdDispatchGraphIndirectAMDX)(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, const VkDispatchGraphCountInfoAMDX*             pCountInfo);
typedef void (VKAPI_PTR *PFN_vkCmdDispatchGraphIndirectCountAMDX)(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, VkDeviceAddress                                 countInfo);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateExecutionGraphPipelinesAMDX(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkCreateExecutionGraphPipelinesAMDX(VkDevice                                        device, VkPipelineCache pipelineCache, std::span<const VkExecutionGraphPipelineCreateInfoAMDX> pCreateInfos, VkPipeline*               pPipelines)
{
    return vkCreateExecutionGraphPipelinesAMDX(device, pipelineCache, uint32_t(pCreateInfos.size()), pCreateInfos.data(), nullptr, pPipelines);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineScratchSizeAMDX(
    VkDevice                                    device,
    VkPipeline                                  executionGraph,
    VkExecutionGraphPipelineScratchSizeAMDX*    pSizeInfo);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineNodeIndexAMDX(
    VkDevice                                    device,
    VkPipeline                                  executionGraph,
    const VkPipelineShaderStageNodeCreateInfoAMDX* pNodeInfo,
    uint32_t*                                   pNodeIndex);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkGetExecutionGraphPipelineNodeIndexAMDX(VkDevice                                        device, VkPipeline                                      executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX& pNodeInfo, uint32_t*                                       pNodeIndex)
{
    return vkGetExecutionGraphPipelineNodeIndexAMDX(device, executionGraph, &pNodeInfo, pNodeIndex);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkCmdInitializeGraphScratchMemoryAMDX(
    VkCommandBuffer                             commandBuffer,
    VkPipeline                                  executionGraph,
    VkDeviceAddress                             scratch,
    VkDeviceSize                                scratchSize);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch,
    VkDeviceSize                                scratchSize,
    const VkDispatchGraphCountInfoAMDX*         pCountInfo);

#if VK_CPP20_FEATURES
extern "C++" inline void vkCmdDispatchGraphAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, const VkDispatchGraphCountInfoAMDX& pCountInfo)
{
    return vkCmdDispatchGraphAMDX(commandBuffer, scratch, scratchSize, &pCountInfo);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch,
    VkDeviceSize                                scratchSize,
    const VkDispatchGraphCountInfoAMDX*         pCountInfo);

#if VK_CPP20_FEATURES
extern "C++" inline void vkCmdDispatchGraphIndirectAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceSize                                    scratchSize, const VkDispatchGraphCountInfoAMDX& pCountInfo)
{
    return vkCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, scratchSize, &pCountInfo);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectCountAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch,
    VkDeviceSize                                scratchSize,
    VkDeviceAddress                             countInfo);
#endif
#endif


// VK_NV_cuda_kernel_launch is a preprocessor guard. Do not pass it to API calls.
#define VK_NV_cuda_kernel_launch 1
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkCudaModuleNV)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkCudaFunctionNV)
#define VK_NV_CUDA_KERNEL_LAUNCH_SPEC_VERSION 2
#define VK_NV_CUDA_KERNEL_LAUNCH_EXTENSION_NAME "VK_NV_cuda_kernel_launch"
typedef struct VkCudaModuleCreateInfoNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    size_t             dataSize;
    const void*        pData;
} VkCudaModuleCreateInfoNV;

typedef struct VkCudaFunctionCreateInfoNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    VkCudaModuleNV     module;
    const char*        pName;
} VkCudaFunctionCreateInfoNV;

typedef struct VkCudaLaunchInfoNV {
    VkStructureType        sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV);
    const void*            pNext VK_CPP11_DEFAULT(nullptr);
    VkCudaFunctionNV       function;
    uint32_t               gridDimX;
    uint32_t               gridDimY;
    uint32_t               gridDimZ;
    uint32_t               blockDimX;
    uint32_t               blockDimY;
    uint32_t               blockDimZ;
    uint32_t               sharedMemBytes;
    size_t                 paramCount;
    const void* const *    pParams;
    size_t                 extraCount;
    const void* const *    pExtras;
} VkCudaLaunchInfoNV;

typedef struct VkPhysicalDeviceCudaKernelLaunchFeaturesNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           cudaKernelLaunchFeatures;
} VkPhysicalDeviceCudaKernelLaunchFeaturesNV;

typedef struct VkPhysicalDeviceCudaKernelLaunchPropertiesNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           computeCapabilityMinor;
    uint32_t           computeCapabilityMajor;
} VkPhysicalDeviceCudaKernelLaunchPropertiesNV;

typedef VkResult (VKAPI_PTR *PFN_vkCreateCudaModuleNV)(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule);
typedef VkResult (VKAPI_PTR *PFN_vkGetCudaModuleCacheNV)(VkDevice device, VkCudaModuleNV module, size_t* pCacheSize, void* pCacheData);
typedef VkResult (VKAPI_PTR *PFN_vkCreateCudaFunctionNV)(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction);
typedef void (VKAPI_PTR *PFN_vkDestroyCudaModuleNV)(VkDevice device, VkCudaModuleNV module, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_vkDestroyCudaFunctionNV)(VkDevice device, VkCudaFunctionNV function, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_vkCmdCudaLaunchKernelNV)(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo);

#ifndef VK_NO_PROTOTYPES
#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaModuleNV(
    VkDevice                                    device,
    const VkCudaModuleCreateInfoNV*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCudaModuleNV*                             pModule);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV& pCreateInfo, VkCudaModuleNV* pModule)
{
    return vkCreateCudaModuleNV(device, &pCreateInfo, nullptr, pModule);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkGetCudaModuleCacheNV(
    VkDevice                                    device,
    VkCudaModuleNV                              module,
    size_t*                                     pCacheSize,
    void*                                       pCacheData);
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaFunctionNV(
    VkDevice                                    device,
    const VkCudaFunctionCreateInfoNV*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCudaFunctionNV*                           pFunction);

#if VK_CPP20_FEATURES
extern "C++" inline VkResult vkCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV& pCreateInfo, VkCudaFunctionNV* pFunction)
{
    return vkCreateCudaFunctionNV(device, &pCreateInfo, nullptr, pFunction);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaModuleNV(
    VkDevice                                    device,
    VkCudaModuleNV                              module,
    const VkAllocationCallbacks*                pAllocator);

#if VK_CPP20_FEATURES
extern "C++" inline void vkDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module)
{
    return vkDestroyCudaModuleNV(device, module, nullptr);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaFunctionNV(
    VkDevice                                    device,
    VkCudaFunctionNV                            function,
    const VkAllocationCallbacks*                pAllocator);

#if VK_CPP20_FEATURES
extern "C++" inline void vkDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function)
{
    return vkDestroyCudaFunctionNV(device, function, nullptr);
}
#endif
#endif

#ifndef VK_ONLY_EXPORTED_PROTOTYPES
VKAPI_ATTR void VKAPI_CALL vkCmdCudaLaunchKernelNV(
    VkCommandBuffer                             commandBuffer,
    const VkCudaLaunchInfoNV*                   pLaunchInfo);

#if VK_CPP20_FEATURES
extern "C++" inline void vkCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV& pLaunchInfo)
{
    return vkCmdCudaLaunchKernelNV(commandBuffer, &pLaunchInfo);
}
#endif
#endif
#endif


// VK_NV_displacement_micromap is a preprocessor guard. Do not pass it to API calls.
#define VK_NV_displacement_micromap 1
#define VK_NV_DISPLACEMENT_MICROMAP_SPEC_VERSION 2
#define VK_NV_DISPLACEMENT_MICROMAP_EXTENSION_NAME "VK_NV_displacement_micromap"

typedef enum VkDisplacementMicromapFormatNV {
    VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV = 1,
    VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV = 2,
    VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV = 3,
    VK_DISPLACEMENT_MICROMAP_FORMAT_MAX_ENUM_NV = 0x7FFFFFFF
} VkDisplacementMicromapFormatNV;
typedef struct VkPhysicalDeviceDisplacementMicromapFeaturesNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           displacementMicromap;
} VkPhysicalDeviceDisplacementMicromapFeaturesNV;

typedef struct VkPhysicalDeviceDisplacementMicromapPropertiesNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           maxDisplacementMicromapSubdivisionLevel;
} VkPhysicalDeviceDisplacementMicromapPropertiesNV;

typedef struct VkAccelerationStructureTrianglesDisplacementMicromapNV {
    VkStructureType                     sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV);
    void*                               pNext VK_CPP11_DEFAULT(nullptr);
    VkFormat                            displacementBiasAndScaleFormat;
    VkFormat                            displacementVectorFormat;
    VkDeviceOrHostAddressConstKHR       displacementBiasAndScaleBuffer;
    VkDeviceSize                        displacementBiasAndScaleStride;
    VkDeviceOrHostAddressConstKHR       displacementVectorBuffer;
    VkDeviceSize                        displacementVectorStride;
    VkDeviceOrHostAddressConstKHR       displacedMicromapPrimitiveFlags;
    VkDeviceSize                        displacedMicromapPrimitiveFlagsStride;
    VkIndexType                         indexType;
    VkDeviceOrHostAddressConstKHR       indexBuffer;
    VkDeviceSize                        indexStride;
    uint32_t                            baseTriangle;
    uint32_t                            usageCountsCount;
    const VkMicromapUsageEXT*           pUsageCounts;
    const VkMicromapUsageEXT* const*    ppUsageCounts;
    VkMicromapEXT                       micromap;
} VkAccelerationStructureTrianglesDisplacementMicromapNV;



// VK_AMDX_dense_geometry_format is a preprocessor guard. Do not pass it to API calls.
#define VK_AMDX_dense_geometry_format 1
#define VK_AMDX_DENSE_GEOMETRY_FORMAT_SPEC_VERSION 1
#define VK_AMDX_DENSE_GEOMETRY_FORMAT_EXTENSION_NAME "VK_AMDX_dense_geometry_format"
#define VK_COMPRESSED_TRIANGLE_FORMAT_DGF1_BYTE_ALIGNMENT_AMDX 128U
#define VK_COMPRESSED_TRIANGLE_FORMAT_DGF1_BYTE_STRIDE_AMDX 128U

typedef enum VkCompressedTriangleFormatAMDX {
    VK_COMPRESSED_TRIANGLE_FORMAT_DGF1_AMDX = 0,
    VK_COMPRESSED_TRIANGLE_FORMAT_MAX_ENUM_AMDX = 0x7FFFFFFF
} VkCompressedTriangleFormatAMDX;
typedef struct VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           denseGeometryFormat;
} VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX;

typedef struct VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX {
    VkStructureType                   sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DENSE_GEOMETRY_FORMAT_TRIANGLES_DATA_AMDX);
    const void*                       pNext VK_CPP11_DEFAULT(nullptr);
    VkDeviceOrHostAddressConstKHR     compressedData;
    VkDeviceSize                      dataSize;
    uint32_t                          numTriangles;
    uint32_t                          numVertices;
    uint32_t                          maxPrimitiveIndex;
    uint32_t                          maxGeometryIndex;
    VkCompressedTriangleFormatAMDX    format;
} VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX;



// VK_NV_present_metering is a preprocessor guard. Do not pass it to API calls.
#define VK_NV_present_metering 1
#define VK_NV_PRESENT_METERING_SPEC_VERSION 1
#define VK_NV_PRESENT_METERING_EXTENSION_NAME "VK_NV_present_metering"
typedef struct VkSetPresentConfigNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV);
    const void*        pNext VK_CPP11_DEFAULT(nullptr);
    uint32_t           numFramesPerBatch;
    uint32_t           presentConfigFeedback;
} VkSetPresentConfigNV;

typedef struct VkPhysicalDevicePresentMeteringFeaturesNV {
    VkStructureType    sType VK_CPP11_DEFAULT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV);
    void*              pNext VK_CPP11_DEFAULT(nullptr);
    VkBool32           presentMetering;
} VkPhysicalDevicePresentMeteringFeaturesNV;


#ifdef __cplusplus
}
#endif

#endif
