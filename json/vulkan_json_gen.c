
/*
** Copyright (c) 2020 The Khronos Group Inc.
**
** SPDX-License-Identifier: Apache-2.0
*/


/********************************************************************************************/
/** This code is generated. To make changes, please modify the scripts or the relevant xml **/
/********************************************************************************************/

#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <vulkan/vulkan.h>
#include "vulkan_json_gen.h"

#define MAX_SIZE 255 // We don't expect to write a bigger string at a time.
#define MAX_JSON_SIZE 1024*1024 // We don't expect the entire JSON file to be bigger than this.

static int s_num_spaces = 0;
static char s_tempBuf[MAX_SIZE];
static char s_outBuf[MAX_JSON_SIZE];
static char *s_writePtr = s_outBuf;

#define _OUT s_tempBuf

#define UPDATE_BUF strncpy(s_writePtr, s_tempBuf, strnlen(s_tempBuf, MAX_SIZE)); s_writePtr += strnlen(s_tempBuf, MAX_SIZE);

// Variadic macro for neat buffer update + print.
#define vk_json_printf(...) { sprintf(__VA_ARGS__); UPDATE_BUF }

// Helper utility to do indentation in the generated json file.
#define PRINT_SPACE {     int i;     for (i = 0; i < s_num_spaces; i++)         vk_json_printf(_OUT, " "); }


#define INDENT(sz) s_num_spaces += (sz);

const char* getJSONOutput()
{
    return s_outBuf;
}

void resetJSONOutput(void)
{
    memset(s_outBuf, 0x00, MAX_JSON_SIZE);
    s_writePtr = s_outBuf;
}



void print_int32_t(const int32_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %d%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%d%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_uint32_t(const uint32_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %u%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%u%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_uint8_t(const uint8_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %u%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%u%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_uint64_t(const uint64_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %" PRIu64 "%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%" PRIu64 "%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_float(const float * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %f%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%f%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_int(const int * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %d%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%d%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_double(const double * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %lf%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%lf%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_int64_t(const int64_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %" PRId64 "%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%" PRId64 "%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_uint16_t(const uint16_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %u%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%u%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_char(const char * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %c%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%c%s\n", *obj, commaNeeded ? "," : "");
    }
}


void print_size_t(const size_t * obj, const char* s, int commaNeeded) {
    PRINT_SPACE
    if (s[0] != 0) {
        vk_json_printf(_OUT, "\"%s\" : %zu%s\n", s, *obj, commaNeeded ? "," : "");
    } else {
        vk_json_printf(_OUT, "%zu%s\n", *obj, commaNeeded ? "," : "");
    }
}

void dumpPNextChain(const void* pNext) {
      VkBaseInStructure *pBase = (VkBaseInStructure*)pNext;
      if (pNext) {
          PRINT_SPACE
          vk_json_printf(_OUT, "\"pNext\":\n");
          switch (pBase->sType) {
#ifdef VK_KHR_display_swapchain
             case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:print_VkDisplayPresentInfoKHR(((VkDisplayPresentInfoKHR *)pNext), "VkDisplayPresentInfoKHR", 1);
             break;
#endif
#ifdef VK_EXT_validation_features
             case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:print_VkValidationFeaturesEXT(((VkValidationFeaturesEXT *)pNext), "VkValidationFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_application_parameters
             case VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT:print_VkApplicationParametersEXT(((VkApplicationParametersEXT *)pNext), "VkApplicationParametersEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:print_VkPhysicalDeviceFeatures2(((VkPhysicalDeviceFeatures2 *)pNext), "VkPhysicalDeviceFeatures2", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:print_VkPhysicalDeviceDriverProperties(((VkPhysicalDeviceDriverProperties *)pNext), "VkPhysicalDeviceDriverProperties", 1);
             break;
#endif
#ifdef VK_KHR_incremental_present
             case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:print_VkPresentRegionsKHR(((VkPresentRegionsKHR *)pNext), "VkPresentRegionsKHR", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:print_VkPhysicalDeviceVariablePointersFeatures(((VkPhysicalDeviceVariablePointersFeatures *)pNext), "VkPhysicalDeviceVariablePointersFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:print_VkPhysicalDeviceExternalImageFormatInfo(((VkPhysicalDeviceExternalImageFormatInfo *)pNext), "VkPhysicalDeviceExternalImageFormatInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:print_VkExternalImageFormatProperties(((VkExternalImageFormatProperties *)pNext), "VkExternalImageFormatProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:print_VkPhysicalDeviceIDProperties(((VkPhysicalDeviceIDProperties *)pNext), "VkPhysicalDeviceIDProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:print_VkExternalMemoryImageCreateInfo(((VkExternalMemoryImageCreateInfo *)pNext), "VkExternalMemoryImageCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:print_VkExternalMemoryBufferCreateInfo(((VkExternalMemoryBufferCreateInfo *)pNext), "VkExternalMemoryBufferCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:print_VkExportMemoryAllocateInfo(((VkExportMemoryAllocateInfo *)pNext), "VkExportMemoryAllocateInfo", 1);
             break;
#endif
#ifdef VK_KHR_external_memory_fd
             case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:print_VkImportMemoryFdInfoKHR(((VkImportMemoryFdInfoKHR *)pNext), "VkImportMemoryFdInfoKHR", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:print_VkExportSemaphoreCreateInfo(((VkExportSemaphoreCreateInfo *)pNext), "VkExportSemaphoreCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:print_VkExportFenceCreateInfo(((VkExportFenceCreateInfo *)pNext), "VkExportFenceCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:print_VkPhysicalDeviceMultiviewFeatures(((VkPhysicalDeviceMultiviewFeatures *)pNext), "VkPhysicalDeviceMultiviewFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:print_VkPhysicalDeviceMultiviewProperties(((VkPhysicalDeviceMultiviewProperties *)pNext), "VkPhysicalDeviceMultiviewProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:print_VkRenderPassMultiviewCreateInfo(((VkRenderPassMultiviewCreateInfo *)pNext), "VkRenderPassMultiviewCreateInfo", 1);
             break;
#endif
#ifdef VK_EXT_display_control
             case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:print_VkSwapchainCounterCreateInfoEXT(((VkSwapchainCounterCreateInfoEXT *)pNext), "VkSwapchainCounterCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:print_VkMemoryAllocateFlagsInfo(((VkMemoryAllocateFlagsInfo *)pNext), "VkMemoryAllocateFlagsInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:print_VkBindBufferMemoryDeviceGroupInfo(((VkBindBufferMemoryDeviceGroupInfo *)pNext), "VkBindBufferMemoryDeviceGroupInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:print_VkBindImageMemoryDeviceGroupInfo(((VkBindImageMemoryDeviceGroupInfo *)pNext), "VkBindImageMemoryDeviceGroupInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:print_VkDeviceGroupRenderPassBeginInfo(((VkDeviceGroupRenderPassBeginInfo *)pNext), "VkDeviceGroupRenderPassBeginInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:print_VkDeviceGroupCommandBufferBeginInfo(((VkDeviceGroupCommandBufferBeginInfo *)pNext), "VkDeviceGroupCommandBufferBeginInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:print_VkDeviceGroupSubmitInfo(((VkDeviceGroupSubmitInfo *)pNext), "VkDeviceGroupSubmitInfo", 1);
             break;
#endif
#ifdef VK_KHR_swapchain
             case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:print_VkImageSwapchainCreateInfoKHR(((VkImageSwapchainCreateInfoKHR *)pNext), "VkImageSwapchainCreateInfoKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:print_VkBindImageMemorySwapchainInfoKHR(((VkBindImageMemorySwapchainInfoKHR *)pNext), "VkBindImageMemorySwapchainInfoKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:print_VkDeviceGroupPresentInfoKHR(((VkDeviceGroupPresentInfoKHR *)pNext), "VkDeviceGroupPresentInfoKHR", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:print_VkDeviceGroupDeviceCreateInfo(((VkDeviceGroupDeviceCreateInfo *)pNext), "VkDeviceGroupDeviceCreateInfo", 1);
             break;
#endif
#ifdef VK_KHR_swapchain
             case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:print_VkDeviceGroupSwapchainCreateInfoKHR(((VkDeviceGroupSwapchainCreateInfoKHR *)pNext), "VkDeviceGroupSwapchainCreateInfoKHR", 1);
             break;
#endif
#ifdef VK_EXT_discard_rectangles
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:print_VkPhysicalDeviceDiscardRectanglePropertiesEXT(((VkPhysicalDeviceDiscardRectanglePropertiesEXT *)pNext), "VkPhysicalDeviceDiscardRectanglePropertiesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:print_VkPipelineDiscardRectangleStateCreateInfoEXT(((VkPipelineDiscardRectangleStateCreateInfoEXT *)pNext), "VkPipelineDiscardRectangleStateCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:print_VkRenderPassInputAttachmentAspectCreateInfo(((VkRenderPassInputAttachmentAspectCreateInfo *)pNext), "VkRenderPassInputAttachmentAspectCreateInfo", 1);
             break;
#endif
#ifdef VK_KHR_shared_presentable_image
             case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:print_VkSharedPresentSurfaceCapabilitiesKHR(((VkSharedPresentSurfaceCapabilitiesKHR *)pNext), "VkSharedPresentSurfaceCapabilitiesKHR", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:print_VkPhysicalDevice16BitStorageFeatures(((VkPhysicalDevice16BitStorageFeatures *)pNext), "VkPhysicalDevice16BitStorageFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:print_VkPhysicalDeviceSubgroupProperties(((VkPhysicalDeviceSubgroupProperties *)pNext), "VkPhysicalDeviceSubgroupProperties", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:print_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(((VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pNext), "VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:print_VkPhysicalDevicePointClippingProperties(((VkPhysicalDevicePointClippingProperties *)pNext), "VkPhysicalDevicePointClippingProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:print_VkMemoryDedicatedRequirements(((VkMemoryDedicatedRequirements *)pNext), "VkMemoryDedicatedRequirements", 1);
             break;
             case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:print_VkMemoryDedicatedAllocateInfo(((VkMemoryDedicatedAllocateInfo *)pNext), "VkMemoryDedicatedAllocateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:print_VkImageViewUsageCreateInfo(((VkImageViewUsageCreateInfo *)pNext), "VkImageViewUsageCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:print_VkPipelineTessellationDomainOriginStateCreateInfo(((VkPipelineTessellationDomainOriginStateCreateInfo *)pNext), "VkPipelineTessellationDomainOriginStateCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:print_VkSamplerYcbcrConversionInfo(((VkSamplerYcbcrConversionInfo *)pNext), "VkSamplerYcbcrConversionInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:print_VkBindImagePlaneMemoryInfo(((VkBindImagePlaneMemoryInfo *)pNext), "VkBindImagePlaneMemoryInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:print_VkImagePlaneMemoryRequirementsInfo(((VkImagePlaneMemoryRequirementsInfo *)pNext), "VkImagePlaneMemoryRequirementsInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:print_VkPhysicalDeviceSamplerYcbcrConversionFeatures(((VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pNext), "VkPhysicalDeviceSamplerYcbcrConversionFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:print_VkSamplerYcbcrConversionImageFormatProperties(((VkSamplerYcbcrConversionImageFormatProperties *)pNext), "VkSamplerYcbcrConversionImageFormatProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:print_VkProtectedSubmitInfo(((VkProtectedSubmitInfo *)pNext), "VkProtectedSubmitInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:print_VkPhysicalDeviceProtectedMemoryFeatures(((VkPhysicalDeviceProtectedMemoryFeatures *)pNext), "VkPhysicalDeviceProtectedMemoryFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:print_VkPhysicalDeviceProtectedMemoryProperties(((VkPhysicalDeviceProtectedMemoryProperties *)pNext), "VkPhysicalDeviceProtectedMemoryProperties", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:print_VkPhysicalDeviceSamplerFilterMinmaxProperties(((VkPhysicalDeviceSamplerFilterMinmaxProperties *)pNext), "VkPhysicalDeviceSamplerFilterMinmaxProperties", 1);
             break;
#endif
#ifdef VK_EXT_sample_locations
             case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:print_VkSampleLocationsInfoEXT(((VkSampleLocationsInfoEXT *)pNext), "VkSampleLocationsInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:print_VkRenderPassSampleLocationsBeginInfoEXT(((VkRenderPassSampleLocationsBeginInfoEXT *)pNext), "VkRenderPassSampleLocationsBeginInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:print_VkPipelineSampleLocationsStateCreateInfoEXT(((VkPipelineSampleLocationsStateCreateInfoEXT *)pNext), "VkPipelineSampleLocationsStateCreateInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:print_VkPhysicalDeviceSampleLocationsPropertiesEXT(((VkPhysicalDeviceSampleLocationsPropertiesEXT *)pNext), "VkPhysicalDeviceSampleLocationsPropertiesEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:print_VkSamplerReductionModeCreateInfo(((VkSamplerReductionModeCreateInfo *)pNext), "VkSamplerReductionModeCreateInfo", 1);
             break;
#endif
#ifdef VK_EXT_blend_operation_advanced
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:print_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(((VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *)pNext), "VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:print_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(((VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *)pNext), "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:print_VkPipelineColorBlendAdvancedStateCreateInfoEXT(((VkPipelineColorBlendAdvancedStateCreateInfoEXT *)pNext), "VkPipelineColorBlendAdvancedStateCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:print_VkImageFormatListCreateInfo(((VkImageFormatListCreateInfo *)pNext), "VkImageFormatListCreateInfo", 1);
             break;
#endif
#ifdef VK_VERSION_1_1
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:print_VkPhysicalDeviceMaintenance3Properties(((VkPhysicalDeviceMaintenance3Properties *)pNext), "VkPhysicalDeviceMaintenance3Properties", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:print_VkPhysicalDeviceShaderDrawParametersFeatures(((VkPhysicalDeviceShaderDrawParametersFeatures *)pNext), "VkPhysicalDeviceShaderDrawParametersFeatures", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:print_VkPhysicalDeviceShaderFloat16Int8Features(((VkPhysicalDeviceShaderFloat16Int8Features *)pNext), "VkPhysicalDeviceShaderFloat16Int8Features", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:print_VkPhysicalDeviceFloatControlsProperties(((VkPhysicalDeviceFloatControlsProperties *)pNext), "VkPhysicalDeviceFloatControlsProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:print_VkPhysicalDeviceHostQueryResetFeatures(((VkPhysicalDeviceHostQueryResetFeatures *)pNext), "VkPhysicalDeviceHostQueryResetFeatures", 1);
             break;
#endif
#ifdef VK_EXT_global_priority
             case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:print_VkDeviceQueueGlobalPriorityCreateInfoEXT(((VkDeviceQueueGlobalPriorityCreateInfoEXT *)pNext), "VkDeviceQueueGlobalPriorityCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_EXT_debug_utils
             case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:print_VkDebugUtilsMessengerCreateInfoEXT(((VkDebugUtilsMessengerCreateInfoEXT *)pNext), "VkDebugUtilsMessengerCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_EXT_external_memory_host
             case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:print_VkImportMemoryHostPointerInfoEXT(((VkImportMemoryHostPointerInfoEXT *)pNext), "VkImportMemoryHostPointerInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:print_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(((VkPhysicalDeviceExternalMemoryHostPropertiesEXT *)pNext), "VkPhysicalDeviceExternalMemoryHostPropertiesEXT", 1);
             break;
#endif
#ifdef VK_EXT_conservative_rasterization
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:print_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(((VkPhysicalDeviceConservativeRasterizationPropertiesEXT *)pNext), "VkPhysicalDeviceConservativeRasterizationPropertiesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:print_VkPipelineRasterizationConservativeStateCreateInfoEXT(((VkPipelineRasterizationConservativeStateCreateInfoEXT *)pNext), "VkPipelineRasterizationConservativeStateCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:print_VkPhysicalDeviceDescriptorIndexingFeatures(((VkPhysicalDeviceDescriptorIndexingFeatures *)pNext), "VkPhysicalDeviceDescriptorIndexingFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:print_VkPhysicalDeviceDescriptorIndexingProperties(((VkPhysicalDeviceDescriptorIndexingProperties *)pNext), "VkPhysicalDeviceDescriptorIndexingProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:print_VkDescriptorSetLayoutBindingFlagsCreateInfo(((VkDescriptorSetLayoutBindingFlagsCreateInfo *)pNext), "VkDescriptorSetLayoutBindingFlagsCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:print_VkDescriptorSetVariableDescriptorCountAllocateInfo(((VkDescriptorSetVariableDescriptorCountAllocateInfo *)pNext), "VkDescriptorSetVariableDescriptorCountAllocateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:print_VkDescriptorSetVariableDescriptorCountLayoutSupport(((VkDescriptorSetVariableDescriptorCountLayoutSupport *)pNext), "VkDescriptorSetVariableDescriptorCountLayoutSupport", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:print_VkPhysicalDeviceTimelineSemaphoreFeatures(((VkPhysicalDeviceTimelineSemaphoreFeatures *)pNext), "VkPhysicalDeviceTimelineSemaphoreFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:print_VkPhysicalDeviceTimelineSemaphoreProperties(((VkPhysicalDeviceTimelineSemaphoreProperties *)pNext), "VkPhysicalDeviceTimelineSemaphoreProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:print_VkSemaphoreTypeCreateInfo(((VkSemaphoreTypeCreateInfo *)pNext), "VkSemaphoreTypeCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:print_VkTimelineSemaphoreSubmitInfo(((VkTimelineSemaphoreSubmitInfo *)pNext), "VkTimelineSemaphoreSubmitInfo", 1);
             break;
#endif
#ifdef VK_EXT_vertex_attribute_divisor
             case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:print_VkPipelineVertexInputDivisorStateCreateInfoEXT(((VkPipelineVertexInputDivisorStateCreateInfoEXT *)pNext), "VkPipelineVertexInputDivisorStateCreateInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:print_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(((VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *)pNext), "VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT", 1);
             break;
#endif
#ifdef VK_EXT_pci_bus_info
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:print_VkPhysicalDevicePCIBusInfoPropertiesEXT(((VkPhysicalDevicePCIBusInfoPropertiesEXT *)pNext), "VkPhysicalDevicePCIBusInfoPropertiesEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:print_VkPhysicalDevice8BitStorageFeatures(((VkPhysicalDevice8BitStorageFeatures *)pNext), "VkPhysicalDevice8BitStorageFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:print_VkPhysicalDeviceVulkanMemoryModelFeatures(((VkPhysicalDeviceVulkanMemoryModelFeatures *)pNext), "VkPhysicalDeviceVulkanMemoryModelFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:print_VkPhysicalDeviceShaderAtomicInt64Features(((VkPhysicalDeviceShaderAtomicInt64Features *)pNext), "VkPhysicalDeviceShaderAtomicInt64Features", 1);
             break;
#endif
#ifdef VK_EXT_shader_atomic_float
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:print_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(((VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *)pNext), "VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_vertex_attribute_divisor
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:print_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(((VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *)pNext), "VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:print_VkPhysicalDeviceDepthStencilResolveProperties(((VkPhysicalDeviceDepthStencilResolveProperties *)pNext), "VkPhysicalDeviceDepthStencilResolveProperties", 1);
             break;
             case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:print_VkSubpassDescriptionDepthStencilResolve(((VkSubpassDescriptionDepthStencilResolve *)pNext), "VkSubpassDescriptionDepthStencilResolve", 1);
             break;
#endif
#ifdef VK_EXT_astc_decode_mode
             case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:print_VkImageViewASTCDecodeModeEXT(((VkImageViewASTCDecodeModeEXT *)pNext), "VkImageViewASTCDecodeModeEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:print_VkPhysicalDeviceASTCDecodeFeaturesEXT(((VkPhysicalDeviceASTCDecodeFeaturesEXT *)pNext), "VkPhysicalDeviceASTCDecodeFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
             case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:print_VkDrmFormatModifierPropertiesListEXT(((VkDrmFormatModifierPropertiesListEXT *)pNext), "VkDrmFormatModifierPropertiesListEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:print_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(((VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)pNext), "VkPhysicalDeviceImageDrmFormatModifierInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:print_VkImageDrmFormatModifierListCreateInfoEXT(((VkImageDrmFormatModifierListCreateInfoEXT *)pNext), "VkImageDrmFormatModifierListCreateInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:print_VkImageDrmFormatModifierExplicitCreateInfoEXT(((VkImageDrmFormatModifierExplicitCreateInfoEXT *)pNext), "VkImageDrmFormatModifierExplicitCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:print_VkImageStencilUsageCreateInfo(((VkImageStencilUsageCreateInfo *)pNext), "VkImageStencilUsageCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:print_VkPhysicalDeviceScalarBlockLayoutFeatures(((VkPhysicalDeviceScalarBlockLayoutFeatures *)pNext), "VkPhysicalDeviceScalarBlockLayoutFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:print_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(((VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pNext), "VkPhysicalDeviceUniformBufferStandardLayoutFeatures", 1);
             break;
#endif
#ifdef VK_EXT_depth_clip_enable
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:print_VkPhysicalDeviceDepthClipEnableFeaturesEXT(((VkPhysicalDeviceDepthClipEnableFeaturesEXT *)pNext), "VkPhysicalDeviceDepthClipEnableFeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:print_VkPipelineRasterizationDepthClipStateCreateInfoEXT(((VkPipelineRasterizationDepthClipStateCreateInfoEXT *)pNext), "VkPipelineRasterizationDepthClipStateCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_EXT_memory_budget
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:print_VkPhysicalDeviceMemoryBudgetPropertiesEXT(((VkPhysicalDeviceMemoryBudgetPropertiesEXT *)pNext), "VkPhysicalDeviceMemoryBudgetPropertiesEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:print_VkPhysicalDeviceBufferDeviceAddressFeatures(((VkPhysicalDeviceBufferDeviceAddressFeatures *)pNext), "VkPhysicalDeviceBufferDeviceAddressFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:print_VkBufferOpaqueCaptureAddressCreateInfo(((VkBufferOpaqueCaptureAddressCreateInfo *)pNext), "VkBufferOpaqueCaptureAddressCreateInfo", 1);
             break;
#endif
#ifdef VK_EXT_filter_cubic
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:print_VkPhysicalDeviceImageViewImageFormatInfoEXT(((VkPhysicalDeviceImageViewImageFormatInfoEXT *)pNext), "VkPhysicalDeviceImageViewImageFormatInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:print_VkFilterCubicImageViewImageFormatPropertiesEXT(((VkFilterCubicImageViewImageFormatPropertiesEXT *)pNext), "VkFilterCubicImageViewImageFormatPropertiesEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:print_VkPhysicalDeviceImagelessFramebufferFeatures(((VkPhysicalDeviceImagelessFramebufferFeatures *)pNext), "VkPhysicalDeviceImagelessFramebufferFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:print_VkFramebufferAttachmentsCreateInfo(((VkFramebufferAttachmentsCreateInfo *)pNext), "VkFramebufferAttachmentsCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:print_VkRenderPassAttachmentBeginInfo(((VkRenderPassAttachmentBeginInfo *)pNext), "VkRenderPassAttachmentBeginInfo", 1);
             break;
#endif
#ifdef VK_EXT_texture_compression_astc_hdr
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:print_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT(((VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *)pNext), "VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_ycbcr_image_arrays
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:print_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(((VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *)pNext), "VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", 1);
             break;
#endif
#ifdef VK_KHR_performance_query
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:print_VkPhysicalDevicePerformanceQueryFeaturesKHR(((VkPhysicalDevicePerformanceQueryFeaturesKHR *)pNext), "VkPhysicalDevicePerformanceQueryFeaturesKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:print_VkPhysicalDevicePerformanceQueryPropertiesKHR(((VkPhysicalDevicePerformanceQueryPropertiesKHR *)pNext), "VkPhysicalDevicePerformanceQueryPropertiesKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:print_VkQueryPoolPerformanceCreateInfoKHR(((VkQueryPoolPerformanceCreateInfoKHR *)pNext), "VkQueryPoolPerformanceCreateInfoKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:print_VkPerformanceQuerySubmitInfoKHR(((VkPerformanceQuerySubmitInfoKHR *)pNext), "VkPerformanceQuerySubmitInfoKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR:print_VkPerformanceQueryReservationInfoKHR(((VkPerformanceQueryReservationInfoKHR *)pNext), "VkPerformanceQueryReservationInfoKHR", 1);
             break;
#endif
#ifdef VK_KHR_shader_clock
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:print_VkPhysicalDeviceShaderClockFeaturesKHR(((VkPhysicalDeviceShaderClockFeaturesKHR *)pNext), "VkPhysicalDeviceShaderClockFeaturesKHR", 1);
             break;
#endif
#ifdef VK_EXT_index_type_uint8
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:print_VkPhysicalDeviceIndexTypeUint8FeaturesEXT(((VkPhysicalDeviceIndexTypeUint8FeaturesEXT *)pNext), "VkPhysicalDeviceIndexTypeUint8FeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_fragment_shader_interlock
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:print_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(((VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *)pNext), "VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:print_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(((VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pNext), "VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", 1);
             break;
             case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:print_VkAttachmentReferenceStencilLayout(((VkAttachmentReferenceStencilLayout *)pNext), "VkAttachmentReferenceStencilLayout", 1);
             break;
             case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:print_VkAttachmentDescriptionStencilLayout(((VkAttachmentDescriptionStencilLayout *)pNext), "VkAttachmentDescriptionStencilLayout", 1);
             break;
#endif
#ifdef VK_EXT_shader_demote_to_helper_invocation
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:print_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT(((VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *)pNext), "VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_texel_buffer_alignment
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:print_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(((VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *)pNext), "VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:print_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT(((VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *)pNext), "VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT", 1);
             break;
#endif
#ifdef VK_EXT_subgroup_size_control
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:print_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT(((VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *)pNext), "VkPhysicalDeviceSubgroupSizeControlFeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:print_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT(((VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *)pNext), "VkPhysicalDeviceSubgroupSizeControlPropertiesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT:print_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT(((VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT *)pNext), "VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:print_VkMemoryOpaqueCaptureAddressAllocateInfo(((VkMemoryOpaqueCaptureAddressAllocateInfo *)pNext), "VkMemoryOpaqueCaptureAddressAllocateInfo", 1);
             break;
#endif
#ifdef VK_EXT_line_rasterization
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:print_VkPhysicalDeviceLineRasterizationFeaturesEXT(((VkPhysicalDeviceLineRasterizationFeaturesEXT *)pNext), "VkPhysicalDeviceLineRasterizationFeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:print_VkPhysicalDeviceLineRasterizationPropertiesEXT(((VkPhysicalDeviceLineRasterizationPropertiesEXT *)pNext), "VkPhysicalDeviceLineRasterizationPropertiesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:print_VkPipelineRasterizationLineStateCreateInfoEXT(((VkPipelineRasterizationLineStateCreateInfoEXT *)pNext), "VkPipelineRasterizationLineStateCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_VERSION_1_2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:print_VkPhysicalDeviceVulkan11Features(((VkPhysicalDeviceVulkan11Features *)pNext), "VkPhysicalDeviceVulkan11Features", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:print_VkPhysicalDeviceVulkan11Properties(((VkPhysicalDeviceVulkan11Properties *)pNext), "VkPhysicalDeviceVulkan11Properties", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:print_VkPhysicalDeviceVulkan12Features(((VkPhysicalDeviceVulkan12Features *)pNext), "VkPhysicalDeviceVulkan12Features", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:print_VkPhysicalDeviceVulkan12Properties(((VkPhysicalDeviceVulkan12Properties *)pNext), "VkPhysicalDeviceVulkan12Properties", 1);
             break;
#endif
#ifdef VKSC_VERSION_1_0
             case VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO:print_VkFaultCallbackInfo(((VkFaultCallbackInfo *)pNext), "VkFaultCallbackInfo", 1);
             break;
#endif
#ifdef VK_EXT_custom_border_color
             case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:print_VkSamplerCustomBorderColorCreateInfoEXT(((VkSamplerCustomBorderColorCreateInfoEXT *)pNext), "VkSamplerCustomBorderColorCreateInfoEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:print_VkPhysicalDeviceCustomBorderColorPropertiesEXT(((VkPhysicalDeviceCustomBorderColorPropertiesEXT *)pNext), "VkPhysicalDeviceCustomBorderColorPropertiesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:print_VkPhysicalDeviceCustomBorderColorFeaturesEXT(((VkPhysicalDeviceCustomBorderColorFeaturesEXT *)pNext), "VkPhysicalDeviceCustomBorderColorFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_extended_dynamic_state
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:print_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(((VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *)pNext), "VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_extended_dynamic_state2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:print_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(((VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *)pNext), "VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", 1);
             break;
#endif
#ifdef VKSC_VERSION_1_0
             case VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO:print_VkPipelineOfflineCreateInfo(((VkPipelineOfflineCreateInfo *)pNext), "VkPipelineOfflineCreateInfo", 1);
             break;
#endif
#ifdef VK_EXT_robustness2
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:print_VkPhysicalDeviceRobustness2FeaturesEXT(((VkPhysicalDeviceRobustness2FeaturesEXT *)pNext), "VkPhysicalDeviceRobustness2FeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:print_VkPhysicalDeviceRobustness2PropertiesEXT(((VkPhysicalDeviceRobustness2PropertiesEXT *)pNext), "VkPhysicalDeviceRobustness2PropertiesEXT", 1);
             break;
#endif
#ifdef VK_EXT_image_robustness
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:print_VkPhysicalDeviceImageRobustnessFeaturesEXT(((VkPhysicalDeviceImageRobustnessFeaturesEXT *)pNext), "VkPhysicalDeviceImageRobustnessFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_4444_formats
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:print_VkPhysicalDevice4444FormatsFeaturesEXT(((VkPhysicalDevice4444FormatsFeaturesEXT *)pNext), "VkPhysicalDevice4444FormatsFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_shader_image_atomic_int64
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:print_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(((VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *)pNext), "VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", 1);
             break;
#endif
#ifdef VK_KHR_fragment_shading_rate
             case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:print_VkFragmentShadingRateAttachmentInfoKHR(((VkFragmentShadingRateAttachmentInfoKHR *)pNext), "VkFragmentShadingRateAttachmentInfoKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:print_VkPipelineFragmentShadingRateStateCreateInfoKHR(((VkPipelineFragmentShadingRateStateCreateInfoKHR *)pNext), "VkPipelineFragmentShadingRateStateCreateInfoKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:print_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(((VkPhysicalDeviceFragmentShadingRateFeaturesKHR *)pNext), "VkPhysicalDeviceFragmentShadingRateFeaturesKHR", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:print_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(((VkPhysicalDeviceFragmentShadingRatePropertiesKHR *)pNext), "VkPhysicalDeviceFragmentShadingRatePropertiesKHR", 1);
             break;
#endif
#ifdef VK_KHR_shader_terminate_invocation
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR:print_VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR(((VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR *)pNext), "VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR", 1);
             break;
#endif
#ifdef VK_EXT_vertex_input_dynamic_state
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:print_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(((VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *)pNext), "VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_color_write_enable
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:print_VkPhysicalDeviceColorWriteEnableFeaturesEXT(((VkPhysicalDeviceColorWriteEnableFeaturesEXT *)pNext), "VkPhysicalDeviceColorWriteEnableFeaturesEXT", 1);
             break;
             case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:print_VkPipelineColorWriteCreateInfoEXT(((VkPipelineColorWriteCreateInfoEXT *)pNext), "VkPipelineColorWriteCreateInfoEXT", 1);
             break;
#endif
#ifdef VK_KHR_synchronization2
             case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2_KHR:print_VkMemoryBarrier2KHR(((VkMemoryBarrier2KHR *)pNext), "VkMemoryBarrier2KHR", 1);
             break;
             case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:print_VkQueueFamilyCheckpointProperties2NV(((VkQueueFamilyCheckpointProperties2NV *)pNext), "VkQueueFamilyCheckpointProperties2NV", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR:print_VkPhysicalDeviceSynchronization2FeaturesKHR(((VkPhysicalDeviceSynchronization2FeaturesKHR *)pNext), "VkPhysicalDeviceSynchronization2FeaturesKHR", 1);
             break;
#endif
#ifdef VKSC_VERSION_1_0
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES:print_VkPhysicalDeviceVulkanSC10Properties(((VkPhysicalDeviceVulkanSC10Properties *)pNext), "VkPhysicalDeviceVulkanSC10Properties", 1);
             break;
             case VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO:print_VkDeviceObjectReservationCreateInfo(((VkDeviceObjectReservationCreateInfo *)pNext), "VkDeviceObjectReservationCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO:print_VkCommandPoolMemoryReservationCreateInfo(((VkCommandPoolMemoryReservationCreateInfo *)pNext), "VkCommandPoolMemoryReservationCreateInfo", 1);
             break;
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES:print_VkPhysicalDeviceVulkanSC10Features(((VkPhysicalDeviceVulkanSC10Features *)pNext), "VkPhysicalDeviceVulkanSC10Features", 1);
             break;
#endif
#ifdef VK_EXT_ycbcr_2plane_444_formats
             case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:print_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(((VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *)pNext), "VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", 1);
             break;
#endif
#ifdef VK_EXT_image_drm_format_modifier
             case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:print_VkDrmFormatModifierPropertiesList2EXT(((VkDrmFormatModifierPropertiesList2EXT *)pNext), "VkDrmFormatModifierPropertiesList2EXT", 1);
             break;
#endif
             default: assert(!"No structure type matching!");
         }
     }
  }

void print_VkBool32(const VkBool32 * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%s\"%s\n", str, (*obj == 0) ? ("VK_FALSE") : ("VK_TRUE"), commaNeeded ? "," : "");
}

void print_VkDeviceAddress(const VkDeviceAddress * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%" PRIu64 "\"%s\n", str, *obj, commaNeeded ? "," : "");
}

void print_VkDeviceSize(const VkDeviceSize * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%" PRIu64 "\"%s\n", str, *obj, commaNeeded ? "," : "");
}

void print_VkFlags(const VkFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%u\"%s\n", str, *obj, commaNeeded ? "," : "");
}

void print_VkSampleMask(const VkSampleMask * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%u\"%s\n", str, *obj, commaNeeded ? "," : "");
}

void print_VkBuffer(const VkBuffer  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkImage(const VkImage  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkInstance(const VkInstance  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkPhysicalDevice(const VkPhysicalDevice  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkDevice(const VkDevice  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkQueue(const VkQueue  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkSemaphore(const VkSemaphore  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkCommandBuffer(const VkCommandBuffer  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkFence(const VkFence  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkDeviceMemory(const VkDeviceMemory  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkEvent(const VkEvent  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkQueryPool(const VkQueryPool  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkBufferView(const VkBufferView  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkImageView(const VkImageView  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkShaderModule(const VkShaderModule  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkPipelineCache(const VkPipelineCache  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkPipelineLayout(const VkPipelineLayout  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkPipeline(const VkPipeline  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkRenderPass(const VkRenderPass  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkDescriptorSetLayout(const VkDescriptorSetLayout  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkSampler(const VkSampler  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkDescriptorSet(const VkDescriptorSet  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkDescriptorPool(const VkDescriptorPool  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkFramebuffer(const VkFramebuffer  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

void print_VkCommandPool(const VkCommandPool  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

static const char* VkResult_map(int o) {
switch (o) {
    case 0: return "VK_SUCCESS";
    case 1: return "VK_NOT_READY";
    case 2: return "VK_TIMEOUT";
    case 3: return "VK_EVENT_SET";
    case 4: return "VK_EVENT_RESET";
    case 5: return "VK_INCOMPLETE";
    case -1: return "VK_ERROR_OUT_OF_HOST_MEMORY";
    case -2: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
    case -3: return "VK_ERROR_INITIALIZATION_FAILED";
    case -4: return "VK_ERROR_DEVICE_LOST";
    case -5: return "VK_ERROR_MEMORY_MAP_FAILED";
    case -6: return "VK_ERROR_LAYER_NOT_PRESENT";
    case -7: return "VK_ERROR_EXTENSION_NOT_PRESENT";
    case -8: return "VK_ERROR_FEATURE_NOT_PRESENT";
    case -9: return "VK_ERROR_INCOMPATIBLE_DRIVER";
    case -10: return "VK_ERROR_TOO_MANY_OBJECTS";
    case -11: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
    case -12: return "VK_ERROR_FRAGMENTED_POOL";
    case -13: return "VK_ERROR_UNKNOWN";
    case 1000069000: return "VK_ERROR_OUT_OF_POOL_MEMORY";
    case 1000072003: return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
    case 1000161000: return "VK_ERROR_FRAGMENTATION";
    case 1000257000: return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
    case 1000011001: return "VK_ERROR_VALIDATION_FAILED";
    case 1000298000: return "VK_ERROR_INVALID_PIPELINE_CACHE_DATA";
    case 1000298001: return "VK_ERROR_NO_PIPELINE_MATCH";
    case 1000000000: return "VK_ERROR_SURFACE_LOST_KHR";
    case 1000000001: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
    case 1000001003: return "VK_SUBOPTIMAL_KHR";
    case 1000001004: return "VK_ERROR_OUT_OF_DATE_KHR";
    case 1000003001: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
    case 1000012000: return "VK_ERROR_INVALID_SHADER_NV";
    case 1000158000: return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
    case 1000174001: return "VK_ERROR_NOT_PERMITTED_EXT";
    case 1000255000: return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
    case 1000268000: return "VK_THREAD_IDLE_KHR";
    case 1000268001: return "VK_THREAD_DONE_KHR";
    case 1000268002: return "VK_OPERATION_DEFERRED_KHR";
    case 1000268003: return "VK_OPERATION_NOT_DEFERRED_KHR";
    case 1000297000: return "VK_PIPELINE_COMPILE_REQUIRED_EXT";
   }
   return NULL;
}
void print_VkResult(const VkResult* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkResult_map(*obj), commaNeeded ? "," : "");
}

static const char* VkStructureType_map(int o) {
switch (o) {
    case 0: return "VK_STRUCTURE_TYPE_APPLICATION_INFO";
    case 1: return "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO";
    case 2: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO";
    case 3: return "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO";
    case 4: return "VK_STRUCTURE_TYPE_SUBMIT_INFO";
    case 5: return "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO";
    case 6: return "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE";
    case 8: return "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO";
    case 9: return "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO";
    case 10: return "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO";
    case 11: return "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO";
    case 12: return "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO";
    case 13: return "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO";
    case 14: return "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO";
    case 15: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO";
    case 17: return "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO";
    case 18: return "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO";
    case 19: return "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO";
    case 20: return "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO";
    case 21: return "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO";
    case 22: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO";
    case 23: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO";
    case 24: return "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO";
    case 25: return "VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO";
    case 26: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO";
    case 27: return "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO";
    case 28: return "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO";
    case 29: return "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO";
    case 30: return "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO";
    case 31: return "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO";
    case 32: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO";
    case 33: return "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO";
    case 34: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO";
    case 35: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET";
    case 36: return "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET";
    case 37: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO";
    case 38: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO";
    case 39: return "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO";
    case 40: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO";
    case 41: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO";
    case 42: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO";
    case 43: return "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO";
    case 44: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER";
    case 45: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER";
    case 46: return "VK_STRUCTURE_TYPE_MEMORY_BARRIER";
    case 47: return "VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO";
    case 48: return "VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO";
    case 1000094000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES";
    case 1000157000: return "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO";
    case 1000157001: return "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO";
    case 1000083000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES";
    case 1000127000: return "VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS";
    case 1000127001: return "VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO";
    case 1000060000: return "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO";
    case 1000060003: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO";
    case 1000060004: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO";
    case 1000060005: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO";
    case 1000060013: return "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO";
    case 1000060014: return "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO";
    case 1000070000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES";
    case 1000070001: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO";
    case 1000146000: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2";
    case 1000146001: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2";
    case 1000146003: return "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2";
    case 1000059000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2";
    case 1000059001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2";
    case 1000059002: return "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2";
    case 1000059003: return "VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2";
    case 1000059004: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2";
    case 1000059005: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2";
    case 1000059006: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2";
    case 1000117000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES";
    case 1000117001: return "VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO";
    case 1000117002: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO";
    case 1000117003: return "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO";
    case 1000053000: return "VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO";
    case 1000053001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES";
    case 1000053002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES";
    case 1000120000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES";
    case 1000145000: return "VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO";
    case 1000145001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES";
    case 1000145002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES";
    case 1000145003: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2";
    case 1000156000: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO";
    case 1000156001: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO";
    case 1000156002: return "VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO";
    case 1000156003: return "VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO";
    case 1000156004: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES";
    case 1000156005: return "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES";
    case 1000071000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO";
    case 1000071001: return "VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES";
    case 1000071002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO";
    case 1000071003: return "VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES";
    case 1000071004: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES";
    case 1000072000: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO";
    case 1000072001: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO";
    case 1000072002: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO";
    case 1000112000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO";
    case 1000112001: return "VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES";
    case 1000113000: return "VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO";
    case 1000077000: return "VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO";
    case 1000076000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO";
    case 1000076001: return "VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES";
    case 1000168000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES";
    case 1000168001: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT";
    case 1000063000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES";
    case 49: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES";
    case 50: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES";
    case 51: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES";
    case 52: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES";
    case 1000147000: return "VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO";
    case 1000109000: return "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2";
    case 1000109001: return "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2";
    case 1000109002: return "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2";
    case 1000109003: return "VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2";
    case 1000109004: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2";
    case 1000109005: return "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO";
    case 1000109006: return "VK_STRUCTURE_TYPE_SUBPASS_END_INFO";
    case 1000177000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES";
    case 1000196000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES";
    case 1000180000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES";
    case 1000082000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES";
    case 1000197000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES";
    case 1000161000: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO";
    case 1000161001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES";
    case 1000161002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES";
    case 1000161003: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO";
    case 1000161004: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT";
    case 1000199000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES";
    case 1000199001: return "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE";
    case 1000221000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES";
    case 1000246000: return "VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO";
    case 1000130000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES";
    case 1000130001: return "VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO";
    case 1000211000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES";
    case 1000108000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES";
    case 1000108001: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO";
    case 1000108002: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO";
    case 1000108003: return "VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO";
    case 1000253000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES";
    case 1000175000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES";
    case 1000241000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES";
    case 1000241001: return "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT";
    case 1000241002: return "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT";
    case 1000261000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES";
    case 1000207000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES";
    case 1000207001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES";
    case 1000207002: return "VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO";
    case 1000207003: return "VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO";
    case 1000207004: return "VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO";
    case 1000207005: return "VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO";
    case 1000257000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES";
    case 1000244001: return "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO";
    case 1000257002: return "VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO";
    case 1000257003: return "VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO";
    case 1000257004: return "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO";
    case 1000298000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES";
    case 1000298001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES";
    case 1000298002: return "VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO";
    case 1000298003: return "VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO";
    case 1000298004: return "VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_CONSUMPTION";
    case 1000298005: return "VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE";
    case 1000298007: return "VK_STRUCTURE_TYPE_FAULT_DATA";
    case 1000298008: return "VK_STRUCTURE_TYPE_FAULT_CALLBACK_INFO";
    case 1000298010: return "VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO";
    case 1000001000: return "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR";
    case 1000001001: return "VK_STRUCTURE_TYPE_PRESENT_INFO_KHR";
    case 1000060007: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR";
    case 1000060008: return "VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR";
    case 1000060009: return "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR";
    case 1000060010: return "VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR";
    case 1000060011: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR";
    case 1000060012: return "VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR";
    case 1000002000: return "VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR";
    case 1000002001: return "VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR";
    case 1000003000: return "VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR";
    case 1000004000: return "VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR";
    case 1000005000: return "VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR";
    case 1000006000: return "VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR";
    case 1000008000: return "VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR";
    case 1000009000: return "VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR";
    case 1000010000: return "VK_STRUCTURE_TYPE_NATIVE_BUFFER_ANDROID";
    case 1000010001: return "VK_STRUCTURE_TYPE_SWAPCHAIN_IMAGE_CREATE_INFO_ANDROID";
    case 1000010002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_ANDROID";
    case 1000011000: return "VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT";
    case 1000018000: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD";
    case 1000022000: return "VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT";
    case 1000022001: return "VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT";
    case 1000022002: return "VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT";
    case 1000023000: return "VK_STRUCTURE_TYPE_VIDEO_PROFILE_KHR";
    case 1000023001: return "VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR";
    case 1000023002: return "VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_KHR";
    case 1000023003: return "VK_STRUCTURE_TYPE_VIDEO_GET_MEMORY_PROPERTIES_KHR";
    case 1000023004: return "VK_STRUCTURE_TYPE_VIDEO_BIND_MEMORY_KHR";
    case 1000023005: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR";
    case 1000023006: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR";
    case 1000023007: return "VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR";
    case 1000023008: return "VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR";
    case 1000023009: return "VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR";
    case 1000023010: return "VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR";
    case 1000023011: return "VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_KHR";
    case 1000023012: return "VK_STRUCTURE_TYPE_VIDEO_QUEUE_FAMILY_PROPERTIES_2_KHR";
    case 1000023013: return "VK_STRUCTURE_TYPE_VIDEO_PROFILES_KHR";
    case 1000023014: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR";
    case 1000023015: return "VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR";
    case 1000024000: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR";
    case 1000026000: return "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV";
    case 1000026001: return "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV";
    case 1000026002: return "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV";
    case 1000028000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT";
    case 1000028001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT";
    case 1000028002: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT";
    case 1000029000: return "VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX";
    case 1000029001: return "VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX";
    case 1000029002: return "VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX";
    case 1000030000: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX";
    case 1000030001: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX";
    case 1000038000: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_EXT";
    case 1000038001: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_EXT";
    case 1000038002: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT";
    case 1000038003: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT";
    case 1000038004: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_VCL_FRAME_INFO_EXT";
    case 1000038005: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_EXT";
    case 1000038006: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_EXT";
    case 1000038007: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_EMIT_PICTURE_PARAMETERS_EXT";
    case 1000038008: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_EXT";
    case 1000038009: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_EXT";
    case 1000038010: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_EXT";
    case 1000039000: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_EXT";
    case 1000039001: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_EXT";
    case 1000039002: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT";
    case 1000039003: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT";
    case 1000039004: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_VCL_FRAME_INFO_EXT";
    case 1000039005: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_EXT";
    case 1000039006: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_EXT";
    case 1000039007: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_EMIT_PICTURE_PARAMETERS_EXT";
    case 1000039008: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_EXT";
    case 1000039009: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_REFERENCE_LISTS_EXT";
    case 1000039010: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_EXT";
    case 1000039011: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_EXT";
    case 1000040000: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_EXT";
    case 1000040001: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_CREATE_INFO_EXT";
    case 1000040002: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_EXT";
    case 1000040003: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_MVC_EXT";
    case 1000040004: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_EXT";
    case 1000040005: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT";
    case 1000040006: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT";
    case 1000040007: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_EXT";
    case 1000041000: return "VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD";
    case 1000044000: return "VK_STRUCTURE_TYPE_RENDERING_INFO_KHR";
    case 1000044001: return "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO_KHR";
    case 1000044002: return "VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR";
    case 1000044003: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR";
    case 1000044004: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR";
    case 1000044006: return "VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR";
    case 1000044007: return "VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT";
    case 1000044008: return "VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD";
    case 1000044009: return "VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX";
    case 1000049000: return "VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP";
    case 1000050000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV";
    case 1000056000: return "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV";
    case 1000056001: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV";
    case 1000057000: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV";
    case 1000057001: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV";
    case 1000058000: return "VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV";
    case 1000061000: return "VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT";
    case 1000062000: return "VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN";
    case 1000066000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT";
    case 1000067000: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT";
    case 1000067001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT";
    case 1000073000: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR";
    case 1000073001: return "VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR";
    case 1000073002: return "VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR";
    case 1000073003: return "VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR";
    case 1000074000: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR";
    case 1000074001: return "VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR";
    case 1000074002: return "VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR";
    case 1000075000: return "VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR";
    case 1000078000: return "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR";
    case 1000078001: return "VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR";
    case 1000078002: return "VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR";
    case 1000078003: return "VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR";
    case 1000079000: return "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR";
    case 1000079001: return "VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR";
    case 1000080000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR";
    case 1000081000: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT";
    case 1000081001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT";
    case 1000081002: return "VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT";
    case 1000084000: return "VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR";
    case 1000087000: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV";
    case 1000090000: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT";
    case 1000091000: return "VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT";
    case 1000091001: return "VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT";
    case 1000091002: return "VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT";
    case 1000091003: return "VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT";
    case 1000092000: return "VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE";
    case 1000097000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX";
    case 1000098000: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV";
    case 1000099000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT";
    case 1000099001: return "VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT";
    case 1000101000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT";
    case 1000101001: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT";
    case 1000102000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT";
    case 1000102001: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT";
    case 1000105000: return "VK_STRUCTURE_TYPE_HDR_METADATA_EXT";
    case 1000111000: return "VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR";
    case 1000114000: return "VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR";
    case 1000114001: return "VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR";
    case 1000114002: return "VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR";
    case 1000115000: return "VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR";
    case 1000115001: return "VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR";
    case 1000116000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR";
    case 1000116001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR";
    case 1000116002: return "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR";
    case 1000116003: return "VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR";
    case 1000116004: return "VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR";
    case 1000116005: return "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR";
    case 1000116006: return "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR";
    case 1000116007: return "VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR";
    case 1000119000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR";
    case 1000119001: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR";
    case 1000119002: return "VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR";
    case 1000121000: return "VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR";
    case 1000121001: return "VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR";
    case 1000121002: return "VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR";
    case 1000121003: return "VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR";
    case 1000121004: return "VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR";
    case 1000122000: return "VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK";
    case 1000123000: return "VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK";
    case 1000128000: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT";
    case 1000128001: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT";
    case 1000128002: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT";
    case 1000128003: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT";
    case 1000128004: return "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT";
    case 1000129000: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID";
    case 1000129001: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID";
    case 1000129002: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID";
    case 1000129003: return "VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID";
    case 1000129004: return "VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID";
    case 1000129005: return "VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID";
    case 1000129006: return "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID";
    case 1000138000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT";
    case 1000138001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT";
    case 1000138002: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT";
    case 1000138003: return "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT";
    case 1000143000: return "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT";
    case 1000143001: return "VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT";
    case 1000143002: return "VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT";
    case 1000143003: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT";
    case 1000143004: return "VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT";
    case 1000148000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT";
    case 1000148001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT";
    case 1000148002: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT";
    case 1000149000: return "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV";
    case 1000150007: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR";
    case 1000150000: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR";
    case 1000150002: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR";
    case 1000150003: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR";
    case 1000150004: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR";
    case 1000150005: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR";
    case 1000150006: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR";
    case 1000150009: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR";
    case 1000150010: return "VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR";
    case 1000150011: return "VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR";
    case 1000150012: return "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR";
    case 1000150013: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR";
    case 1000150014: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR";
    case 1000150017: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR";
    case 1000150020: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR";
    case 1000347000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR";
    case 1000347001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR";
    case 1000150015: return "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR";
    case 1000150016: return "VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR";
    case 1000150018: return "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR";
    case 1000348013: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR";
    case 1000152000: return "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV";
    case 1000154000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV";
    case 1000154001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV";
    case 1000158000: return "VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT";
    case 1000158002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT";
    case 1000158003: return "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT";
    case 1000158004: return "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT";
    case 1000158005: return "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT";
    case 1000158006: return "VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT";
    case 1000160000: return "VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT";
    case 1000160001: return "VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT";
    case 1000163000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR";
    case 1000163001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR";
    case 1000164000: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV";
    case 1000164001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV";
    case 1000164002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV";
    case 1000164005: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV";
    case 1000165000: return "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV";
    case 1000165001: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV";
    case 1000165003: return "VK_STRUCTURE_TYPE_GEOMETRY_NV";
    case 1000165004: return "VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV";
    case 1000165005: return "VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV";
    case 1000165006: return "VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV";
    case 1000165007: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV";
    case 1000165008: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV";
    case 1000165009: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV";
    case 1000165011: return "VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV";
    case 1000165012: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV";
    case 1000166000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV";
    case 1000166001: return "VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV";
    case 1000170000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT";
    case 1000170001: return "VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT";
    case 1000174000: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT";
    case 1000178000: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT";
    case 1000178001: return "VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT";
    case 1000178002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT";
    case 1000181000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR";
    case 1000183000: return "VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD";
    case 1000184000: return "VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT";
    case 1000185000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD";
    case 1000187000: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_EXT";
    case 1000187001: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_CREATE_INFO_EXT";
    case 1000187002: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT";
    case 1000187003: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT";
    case 1000187004: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_EXT";
    case 1000187005: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_EXT";
    case 1000187006: return "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_EXT";
    case 1000189000: return "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD";
    case 1000190000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT";
    case 1000190001: return "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT";
    case 1000190002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT";
    case 1000191000: return "VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP";
    case 1000192000: return "VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT";
    case 1000201000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV";
    case 1000202000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV";
    case 1000202001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV";
    case 1000203000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV";
    case 1000204000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV";
    case 1000205000: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV";
    case 1000205002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV";
    case 1000206000: return "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV";
    case 1000206001: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV";
    case 1000209000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL";
    case 1000210000: return "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL";
    case 1000210001: return "VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL";
    case 1000210002: return "VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL";
    case 1000210003: return "VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL";
    case 1000210004: return "VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL";
    case 1000210005: return "VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL";
    case 1000212000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT";
    case 1000213000: return "VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD";
    case 1000213001: return "VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD";
    case 1000214000: return "VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA";
    case 1000215000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR";
    case 1000217000: return "VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT";
    case 1000218000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT";
    case 1000218001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT";
    case 1000218002: return "VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT";
    case 1000225000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT";
    case 1000225001: return "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT";
    case 1000225002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT";
    case 1000226000: return "VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR";
    case 1000226001: return "VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR";
    case 1000226002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR";
    case 1000226003: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR";
    case 1000226004: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR";
    case 1000227000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD";
    case 1000229000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD";
    case 1000234000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT";
    case 1000237000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT";
    case 1000238000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT";
    case 1000238001: return "VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT";
    case 1000239000: return "VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR";
    case 1000240000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV";
    case 1000244000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT";
    case 1000244002: return "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT";
    case 1000245000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT";
    case 1000247000: return "VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT";
    case 1000248000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR";
    case 1000249000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV";
    case 1000249001: return "VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV";
    case 1000249002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV";
    case 1000250000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV";
    case 1000250001: return "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV";
    case 1000250002: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV";
    case 1000251000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT";
    case 1000252000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT";
    case 1000254000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT";
    case 1000254001: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT";
    case 1000254002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT";
    case 1000255000: return "VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT";
    case 1000255002: return "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT";
    case 1000255001: return "VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT";
    case 1000256000: return "VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT";
    case 1000259000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT";
    case 1000259001: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT";
    case 1000259002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT";
    case 1000260000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT";
    case 1000265000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT";
    case 1000267000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT";
    case 1000269000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR";
    case 1000269001: return "VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR";
    case 1000269002: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR";
    case 1000269003: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR";
    case 1000269004: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR";
    case 1000269005: return "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR";
    case 1000273000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT";
    case 1000276000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT";
    case 1000277000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV";
    case 1000277001: return "VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV";
    case 1000277002: return "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV";
    case 1000277003: return "VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV";
    case 1000277004: return "VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV";
    case 1000277005: return "VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV";
    case 1000277006: return "VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV";
    case 1000277007: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV";
    case 1000278000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV";
    case 1000278001: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV";
    case 1000280000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR";
    case 1000280001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR";
    case 1000281000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT";
    case 1000281001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT";
    case 1000282000: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM";
    case 1000282001: return "VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM";
    case 1000284000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT";
    case 1000284001: return "VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT";
    case 1000284002: return "VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT";
    case 1000286000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT";
    case 1000286001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT";
    case 1000287000: return "VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT";
    case 1000287001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT";
    case 1000287002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT";
    case 1000290000: return "VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR";
    case 1000294000: return "VK_STRUCTURE_TYPE_PRESENT_ID_KHR";
    case 1000294001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR";
    case 1000295000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT";
    case 1000295001: return "VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT";
    case 1000295002: return "VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO_EXT";
    case 1000297000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT";
    case 1000299000: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR";
    case 1000299001: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR";
    case 1000299002: return "VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR";
    case 1000300000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV";
    case 1000300001: return "VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV";
    case 1000308000: return "VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR";
    case 1000309000: return "VK_STRUCTURE_TYPE_RESERVED_QCOM";
    case 1000314000: return "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2_KHR";
    case 1000314001: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2_KHR";
    case 1000314002: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2_KHR";
    case 1000314003: return "VK_STRUCTURE_TYPE_DEPENDENCY_INFO_KHR";
    case 1000314004: return "VK_STRUCTURE_TYPE_SUBMIT_INFO_2_KHR";
    case 1000314005: return "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO_KHR";
    case 1000314006: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO_KHR";
    case 1000314007: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR";
    case 1000314008: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV";
    case 1000314009: return "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV";
    case 1000323000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR";
    case 1000325000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR";
    case 1000326000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV";
    case 1000326001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV";
    case 1000326002: return "VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV";
    case 1000327000: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV";
    case 1000327001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV";
    case 1000327002: return "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV";
    case 1000330000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT";
    case 1000332000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT";
    case 1000332001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT";
    case 1000333000: return "VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM";
    case 1000335000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT";
    case 1000336000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR";
    case 1000337000: return "VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2_KHR";
    case 1000337001: return "VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2_KHR";
    case 1000337002: return "VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2_KHR";
    case 1000337003: return "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2_KHR";
    case 1000337004: return "VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2_KHR";
    case 1000337005: return "VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2_KHR";
    case 1000337006: return "VK_STRUCTURE_TYPE_BUFFER_COPY_2_KHR";
    case 1000337007: return "VK_STRUCTURE_TYPE_IMAGE_COPY_2_KHR";
    case 1000337008: return "VK_STRUCTURE_TYPE_IMAGE_BLIT_2_KHR";
    case 1000337009: return "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2_KHR";
    case 1000337010: return "VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2_KHR";
    case 1000340000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT";
    case 1000342000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM";
    case 1000344000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT";
    case 1000346000: return "VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT";
    case 1000351000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE";
    case 1000351002: return "VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE";
    case 1000352000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT";
    case 1000352001: return "VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT";
    case 1000352002: return "VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT";
    case 1000353000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT";
    case 1000355000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT";
    case 1000355001: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT";
    case 1000356000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT";
    case 1000360000: return "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR";
    case 1000364000: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA";
    case 1000364001: return "VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA";
    case 1000364002: return "VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA";
    case 1000365000: return "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA";
    case 1000365001: return "VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA";
    case 1000366000: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA";
    case 1000366001: return "VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA";
    case 1000366002: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA";
    case 1000366003: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA";
    case 1000366004: return "VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA";
    case 1000366005: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA";
    case 1000366006: return "VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA";
    case 1000366007: return "VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA";
    case 1000366008: return "VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA";
    case 1000366009: return "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA";
    case 1000369000: return "VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI";
    case 1000369001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI";
    case 1000369002: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI";
    case 1000370000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI";
    case 1000371000: return "VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV";
    case 1000371001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV";
    case 1000377000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT";
    case 1000378000: return "VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX";
    case 1000381000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT";
    case 1000381001: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT";
    case 1000388000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT";
    case 1000388001: return "VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT";
    case 1000391000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT";
    case 1000391001: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT";
    case 1000392000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT";
    case 1000392001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT";
    case 1000411000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT";
    case 1000411001: return "VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT";
    case 1000412000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT";
    case 1000413000: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR";
    case 1000413001: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR";
    case 1000413002: return "VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS_KHR";
    case 1000413003: return "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS_KHR";
    case 1000435000: return "VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT";
   }
   return NULL;
}
void print_VkStructureType(const VkStructureType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkStructureType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkAccessFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_ACCESS_INDIRECT_COMMAND_READ_BIT";
    case (1 << 1): return "VK_ACCESS_INDEX_READ_BIT";
    case (1 << 2): return "VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT";
    case (1 << 3): return "VK_ACCESS_UNIFORM_READ_BIT";
    case (1 << 4): return "VK_ACCESS_INPUT_ATTACHMENT_READ_BIT";
    case (1 << 5): return "VK_ACCESS_SHADER_READ_BIT";
    case (1 << 6): return "VK_ACCESS_SHADER_WRITE_BIT";
    case (1 << 7): return "VK_ACCESS_COLOR_ATTACHMENT_READ_BIT";
    case (1 << 8): return "VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT";
    case (1 << 9): return "VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT";
    case (1 << 10): return "VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT";
    case (1 << 11): return "VK_ACCESS_TRANSFER_READ_BIT";
    case (1 << 12): return "VK_ACCESS_TRANSFER_WRITE_BIT";
    case (1 << 13): return "VK_ACCESS_HOST_READ_BIT";
    case (1 << 14): return "VK_ACCESS_HOST_WRITE_BIT";
    case (1 << 15): return "VK_ACCESS_MEMORY_READ_BIT";
    case (1 << 16): return "VK_ACCESS_MEMORY_WRITE_BIT";
    case (1 << 25): return "VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
    case (1 << 26): return "VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
    case (1 << 27): return "VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
    case (1 << 20): return "VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT";
    case (1 << 19): return "VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
    case (1 << 21): return "VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR";
    case (1 << 22): return "VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
    case (1 << 24): return "VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
    case (1 << 23): return "VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
    case (1 << 17): return "VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV";
    case (1 << 18): return "VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV";
    case 0: return "VK_ACCESS_NONE_KHR";
   }
   return NULL;
}
void print_VkAccessFlagBits(const VkAccessFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkAccessFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageLayout_map(int o) {
switch (o) {
    case 0: return "VK_IMAGE_LAYOUT_UNDEFINED";
    case 1: return "VK_IMAGE_LAYOUT_GENERAL";
    case 2: return "VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL";
    case 3: return "VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL";
    case 4: return "VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL";
    case 5: return "VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL";
    case 6: return "VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL";
    case 7: return "VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL";
    case 8: return "VK_IMAGE_LAYOUT_PREINITIALIZED";
    case 1000117000: return "VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL";
    case 1000117001: return "VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL";
    case 1000241000: return "VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL";
    case 1000241001: return "VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL";
    case 1000241002: return "VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL";
    case 1000241003: return "VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL";
    case 1000001002: return "VK_IMAGE_LAYOUT_PRESENT_SRC_KHR";
    case 1000024000: return "VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR";
    case 1000024001: return "VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR";
    case 1000024002: return "VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR";
    case 1000111000: return "VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR";
    case 1000218000: return "VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT";
    case 1000164003: return "VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR";
    case 1000299000: return "VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR";
    case 1000299001: return "VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR";
    case 1000299002: return "VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR";
    case 1000314000: return "VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL_KHR";
    case 1000314001: return "VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR";
   }
   return NULL;
}
void print_VkImageLayout(const VkImageLayout* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageLayout_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageAspectFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_IMAGE_ASPECT_COLOR_BIT";
    case (1 << 1): return "VK_IMAGE_ASPECT_DEPTH_BIT";
    case (1 << 2): return "VK_IMAGE_ASPECT_STENCIL_BIT";
    case (1 << 3): return "VK_IMAGE_ASPECT_METADATA_BIT";
    case (1 << 4): return "VK_IMAGE_ASPECT_PLANE_0_BIT";
    case (1 << 5): return "VK_IMAGE_ASPECT_PLANE_1_BIT";
    case (1 << 6): return "VK_IMAGE_ASPECT_PLANE_2_BIT";
    case (1 << 7): return "VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT";
    case (1 << 8): return "VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT";
    case (1 << 9): return "VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT";
    case (1 << 10): return "VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT";
    case 0: return "VK_IMAGE_ASPECT_NONE_KHR";
   }
   return NULL;
}
void print_VkImageAspectFlagBits(const VkImageAspectFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageAspectFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkObjectType_map(int o) {
switch (o) {
    case 0: return "VK_OBJECT_TYPE_UNKNOWN";
    case 1: return "VK_OBJECT_TYPE_INSTANCE";
    case 2: return "VK_OBJECT_TYPE_PHYSICAL_DEVICE";
    case 3: return "VK_OBJECT_TYPE_DEVICE";
    case 4: return "VK_OBJECT_TYPE_QUEUE";
    case 5: return "VK_OBJECT_TYPE_SEMAPHORE";
    case 6: return "VK_OBJECT_TYPE_COMMAND_BUFFER";
    case 7: return "VK_OBJECT_TYPE_FENCE";
    case 8: return "VK_OBJECT_TYPE_DEVICE_MEMORY";
    case 9: return "VK_OBJECT_TYPE_BUFFER";
    case 10: return "VK_OBJECT_TYPE_IMAGE";
    case 11: return "VK_OBJECT_TYPE_EVENT";
    case 12: return "VK_OBJECT_TYPE_QUERY_POOL";
    case 13: return "VK_OBJECT_TYPE_BUFFER_VIEW";
    case 14: return "VK_OBJECT_TYPE_IMAGE_VIEW";
    case 16: return "VK_OBJECT_TYPE_PIPELINE_CACHE";
    case 17: return "VK_OBJECT_TYPE_PIPELINE_LAYOUT";
    case 18: return "VK_OBJECT_TYPE_RENDER_PASS";
    case 19: return "VK_OBJECT_TYPE_PIPELINE";
    case 20: return "VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT";
    case 21: return "VK_OBJECT_TYPE_SAMPLER";
    case 22: return "VK_OBJECT_TYPE_DESCRIPTOR_POOL";
    case 23: return "VK_OBJECT_TYPE_DESCRIPTOR_SET";
    case 24: return "VK_OBJECT_TYPE_FRAMEBUFFER";
    case 25: return "VK_OBJECT_TYPE_COMMAND_POOL";
    case 1000156000: return "VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION";
    case 1000000000: return "VK_OBJECT_TYPE_SURFACE_KHR";
    case 1000001000: return "VK_OBJECT_TYPE_SWAPCHAIN_KHR";
    case 1000002000: return "VK_OBJECT_TYPE_DISPLAY_KHR";
    case 1000002001: return "VK_OBJECT_TYPE_DISPLAY_MODE_KHR";
    case 1000011000: return "VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT";
    case 1000023000: return "VK_OBJECT_TYPE_VIDEO_SESSION_KHR";
    case 1000023001: return "VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR";
    case 1000029000: return "VK_OBJECT_TYPE_CU_MODULE_NVX";
    case 1000029001: return "VK_OBJECT_TYPE_CU_FUNCTION_NVX";
    case 1000128000: return "VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT";
    case 1000150000: return "VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR";
    case 1000160000: return "VK_OBJECT_TYPE_VALIDATION_CACHE_EXT";
    case 1000165000: return "VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV";
    case 1000210000: return "VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL";
    case 1000268000: return "VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR";
    case 1000277000: return "VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV";
    case 1000295000: return "VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT";
    case 1000366000: return "VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA";
   }
   return NULL;
}
void print_VkObjectType(const VkObjectType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkObjectType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPipelineCacheHeaderVersion_map(int o) {
switch (o) {
    case 1: return "VK_PIPELINE_CACHE_HEADER_VERSION_ONE";
    case 1000298001: return "VK_PIPELINE_CACHE_HEADER_VERSION_SAFETY_CRITICAL_ONE";
   }
   return NULL;
}
void print_VkPipelineCacheHeaderVersion(const VkPipelineCacheHeaderVersion* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineCacheHeaderVersion_map(*obj), commaNeeded ? "," : "");
}

static const char* VkVendorId_map(int o) {
switch (o) {
    case 0x10001: return "VK_VENDOR_ID_VIV";
    case 0x10002: return "VK_VENDOR_ID_VSI";
    case 0x10003: return "VK_VENDOR_ID_KAZAN";
    case 0x10004: return "VK_VENDOR_ID_CODEPLAY";
    case 0x10005: return "VK_VENDOR_ID_MESA";
    case 0x10006: return "VK_VENDOR_ID_POCL";
   }
   return NULL;
}
void print_VkVendorId(const VkVendorId* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkVendorId_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSystemAllocationScope_map(int o) {
switch (o) {
    case 0: return "VK_SYSTEM_ALLOCATION_SCOPE_COMMAND";
    case 1: return "VK_SYSTEM_ALLOCATION_SCOPE_OBJECT";
    case 2: return "VK_SYSTEM_ALLOCATION_SCOPE_CACHE";
    case 3: return "VK_SYSTEM_ALLOCATION_SCOPE_DEVICE";
    case 4: return "VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE";
   }
   return NULL;
}
void print_VkSystemAllocationScope(const VkSystemAllocationScope* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSystemAllocationScope_map(*obj), commaNeeded ? "," : "");
}

static const char* VkInternalAllocationType_map(int o) {
switch (o) {
    case 0: return "VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE";
   }
   return NULL;
}
void print_VkInternalAllocationType(const VkInternalAllocationType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkInternalAllocationType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkFormat_map(int o) {
switch (o) {
    case 0: return "VK_FORMAT_UNDEFINED";
    case 1: return "VK_FORMAT_R4G4_UNORM_PACK8";
    case 2: return "VK_FORMAT_R4G4B4A4_UNORM_PACK16";
    case 3: return "VK_FORMAT_B4G4R4A4_UNORM_PACK16";
    case 4: return "VK_FORMAT_R5G6B5_UNORM_PACK16";
    case 5: return "VK_FORMAT_B5G6R5_UNORM_PACK16";
    case 6: return "VK_FORMAT_R5G5B5A1_UNORM_PACK16";
    case 7: return "VK_FORMAT_B5G5R5A1_UNORM_PACK16";
    case 8: return "VK_FORMAT_A1R5G5B5_UNORM_PACK16";
    case 9: return "VK_FORMAT_R8_UNORM";
    case 10: return "VK_FORMAT_R8_SNORM";
    case 11: return "VK_FORMAT_R8_USCALED";
    case 12: return "VK_FORMAT_R8_SSCALED";
    case 13: return "VK_FORMAT_R8_UINT";
    case 14: return "VK_FORMAT_R8_SINT";
    case 15: return "VK_FORMAT_R8_SRGB";
    case 16: return "VK_FORMAT_R8G8_UNORM";
    case 17: return "VK_FORMAT_R8G8_SNORM";
    case 18: return "VK_FORMAT_R8G8_USCALED";
    case 19: return "VK_FORMAT_R8G8_SSCALED";
    case 20: return "VK_FORMAT_R8G8_UINT";
    case 21: return "VK_FORMAT_R8G8_SINT";
    case 22: return "VK_FORMAT_R8G8_SRGB";
    case 23: return "VK_FORMAT_R8G8B8_UNORM";
    case 24: return "VK_FORMAT_R8G8B8_SNORM";
    case 25: return "VK_FORMAT_R8G8B8_USCALED";
    case 26: return "VK_FORMAT_R8G8B8_SSCALED";
    case 27: return "VK_FORMAT_R8G8B8_UINT";
    case 28: return "VK_FORMAT_R8G8B8_SINT";
    case 29: return "VK_FORMAT_R8G8B8_SRGB";
    case 30: return "VK_FORMAT_B8G8R8_UNORM";
    case 31: return "VK_FORMAT_B8G8R8_SNORM";
    case 32: return "VK_FORMAT_B8G8R8_USCALED";
    case 33: return "VK_FORMAT_B8G8R8_SSCALED";
    case 34: return "VK_FORMAT_B8G8R8_UINT";
    case 35: return "VK_FORMAT_B8G8R8_SINT";
    case 36: return "VK_FORMAT_B8G8R8_SRGB";
    case 37: return "VK_FORMAT_R8G8B8A8_UNORM";
    case 38: return "VK_FORMAT_R8G8B8A8_SNORM";
    case 39: return "VK_FORMAT_R8G8B8A8_USCALED";
    case 40: return "VK_FORMAT_R8G8B8A8_SSCALED";
    case 41: return "VK_FORMAT_R8G8B8A8_UINT";
    case 42: return "VK_FORMAT_R8G8B8A8_SINT";
    case 43: return "VK_FORMAT_R8G8B8A8_SRGB";
    case 44: return "VK_FORMAT_B8G8R8A8_UNORM";
    case 45: return "VK_FORMAT_B8G8R8A8_SNORM";
    case 46: return "VK_FORMAT_B8G8R8A8_USCALED";
    case 47: return "VK_FORMAT_B8G8R8A8_SSCALED";
    case 48: return "VK_FORMAT_B8G8R8A8_UINT";
    case 49: return "VK_FORMAT_B8G8R8A8_SINT";
    case 50: return "VK_FORMAT_B8G8R8A8_SRGB";
    case 51: return "VK_FORMAT_A8B8G8R8_UNORM_PACK32";
    case 52: return "VK_FORMAT_A8B8G8R8_SNORM_PACK32";
    case 53: return "VK_FORMAT_A8B8G8R8_USCALED_PACK32";
    case 54: return "VK_FORMAT_A8B8G8R8_SSCALED_PACK32";
    case 55: return "VK_FORMAT_A8B8G8R8_UINT_PACK32";
    case 56: return "VK_FORMAT_A8B8G8R8_SINT_PACK32";
    case 57: return "VK_FORMAT_A8B8G8R8_SRGB_PACK32";
    case 58: return "VK_FORMAT_A2R10G10B10_UNORM_PACK32";
    case 59: return "VK_FORMAT_A2R10G10B10_SNORM_PACK32";
    case 60: return "VK_FORMAT_A2R10G10B10_USCALED_PACK32";
    case 61: return "VK_FORMAT_A2R10G10B10_SSCALED_PACK32";
    case 62: return "VK_FORMAT_A2R10G10B10_UINT_PACK32";
    case 63: return "VK_FORMAT_A2R10G10B10_SINT_PACK32";
    case 64: return "VK_FORMAT_A2B10G10R10_UNORM_PACK32";
    case 65: return "VK_FORMAT_A2B10G10R10_SNORM_PACK32";
    case 66: return "VK_FORMAT_A2B10G10R10_USCALED_PACK32";
    case 67: return "VK_FORMAT_A2B10G10R10_SSCALED_PACK32";
    case 68: return "VK_FORMAT_A2B10G10R10_UINT_PACK32";
    case 69: return "VK_FORMAT_A2B10G10R10_SINT_PACK32";
    case 70: return "VK_FORMAT_R16_UNORM";
    case 71: return "VK_FORMAT_R16_SNORM";
    case 72: return "VK_FORMAT_R16_USCALED";
    case 73: return "VK_FORMAT_R16_SSCALED";
    case 74: return "VK_FORMAT_R16_UINT";
    case 75: return "VK_FORMAT_R16_SINT";
    case 76: return "VK_FORMAT_R16_SFLOAT";
    case 77: return "VK_FORMAT_R16G16_UNORM";
    case 78: return "VK_FORMAT_R16G16_SNORM";
    case 79: return "VK_FORMAT_R16G16_USCALED";
    case 80: return "VK_FORMAT_R16G16_SSCALED";
    case 81: return "VK_FORMAT_R16G16_UINT";
    case 82: return "VK_FORMAT_R16G16_SINT";
    case 83: return "VK_FORMAT_R16G16_SFLOAT";
    case 84: return "VK_FORMAT_R16G16B16_UNORM";
    case 85: return "VK_FORMAT_R16G16B16_SNORM";
    case 86: return "VK_FORMAT_R16G16B16_USCALED";
    case 87: return "VK_FORMAT_R16G16B16_SSCALED";
    case 88: return "VK_FORMAT_R16G16B16_UINT";
    case 89: return "VK_FORMAT_R16G16B16_SINT";
    case 90: return "VK_FORMAT_R16G16B16_SFLOAT";
    case 91: return "VK_FORMAT_R16G16B16A16_UNORM";
    case 92: return "VK_FORMAT_R16G16B16A16_SNORM";
    case 93: return "VK_FORMAT_R16G16B16A16_USCALED";
    case 94: return "VK_FORMAT_R16G16B16A16_SSCALED";
    case 95: return "VK_FORMAT_R16G16B16A16_UINT";
    case 96: return "VK_FORMAT_R16G16B16A16_SINT";
    case 97: return "VK_FORMAT_R16G16B16A16_SFLOAT";
    case 98: return "VK_FORMAT_R32_UINT";
    case 99: return "VK_FORMAT_R32_SINT";
    case 100: return "VK_FORMAT_R32_SFLOAT";
    case 101: return "VK_FORMAT_R32G32_UINT";
    case 102: return "VK_FORMAT_R32G32_SINT";
    case 103: return "VK_FORMAT_R32G32_SFLOAT";
    case 104: return "VK_FORMAT_R32G32B32_UINT";
    case 105: return "VK_FORMAT_R32G32B32_SINT";
    case 106: return "VK_FORMAT_R32G32B32_SFLOAT";
    case 107: return "VK_FORMAT_R32G32B32A32_UINT";
    case 108: return "VK_FORMAT_R32G32B32A32_SINT";
    case 109: return "VK_FORMAT_R32G32B32A32_SFLOAT";
    case 110: return "VK_FORMAT_R64_UINT";
    case 111: return "VK_FORMAT_R64_SINT";
    case 112: return "VK_FORMAT_R64_SFLOAT";
    case 113: return "VK_FORMAT_R64G64_UINT";
    case 114: return "VK_FORMAT_R64G64_SINT";
    case 115: return "VK_FORMAT_R64G64_SFLOAT";
    case 116: return "VK_FORMAT_R64G64B64_UINT";
    case 117: return "VK_FORMAT_R64G64B64_SINT";
    case 118: return "VK_FORMAT_R64G64B64_SFLOAT";
    case 119: return "VK_FORMAT_R64G64B64A64_UINT";
    case 120: return "VK_FORMAT_R64G64B64A64_SINT";
    case 121: return "VK_FORMAT_R64G64B64A64_SFLOAT";
    case 122: return "VK_FORMAT_B10G11R11_UFLOAT_PACK32";
    case 123: return "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32";
    case 124: return "VK_FORMAT_D16_UNORM";
    case 125: return "VK_FORMAT_X8_D24_UNORM_PACK32";
    case 126: return "VK_FORMAT_D32_SFLOAT";
    case 127: return "VK_FORMAT_S8_UINT";
    case 128: return "VK_FORMAT_D16_UNORM_S8_UINT";
    case 129: return "VK_FORMAT_D24_UNORM_S8_UINT";
    case 130: return "VK_FORMAT_D32_SFLOAT_S8_UINT";
    case 131: return "VK_FORMAT_BC1_RGB_UNORM_BLOCK";
    case 132: return "VK_FORMAT_BC1_RGB_SRGB_BLOCK";
    case 133: return "VK_FORMAT_BC1_RGBA_UNORM_BLOCK";
    case 134: return "VK_FORMAT_BC1_RGBA_SRGB_BLOCK";
    case 135: return "VK_FORMAT_BC2_UNORM_BLOCK";
    case 136: return "VK_FORMAT_BC2_SRGB_BLOCK";
    case 137: return "VK_FORMAT_BC3_UNORM_BLOCK";
    case 138: return "VK_FORMAT_BC3_SRGB_BLOCK";
    case 139: return "VK_FORMAT_BC4_UNORM_BLOCK";
    case 140: return "VK_FORMAT_BC4_SNORM_BLOCK";
    case 141: return "VK_FORMAT_BC5_UNORM_BLOCK";
    case 142: return "VK_FORMAT_BC5_SNORM_BLOCK";
    case 143: return "VK_FORMAT_BC6H_UFLOAT_BLOCK";
    case 144: return "VK_FORMAT_BC6H_SFLOAT_BLOCK";
    case 145: return "VK_FORMAT_BC7_UNORM_BLOCK";
    case 146: return "VK_FORMAT_BC7_SRGB_BLOCK";
    case 147: return "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
    case 148: return "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
    case 149: return "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
    case 150: return "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
    case 151: return "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
    case 152: return "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
    case 153: return "VK_FORMAT_EAC_R11_UNORM_BLOCK";
    case 154: return "VK_FORMAT_EAC_R11_SNORM_BLOCK";
    case 155: return "VK_FORMAT_EAC_R11G11_UNORM_BLOCK";
    case 156: return "VK_FORMAT_EAC_R11G11_SNORM_BLOCK";
    case 157: return "VK_FORMAT_ASTC_4x4_UNORM_BLOCK";
    case 158: return "VK_FORMAT_ASTC_4x4_SRGB_BLOCK";
    case 159: return "VK_FORMAT_ASTC_5x4_UNORM_BLOCK";
    case 160: return "VK_FORMAT_ASTC_5x4_SRGB_BLOCK";
    case 161: return "VK_FORMAT_ASTC_5x5_UNORM_BLOCK";
    case 162: return "VK_FORMAT_ASTC_5x5_SRGB_BLOCK";
    case 163: return "VK_FORMAT_ASTC_6x5_UNORM_BLOCK";
    case 164: return "VK_FORMAT_ASTC_6x5_SRGB_BLOCK";
    case 165: return "VK_FORMAT_ASTC_6x6_UNORM_BLOCK";
    case 166: return "VK_FORMAT_ASTC_6x6_SRGB_BLOCK";
    case 167: return "VK_FORMAT_ASTC_8x5_UNORM_BLOCK";
    case 168: return "VK_FORMAT_ASTC_8x5_SRGB_BLOCK";
    case 169: return "VK_FORMAT_ASTC_8x6_UNORM_BLOCK";
    case 170: return "VK_FORMAT_ASTC_8x6_SRGB_BLOCK";
    case 171: return "VK_FORMAT_ASTC_8x8_UNORM_BLOCK";
    case 172: return "VK_FORMAT_ASTC_8x8_SRGB_BLOCK";
    case 173: return "VK_FORMAT_ASTC_10x5_UNORM_BLOCK";
    case 174: return "VK_FORMAT_ASTC_10x5_SRGB_BLOCK";
    case 175: return "VK_FORMAT_ASTC_10x6_UNORM_BLOCK";
    case 176: return "VK_FORMAT_ASTC_10x6_SRGB_BLOCK";
    case 177: return "VK_FORMAT_ASTC_10x8_UNORM_BLOCK";
    case 178: return "VK_FORMAT_ASTC_10x8_SRGB_BLOCK";
    case 179: return "VK_FORMAT_ASTC_10x10_UNORM_BLOCK";
    case 180: return "VK_FORMAT_ASTC_10x10_SRGB_BLOCK";
    case 181: return "VK_FORMAT_ASTC_12x10_UNORM_BLOCK";
    case 182: return "VK_FORMAT_ASTC_12x10_SRGB_BLOCK";
    case 183: return "VK_FORMAT_ASTC_12x12_UNORM_BLOCK";
    case 184: return "VK_FORMAT_ASTC_12x12_SRGB_BLOCK";
    case 1000156000: return "VK_FORMAT_G8B8G8R8_422_UNORM";
    case 1000156001: return "VK_FORMAT_B8G8R8G8_422_UNORM";
    case 1000156002: return "VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM";
    case 1000156003: return "VK_FORMAT_G8_B8R8_2PLANE_420_UNORM";
    case 1000156004: return "VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM";
    case 1000156005: return "VK_FORMAT_G8_B8R8_2PLANE_422_UNORM";
    case 1000156006: return "VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM";
    case 1000156007: return "VK_FORMAT_R10X6_UNORM_PACK16";
    case 1000156008: return "VK_FORMAT_R10X6G10X6_UNORM_2PACK16";
    case 1000156009: return "VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16";
    case 1000156010: return "VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16";
    case 1000156011: return "VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16";
    case 1000156012: return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16";
    case 1000156013: return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16";
    case 1000156014: return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16";
    case 1000156015: return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16";
    case 1000156016: return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16";
    case 1000156017: return "VK_FORMAT_R12X4_UNORM_PACK16";
    case 1000156018: return "VK_FORMAT_R12X4G12X4_UNORM_2PACK16";
    case 1000156019: return "VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16";
    case 1000156020: return "VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16";
    case 1000156021: return "VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16";
    case 1000156022: return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16";
    case 1000156023: return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16";
    case 1000156024: return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16";
    case 1000156025: return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16";
    case 1000156026: return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16";
    case 1000156027: return "VK_FORMAT_G16B16G16R16_422_UNORM";
    case 1000156028: return "VK_FORMAT_B16G16R16G16_422_UNORM";
    case 1000156029: return "VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM";
    case 1000156030: return "VK_FORMAT_G16_B16R16_2PLANE_420_UNORM";
    case 1000156031: return "VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM";
    case 1000156032: return "VK_FORMAT_G16_B16R16_2PLANE_422_UNORM";
    case 1000156033: return "VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM";
    case 1000054000: return "VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG";
    case 1000054001: return "VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG";
    case 1000054002: return "VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG";
    case 1000054003: return "VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG";
    case 1000054004: return "VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG";
    case 1000054005: return "VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG";
    case 1000054006: return "VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG";
    case 1000054007: return "VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG";
    case 1000066000: return "VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT";
    case 1000066001: return "VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT";
    case 1000066002: return "VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT";
    case 1000066003: return "VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT";
    case 1000066004: return "VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT";
    case 1000066005: return "VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT";
    case 1000066006: return "VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT";
    case 1000066007: return "VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT";
    case 1000066008: return "VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT";
    case 1000066009: return "VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT";
    case 1000066010: return "VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT";
    case 1000066011: return "VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT";
    case 1000066012: return "VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT";
    case 1000066013: return "VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT";
    case 1000288000: return "VK_FORMAT_ASTC_3x3x3_UNORM_BLOCK_EXT";
    case 1000288001: return "VK_FORMAT_ASTC_3x3x3_SRGB_BLOCK_EXT";
    case 1000288002: return "VK_FORMAT_ASTC_3x3x3_SFLOAT_BLOCK_EXT";
    case 1000288003: return "VK_FORMAT_ASTC_4x3x3_UNORM_BLOCK_EXT";
    case 1000288004: return "VK_FORMAT_ASTC_4x3x3_SRGB_BLOCK_EXT";
    case 1000288005: return "VK_FORMAT_ASTC_4x3x3_SFLOAT_BLOCK_EXT";
    case 1000288006: return "VK_FORMAT_ASTC_4x4x3_UNORM_BLOCK_EXT";
    case 1000288007: return "VK_FORMAT_ASTC_4x4x3_SRGB_BLOCK_EXT";
    case 1000288008: return "VK_FORMAT_ASTC_4x4x3_SFLOAT_BLOCK_EXT";
    case 1000288009: return "VK_FORMAT_ASTC_4x4x4_UNORM_BLOCK_EXT";
    case 1000288010: return "VK_FORMAT_ASTC_4x4x4_SRGB_BLOCK_EXT";
    case 1000288011: return "VK_FORMAT_ASTC_4x4x4_SFLOAT_BLOCK_EXT";
    case 1000288012: return "VK_FORMAT_ASTC_5x4x4_UNORM_BLOCK_EXT";
    case 1000288013: return "VK_FORMAT_ASTC_5x4x4_SRGB_BLOCK_EXT";
    case 1000288014: return "VK_FORMAT_ASTC_5x4x4_SFLOAT_BLOCK_EXT";
    case 1000288015: return "VK_FORMAT_ASTC_5x5x4_UNORM_BLOCK_EXT";
    case 1000288016: return "VK_FORMAT_ASTC_5x5x4_SRGB_BLOCK_EXT";
    case 1000288017: return "VK_FORMAT_ASTC_5x5x4_SFLOAT_BLOCK_EXT";
    case 1000288018: return "VK_FORMAT_ASTC_5x5x5_UNORM_BLOCK_EXT";
    case 1000288019: return "VK_FORMAT_ASTC_5x5x5_SRGB_BLOCK_EXT";
    case 1000288020: return "VK_FORMAT_ASTC_5x5x5_SFLOAT_BLOCK_EXT";
    case 1000288021: return "VK_FORMAT_ASTC_6x5x5_UNORM_BLOCK_EXT";
    case 1000288022: return "VK_FORMAT_ASTC_6x5x5_SRGB_BLOCK_EXT";
    case 1000288023: return "VK_FORMAT_ASTC_6x5x5_SFLOAT_BLOCK_EXT";
    case 1000288024: return "VK_FORMAT_ASTC_6x6x5_UNORM_BLOCK_EXT";
    case 1000288025: return "VK_FORMAT_ASTC_6x6x5_SRGB_BLOCK_EXT";
    case 1000288026: return "VK_FORMAT_ASTC_6x6x5_SFLOAT_BLOCK_EXT";
    case 1000288027: return "VK_FORMAT_ASTC_6x6x6_UNORM_BLOCK_EXT";
    case 1000288028: return "VK_FORMAT_ASTC_6x6x6_SRGB_BLOCK_EXT";
    case 1000288029: return "VK_FORMAT_ASTC_6x6x6_SFLOAT_BLOCK_EXT";
    case 1000330000: return "VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT";
    case 1000330001: return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT";
    case 1000330002: return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT";
    case 1000330003: return "VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT";
    case 1000340000: return "VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT";
    case 1000340001: return "VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT";
   }
   return NULL;
}
void print_VkFormat(const VkFormat* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFormat_map(*obj), commaNeeded ? "," : "");
}

static const char* VkFormatFeatureFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT";
    case (1 << 1): return "VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT";
    case (1 << 2): return "VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT";
    case (1 << 3): return "VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT";
    case (1 << 4): return "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT";
    case (1 << 5): return "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
    case (1 << 6): return "VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT";
    case (1 << 7): return "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT";
    case (1 << 8): return "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT";
    case (1 << 9): return "VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT";
    case (1 << 10): return "VK_FORMAT_FEATURE_BLIT_SRC_BIT";
    case (1 << 11): return "VK_FORMAT_FEATURE_BLIT_DST_BIT";
    case (1 << 12): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
    case (1 << 14): return "VK_FORMAT_FEATURE_TRANSFER_SRC_BIT";
    case (1 << 15): return "VK_FORMAT_FEATURE_TRANSFER_DST_BIT";
    case (1 << 17): return "VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT";
    case (1 << 18): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
    case (1 << 19): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
    case (1 << 20): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
    case (1 << 21): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
    case (1 << 22): return "VK_FORMAT_FEATURE_DISJOINT_BIT";
    case (1 << 23): return "VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT";
    case (1 << 16): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
    case (1 << 13): return "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG";
    case (1 << 25): return "VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR";
    case (1 << 26): return "VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR";
    case (1 << 29): return "VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
    case (1 << 24): return "VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT";
    case (1 << 30): return "VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case (1 << 27): return "VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR";
    case (1 << 28): return "VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR";
   }
   return NULL;
}
void print_VkFormatFeatureFlagBits(const VkFormatFeatureFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFormatFeatureFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_IMAGE_CREATE_SPARSE_BINDING_BIT";
    case (1 << 1): return "VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT";
    case (1 << 2): return "VK_IMAGE_CREATE_SPARSE_ALIASED_BIT";
    case (1 << 3): return "VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT";
    case (1 << 4): return "VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT";
    case (1 << 10): return "VK_IMAGE_CREATE_ALIAS_BIT";
    case (1 << 6): return "VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT";
    case (1 << 5): return "VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT";
    case (1 << 7): return "VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT";
    case (1 << 8): return "VK_IMAGE_CREATE_EXTENDED_USAGE_BIT";
    case (1 << 11): return "VK_IMAGE_CREATE_PROTECTED_BIT";
    case (1 << 9): return "VK_IMAGE_CREATE_DISJOINT_BIT";
    case (1 << 13): return "VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV";
    case (1 << 12): return "VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT";
    case (1 << 14): return "VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT";
    case (1 << 16): return "VK_IMAGE_CREATE_RESERVED_16_BIT_AMD";
    case (1 << 17): return "VK_IMAGE_CREATE_RESERVED_394_BIT_EXT";
    case (1 << 15): return "VK_IMAGE_CREATE_RESERVED_426_BIT_QCOM";
   }
   return NULL;
}
void print_VkImageCreateFlagBits(const VkImageCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSampleCountFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SAMPLE_COUNT_1_BIT";
    case (1 << 1): return "VK_SAMPLE_COUNT_2_BIT";
    case (1 << 2): return "VK_SAMPLE_COUNT_4_BIT";
    case (1 << 3): return "VK_SAMPLE_COUNT_8_BIT";
    case (1 << 4): return "VK_SAMPLE_COUNT_16_BIT";
    case (1 << 5): return "VK_SAMPLE_COUNT_32_BIT";
    case (1 << 6): return "VK_SAMPLE_COUNT_64_BIT";
   }
   return NULL;
}
void print_VkSampleCountFlagBits(const VkSampleCountFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSampleCountFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageTiling_map(int o) {
switch (o) {
    case 0: return "VK_IMAGE_TILING_OPTIMAL";
    case 1: return "VK_IMAGE_TILING_LINEAR";
    case 1000158000: return "VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT";
   }
   return NULL;
}
void print_VkImageTiling(const VkImageTiling* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageTiling_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageType_map(int o) {
switch (o) {
    case 0: return "VK_IMAGE_TYPE_1D";
    case 1: return "VK_IMAGE_TYPE_2D";
    case 2: return "VK_IMAGE_TYPE_3D";
   }
   return NULL;
}
void print_VkImageType(const VkImageType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageUsageFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_IMAGE_USAGE_TRANSFER_SRC_BIT";
    case (1 << 1): return "VK_IMAGE_USAGE_TRANSFER_DST_BIT";
    case (1 << 2): return "VK_IMAGE_USAGE_SAMPLED_BIT";
    case (1 << 3): return "VK_IMAGE_USAGE_STORAGE_BIT";
    case (1 << 4): return "VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT";
    case (1 << 5): return "VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT";
    case (1 << 6): return "VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT";
    case (1 << 7): return "VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT";
    case (1 << 10): return "VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR";
    case (1 << 11): return "VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR";
    case (1 << 12): return "VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR";
    case (1 << 16): return "VK_IMAGE_USAGE_RESERVED_16_BIT_QCOM";
    case (1 << 17): return "VK_IMAGE_USAGE_RESERVED_17_BIT_QCOM";
    case (1 << 9): return "VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT";
    case (1 << 8): return "VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case (1 << 13): return "VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR";
    case (1 << 14): return "VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR";
    case (1 << 15): return "VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR";
    case (1 << 19): return "VK_IMAGE_USAGE_RESERVED_19_BIT_EXT";
    case (1 << 18): return "VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI";
   }
   return NULL;
}
void print_VkImageUsageFlagBits(const VkImageUsageFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageUsageFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkMemoryHeapFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_MEMORY_HEAP_DEVICE_LOCAL_BIT";
    case (1 << 1): return "VK_MEMORY_HEAP_MULTI_INSTANCE_BIT";
    case (1 << 2): return "VK_MEMORY_HEAP_SEU_SAFE_BIT";
   }
   return NULL;
}
void print_VkMemoryHeapFlagBits(const VkMemoryHeapFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkMemoryHeapFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkMemoryPropertyFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT";
    case (1 << 1): return "VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT";
    case (1 << 2): return "VK_MEMORY_PROPERTY_HOST_COHERENT_BIT";
    case (1 << 3): return "VK_MEMORY_PROPERTY_HOST_CACHED_BIT";
    case (1 << 4): return "VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT";
    case (1 << 5): return "VK_MEMORY_PROPERTY_PROTECTED_BIT";
    case (1 << 6): return "VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD";
    case (1 << 7): return "VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD";
    case (1 << 8): return "VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV";
   }
   return NULL;
}
void print_VkMemoryPropertyFlagBits(const VkMemoryPropertyFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkMemoryPropertyFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPhysicalDeviceType_map(int o) {
switch (o) {
    case 0: return "VK_PHYSICAL_DEVICE_TYPE_OTHER";
    case 1: return "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
    case 2: return "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
    case 3: return "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
    case 4: return "VK_PHYSICAL_DEVICE_TYPE_CPU";
   }
   return NULL;
}
void print_VkPhysicalDeviceType(const VkPhysicalDeviceType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPhysicalDeviceType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkQueueFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_QUEUE_GRAPHICS_BIT";
    case (1 << 1): return "VK_QUEUE_COMPUTE_BIT";
    case (1 << 2): return "VK_QUEUE_TRANSFER_BIT";
    case (1 << 4): return "VK_QUEUE_PROTECTED_BIT";
    case (1 << 5): return "VK_QUEUE_VIDEO_DECODE_BIT_KHR";
    case (1 << 6): return "VK_QUEUE_VIDEO_ENCODE_BIT_KHR";
   }
   return NULL;
}
void print_VkQueueFlagBits(const VkQueueFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkQueueFlagBits_map(*obj), commaNeeded ? "," : "");
}

#ifdef VK_VERSION_1_1
static const char* VkDeviceQueueCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT";
   }
   return NULL;
}
void print_VkDeviceQueueCreateFlagBits(const VkDeviceQueueCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDeviceQueueCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
static const char* VkPipelineStageFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT";
    case (1 << 1): return "VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT";
    case (1 << 2): return "VK_PIPELINE_STAGE_VERTEX_INPUT_BIT";
    case (1 << 3): return "VK_PIPELINE_STAGE_VERTEX_SHADER_BIT";
    case (1 << 4): return "VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT";
    case (1 << 5): return "VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT";
    case (1 << 6): return "VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT";
    case (1 << 7): return "VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT";
    case (1 << 8): return "VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT";
    case (1 << 9): return "VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT";
    case (1 << 10): return "VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT";
    case (1 << 11): return "VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT";
    case (1 << 12): return "VK_PIPELINE_STAGE_TRANSFER_BIT";
    case (1 << 13): return "VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT";
    case (1 << 14): return "VK_PIPELINE_STAGE_HOST_BIT";
    case (1 << 15): return "VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT";
    case (1 << 16): return "VK_PIPELINE_STAGE_ALL_COMMANDS_BIT";
    case (1 << 24): return "VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT";
    case (1 << 18): return "VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT";
    case (1 << 25): return "VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
    case (1 << 21): return "VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR";
    case (1 << 19): return "VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV";
    case (1 << 20): return "VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV";
    case (1 << 23): return "VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
    case (1 << 22): return "VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case (1 << 17): return "VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV";
    case 0: return "VK_PIPELINE_STAGE_NONE_KHR";
   }
   return NULL;
}
void print_VkPipelineStageFlagBits(const VkPipelineStageFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineStageFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkFenceCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_FENCE_CREATE_SIGNALED_BIT";
   }
   return NULL;
}
void print_VkFenceCreateFlagBits(const VkFenceCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFenceCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkEventCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EVENT_CREATE_DEVICE_ONLY_BIT_KHR";
   }
   return NULL;
}
void print_VkEventCreateFlagBits(const VkEventCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkEventCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkQueryPipelineStatisticFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT";
    case (1 << 1): return "VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT";
    case (1 << 2): return "VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT";
    case (1 << 3): return "VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT";
    case (1 << 4): return "VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT";
    case (1 << 5): return "VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT";
    case (1 << 6): return "VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT";
    case (1 << 7): return "VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT";
    case (1 << 8): return "VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT";
    case (1 << 9): return "VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT";
    case (1 << 10): return "VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT";
   }
   return NULL;
}
void print_VkQueryPipelineStatisticFlagBits(const VkQueryPipelineStatisticFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkQueryPipelineStatisticFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkQueryType_map(int o) {
switch (o) {
    case 0: return "VK_QUERY_TYPE_OCCLUSION";
    case 1: return "VK_QUERY_TYPE_PIPELINE_STATISTICS";
    case 2: return "VK_QUERY_TYPE_TIMESTAMP";
    case 1000023000: return "VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR";
    case 1000028004: return "VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT";
    case 1000116000: return "VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR";
    case 1000150000: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR";
    case 1000150001: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR";
    case 1000165000: return "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV";
    case 1000210000: return "VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL";
    case 1000299000: return "VK_QUERY_TYPE_VIDEO_ENCODE_BITSTREAM_BUFFER_RANGE_KHR";
   }
   return NULL;
}
void print_VkQueryType(const VkQueryType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkQueryType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkQueryResultFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_QUERY_RESULT_64_BIT";
    case (1 << 1): return "VK_QUERY_RESULT_WAIT_BIT";
    case (1 << 2): return "VK_QUERY_RESULT_WITH_AVAILABILITY_BIT";
    case (1 << 3): return "VK_QUERY_RESULT_PARTIAL_BIT";
    case (1 << 4): return "VK_QUERY_RESULT_WITH_STATUS_BIT_KHR";
   }
   return NULL;
}
void print_VkQueryResultFlagBits(const VkQueryResultFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkQueryResultFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkBufferCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_BUFFER_CREATE_SPARSE_BINDING_BIT";
    case (1 << 1): return "VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT";
    case (1 << 2): return "VK_BUFFER_CREATE_SPARSE_ALIASED_BIT";
    case (1 << 3): return "VK_BUFFER_CREATE_PROTECTED_BIT";
    case (1 << 4): return "VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT";
    case (1 << 5): return "VK_BUFFER_CREATE_RESERVED_5_BIT_AMD";
   }
   return NULL;
}
void print_VkBufferCreateFlagBits(const VkBufferCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkBufferCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkBufferUsageFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_BUFFER_USAGE_TRANSFER_SRC_BIT";
    case (1 << 1): return "VK_BUFFER_USAGE_TRANSFER_DST_BIT";
    case (1 << 2): return "VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT";
    case (1 << 3): return "VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT";
    case (1 << 4): return "VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT";
    case (1 << 5): return "VK_BUFFER_USAGE_STORAGE_BUFFER_BIT";
    case (1 << 6): return "VK_BUFFER_USAGE_INDEX_BUFFER_BIT";
    case (1 << 7): return "VK_BUFFER_USAGE_VERTEX_BUFFER_BIT";
    case (1 << 8): return "VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT";
    case (1 << 17): return "VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT";
    case (1 << 13): return "VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR";
    case (1 << 14): return "VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR";
    case (1 << 11): return "VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT";
    case (1 << 12): return "VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT";
    case (1 << 9): return "VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT";
    case (1 << 19): return "VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR";
    case (1 << 20): return "VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR";
    case (1 << 10): return "VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR";
    case (1 << 18): return "VK_BUFFER_USAGE_RESERVED_18_BIT_QCOM";
    case (1 << 15): return "VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR";
    case (1 << 16): return "VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR";
    case (1 << 21): return "VK_BUFFER_USAGE_RESERVED_21_BIT_AMD";
    case (1 << 22): return "VK_BUFFER_USAGE_RESERVED_22_BIT_AMD";
   }
   return NULL;
}
void print_VkBufferUsageFlagBits(const VkBufferUsageFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkBufferUsageFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSharingMode_map(int o) {
switch (o) {
    case 0: return "VK_SHARING_MODE_EXCLUSIVE";
    case 1: return "VK_SHARING_MODE_CONCURRENT";
   }
   return NULL;
}
void print_VkSharingMode(const VkSharingMode* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSharingMode_map(*obj), commaNeeded ? "," : "");
}

static const char* VkComponentSwizzle_map(int o) {
switch (o) {
    case 0: return "VK_COMPONENT_SWIZZLE_IDENTITY";
    case 1: return "VK_COMPONENT_SWIZZLE_ZERO";
    case 2: return "VK_COMPONENT_SWIZZLE_ONE";
    case 3: return "VK_COMPONENT_SWIZZLE_R";
    case 4: return "VK_COMPONENT_SWIZZLE_G";
    case 5: return "VK_COMPONENT_SWIZZLE_B";
    case 6: return "VK_COMPONENT_SWIZZLE_A";
   }
   return NULL;
}
void print_VkComponentSwizzle(const VkComponentSwizzle* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkComponentSwizzle_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageViewCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT";
    case (1 << 1): return "VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT";
   }
   return NULL;
}
void print_VkImageViewCreateFlagBits(const VkImageViewCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageViewCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkImageViewType_map(int o) {
switch (o) {
    case 0: return "VK_IMAGE_VIEW_TYPE_1D";
    case 1: return "VK_IMAGE_VIEW_TYPE_2D";
    case 2: return "VK_IMAGE_VIEW_TYPE_3D";
    case 3: return "VK_IMAGE_VIEW_TYPE_CUBE";
    case 4: return "VK_IMAGE_VIEW_TYPE_1D_ARRAY";
    case 5: return "VK_IMAGE_VIEW_TYPE_2D_ARRAY";
    case 6: return "VK_IMAGE_VIEW_TYPE_CUBE_ARRAY";
   }
   return NULL;
}
void print_VkImageViewType(const VkImageViewType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkImageViewType_map(*obj), commaNeeded ? "," : "");
}

#ifdef VKSC_VERSION_1_0
static const char* VkPipelineCacheCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 2): return "VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT";
    case (1 << 1): return "VK_PIPELINE_CACHE_CREATE_RESERVED_1_BIT_EXT";
    case (1 << 0): return "VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT";
   }
   return NULL;
}
void print_VkPipelineCacheCreateFlagBits(const VkPipelineCacheCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineCacheCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
static const char* VkBlendFactor_map(int o) {
switch (o) {
    case 0: return "VK_BLEND_FACTOR_ZERO";
    case 1: return "VK_BLEND_FACTOR_ONE";
    case 2: return "VK_BLEND_FACTOR_SRC_COLOR";
    case 3: return "VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR";
    case 4: return "VK_BLEND_FACTOR_DST_COLOR";
    case 5: return "VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR";
    case 6: return "VK_BLEND_FACTOR_SRC_ALPHA";
    case 7: return "VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA";
    case 8: return "VK_BLEND_FACTOR_DST_ALPHA";
    case 9: return "VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA";
    case 10: return "VK_BLEND_FACTOR_CONSTANT_COLOR";
    case 11: return "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR";
    case 12: return "VK_BLEND_FACTOR_CONSTANT_ALPHA";
    case 13: return "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA";
    case 14: return "VK_BLEND_FACTOR_SRC_ALPHA_SATURATE";
    case 15: return "VK_BLEND_FACTOR_SRC1_COLOR";
    case 16: return "VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR";
    case 17: return "VK_BLEND_FACTOR_SRC1_ALPHA";
    case 18: return "VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA";
   }
   return NULL;
}
void print_VkBlendFactor(const VkBlendFactor* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkBlendFactor_map(*obj), commaNeeded ? "," : "");
}

static const char* VkBlendOp_map(int o) {
switch (o) {
    case 0: return "VK_BLEND_OP_ADD";
    case 1: return "VK_BLEND_OP_SUBTRACT";
    case 2: return "VK_BLEND_OP_REVERSE_SUBTRACT";
    case 3: return "VK_BLEND_OP_MIN";
    case 4: return "VK_BLEND_OP_MAX";
    case 1000148000: return "VK_BLEND_OP_ZERO_EXT";
    case 1000148001: return "VK_BLEND_OP_SRC_EXT";
    case 1000148002: return "VK_BLEND_OP_DST_EXT";
    case 1000148003: return "VK_BLEND_OP_SRC_OVER_EXT";
    case 1000148004: return "VK_BLEND_OP_DST_OVER_EXT";
    case 1000148005: return "VK_BLEND_OP_SRC_IN_EXT";
    case 1000148006: return "VK_BLEND_OP_DST_IN_EXT";
    case 1000148007: return "VK_BLEND_OP_SRC_OUT_EXT";
    case 1000148008: return "VK_BLEND_OP_DST_OUT_EXT";
    case 1000148009: return "VK_BLEND_OP_SRC_ATOP_EXT";
    case 1000148010: return "VK_BLEND_OP_DST_ATOP_EXT";
    case 1000148011: return "VK_BLEND_OP_XOR_EXT";
    case 1000148012: return "VK_BLEND_OP_MULTIPLY_EXT";
    case 1000148013: return "VK_BLEND_OP_SCREEN_EXT";
    case 1000148014: return "VK_BLEND_OP_OVERLAY_EXT";
    case 1000148015: return "VK_BLEND_OP_DARKEN_EXT";
    case 1000148016: return "VK_BLEND_OP_LIGHTEN_EXT";
    case 1000148017: return "VK_BLEND_OP_COLORDODGE_EXT";
    case 1000148018: return "VK_BLEND_OP_COLORBURN_EXT";
    case 1000148019: return "VK_BLEND_OP_HARDLIGHT_EXT";
    case 1000148020: return "VK_BLEND_OP_SOFTLIGHT_EXT";
    case 1000148021: return "VK_BLEND_OP_DIFFERENCE_EXT";
    case 1000148022: return "VK_BLEND_OP_EXCLUSION_EXT";
    case 1000148023: return "VK_BLEND_OP_INVERT_EXT";
    case 1000148024: return "VK_BLEND_OP_INVERT_RGB_EXT";
    case 1000148025: return "VK_BLEND_OP_LINEARDODGE_EXT";
    case 1000148026: return "VK_BLEND_OP_LINEARBURN_EXT";
    case 1000148027: return "VK_BLEND_OP_VIVIDLIGHT_EXT";
    case 1000148028: return "VK_BLEND_OP_LINEARLIGHT_EXT";
    case 1000148029: return "VK_BLEND_OP_PINLIGHT_EXT";
    case 1000148030: return "VK_BLEND_OP_HARDMIX_EXT";
    case 1000148031: return "VK_BLEND_OP_HSL_HUE_EXT";
    case 1000148032: return "VK_BLEND_OP_HSL_SATURATION_EXT";
    case 1000148033: return "VK_BLEND_OP_HSL_COLOR_EXT";
    case 1000148034: return "VK_BLEND_OP_HSL_LUMINOSITY_EXT";
    case 1000148035: return "VK_BLEND_OP_PLUS_EXT";
    case 1000148036: return "VK_BLEND_OP_PLUS_CLAMPED_EXT";
    case 1000148037: return "VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT";
    case 1000148038: return "VK_BLEND_OP_PLUS_DARKER_EXT";
    case 1000148039: return "VK_BLEND_OP_MINUS_EXT";
    case 1000148040: return "VK_BLEND_OP_MINUS_CLAMPED_EXT";
    case 1000148041: return "VK_BLEND_OP_CONTRAST_EXT";
    case 1000148042: return "VK_BLEND_OP_INVERT_OVG_EXT";
    case 1000148043: return "VK_BLEND_OP_RED_EXT";
    case 1000148044: return "VK_BLEND_OP_GREEN_EXT";
    case 1000148045: return "VK_BLEND_OP_BLUE_EXT";
   }
   return NULL;
}
void print_VkBlendOp(const VkBlendOp* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkBlendOp_map(*obj), commaNeeded ? "," : "");
}

static const char* VkColorComponentFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_COLOR_COMPONENT_R_BIT";
    case (1 << 1): return "VK_COLOR_COMPONENT_G_BIT";
    case (1 << 2): return "VK_COLOR_COMPONENT_B_BIT";
    case (1 << 3): return "VK_COLOR_COMPONENT_A_BIT";
   }
   return NULL;
}
void print_VkColorComponentFlagBits(const VkColorComponentFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkColorComponentFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCompareOp_map(int o) {
switch (o) {
    case 0: return "VK_COMPARE_OP_NEVER";
    case 1: return "VK_COMPARE_OP_LESS";
    case 2: return "VK_COMPARE_OP_EQUAL";
    case 3: return "VK_COMPARE_OP_LESS_OR_EQUAL";
    case 4: return "VK_COMPARE_OP_GREATER";
    case 5: return "VK_COMPARE_OP_NOT_EQUAL";
    case 6: return "VK_COMPARE_OP_GREATER_OR_EQUAL";
    case 7: return "VK_COMPARE_OP_ALWAYS";
   }
   return NULL;
}
void print_VkCompareOp(const VkCompareOp* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCompareOp_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPipelineCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT";
    case (1 << 3): return "VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT";
    case (1 << 4): return "VK_PIPELINE_CREATE_DISPATCH_BASE_BIT";
    case (1 << 21): return "VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case (1 << 22): return "VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
    case (1 << 14): return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR";
    case (1 << 15): return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR";
    case (1 << 16): return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR";
    case (1 << 17): return "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR";
    case (1 << 12): return "VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR";
    case (1 << 13): return "VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR";
    case (1 << 19): return "VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR";
    case (1 << 5): return "VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV";
    case (1 << 6): return "VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR";
    case (1 << 7): return "VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR";
    case (1 << 18): return "VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV";
    case (1 << 11): return "VK_PIPELINE_CREATE_LIBRARY_BIT_KHR";
    case (1 << 8): return "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT";
    case (1 << 9): return "VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT";
    case (1 << 23): return "VK_PIPELINE_CREATE_RESERVED_23_BIT_AMD";
    case (1 << 10): return "VK_PIPELINE_CREATE_RESERVED_10_BIT_AMD";
    case (1 << 20): return "VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV";
   }
   return NULL;
}
void print_VkPipelineCreateFlagBits(const VkPipelineCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPipelineShaderStageCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 2): return "VK_PIPELINE_SHADER_STAGE_CREATE_RESERVED_2_BIT_NV";
    case (1 << 0): return "VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT";
    case (1 << 1): return "VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT";
    case (1 << 3): return "VK_PIPELINE_SHADER_STAGE_CREATE_RESERVED_3_BIT_KHR";
   }
   return NULL;
}
void print_VkPipelineShaderStageCreateFlagBits(const VkPipelineShaderStageCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineShaderStageCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkShaderStageFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SHADER_STAGE_VERTEX_BIT";
    case (1 << 1): return "VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT";
    case (1 << 2): return "VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT";
    case (1 << 3): return "VK_SHADER_STAGE_GEOMETRY_BIT";
    case (1 << 4): return "VK_SHADER_STAGE_FRAGMENT_BIT";
    case (1 << 5): return "VK_SHADER_STAGE_COMPUTE_BIT";
    case 0x0000001F: return "VK_SHADER_STAGE_ALL_GRAPHICS";
    case 0x7FFFFFFF: return "VK_SHADER_STAGE_ALL";
    case (1 << 8): return "VK_SHADER_STAGE_RAYGEN_BIT_KHR";
    case (1 << 9): return "VK_SHADER_STAGE_ANY_HIT_BIT_KHR";
    case (1 << 10): return "VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR";
    case (1 << 11): return "VK_SHADER_STAGE_MISS_BIT_KHR";
    case (1 << 12): return "VK_SHADER_STAGE_INTERSECTION_BIT_KHR";
    case (1 << 13): return "VK_SHADER_STAGE_CALLABLE_BIT_KHR";
    case (1 << 6): return "VK_SHADER_STAGE_TASK_BIT_NV";
    case (1 << 7): return "VK_SHADER_STAGE_MESH_BIT_NV";
    case (1 << 14): return "VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI";
   }
   return NULL;
}
void print_VkShaderStageFlagBits(const VkShaderStageFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkShaderStageFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCullModeFlagBits_map(int o) {
switch (o) {
    case 0: return "VK_CULL_MODE_NONE";
    case (1 << 0): return "VK_CULL_MODE_FRONT_BIT";
    case (1 << 1): return "VK_CULL_MODE_BACK_BIT";
    case 0x00000003: return "VK_CULL_MODE_FRONT_AND_BACK";
   }
   return NULL;
}
void print_VkCullModeFlagBits(const VkCullModeFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCullModeFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkDynamicState_map(int o) {
switch (o) {
    case 0: return "VK_DYNAMIC_STATE_VIEWPORT";
    case 1: return "VK_DYNAMIC_STATE_SCISSOR";
    case 2: return "VK_DYNAMIC_STATE_LINE_WIDTH";
    case 3: return "VK_DYNAMIC_STATE_DEPTH_BIAS";
    case 4: return "VK_DYNAMIC_STATE_BLEND_CONSTANTS";
    case 5: return "VK_DYNAMIC_STATE_DEPTH_BOUNDS";
    case 6: return "VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK";
    case 7: return "VK_DYNAMIC_STATE_STENCIL_WRITE_MASK";
    case 8: return "VK_DYNAMIC_STATE_STENCIL_REFERENCE";
    case 1000087000: return "VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV";
    case 1000099000: return "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT";
    case 1000143000: return "VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT";
    case 1000347000: return "VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR";
    case 1000164004: return "VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV";
    case 1000164006: return "VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV";
    case 1000205001: return "VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV";
    case 1000226000: return "VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR";
    case 1000259000: return "VK_DYNAMIC_STATE_LINE_STIPPLE_EXT";
    case 1000267000: return "VK_DYNAMIC_STATE_CULL_MODE_EXT";
    case 1000267001: return "VK_DYNAMIC_STATE_FRONT_FACE_EXT";
    case 1000267002: return "VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY_EXT";
    case 1000267003: return "VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT_EXT";
    case 1000267004: return "VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT_EXT";
    case 1000267005: return "VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT";
    case 1000267006: return "VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE_EXT";
    case 1000267007: return "VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE_EXT";
    case 1000267008: return "VK_DYNAMIC_STATE_DEPTH_COMPARE_OP_EXT";
    case 1000267009: return "VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE_EXT";
    case 1000267010: return "VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE_EXT";
    case 1000267011: return "VK_DYNAMIC_STATE_STENCIL_OP_EXT";
    case 1000352000: return "VK_DYNAMIC_STATE_VERTEX_INPUT_EXT";
    case 1000377000: return "VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT";
    case 1000377001: return "VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE_EXT";
    case 1000377002: return "VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE_EXT";
    case 1000377003: return "VK_DYNAMIC_STATE_LOGIC_OP_EXT";
    case 1000377004: return "VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE_EXT";
    case 1000381000: return "VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT";
   }
   return NULL;
}
void print_VkDynamicState(const VkDynamicState* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDynamicState_map(*obj), commaNeeded ? "," : "");
}

static const char* VkFrontFace_map(int o) {
switch (o) {
    case 0: return "VK_FRONT_FACE_COUNTER_CLOCKWISE";
    case 1: return "VK_FRONT_FACE_CLOCKWISE";
   }
   return NULL;
}
void print_VkFrontFace(const VkFrontFace* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFrontFace_map(*obj), commaNeeded ? "," : "");
}

static const char* VkVertexInputRate_map(int o) {
switch (o) {
    case 0: return "VK_VERTEX_INPUT_RATE_VERTEX";
    case 1: return "VK_VERTEX_INPUT_RATE_INSTANCE";
   }
   return NULL;
}
void print_VkVertexInputRate(const VkVertexInputRate* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkVertexInputRate_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPrimitiveTopology_map(int o) {
switch (o) {
    case 0: return "VK_PRIMITIVE_TOPOLOGY_POINT_LIST";
    case 1: return "VK_PRIMITIVE_TOPOLOGY_LINE_LIST";
    case 2: return "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP";
    case 3: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST";
    case 4: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP";
    case 5: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN";
    case 6: return "VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY";
    case 7: return "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY";
    case 8: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY";
    case 9: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY";
    case 10: return "VK_PRIMITIVE_TOPOLOGY_PATCH_LIST";
   }
   return NULL;
}
void print_VkPrimitiveTopology(const VkPrimitiveTopology* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPrimitiveTopology_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPolygonMode_map(int o) {
switch (o) {
    case 0: return "VK_POLYGON_MODE_FILL";
    case 1: return "VK_POLYGON_MODE_LINE";
    case 2: return "VK_POLYGON_MODE_POINT";
    case 1000153000: return "VK_POLYGON_MODE_FILL_RECTANGLE_NV";
   }
   return NULL;
}
void print_VkPolygonMode(const VkPolygonMode* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPolygonMode_map(*obj), commaNeeded ? "," : "");
}

static const char* VkStencilOp_map(int o) {
switch (o) {
    case 0: return "VK_STENCIL_OP_KEEP";
    case 1: return "VK_STENCIL_OP_ZERO";
    case 2: return "VK_STENCIL_OP_REPLACE";
    case 3: return "VK_STENCIL_OP_INCREMENT_AND_CLAMP";
    case 4: return "VK_STENCIL_OP_DECREMENT_AND_CLAMP";
    case 5: return "VK_STENCIL_OP_INVERT";
    case 6: return "VK_STENCIL_OP_INCREMENT_AND_WRAP";
    case 7: return "VK_STENCIL_OP_DECREMENT_AND_WRAP";
   }
   return NULL;
}
void print_VkStencilOp(const VkStencilOp* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkStencilOp_map(*obj), commaNeeded ? "," : "");
}

static const char* VkLogicOp_map(int o) {
switch (o) {
    case 0: return "VK_LOGIC_OP_CLEAR";
    case 1: return "VK_LOGIC_OP_AND";
    case 2: return "VK_LOGIC_OP_AND_REVERSE";
    case 3: return "VK_LOGIC_OP_COPY";
    case 4: return "VK_LOGIC_OP_AND_INVERTED";
    case 5: return "VK_LOGIC_OP_NO_OP";
    case 6: return "VK_LOGIC_OP_XOR";
    case 7: return "VK_LOGIC_OP_OR";
    case 8: return "VK_LOGIC_OP_NOR";
    case 9: return "VK_LOGIC_OP_EQUIVALENT";
    case 10: return "VK_LOGIC_OP_INVERT";
    case 11: return "VK_LOGIC_OP_OR_REVERSE";
    case 12: return "VK_LOGIC_OP_COPY_INVERTED";
    case 13: return "VK_LOGIC_OP_OR_INVERTED";
    case 14: return "VK_LOGIC_OP_NAND";
    case 15: return "VK_LOGIC_OP_SET";
   }
   return NULL;
}
void print_VkLogicOp(const VkLogicOp* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkLogicOp_map(*obj), commaNeeded ? "," : "");
}

static const char* VkBorderColor_map(int o) {
switch (o) {
    case 0: return "VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK";
    case 1: return "VK_BORDER_COLOR_INT_TRANSPARENT_BLACK";
    case 2: return "VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK";
    case 3: return "VK_BORDER_COLOR_INT_OPAQUE_BLACK";
    case 4: return "VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE";
    case 5: return "VK_BORDER_COLOR_INT_OPAQUE_WHITE";
    case 1000287003: return "VK_BORDER_COLOR_FLOAT_CUSTOM_EXT";
    case 1000287004: return "VK_BORDER_COLOR_INT_CUSTOM_EXT";
   }
   return NULL;
}
void print_VkBorderColor(const VkBorderColor* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkBorderColor_map(*obj), commaNeeded ? "," : "");
}

static const char* VkFilter_map(int o) {
switch (o) {
    case 0: return "VK_FILTER_NEAREST";
    case 1: return "VK_FILTER_LINEAR";
    case 1000015000: return "VK_FILTER_CUBIC_IMG";
   }
   return NULL;
}
void print_VkFilter(const VkFilter* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFilter_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSamplerAddressMode_map(int o) {
switch (o) {
    case 0: return "VK_SAMPLER_ADDRESS_MODE_REPEAT";
    case 1: return "VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT";
    case 2: return "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE";
    case 3: return "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER";
    case 4: return "VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE";
   }
   return NULL;
}
void print_VkSamplerAddressMode(const VkSamplerAddressMode* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSamplerAddressMode_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSamplerCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT";
    case (1 << 1): return "VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT";
    case (1 << 3): return "VK_SAMPLER_CREATE_RESERVED_3_BIT_AMD";
    case (1 << 2): return "VK_SAMPLER_CREATE_RESERVED_2_BIT_EXT";
   }
   return NULL;
}
void print_VkSamplerCreateFlagBits(const VkSamplerCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSamplerCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSamplerMipmapMode_map(int o) {
switch (o) {
    case 0: return "VK_SAMPLER_MIPMAP_MODE_NEAREST";
    case 1: return "VK_SAMPLER_MIPMAP_MODE_LINEAR";
   }
   return NULL;
}
void print_VkSamplerMipmapMode(const VkSamplerMipmapMode* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSamplerMipmapMode_map(*obj), commaNeeded ? "," : "");
}

static const char* VkDescriptorPoolCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT";
    case (1 << 1): return "VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT";
    case (1 << 2): return "VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_VALVE";
   }
   return NULL;
}
void print_VkDescriptorPoolCreateFlagBits(const VkDescriptorPoolCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDescriptorPoolCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkDescriptorType_map(int o) {
switch (o) {
    case 0: return "VK_DESCRIPTOR_TYPE_SAMPLER";
    case 1: return "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER";
    case 2: return "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE";
    case 3: return "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE";
    case 4: return "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER";
    case 5: return "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER";
    case 6: return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER";
    case 7: return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER";
    case 8: return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC";
    case 9: return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC";
    case 10: return "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT";
    case 1000138000: return "VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT";
    case 1000150000: return "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR";
    case 1000165000: return "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV";
    case 1000351000: return "VK_DESCRIPTOR_TYPE_MUTABLE_VALVE";
   }
   return NULL;
}
void print_VkDescriptorType(const VkDescriptorType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDescriptorType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkDescriptorSetLayoutCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 1): return "VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT";
    case (1 << 0): return "VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR";
    case (1 << 4): return "VK_DESCRIPTOR_SET_LAYOUT_CREATE_RESERVED_4_BIT_AMD";
    case (1 << 3): return "VK_DESCRIPTOR_SET_LAYOUT_CREATE_RESERVED_3_BIT_AMD";
    case (1 << 2): return "VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_VALVE";
   }
   return NULL;
}
void print_VkDescriptorSetLayoutCreateFlagBits(const VkDescriptorSetLayoutCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDescriptorSetLayoutCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkAttachmentDescriptionFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT";
   }
   return NULL;
}
void print_VkAttachmentDescriptionFlagBits(const VkAttachmentDescriptionFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkAttachmentDescriptionFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkAttachmentLoadOp_map(int o) {
switch (o) {
    case 0: return "VK_ATTACHMENT_LOAD_OP_LOAD";
    case 1: return "VK_ATTACHMENT_LOAD_OP_CLEAR";
    case 2: return "VK_ATTACHMENT_LOAD_OP_DONT_CARE";
    case 1000400000: return "VK_ATTACHMENT_LOAD_OP_NONE_EXT";
   }
   return NULL;
}
void print_VkAttachmentLoadOp(const VkAttachmentLoadOp* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkAttachmentLoadOp_map(*obj), commaNeeded ? "," : "");
}

static const char* VkAttachmentStoreOp_map(int o) {
switch (o) {
    case 0: return "VK_ATTACHMENT_STORE_OP_STORE";
    case 1: return "VK_ATTACHMENT_STORE_OP_DONT_CARE";
    case 1000301000: return "VK_ATTACHMENT_STORE_OP_NONE_KHR";
   }
   return NULL;
}
void print_VkAttachmentStoreOp(const VkAttachmentStoreOp* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkAttachmentStoreOp_map(*obj), commaNeeded ? "," : "");
}

static const char* VkDependencyFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DEPENDENCY_BY_REGION_BIT";
    case (1 << 2): return "VK_DEPENDENCY_DEVICE_GROUP_BIT";
    case (1 << 1): return "VK_DEPENDENCY_VIEW_LOCAL_BIT";
   }
   return NULL;
}
void print_VkDependencyFlagBits(const VkDependencyFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDependencyFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkFramebufferCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT";
   }
   return NULL;
}
void print_VkFramebufferCreateFlagBits(const VkFramebufferCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFramebufferCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkPipelineBindPoint_map(int o) {
switch (o) {
    case 0: return "VK_PIPELINE_BIND_POINT_GRAPHICS";
    case 1: return "VK_PIPELINE_BIND_POINT_COMPUTE";
    case 1000165000: return "VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR";
    case 1000369003: return "VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI";
   }
   return NULL;
}
void print_VkPipelineBindPoint(const VkPipelineBindPoint* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineBindPoint_map(*obj), commaNeeded ? "," : "");
}

static const char* VkRenderPassCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_RENDER_PASS_CREATE_RESERVED_0_BIT_KHR";
    case (1 << 1): return "VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM";
   }
   return NULL;
}
void print_VkRenderPassCreateFlagBits(const VkRenderPassCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkRenderPassCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSubpassDescriptionFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX";
    case (1 << 1): return "VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX";
    case (1 << 2): return "VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM";
    case (1 << 3): return "VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM";
    case (1 << 4): return "VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_ARM";
    case (1 << 5): return "VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_ARM";
    case (1 << 6): return "VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_ARM";
   }
   return NULL;
}
void print_VkSubpassDescriptionFlagBits(const VkSubpassDescriptionFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSubpassDescriptionFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCommandPoolCreateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_COMMAND_POOL_CREATE_TRANSIENT_BIT";
    case (1 << 1): return "VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT";
    case (1 << 2): return "VK_COMMAND_POOL_CREATE_PROTECTED_BIT";
   }
   return NULL;
}
void print_VkCommandPoolCreateFlagBits(const VkCommandPoolCreateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCommandPoolCreateFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCommandPoolResetFlagBits_map(int o) {
switch (o) {
    case (1 << 1): return "VK_COMMAND_POOL_RESET_RESERVED_1_BIT_COREAVI";
   }
   return NULL;
}
void print_VkCommandPoolResetFlagBits(const VkCommandPoolResetFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCommandPoolResetFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCommandBufferLevel_map(int o) {
switch (o) {
    case 0: return "VK_COMMAND_BUFFER_LEVEL_PRIMARY";
    case 1: return "VK_COMMAND_BUFFER_LEVEL_SECONDARY";
   }
   return NULL;
}
void print_VkCommandBufferLevel(const VkCommandBufferLevel* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCommandBufferLevel_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCommandBufferUsageFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT";
    case (1 << 1): return "VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT";
    case (1 << 2): return "VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT";
   }
   return NULL;
}
void print_VkCommandBufferUsageFlagBits(const VkCommandBufferUsageFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCommandBufferUsageFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkQueryControlFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_QUERY_CONTROL_PRECISE_BIT";
   }
   return NULL;
}
void print_VkQueryControlFlagBits(const VkQueryControlFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkQueryControlFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkCommandBufferResetFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT";
   }
   return NULL;
}
void print_VkCommandBufferResetFlagBits(const VkCommandBufferResetFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCommandBufferResetFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkIndexType_map(int o) {
switch (o) {
    case 0: return "VK_INDEX_TYPE_UINT16";
    case 1: return "VK_INDEX_TYPE_UINT32";
    case 1000165000: return "VK_INDEX_TYPE_NONE_KHR";
    case 1000265000: return "VK_INDEX_TYPE_UINT8_EXT";
   }
   return NULL;
}
void print_VkIndexType(const VkIndexType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkIndexType_map(*obj), commaNeeded ? "," : "");
}

static const char* VkStencilFaceFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_STENCIL_FACE_FRONT_BIT";
    case (1 << 1): return "VK_STENCIL_FACE_BACK_BIT";
    case 0x00000003: return "VK_STENCIL_FACE_FRONT_AND_BACK";
   }
   return NULL;
}
void print_VkStencilFaceFlagBits(const VkStencilFaceFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkStencilFaceFlagBits_map(*obj), commaNeeded ? "," : "");
}

static const char* VkSubpassContents_map(int o) {
switch (o) {
    case 0: return "VK_SUBPASS_CONTENTS_INLINE";
    case 1: return "VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS";
   }
   return NULL;
}
void print_VkSubpassContents(const VkSubpassContents* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSubpassContents_map(*obj), commaNeeded ? "," : "");
}

void print_VkAccessFlags(const VkAccessFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkAccessFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkAccessFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkImageAspectFlags(const VkImageAspectFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkImageAspectFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkImageAspectFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkFormatFeatureFlags(const VkFormatFeatureFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkFormatFeatureFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkFormatFeatureFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkImageCreateFlags(const VkImageCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkImageCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkImageCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkSampleCountFlags(const VkSampleCountFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSampleCountFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSampleCountFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkImageUsageFlags(const VkImageUsageFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkImageUsageFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkImageUsageFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkInstanceCreateFlags(const VkInstanceCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkMemoryHeapFlags(const VkMemoryHeapFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkMemoryHeapFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkMemoryHeapFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryPropertyFlags(const VkMemoryPropertyFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkMemoryPropertyFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkMemoryPropertyFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkQueueFlags(const VkQueueFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkQueueFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkQueueFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkDeviceCreateFlags(const VkDeviceCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkDeviceQueueCreateFlags(const VkDeviceQueueCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDeviceQueueCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDeviceQueueCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineStageFlags(const VkPipelineStageFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkPipelineStageFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkPipelineStageFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryMapFlags(const VkMemoryMapFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkFenceCreateFlags(const VkFenceCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkFenceCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkFenceCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkSemaphoreCreateFlags(const VkSemaphoreCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkEventCreateFlags(const VkEventCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkEventCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkEventCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkQueryPipelineStatisticFlags(const VkQueryPipelineStatisticFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkQueryPipelineStatisticFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkQueryPipelineStatisticFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkQueryPoolCreateFlags(const VkQueryPoolCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkQueryResultFlags(const VkQueryResultFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkQueryResultFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkQueryResultFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkBufferCreateFlags(const VkBufferCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkBufferCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkBufferCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkBufferUsageFlags(const VkBufferUsageFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkBufferUsageFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkBufferUsageFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkBufferViewCreateFlags(const VkBufferViewCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkImageViewCreateFlags(const VkImageViewCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkImageViewCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkImageViewCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineCacheCreateFlags(const VkPipelineCacheCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkPipelineCacheCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkPipelineCacheCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkColorComponentFlags(const VkColorComponentFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkColorComponentFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkColorComponentFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineCreateFlags(const VkPipelineCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkPipelineCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkPipelineCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineShaderStageCreateFlags(const VkPipelineShaderStageCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkPipelineShaderStageCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkPipelineShaderStageCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkCullModeFlags(const VkCullModeFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkCullModeFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkCullModeFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineVertexInputStateCreateFlags(const VkPipelineVertexInputStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineInputAssemblyStateCreateFlags(const VkPipelineInputAssemblyStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineTessellationStateCreateFlags(const VkPipelineTessellationStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineViewportStateCreateFlags(const VkPipelineViewportStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineRasterizationStateCreateFlags(const VkPipelineRasterizationStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineMultisampleStateCreateFlags(const VkPipelineMultisampleStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineDepthStencilStateCreateFlags(const VkPipelineDepthStencilStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineColorBlendStateCreateFlags(const VkPipelineColorBlendStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineDynamicStateCreateFlags(const VkPipelineDynamicStateCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkPipelineLayoutCreateFlags(const VkPipelineLayoutCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkShaderStageFlags(const VkShaderStageFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkShaderStageFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkShaderStageFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkSamplerCreateFlags(const VkSamplerCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSamplerCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSamplerCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorPoolCreateFlags(const VkDescriptorPoolCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDescriptorPoolCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDescriptorPoolCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorPoolResetFlags(const VkDescriptorPoolResetFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

void print_VkDescriptorSetLayoutCreateFlags(const VkDescriptorSetLayoutCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDescriptorSetLayoutCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDescriptorSetLayoutCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkAttachmentDescriptionFlags(const VkAttachmentDescriptionFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkAttachmentDescriptionFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkAttachmentDescriptionFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkDependencyFlags(const VkDependencyFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDependencyFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDependencyFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkFramebufferCreateFlags(const VkFramebufferCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkFramebufferCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkFramebufferCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkRenderPassCreateFlags(const VkRenderPassCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkRenderPassCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkRenderPassCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkSubpassDescriptionFlags(const VkSubpassDescriptionFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSubpassDescriptionFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSubpassDescriptionFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkCommandPoolCreateFlags(const VkCommandPoolCreateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkCommandPoolCreateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkCommandPoolCreateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkCommandPoolResetFlags(const VkCommandPoolResetFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkCommandPoolResetFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkCommandPoolResetFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkCommandBufferUsageFlags(const VkCommandBufferUsageFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkCommandBufferUsageFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkCommandBufferUsageFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkQueryControlFlags(const VkQueryControlFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkQueryControlFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkQueryControlFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkCommandBufferResetFlags(const VkCommandBufferResetFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkCommandBufferResetFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkCommandBufferResetFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkStencilFaceFlags(const VkStencilFaceFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkStencilFaceFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkStencilFaceFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

void print_VkExtent2D(const VkExtent2D * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->width, "width", 1);

     print_uint32_t(&obj->height, "height", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkExtent3D(const VkExtent3D * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->width, "width", 1);

     print_uint32_t(&obj->height, "height", 1);

     print_uint32_t(&obj->depth, "depth", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkOffset2D(const VkOffset2D * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_int32_t(&obj->x, "x", 1);

     print_int32_t(&obj->y, "y", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkOffset3D(const VkOffset3D * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_int32_t(&obj->x, "x", 1);

     print_int32_t(&obj->y, "y", 1);

     print_int32_t(&obj->z, "z", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkRect2D(const VkRect2D * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"offset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset2D(&obj->offset, "offset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->extent, "extent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBaseInStructure(const VkBaseInStructure * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBaseOutStructure(const VkBaseOutStructure * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBufferMemoryBarrier(const VkBufferMemoryBarrier * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkAccessFlags(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkAccessFlags(&obj->dstAccessMask, "dstAccessMask", 1);

     print_uint32_t(&obj->srcQueueFamilyIndex, "srcQueueFamilyIndex", 1);

     print_uint32_t(&obj->dstQueueFamilyIndex, "dstQueueFamilyIndex", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\",\n");

     print_VkDeviceSize(&obj->offset, "offset", 1);

     print_VkDeviceSize(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDispatchIndirectCommand(const VkDispatchIndirectCommand * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->x, "x", 1);

     print_uint32_t(&obj->y, "y", 1);

     print_uint32_t(&obj->z, "z", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDrawIndexedIndirectCommand(const VkDrawIndexedIndirectCommand * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->indexCount, "indexCount", 1);

     print_uint32_t(&obj->instanceCount, "instanceCount", 1);

     print_uint32_t(&obj->firstIndex, "firstIndex", 1);

     print_int32_t(&obj->vertexOffset, "vertexOffset", 1);

     print_uint32_t(&obj->firstInstance, "firstInstance", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDrawIndirectCommand(const VkDrawIndirectCommand * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->vertexCount, "vertexCount", 1);

     print_uint32_t(&obj->instanceCount, "instanceCount", 1);

     print_uint32_t(&obj->firstVertex, "firstVertex", 1);

     print_uint32_t(&obj->firstInstance, "firstInstance", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageSubresourceRange(const VkImageSubresourceRange * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkImageAspectFlags(&obj->aspectMask, "aspectMask", 1);

     print_uint32_t(&obj->baseMipLevel, "baseMipLevel", 1);

     print_uint32_t(&obj->levelCount, "levelCount", 1);

     print_uint32_t(&obj->baseArrayLayer, "baseArrayLayer", 1);

     print_uint32_t(&obj->layerCount, "layerCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageMemoryBarrier(const VkImageMemoryBarrier * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkAccessFlags(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkAccessFlags(&obj->dstAccessMask, "dstAccessMask", 1);

     print_VkImageLayout(&obj->oldLayout, "oldLayout", 1);

     print_VkImageLayout(&obj->newLayout, "newLayout", 1);

     print_uint32_t(&obj->srcQueueFamilyIndex, "srcQueueFamilyIndex", 1);

     print_uint32_t(&obj->dstQueueFamilyIndex, "dstQueueFamilyIndex", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"image\" : \"\",\n");

     PRINT_SPACE
     vk_json_printf(_OUT, "\"subresourceRange\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceRange(&obj->subresourceRange, "subresourceRange", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryBarrier(const VkMemoryBarrier * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkAccessFlags(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkAccessFlags(&obj->dstAccessMask, "dstAccessMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineCacheHeaderVersionOne(const VkPipelineCacheHeaderVersionOne * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->headerSize, "headerSize", 1);

     print_VkPipelineCacheHeaderVersion(&obj->headerVersion, "headerVersion", 1);

     print_uint32_t(&obj->vendorID, "vendorID", 1);

     print_uint32_t(&obj->deviceID, "deviceID", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pipelineCacheUUID\" :");
     if (obj->pipelineCacheUUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "pipelineCacheUUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->pipelineCacheUUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkAllocationCallbacks(const VkAllocationCallbacks * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     /** Note: Ignoring void* data. **/

     /** Note: Ignoring function pointer (PFN_vkAllocationFunction). **/

     /** Note: Ignoring function pointer (PFN_vkReallocationFunction). **/

     /** Note: Ignoring function pointer (PFN_vkFreeFunction). **/

     /** Note: Ignoring function pointer (PFN_vkInternalAllocationNotification). **/

     /** Note: Ignoring function pointer (PFN_vkInternalFreeNotification). **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkApplicationInfo(const VkApplicationInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pApplicationName\" : \"%s\",\n", (char*)obj->pApplicationName);

     print_uint32_t(&obj->applicationVersion, "applicationVersion", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pEngineName\" : \"%s\",\n", (char*)obj->pEngineName);

     print_uint32_t(&obj->engineVersion, "engineVersion", 1);

     print_uint32_t(&obj->apiVersion, "apiVersion", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkFormatProperties(const VkFormatProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkFormatFeatureFlags(&obj->linearTilingFeatures, "linearTilingFeatures", 1);

     print_VkFormatFeatureFlags(&obj->optimalTilingFeatures, "optimalTilingFeatures", 1);

     print_VkFormatFeatureFlags(&obj->bufferFeatures, "bufferFeatures", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageFormatProperties(const VkImageFormatProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->maxExtent, "maxExtent", 1);
     }

     print_uint32_t(&obj->maxMipLevels, "maxMipLevels", 1);

     print_uint32_t(&obj->maxArrayLayers, "maxArrayLayers", 1);

     print_VkSampleCountFlags(&obj->sampleCounts, "sampleCounts", 1);

     print_VkDeviceSize(&obj->maxResourceSize, "maxResourceSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkInstanceCreateInfo(const VkInstanceCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkInstanceCreateFlags(&obj->flags, "flags", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pApplicationInfo\" :");
     if (obj->pApplicationInfo) {
         vk_json_printf(_OUT, "\n");
         print_VkApplicationInfo(*(&obj->pApplicationInfo), "pApplicationInfo", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->enabledLayerCount, "enabledLayerCount", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"ppEnabledLayerNames\" : \"%s\",\n", (char*)obj->ppEnabledLayerNames);

     print_uint32_t(&obj->enabledExtensionCount, "enabledExtensionCount", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"ppEnabledExtensionNames\" : \"%s\",\n", (char*)obj->ppEnabledExtensionNames);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryHeap(const VkMemoryHeap * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDeviceSize(&obj->size, "size", 1);

     print_VkMemoryHeapFlags(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryType(const VkMemoryType * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkMemoryPropertyFlags(&obj->propertyFlags, "propertyFlags", 1);

     print_uint32_t(&obj->heapIndex, "heapIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPhysicalDeviceFeatures(const VkPhysicalDeviceFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkBool32(&obj->robustBufferAccess, "robustBufferAccess", 1);

     print_VkBool32(&obj->fullDrawIndexUint32, "fullDrawIndexUint32", 1);

     print_VkBool32(&obj->imageCubeArray, "imageCubeArray", 1);

     print_VkBool32(&obj->independentBlend, "independentBlend", 1);

     print_VkBool32(&obj->geometryShader, "geometryShader", 1);

     print_VkBool32(&obj->tessellationShader, "tessellationShader", 1);

     print_VkBool32(&obj->sampleRateShading, "sampleRateShading", 1);

     print_VkBool32(&obj->dualSrcBlend, "dualSrcBlend", 1);

     print_VkBool32(&obj->logicOp, "logicOp", 1);

     print_VkBool32(&obj->multiDrawIndirect, "multiDrawIndirect", 1);

     print_VkBool32(&obj->drawIndirectFirstInstance, "drawIndirectFirstInstance", 1);

     print_VkBool32(&obj->depthClamp, "depthClamp", 1);

     print_VkBool32(&obj->depthBiasClamp, "depthBiasClamp", 1);

     print_VkBool32(&obj->fillModeNonSolid, "fillModeNonSolid", 1);

     print_VkBool32(&obj->depthBounds, "depthBounds", 1);

     print_VkBool32(&obj->wideLines, "wideLines", 1);

     print_VkBool32(&obj->largePoints, "largePoints", 1);

     print_VkBool32(&obj->alphaToOne, "alphaToOne", 1);

     print_VkBool32(&obj->multiViewport, "multiViewport", 1);

     print_VkBool32(&obj->samplerAnisotropy, "samplerAnisotropy", 1);

     print_VkBool32(&obj->textureCompressionETC2, "textureCompressionETC2", 1);

     print_VkBool32(&obj->textureCompressionASTC_LDR, "textureCompressionASTC_LDR", 1);

     print_VkBool32(&obj->textureCompressionBC, "textureCompressionBC", 1);

     print_VkBool32(&obj->occlusionQueryPrecise, "occlusionQueryPrecise", 1);

     print_VkBool32(&obj->pipelineStatisticsQuery, "pipelineStatisticsQuery", 1);

     print_VkBool32(&obj->vertexPipelineStoresAndAtomics, "vertexPipelineStoresAndAtomics", 1);

     print_VkBool32(&obj->fragmentStoresAndAtomics, "fragmentStoresAndAtomics", 1);

     print_VkBool32(&obj->shaderTessellationAndGeometryPointSize, "shaderTessellationAndGeometryPointSize", 1);

     print_VkBool32(&obj->shaderImageGatherExtended, "shaderImageGatherExtended", 1);

     print_VkBool32(&obj->shaderStorageImageExtendedFormats, "shaderStorageImageExtendedFormats", 1);

     print_VkBool32(&obj->shaderStorageImageMultisample, "shaderStorageImageMultisample", 1);

     print_VkBool32(&obj->shaderStorageImageReadWithoutFormat, "shaderStorageImageReadWithoutFormat", 1);

     print_VkBool32(&obj->shaderStorageImageWriteWithoutFormat, "shaderStorageImageWriteWithoutFormat", 1);

     print_VkBool32(&obj->shaderUniformBufferArrayDynamicIndexing, "shaderUniformBufferArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderSampledImageArrayDynamicIndexing, "shaderSampledImageArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderStorageBufferArrayDynamicIndexing, "shaderStorageBufferArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderStorageImageArrayDynamicIndexing, "shaderStorageImageArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderClipDistance, "shaderClipDistance", 1);

     print_VkBool32(&obj->shaderCullDistance, "shaderCullDistance", 1);

     print_VkBool32(&obj->shaderFloat64, "shaderFloat64", 1);

     print_VkBool32(&obj->shaderInt64, "shaderInt64", 1);

     print_VkBool32(&obj->shaderInt16, "shaderInt16", 1);

     print_VkBool32(&obj->shaderResourceResidency, "shaderResourceResidency", 1);

     print_VkBool32(&obj->shaderResourceMinLod, "shaderResourceMinLod", 1);

     print_VkBool32(&obj->sparseBinding, "sparseBinding", 1);

     print_VkBool32(&obj->sparseResidencyBuffer, "sparseResidencyBuffer", 1);

     print_VkBool32(&obj->sparseResidencyImage2D, "sparseResidencyImage2D", 1);

     print_VkBool32(&obj->sparseResidencyImage3D, "sparseResidencyImage3D", 1);

     print_VkBool32(&obj->sparseResidency2Samples, "sparseResidency2Samples", 1);

     print_VkBool32(&obj->sparseResidency4Samples, "sparseResidency4Samples", 1);

     print_VkBool32(&obj->sparseResidency8Samples, "sparseResidency8Samples", 1);

     print_VkBool32(&obj->sparseResidency16Samples, "sparseResidency16Samples", 1);

     print_VkBool32(&obj->sparseResidencyAliased, "sparseResidencyAliased", 1);

     print_VkBool32(&obj->variableMultisampleRate, "variableMultisampleRate", 1);

     print_VkBool32(&obj->inheritedQueries, "inheritedQueries", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPhysicalDeviceLimits(const VkPhysicalDeviceLimits * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->maxImageDimension1D, "maxImageDimension1D", 1);

     print_uint32_t(&obj->maxImageDimension2D, "maxImageDimension2D", 1);

     print_uint32_t(&obj->maxImageDimension3D, "maxImageDimension3D", 1);

     print_uint32_t(&obj->maxImageDimensionCube, "maxImageDimensionCube", 1);

     print_uint32_t(&obj->maxImageArrayLayers, "maxImageArrayLayers", 1);

     print_uint32_t(&obj->maxTexelBufferElements, "maxTexelBufferElements", 1);

     print_uint32_t(&obj->maxUniformBufferRange, "maxUniformBufferRange", 1);

     print_uint32_t(&obj->maxStorageBufferRange, "maxStorageBufferRange", 1);

     print_uint32_t(&obj->maxPushConstantsSize, "maxPushConstantsSize", 1);

     print_uint32_t(&obj->maxMemoryAllocationCount, "maxMemoryAllocationCount", 1);

     print_uint32_t(&obj->maxSamplerAllocationCount, "maxSamplerAllocationCount", 1);

     print_VkDeviceSize(&obj->bufferImageGranularity, "bufferImageGranularity", 1);

     print_VkDeviceSize(&obj->sparseAddressSpaceSize, "sparseAddressSpaceSize", 1);

     print_uint32_t(&obj->maxBoundDescriptorSets, "maxBoundDescriptorSets", 1);

     print_uint32_t(&obj->maxPerStageDescriptorSamplers, "maxPerStageDescriptorSamplers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUniformBuffers, "maxPerStageDescriptorUniformBuffers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorStorageBuffers, "maxPerStageDescriptorStorageBuffers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorSampledImages, "maxPerStageDescriptorSampledImages", 1);

     print_uint32_t(&obj->maxPerStageDescriptorStorageImages, "maxPerStageDescriptorStorageImages", 1);

     print_uint32_t(&obj->maxPerStageDescriptorInputAttachments, "maxPerStageDescriptorInputAttachments", 1);

     print_uint32_t(&obj->maxPerStageResources, "maxPerStageResources", 1);

     print_uint32_t(&obj->maxDescriptorSetSamplers, "maxDescriptorSetSamplers", 1);

     print_uint32_t(&obj->maxDescriptorSetUniformBuffers, "maxDescriptorSetUniformBuffers", 1);

     print_uint32_t(&obj->maxDescriptorSetUniformBuffersDynamic, "maxDescriptorSetUniformBuffersDynamic", 1);

     print_uint32_t(&obj->maxDescriptorSetStorageBuffers, "maxDescriptorSetStorageBuffers", 1);

     print_uint32_t(&obj->maxDescriptorSetStorageBuffersDynamic, "maxDescriptorSetStorageBuffersDynamic", 1);

     print_uint32_t(&obj->maxDescriptorSetSampledImages, "maxDescriptorSetSampledImages", 1);

     print_uint32_t(&obj->maxDescriptorSetStorageImages, "maxDescriptorSetStorageImages", 1);

     print_uint32_t(&obj->maxDescriptorSetInputAttachments, "maxDescriptorSetInputAttachments", 1);

     print_uint32_t(&obj->maxVertexInputAttributes, "maxVertexInputAttributes", 1);

     print_uint32_t(&obj->maxVertexInputBindings, "maxVertexInputBindings", 1);

     print_uint32_t(&obj->maxVertexInputAttributeOffset, "maxVertexInputAttributeOffset", 1);

     print_uint32_t(&obj->maxVertexInputBindingStride, "maxVertexInputBindingStride", 1);

     print_uint32_t(&obj->maxVertexOutputComponents, "maxVertexOutputComponents", 1);

     print_uint32_t(&obj->maxTessellationGenerationLevel, "maxTessellationGenerationLevel", 1);

     print_uint32_t(&obj->maxTessellationPatchSize, "maxTessellationPatchSize", 1);

     print_uint32_t(&obj->maxTessellationControlPerVertexInputComponents, "maxTessellationControlPerVertexInputComponents", 1);

     print_uint32_t(&obj->maxTessellationControlPerVertexOutputComponents, "maxTessellationControlPerVertexOutputComponents", 1);

     print_uint32_t(&obj->maxTessellationControlPerPatchOutputComponents, "maxTessellationControlPerPatchOutputComponents", 1);

     print_uint32_t(&obj->maxTessellationControlTotalOutputComponents, "maxTessellationControlTotalOutputComponents", 1);

     print_uint32_t(&obj->maxTessellationEvaluationInputComponents, "maxTessellationEvaluationInputComponents", 1);

     print_uint32_t(&obj->maxTessellationEvaluationOutputComponents, "maxTessellationEvaluationOutputComponents", 1);

     print_uint32_t(&obj->maxGeometryShaderInvocations, "maxGeometryShaderInvocations", 1);

     print_uint32_t(&obj->maxGeometryInputComponents, "maxGeometryInputComponents", 1);

     print_uint32_t(&obj->maxGeometryOutputComponents, "maxGeometryOutputComponents", 1);

     print_uint32_t(&obj->maxGeometryOutputVertices, "maxGeometryOutputVertices", 1);

     print_uint32_t(&obj->maxGeometryTotalOutputComponents, "maxGeometryTotalOutputComponents", 1);

     print_uint32_t(&obj->maxFragmentInputComponents, "maxFragmentInputComponents", 1);

     print_uint32_t(&obj->maxFragmentOutputAttachments, "maxFragmentOutputAttachments", 1);

     print_uint32_t(&obj->maxFragmentDualSrcAttachments, "maxFragmentDualSrcAttachments", 1);

     print_uint32_t(&obj->maxFragmentCombinedOutputResources, "maxFragmentCombinedOutputResources", 1);

     print_uint32_t(&obj->maxComputeSharedMemorySize, "maxComputeSharedMemorySize", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxComputeWorkGroupCount\" :");
     if (obj->maxComputeWorkGroupCount) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (3); i++) {
            char tmp[100];
            sprintf(tmp, "maxComputeWorkGroupCount_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (3);
            print_uint32_t(&obj->maxComputeWorkGroupCount[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->maxComputeWorkGroupInvocations, "maxComputeWorkGroupInvocations", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxComputeWorkGroupSize\" :");
     if (obj->maxComputeWorkGroupSize) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (3); i++) {
            char tmp[100];
            sprintf(tmp, "maxComputeWorkGroupSize_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (3);
            print_uint32_t(&obj->maxComputeWorkGroupSize[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->subPixelPrecisionBits, "subPixelPrecisionBits", 1);

     print_uint32_t(&obj->subTexelPrecisionBits, "subTexelPrecisionBits", 1);

     print_uint32_t(&obj->mipmapPrecisionBits, "mipmapPrecisionBits", 1);

     print_uint32_t(&obj->maxDrawIndexedIndexValue, "maxDrawIndexedIndexValue", 1);

     print_uint32_t(&obj->maxDrawIndirectCount, "maxDrawIndirectCount", 1);

     print_float(&obj->maxSamplerLodBias, "maxSamplerLodBias", 1);

     print_float(&obj->maxSamplerAnisotropy, "maxSamplerAnisotropy", 1);

     print_uint32_t(&obj->maxViewports, "maxViewports", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxViewportDimensions\" :");
     if (obj->maxViewportDimensions) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "maxViewportDimensions_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_uint32_t(&obj->maxViewportDimensions[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"viewportBoundsRange\" :");
     if (obj->viewportBoundsRange) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "viewportBoundsRange_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_float(&obj->viewportBoundsRange[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->viewportSubPixelBits, "viewportSubPixelBits", 1);

     print_size_t(&obj->minMemoryMapAlignment, "minMemoryMapAlignment", 1);

     print_VkDeviceSize(&obj->minTexelBufferOffsetAlignment, "minTexelBufferOffsetAlignment", 1);

     print_VkDeviceSize(&obj->minUniformBufferOffsetAlignment, "minUniformBufferOffsetAlignment", 1);

     print_VkDeviceSize(&obj->minStorageBufferOffsetAlignment, "minStorageBufferOffsetAlignment", 1);

     print_int32_t(&obj->minTexelOffset, "minTexelOffset", 1);

     print_uint32_t(&obj->maxTexelOffset, "maxTexelOffset", 1);

     print_int32_t(&obj->minTexelGatherOffset, "minTexelGatherOffset", 1);

     print_uint32_t(&obj->maxTexelGatherOffset, "maxTexelGatherOffset", 1);

     print_float(&obj->minInterpolationOffset, "minInterpolationOffset", 1);

     print_float(&obj->maxInterpolationOffset, "maxInterpolationOffset", 1);

     print_uint32_t(&obj->subPixelInterpolationOffsetBits, "subPixelInterpolationOffsetBits", 1);

     print_uint32_t(&obj->maxFramebufferWidth, "maxFramebufferWidth", 1);

     print_uint32_t(&obj->maxFramebufferHeight, "maxFramebufferHeight", 1);

     print_uint32_t(&obj->maxFramebufferLayers, "maxFramebufferLayers", 1);

     print_VkSampleCountFlags(&obj->framebufferColorSampleCounts, "framebufferColorSampleCounts", 1);

     print_VkSampleCountFlags(&obj->framebufferDepthSampleCounts, "framebufferDepthSampleCounts", 1);

     print_VkSampleCountFlags(&obj->framebufferStencilSampleCounts, "framebufferStencilSampleCounts", 1);

     print_VkSampleCountFlags(&obj->framebufferNoAttachmentsSampleCounts, "framebufferNoAttachmentsSampleCounts", 1);

     print_uint32_t(&obj->maxColorAttachments, "maxColorAttachments", 1);

     print_VkSampleCountFlags(&obj->sampledImageColorSampleCounts, "sampledImageColorSampleCounts", 1);

     print_VkSampleCountFlags(&obj->sampledImageIntegerSampleCounts, "sampledImageIntegerSampleCounts", 1);

     print_VkSampleCountFlags(&obj->sampledImageDepthSampleCounts, "sampledImageDepthSampleCounts", 1);

     print_VkSampleCountFlags(&obj->sampledImageStencilSampleCounts, "sampledImageStencilSampleCounts", 1);

     print_VkSampleCountFlags(&obj->storageImageSampleCounts, "storageImageSampleCounts", 1);

     print_uint32_t(&obj->maxSampleMaskWords, "maxSampleMaskWords", 1);

     print_VkBool32(&obj->timestampComputeAndGraphics, "timestampComputeAndGraphics", 1);

     print_float(&obj->timestampPeriod, "timestampPeriod", 1);

     print_uint32_t(&obj->maxClipDistances, "maxClipDistances", 1);

     print_uint32_t(&obj->maxCullDistances, "maxCullDistances", 1);

     print_uint32_t(&obj->maxCombinedClipAndCullDistances, "maxCombinedClipAndCullDistances", 1);

     print_uint32_t(&obj->discreteQueuePriorities, "discreteQueuePriorities", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pointSizeRange\" :");
     if (obj->pointSizeRange) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "pointSizeRange_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_float(&obj->pointSizeRange[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"lineWidthRange\" :");
     if (obj->lineWidthRange) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "lineWidthRange_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_float(&obj->lineWidthRange[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_float(&obj->pointSizeGranularity, "pointSizeGranularity", 1);

     print_float(&obj->lineWidthGranularity, "lineWidthGranularity", 1);

     print_VkBool32(&obj->strictLines, "strictLines", 1);

     print_VkBool32(&obj->standardSampleLocations, "standardSampleLocations", 1);

     print_VkDeviceSize(&obj->optimalBufferCopyOffsetAlignment, "optimalBufferCopyOffsetAlignment", 1);

     print_VkDeviceSize(&obj->optimalBufferCopyRowPitchAlignment, "optimalBufferCopyRowPitchAlignment", 1);

     print_VkDeviceSize(&obj->nonCoherentAtomSize, "nonCoherentAtomSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPhysicalDeviceMemoryProperties(const VkPhysicalDeviceMemoryProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->memoryTypeCount, "memoryTypeCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"memoryTypes\" :");
     if (obj->memoryTypes) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_MEMORY_TYPES); i++) {
            char tmp[100];
            sprintf(tmp, "memoryTypes_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_MEMORY_TYPES);
            print_VkMemoryType(&obj->memoryTypes[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->memoryHeapCount, "memoryHeapCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"memoryHeaps\" :");
     if (obj->memoryHeaps) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_MEMORY_HEAPS); i++) {
            char tmp[100];
            sprintf(tmp, "memoryHeaps_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_MEMORY_HEAPS);
            print_VkMemoryHeap(&obj->memoryHeaps[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPhysicalDeviceSparseProperties(const VkPhysicalDeviceSparseProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkBool32(&obj->residencyStandard2DBlockShape, "residencyStandard2DBlockShape", 1);

     print_VkBool32(&obj->residencyStandard2DMultisampleBlockShape, "residencyStandard2DMultisampleBlockShape", 1);

     print_VkBool32(&obj->residencyStandard3DBlockShape, "residencyStandard3DBlockShape", 1);

     print_VkBool32(&obj->residencyAlignedMipSize, "residencyAlignedMipSize", 1);

     print_VkBool32(&obj->residencyNonResidentStrict, "residencyNonResidentStrict", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPhysicalDeviceProperties(const VkPhysicalDeviceProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->apiVersion, "apiVersion", 1);

     print_uint32_t(&obj->driverVersion, "driverVersion", 1);

     print_uint32_t(&obj->vendorID, "vendorID", 1);

     print_uint32_t(&obj->deviceID, "deviceID", 1);

     print_VkPhysicalDeviceType(&obj->deviceType, "deviceType", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"deviceName\" :");
     if (obj->deviceName) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_PHYSICAL_DEVICE_NAME_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "deviceName_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);
            print_char(&obj->deviceName[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pipelineCacheUUID\" :");
     if (obj->pipelineCacheUUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "pipelineCacheUUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->pipelineCacheUUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"limits\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPhysicalDeviceLimits(&obj->limits, "limits", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"sparseProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPhysicalDeviceSparseProperties(&obj->sparseProperties, "sparseProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkQueueFamilyProperties(const VkQueueFamilyProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkQueueFlags(&obj->queueFlags, "queueFlags", 1);

     print_uint32_t(&obj->queueCount, "queueCount", 1);

     print_uint32_t(&obj->timestampValidBits, "timestampValidBits", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minImageTransferGranularity\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->minImageTransferGranularity, "minImageTransferGranularity", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDeviceQueueCreateInfo(const VkDeviceQueueCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceQueueCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->queueFamilyIndex, "queueFamilyIndex", 1);

     print_uint32_t(&obj->queueCount, "queueCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueuePriorities\" :");
     if (obj->pQueuePriorities) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->queueCount); i++) {
            char tmp[100];
            sprintf(tmp, "pQueuePriorities_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->queueCount);
            print_float(&obj->pQueuePriorities[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDeviceCreateInfo(const VkDeviceCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->queueCreateInfoCount, "queueCreateInfoCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueueCreateInfos\" :");
     if (obj->pQueueCreateInfos) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->queueCreateInfoCount); i++) {
             if (i+1 == *(&obj->queueCreateInfoCount))
                 print_VkDeviceQueueCreateInfo(&obj->pQueueCreateInfos[i], "pQueueCreateInfos", 0);
             else
                 print_VkDeviceQueueCreateInfo(&obj->pQueueCreateInfos[i], "pQueueCreateInfos", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->enabledLayerCount, "enabledLayerCount", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"ppEnabledLayerNames\" : \"%s\",\n", (char*)obj->ppEnabledLayerNames);

     print_uint32_t(&obj->enabledExtensionCount, "enabledExtensionCount", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"ppEnabledExtensionNames\" : \"%s\",\n", (char*)obj->ppEnabledExtensionNames);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pEnabledFeatures\" :");
     if (obj->pEnabledFeatures) {
         vk_json_printf(_OUT, "\n");
         print_VkPhysicalDeviceFeatures(*(&obj->pEnabledFeatures), "pEnabledFeatures", 0);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkExtensionProperties(const VkExtensionProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extensionName\" :");
     if (obj->extensionName) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_EXTENSION_NAME_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "extensionName_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_EXTENSION_NAME_SIZE);
            print_char(&obj->extensionName[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->specVersion, "specVersion", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkLayerProperties(const VkLayerProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"layerName\" :");
     if (obj->layerName) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_EXTENSION_NAME_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "layerName_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_EXTENSION_NAME_SIZE);
            print_char(&obj->layerName[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->specVersion, "specVersion", 1);

     print_uint32_t(&obj->implementationVersion, "implementationVersion", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"description\" :");
     if (obj->description) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DESCRIPTION_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "description_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DESCRIPTION_SIZE);
            print_char(&obj->description[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSubmitInfo(const VkSubmitInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->waitSemaphoreCount, "waitSemaphoreCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pWaitSemaphores\" :");
     if (obj->pWaitSemaphores) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->waitSemaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pWaitSemaphores_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->waitSemaphoreCount);
            print_VkSemaphore(&obj->pWaitSemaphores[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pWaitDstStageMask\" :");
     if (obj->pWaitDstStageMask) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->waitSemaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pWaitDstStageMask_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->waitSemaphoreCount);
            print_VkPipelineStageFlags(&obj->pWaitDstStageMask[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->commandBufferCount, "commandBufferCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCommandBuffers\" :");
     if (obj->pCommandBuffers) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->commandBufferCount); i++) {
            char tmp[100];
            sprintf(tmp, "pCommandBuffers_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->commandBufferCount);
            print_VkCommandBuffer(&obj->pCommandBuffers[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->signalSemaphoreCount, "signalSemaphoreCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSignalSemaphores\" :");
     if (obj->pSignalSemaphores) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->signalSemaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSignalSemaphores_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->signalSemaphoreCount);
            print_VkSemaphore(&obj->pSignalSemaphores[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkMappedMemoryRange(const VkMappedMemoryRange * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"memory\" : \"\",\n");

     print_VkDeviceSize(&obj->offset, "offset", 1);

     print_VkDeviceSize(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryAllocateInfo(const VkMemoryAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->allocationSize, "allocationSize", 1);

     print_uint32_t(&obj->memoryTypeIndex, "memoryTypeIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkMemoryRequirements(const VkMemoryRequirements * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDeviceSize(&obj->size, "size", 1);

     print_VkDeviceSize(&obj->alignment, "alignment", 1);

     print_uint32_t(&obj->memoryTypeBits, "memoryTypeBits", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageSubresource(const VkImageSubresource * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkImageAspectFlags(&obj->aspectMask, "aspectMask", 1);

     print_uint32_t(&obj->mipLevel, "mipLevel", 1);

     print_uint32_t(&obj->arrayLayer, "arrayLayer", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkFenceCreateInfo(const VkFenceCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkFenceCreateFlags(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSemaphoreCreateInfo(const VkSemaphoreCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSemaphoreCreateFlags(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkEventCreateInfo(const VkEventCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkEventCreateFlags(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkQueryPoolCreateInfo(const VkQueryPoolCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkQueryPoolCreateFlags(&obj->flags, "flags", 1);

     print_VkQueryType(&obj->queryType, "queryType", 1);

     print_uint32_t(&obj->queryCount, "queryCount", 1);

     print_VkQueryPipelineStatisticFlags(&obj->pipelineStatistics, "pipelineStatistics", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBufferCreateInfo(const VkBufferCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBufferCreateFlags(&obj->flags, "flags", 1);

     print_VkDeviceSize(&obj->size, "size", 1);

     print_VkBufferUsageFlags(&obj->usage, "usage", 1);

     print_VkSharingMode(&obj->sharingMode, "sharingMode", 1);

     print_uint32_t(&obj->queueFamilyIndexCount, "queueFamilyIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueueFamilyIndices\" :");
     if (obj->pQueueFamilyIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->queueFamilyIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pQueueFamilyIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->queueFamilyIndexCount);
            print_uint32_t(&obj->pQueueFamilyIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBufferViewCreateInfo(const VkBufferViewCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBufferViewCreateFlags(&obj->flags, "flags", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\",\n");

     print_VkFormat(&obj->format, "format", 1);

     print_VkDeviceSize(&obj->offset, "offset", 1);

     print_VkDeviceSize(&obj->range, "range", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageCreateInfo(const VkImageCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageCreateFlags(&obj->flags, "flags", 1);

     print_VkImageType(&obj->imageType, "imageType", 1);

     print_VkFormat(&obj->format, "format", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->extent, "extent", 1);
     }

     print_uint32_t(&obj->mipLevels, "mipLevels", 1);

     print_uint32_t(&obj->arrayLayers, "arrayLayers", 1);

     print_VkSampleCountFlagBits(&obj->samples, "samples", 1);

     print_VkImageTiling(&obj->tiling, "tiling", 1);

     print_VkImageUsageFlags(&obj->usage, "usage", 1);

     print_VkSharingMode(&obj->sharingMode, "sharingMode", 1);

     print_uint32_t(&obj->queueFamilyIndexCount, "queueFamilyIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueueFamilyIndices\" :");
     if (obj->pQueueFamilyIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->queueFamilyIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pQueueFamilyIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->queueFamilyIndexCount);
            print_uint32_t(&obj->pQueueFamilyIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkImageLayout(&obj->initialLayout, "initialLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSubresourceLayout(const VkSubresourceLayout * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDeviceSize(&obj->offset, "offset", 1);

     print_VkDeviceSize(&obj->size, "size", 1);

     print_VkDeviceSize(&obj->rowPitch, "rowPitch", 1);

     print_VkDeviceSize(&obj->arrayPitch, "arrayPitch", 1);

     print_VkDeviceSize(&obj->depthPitch, "depthPitch", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkComponentMapping(const VkComponentMapping * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkComponentSwizzle(&obj->r, "r", 1);

     print_VkComponentSwizzle(&obj->g, "g", 1);

     print_VkComponentSwizzle(&obj->b, "b", 1);

     print_VkComponentSwizzle(&obj->a, "a", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageViewCreateInfo(const VkImageViewCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageViewCreateFlags(&obj->flags, "flags", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"image\" : \"\",\n");

     print_VkImageViewType(&obj->viewType, "viewType", 1);

     print_VkFormat(&obj->format, "format", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"components\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkComponentMapping(&obj->components, "components", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"subresourceRange\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceRange(&obj->subresourceRange, "subresourceRange", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineCacheCreateInfo(const VkPipelineCacheCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineCacheCreateFlags(&obj->flags, "flags", 1);

     print_size_t(&obj->initialDataSize, "initialDataSize", 1);

     /** Note: Ignoring void* data. **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSpecializationMapEntry(const VkSpecializationMapEntry * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->constantID, "constantID", 1);

     print_uint32_t(&obj->offset, "offset", 1);

     print_size_t(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSpecializationInfo(const VkSpecializationInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->mapEntryCount, "mapEntryCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pMapEntries\" :");
     if (obj->pMapEntries) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->mapEntryCount); i++) {
             if (i+1 == *(&obj->mapEntryCount))
                 print_VkSpecializationMapEntry(&obj->pMapEntries[i], "pMapEntries", 0);
             else
                 print_VkSpecializationMapEntry(&obj->pMapEntries[i], "pMapEntries", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_size_t(&obj->dataSize, "dataSize", 1);

     /** Note: Ignoring void* data. **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineShaderStageCreateInfo(const VkPipelineShaderStageCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineShaderStageCreateFlags(&obj->flags, "flags", 1);

     print_VkShaderStageFlagBits(&obj->stage, "stage", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"module\" : \"\",\n");

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pName\" : \"%s\",\n", (char*)obj->pName);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSpecializationInfo\" :");
     if (obj->pSpecializationInfo) {
         vk_json_printf(_OUT, "\n");
         print_VkSpecializationInfo(*(&obj->pSpecializationInfo), "pSpecializationInfo", 0);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkComputePipelineCreateInfo(const VkComputePipelineCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineCreateFlags(&obj->flags, "flags", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"stage\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineShaderStageCreateInfo(&obj->stage, "stage", 1);
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"layout\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"basePipelineHandle\" : \"\",\n");

     print_int32_t(&obj->basePipelineIndex, "basePipelineIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkVertexInputBindingDescription(const VkVertexInputBindingDescription * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->binding, "binding", 1);

     print_uint32_t(&obj->stride, "stride", 1);

     print_VkVertexInputRate(&obj->inputRate, "inputRate", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkVertexInputAttributeDescription(const VkVertexInputAttributeDescription * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->location, "location", 1);

     print_uint32_t(&obj->binding, "binding", 1);

     print_VkFormat(&obj->format, "format", 1);

     print_uint32_t(&obj->offset, "offset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineVertexInputStateCreateInfo(const VkPipelineVertexInputStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineVertexInputStateCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->vertexBindingDescriptionCount, "vertexBindingDescriptionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pVertexBindingDescriptions\" :");
     if (obj->pVertexBindingDescriptions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->vertexBindingDescriptionCount); i++) {
             if (i+1 == *(&obj->vertexBindingDescriptionCount))
                 print_VkVertexInputBindingDescription(&obj->pVertexBindingDescriptions[i], "pVertexBindingDescriptions", 0);
             else
                 print_VkVertexInputBindingDescription(&obj->pVertexBindingDescriptions[i], "pVertexBindingDescriptions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->vertexAttributeDescriptionCount, "vertexAttributeDescriptionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pVertexAttributeDescriptions\" :");
     if (obj->pVertexAttributeDescriptions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->vertexAttributeDescriptionCount); i++) {
             if (i+1 == *(&obj->vertexAttributeDescriptionCount))
                 print_VkVertexInputAttributeDescription(&obj->pVertexAttributeDescriptions[i], "pVertexAttributeDescriptions", 0);
             else
                 print_VkVertexInputAttributeDescription(&obj->pVertexAttributeDescriptions[i], "pVertexAttributeDescriptions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineInputAssemblyStateCreateInfo(const VkPipelineInputAssemblyStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineInputAssemblyStateCreateFlags(&obj->flags, "flags", 1);

     print_VkPrimitiveTopology(&obj->topology, "topology", 1);

     print_VkBool32(&obj->primitiveRestartEnable, "primitiveRestartEnable", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineTessellationStateCreateInfo(const VkPipelineTessellationStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineTessellationStateCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->patchControlPoints, "patchControlPoints", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkViewport(const VkViewport * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_float(&obj->x, "x", 1);

     print_float(&obj->y, "y", 1);

     print_float(&obj->width, "width", 1);

     print_float(&obj->height, "height", 1);

     print_float(&obj->minDepth, "minDepth", 1);

     print_float(&obj->maxDepth, "maxDepth", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineViewportStateCreateInfo(const VkPipelineViewportStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineViewportStateCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->viewportCount, "viewportCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pViewports\" :");
     if (obj->pViewports) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->viewportCount); i++) {
             if (i+1 == *(&obj->viewportCount))
                 print_VkViewport(&obj->pViewports[i], "pViewports", 0);
             else
                 print_VkViewport(&obj->pViewports[i], "pViewports", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->scissorCount, "scissorCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pScissors\" :");
     if (obj->pScissors) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->scissorCount); i++) {
             if (i+1 == *(&obj->scissorCount))
                 print_VkRect2D(&obj->pScissors[i], "pScissors", 0);
             else
                 print_VkRect2D(&obj->pScissors[i], "pScissors", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineRasterizationStateCreateInfo(const VkPipelineRasterizationStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineRasterizationStateCreateFlags(&obj->flags, "flags", 1);

     print_VkBool32(&obj->depthClampEnable, "depthClampEnable", 1);

     print_VkBool32(&obj->rasterizerDiscardEnable, "rasterizerDiscardEnable", 1);

     print_VkPolygonMode(&obj->polygonMode, "polygonMode", 1);

     print_VkCullModeFlags(&obj->cullMode, "cullMode", 1);

     print_VkFrontFace(&obj->frontFace, "frontFace", 1);

     print_VkBool32(&obj->depthBiasEnable, "depthBiasEnable", 1);

     print_float(&obj->depthBiasConstantFactor, "depthBiasConstantFactor", 1);

     print_float(&obj->depthBiasClamp, "depthBiasClamp", 1);

     print_float(&obj->depthBiasSlopeFactor, "depthBiasSlopeFactor", 1);

     print_float(&obj->lineWidth, "lineWidth", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineMultisampleStateCreateInfo(const VkPipelineMultisampleStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineMultisampleStateCreateFlags(&obj->flags, "flags", 1);

     print_VkSampleCountFlagBits(&obj->rasterizationSamples, "rasterizationSamples", 1);

     print_VkBool32(&obj->sampleShadingEnable, "sampleShadingEnable", 1);

     print_float(&obj->minSampleShading, "minSampleShading", 1);

     /** Skipping VkSampleMask. **/

     print_VkBool32(&obj->alphaToCoverageEnable, "alphaToCoverageEnable", 1);

     print_VkBool32(&obj->alphaToOneEnable, "alphaToOneEnable", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkStencilOpState(const VkStencilOpState * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStencilOp(&obj->failOp, "failOp", 1);

     print_VkStencilOp(&obj->passOp, "passOp", 1);

     print_VkStencilOp(&obj->depthFailOp, "depthFailOp", 1);

     print_VkCompareOp(&obj->compareOp, "compareOp", 1);

     print_uint32_t(&obj->compareMask, "compareMask", 1);

     print_uint32_t(&obj->writeMask, "writeMask", 1);

     print_uint32_t(&obj->reference, "reference", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineDepthStencilStateCreateInfo(const VkPipelineDepthStencilStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineDepthStencilStateCreateFlags(&obj->flags, "flags", 1);

     print_VkBool32(&obj->depthTestEnable, "depthTestEnable", 1);

     print_VkBool32(&obj->depthWriteEnable, "depthWriteEnable", 1);

     print_VkCompareOp(&obj->depthCompareOp, "depthCompareOp", 1);

     print_VkBool32(&obj->depthBoundsTestEnable, "depthBoundsTestEnable", 1);

     print_VkBool32(&obj->stencilTestEnable, "stencilTestEnable", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"front\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkStencilOpState(&obj->front, "front", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"back\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkStencilOpState(&obj->back, "back", 1);
     }

     print_float(&obj->minDepthBounds, "minDepthBounds", 1);

     print_float(&obj->maxDepthBounds, "maxDepthBounds", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineColorBlendAttachmentState(const VkPipelineColorBlendAttachmentState * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkBool32(&obj->blendEnable, "blendEnable", 1);

     print_VkBlendFactor(&obj->srcColorBlendFactor, "srcColorBlendFactor", 1);

     print_VkBlendFactor(&obj->dstColorBlendFactor, "dstColorBlendFactor", 1);

     print_VkBlendOp(&obj->colorBlendOp, "colorBlendOp", 1);

     print_VkBlendFactor(&obj->srcAlphaBlendFactor, "srcAlphaBlendFactor", 1);

     print_VkBlendFactor(&obj->dstAlphaBlendFactor, "dstAlphaBlendFactor", 1);

     print_VkBlendOp(&obj->alphaBlendOp, "alphaBlendOp", 1);

     print_VkColorComponentFlags(&obj->colorWriteMask, "colorWriteMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineColorBlendStateCreateInfo(const VkPipelineColorBlendStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineColorBlendStateCreateFlags(&obj->flags, "flags", 1);

     print_VkBool32(&obj->logicOpEnable, "logicOpEnable", 1);

     print_VkLogicOp(&obj->logicOp, "logicOp", 1);

     print_uint32_t(&obj->attachmentCount, "attachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachments\" :");
     if (obj->pAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->attachmentCount); i++) {
             if (i+1 == *(&obj->attachmentCount))
                 print_VkPipelineColorBlendAttachmentState(&obj->pAttachments[i], "pAttachments", 0);
             else
                 print_VkPipelineColorBlendAttachmentState(&obj->pAttachments[i], "pAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"blendConstants\" :");
     if (obj->blendConstants) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (4); i++) {
            char tmp[100];
            sprintf(tmp, "blendConstants_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (4);
            print_float(&obj->blendConstants[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineDynamicStateCreateInfo(const VkPipelineDynamicStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineDynamicStateCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->dynamicStateCount, "dynamicStateCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDynamicStates\" :");
     if (obj->pDynamicStates) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->dynamicStateCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDynamicStates_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->dynamicStateCount);
            print_VkDynamicState(&obj->pDynamicStates[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkGraphicsPipelineCreateInfo(const VkGraphicsPipelineCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->stageCount, "stageCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pStages\" :");
     if (obj->pStages) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->stageCount); i++) {
             if (i+1 == *(&obj->stageCount))
                 print_VkPipelineShaderStageCreateInfo(&obj->pStages[i], "pStages", 0);
             else
                 print_VkPipelineShaderStageCreateInfo(&obj->pStages[i], "pStages", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pVertexInputState\" :");
     if (obj->pVertexInputState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineVertexInputStateCreateInfo(*(&obj->pVertexInputState), "pVertexInputState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pInputAssemblyState\" :");
     if (obj->pInputAssemblyState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineInputAssemblyStateCreateInfo(*(&obj->pInputAssemblyState), "pInputAssemblyState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pTessellationState\" :");
     if (obj->pTessellationState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineTessellationStateCreateInfo(*(&obj->pTessellationState), "pTessellationState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pViewportState\" :");
     if (obj->pViewportState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineViewportStateCreateInfo(*(&obj->pViewportState), "pViewportState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRasterizationState\" :");
     if (obj->pRasterizationState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineRasterizationStateCreateInfo(*(&obj->pRasterizationState), "pRasterizationState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pMultisampleState\" :");
     if (obj->pMultisampleState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineMultisampleStateCreateInfo(*(&obj->pMultisampleState), "pMultisampleState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDepthStencilState\" :");
     if (obj->pDepthStencilState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineDepthStencilStateCreateInfo(*(&obj->pDepthStencilState), "pDepthStencilState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pColorBlendState\" :");
     if (obj->pColorBlendState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineColorBlendStateCreateInfo(*(&obj->pColorBlendState), "pColorBlendState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDynamicState\" :");
     if (obj->pDynamicState) {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineDynamicStateCreateInfo(*(&obj->pDynamicState), "pDynamicState", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"layout\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"renderPass\" : \"\",\n");

     print_uint32_t(&obj->subpass, "subpass", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"basePipelineHandle\" : \"\",\n");

     print_int32_t(&obj->basePipelineIndex, "basePipelineIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPushConstantRange(const VkPushConstantRange * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkShaderStageFlags(&obj->stageFlags, "stageFlags", 1);

     print_uint32_t(&obj->offset, "offset", 1);

     print_uint32_t(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkPipelineLayoutCreateInfo(const VkPipelineLayoutCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineLayoutCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->setLayoutCount, "setLayoutCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSetLayouts\" :");
     if (obj->pSetLayouts) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->setLayoutCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSetLayouts_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->setLayoutCount);
            print_VkDescriptorSetLayout(&obj->pSetLayouts[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->pushConstantRangeCount, "pushConstantRangeCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPushConstantRanges\" :");
     if (obj->pPushConstantRanges) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->pushConstantRangeCount); i++) {
             if (i+1 == *(&obj->pushConstantRangeCount))
                 print_VkPushConstantRange(&obj->pPushConstantRanges[i], "pPushConstantRanges", 0);
             else
                 print_VkPushConstantRange(&obj->pPushConstantRanges[i], "pPushConstantRanges", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSamplerCreateInfo(const VkSamplerCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSamplerCreateFlags(&obj->flags, "flags", 1);

     print_VkFilter(&obj->magFilter, "magFilter", 1);

     print_VkFilter(&obj->minFilter, "minFilter", 1);

     print_VkSamplerMipmapMode(&obj->mipmapMode, "mipmapMode", 1);

     print_VkSamplerAddressMode(&obj->addressModeU, "addressModeU", 1);

     print_VkSamplerAddressMode(&obj->addressModeV, "addressModeV", 1);

     print_VkSamplerAddressMode(&obj->addressModeW, "addressModeW", 1);

     print_float(&obj->mipLodBias, "mipLodBias", 1);

     print_VkBool32(&obj->anisotropyEnable, "anisotropyEnable", 1);

     print_float(&obj->maxAnisotropy, "maxAnisotropy", 1);

     print_VkBool32(&obj->compareEnable, "compareEnable", 1);

     print_VkCompareOp(&obj->compareOp, "compareOp", 1);

     print_float(&obj->minLod, "minLod", 1);

     print_float(&obj->maxLod, "maxLod", 1);

     print_VkBorderColor(&obj->borderColor, "borderColor", 1);

     print_VkBool32(&obj->unnormalizedCoordinates, "unnormalizedCoordinates", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkCopyDescriptorSet(const VkCopyDescriptorSet * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcSet\" : \"\",\n");

     print_uint32_t(&obj->srcBinding, "srcBinding", 1);

     print_uint32_t(&obj->srcArrayElement, "srcArrayElement", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstSet\" : \"\",\n");

     print_uint32_t(&obj->dstBinding, "dstBinding", 1);

     print_uint32_t(&obj->dstArrayElement, "dstArrayElement", 1);

     print_uint32_t(&obj->descriptorCount, "descriptorCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorBufferInfo(const VkDescriptorBufferInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\",\n");

     print_VkDeviceSize(&obj->offset, "offset", 1);

     print_VkDeviceSize(&obj->range, "range", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorImageInfo(const VkDescriptorImageInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"sampler\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"imageView\" : \"\",\n");

     print_VkImageLayout(&obj->imageLayout, "imageLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorPoolSize(const VkDescriptorPoolSize * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDescriptorType(&obj->type, "type", 1);

     print_uint32_t(&obj->descriptorCount, "descriptorCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorPoolCreateInfo(const VkDescriptorPoolCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDescriptorPoolCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->maxSets, "maxSets", 1);

     print_uint32_t(&obj->poolSizeCount, "poolSizeCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPoolSizes\" :");
     if (obj->pPoolSizes) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->poolSizeCount); i++) {
             if (i+1 == *(&obj->poolSizeCount))
                 print_VkDescriptorPoolSize(&obj->pPoolSizes[i], "pPoolSizes", 0);
             else
                 print_VkDescriptorPoolSize(&obj->pPoolSizes[i], "pPoolSizes", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorSetAllocateInfo(const VkDescriptorSetAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"descriptorPool\" : \"\",\n");

     print_uint32_t(&obj->descriptorSetCount, "descriptorSetCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSetLayouts\" :");
     if (obj->pSetLayouts) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->descriptorSetCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSetLayouts_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->descriptorSetCount);
            print_VkDescriptorSetLayout(&obj->pSetLayouts[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorSetLayoutBinding(const VkDescriptorSetLayoutBinding * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->binding, "binding", 1);

     print_VkDescriptorType(&obj->descriptorType, "descriptorType", 1);

     print_uint32_t(&obj->descriptorCount, "descriptorCount", 1);

     print_VkShaderStageFlags(&obj->stageFlags, "stageFlags", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pImmutableSamplers\" :");
     if (obj->pImmutableSamplers) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->descriptorCount); i++) {
            char tmp[100];
            sprintf(tmp, "pImmutableSamplers_%u_%u", *(&obj->binding), i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->descriptorCount);
            print_VkSampler(&obj->pImmutableSamplers[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkDescriptorSetLayoutCreateInfo(const VkDescriptorSetLayoutCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDescriptorSetLayoutCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->bindingCount, "bindingCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pBindings\" :");
     if (obj->pBindings) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->bindingCount); i++) {
             if (i+1 == *(&obj->bindingCount))
                 print_VkDescriptorSetLayoutBinding(&obj->pBindings[i], "pBindings", 0);
             else
                 print_VkDescriptorSetLayoutBinding(&obj->pBindings[i], "pBindings", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkWriteDescriptorSet(const VkWriteDescriptorSet * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstSet\" : \"\",\n");

     print_uint32_t(&obj->dstBinding, "dstBinding", 1);

     print_uint32_t(&obj->dstArrayElement, "dstArrayElement", 1);

     print_uint32_t(&obj->descriptorCount, "descriptorCount", 1);

     print_VkDescriptorType(&obj->descriptorType, "descriptorType", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pImageInfo\" :");
     if (obj->pImageInfo) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->descriptorCount); i++) {
             if (i+1 == *(&obj->descriptorCount))
                 print_VkDescriptorImageInfo(&obj->pImageInfo[i], "pImageInfo", 0);
             else
                 print_VkDescriptorImageInfo(&obj->pImageInfo[i], "pImageInfo", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pBufferInfo\" :");
     if (obj->pBufferInfo) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->descriptorCount); i++) {
             if (i+1 == *(&obj->descriptorCount))
                 print_VkDescriptorBufferInfo(&obj->pBufferInfo[i], "pBufferInfo", 0);
             else
                 print_VkDescriptorBufferInfo(&obj->pBufferInfo[i], "pBufferInfo", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pTexelBufferView\" :");
     if (obj->pTexelBufferView) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->descriptorCount); i++) {
            char tmp[100];
            sprintf(tmp, "pTexelBufferView_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->descriptorCount);
            print_VkBufferView(&obj->pTexelBufferView[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkAttachmentDescription(const VkAttachmentDescription * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkAttachmentDescriptionFlags(&obj->flags, "flags", 1);

     print_VkFormat(&obj->format, "format", 1);

     print_VkSampleCountFlagBits(&obj->samples, "samples", 1);

     print_VkAttachmentLoadOp(&obj->loadOp, "loadOp", 1);

     print_VkAttachmentStoreOp(&obj->storeOp, "storeOp", 1);

     print_VkAttachmentLoadOp(&obj->stencilLoadOp, "stencilLoadOp", 1);

     print_VkAttachmentStoreOp(&obj->stencilStoreOp, "stencilStoreOp", 1);

     print_VkImageLayout(&obj->initialLayout, "initialLayout", 1);

     print_VkImageLayout(&obj->finalLayout, "finalLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkAttachmentReference(const VkAttachmentReference * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->attachment, "attachment", 1);

     print_VkImageLayout(&obj->layout, "layout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkFramebufferCreateInfo(const VkFramebufferCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkFramebufferCreateFlags(&obj->flags, "flags", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"renderPass\" : \"\",\n");

     print_uint32_t(&obj->attachmentCount, "attachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachments\" :");
     if (obj->pAttachments) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->attachmentCount); i++) {
            char tmp[100];
            sprintf(tmp, "pAttachments_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->attachmentCount);
            print_VkImageView(&obj->pAttachments[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->width, "width", 1);

     print_uint32_t(&obj->height, "height", 1);

     print_uint32_t(&obj->layers, "layers", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSubpassDescription(const VkSubpassDescription * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkSubpassDescriptionFlags(&obj->flags, "flags", 1);

     print_VkPipelineBindPoint(&obj->pipelineBindPoint, "pipelineBindPoint", 1);

     print_uint32_t(&obj->inputAttachmentCount, "inputAttachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pInputAttachments\" :");
     if (obj->pInputAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->inputAttachmentCount); i++) {
             if (i+1 == *(&obj->inputAttachmentCount))
                 print_VkAttachmentReference(&obj->pInputAttachments[i], "pInputAttachments", 0);
             else
                 print_VkAttachmentReference(&obj->pInputAttachments[i], "pInputAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->colorAttachmentCount, "colorAttachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pColorAttachments\" :");
     if (obj->pColorAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->colorAttachmentCount); i++) {
             if (i+1 == *(&obj->colorAttachmentCount))
                 print_VkAttachmentReference(&obj->pColorAttachments[i], "pColorAttachments", 0);
             else
                 print_VkAttachmentReference(&obj->pColorAttachments[i], "pColorAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pResolveAttachments\" :");
     if (obj->pResolveAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->colorAttachmentCount); i++) {
             if (i+1 == *(&obj->colorAttachmentCount))
                 print_VkAttachmentReference(&obj->pResolveAttachments[i], "pResolveAttachments", 0);
             else
                 print_VkAttachmentReference(&obj->pResolveAttachments[i], "pResolveAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDepthStencilAttachment\" :");
     if (obj->pDepthStencilAttachment) {
         vk_json_printf(_OUT, "\n");
         print_VkAttachmentReference(*(&obj->pDepthStencilAttachment), "pDepthStencilAttachment", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->preserveAttachmentCount, "preserveAttachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPreserveAttachments\" :");
     if (obj->pPreserveAttachments) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->preserveAttachmentCount); i++) {
            char tmp[100];
            sprintf(tmp, "pPreserveAttachments_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->preserveAttachmentCount);
            print_uint32_t(&obj->pPreserveAttachments[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkSubpassDependency(const VkSubpassDependency * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->srcSubpass, "srcSubpass", 1);

     print_uint32_t(&obj->dstSubpass, "dstSubpass", 1);

     print_VkPipelineStageFlags(&obj->srcStageMask, "srcStageMask", 1);

     print_VkPipelineStageFlags(&obj->dstStageMask, "dstStageMask", 1);

     print_VkAccessFlags(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkAccessFlags(&obj->dstAccessMask, "dstAccessMask", 1);

     print_VkDependencyFlags(&obj->dependencyFlags, "dependencyFlags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkRenderPassCreateInfo(const VkRenderPassCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkRenderPassCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->attachmentCount, "attachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachments\" :");
     if (obj->pAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->attachmentCount); i++) {
             if (i+1 == *(&obj->attachmentCount))
                 print_VkAttachmentDescription(&obj->pAttachments[i], "pAttachments", 0);
             else
                 print_VkAttachmentDescription(&obj->pAttachments[i], "pAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->subpassCount, "subpassCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSubpasses\" :");
     if (obj->pSubpasses) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->subpassCount); i++) {
             if (i+1 == *(&obj->subpassCount))
                 print_VkSubpassDescription(&obj->pSubpasses[i], "pSubpasses", 0);
             else
                 print_VkSubpassDescription(&obj->pSubpasses[i], "pSubpasses", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->dependencyCount, "dependencyCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDependencies\" :");
     if (obj->pDependencies) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->dependencyCount); i++) {
             if (i+1 == *(&obj->dependencyCount))
                 print_VkSubpassDependency(&obj->pDependencies[i], "pDependencies", 0);
             else
                 print_VkSubpassDependency(&obj->pDependencies[i], "pDependencies", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkCommandPoolCreateInfo(const VkCommandPoolCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkCommandPoolCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->queueFamilyIndex, "queueFamilyIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkCommandBufferAllocateInfo(const VkCommandBufferAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"commandPool\" : \"\",\n");

     print_VkCommandBufferLevel(&obj->level, "level", 1);

     print_uint32_t(&obj->commandBufferCount, "commandBufferCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkCommandBufferInheritanceInfo(const VkCommandBufferInheritanceInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"renderPass\" : \"\",\n");

     print_uint32_t(&obj->subpass, "subpass", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"framebuffer\" : \"\",\n");

     print_VkBool32(&obj->occlusionQueryEnable, "occlusionQueryEnable", 1);

     print_VkQueryControlFlags(&obj->queryFlags, "queryFlags", 1);

     print_VkQueryPipelineStatisticFlags(&obj->pipelineStatistics, "pipelineStatistics", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkCommandBufferBeginInfo(const VkCommandBufferBeginInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkCommandBufferUsageFlags(&obj->flags, "flags", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pInheritanceInfo\" :");
     if (obj->pInheritanceInfo) {
         vk_json_printf(_OUT, "\n");
         print_VkCommandBufferInheritanceInfo(*(&obj->pInheritanceInfo), "pInheritanceInfo", 0);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBufferCopy(const VkBufferCopy * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDeviceSize(&obj->srcOffset, "srcOffset", 1);

     print_VkDeviceSize(&obj->dstOffset, "dstOffset", 1);

     print_VkDeviceSize(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageSubresourceLayers(const VkImageSubresourceLayers * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkImageAspectFlags(&obj->aspectMask, "aspectMask", 1);

     print_uint32_t(&obj->mipLevel, "mipLevel", 1);

     print_uint32_t(&obj->baseArrayLayer, "baseArrayLayer", 1);

     print_uint32_t(&obj->layerCount, "layerCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkBufferImageCopy(const VkBufferImageCopy * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDeviceSize(&obj->bufferOffset, "bufferOffset", 1);

     print_uint32_t(&obj->bufferRowLength, "bufferRowLength", 1);

     print_uint32_t(&obj->bufferImageHeight, "bufferImageHeight", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->imageSubresource, "imageSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->imageOffset, "imageOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->imageExtent, "imageExtent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkClearColorValue(const VkClearColorValue * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"float32\" :");
     if (obj->float32) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (4); i++) {
            char tmp[100];
            sprintf(tmp, "float32_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (4);
            print_float(&obj->float32[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"int32\" :");
     if (obj->int32) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (4); i++) {
            char tmp[100];
            sprintf(tmp, "int32_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (4);
            print_int32_t(&obj->int32[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"uint32\" :");
     if (obj->uint32) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (4); i++) {
            char tmp[100];
            sprintf(tmp, "uint32_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (4);
            print_uint32_t(&obj->uint32[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkClearDepthStencilValue(const VkClearDepthStencilValue * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_float(&obj->depth, "depth", 1);

     print_uint32_t(&obj->stencil, "stencil", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkClearValue(const VkClearValue * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkClearColorValue(&obj->color, "color", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"depthStencil\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkClearDepthStencilValue(&obj->depthStencil, "depthStencil", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkClearAttachment(const VkClearAttachment * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkImageAspectFlags(&obj->aspectMask, "aspectMask", 1);

     print_uint32_t(&obj->colorAttachment, "colorAttachment", 1);

     print_VkClearValue(&obj->clearValue, "clearValue", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkClearRect(const VkClearRect * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"rect\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkRect2D(&obj->rect, "rect", 1);
     }

     print_uint32_t(&obj->baseArrayLayer, "baseArrayLayer", 1);

     print_uint32_t(&obj->layerCount, "layerCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageBlit(const VkImageBlit * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->srcSubresource, "srcSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcOffsets\" :");
     if (obj->srcOffsets) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "srcOffsets_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_VkOffset3D(&obj->srcOffsets[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->dstSubresource, "dstSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstOffsets\" :");
     if (obj->dstOffsets) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "dstOffsets_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_VkOffset3D(&obj->dstOffsets[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageCopy(const VkImageCopy * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->srcSubresource, "srcSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->srcOffset, "srcOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->dstSubresource, "dstSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->dstOffset, "dstOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->extent, "extent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkImageResolve(const VkImageResolve * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->srcSubresource, "srcSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->srcOffset, "srcOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->dstSubresource, "dstSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->dstOffset, "dstOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->extent, "extent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

void print_VkRenderPassBeginInfo(const VkRenderPassBeginInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"renderPass\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"framebuffer\" : \"\",\n");

     PRINT_SPACE
     vk_json_printf(_OUT, "\"renderArea\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkRect2D(&obj->renderArea, "renderArea", 1);
     }

     print_uint32_t(&obj->clearValueCount, "clearValueCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pClearValues\" :");
     if (obj->pClearValues) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->clearValueCount); i++) {
            char tmp[100];
            sprintf(tmp, "pClearValues_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->clearValueCount);
            print_VkClearValue(&obj->pClearValues[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#ifdef VK_VERSION_1_1
void print_VkSamplerYcbcrConversion(const VkSamplerYcbcrConversion  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkSubgroupFeatureFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SUBGROUP_FEATURE_BASIC_BIT";
    case (1 << 1): return "VK_SUBGROUP_FEATURE_VOTE_BIT";
    case (1 << 2): return "VK_SUBGROUP_FEATURE_ARITHMETIC_BIT";
    case (1 << 3): return "VK_SUBGROUP_FEATURE_BALLOT_BIT";
    case (1 << 4): return "VK_SUBGROUP_FEATURE_SHUFFLE_BIT";
    case (1 << 5): return "VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT";
    case (1 << 6): return "VK_SUBGROUP_FEATURE_CLUSTERED_BIT";
    case (1 << 7): return "VK_SUBGROUP_FEATURE_QUAD_BIT";
    case (1 << 8): return "VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV";
   }
   return NULL;
}
void print_VkSubgroupFeatureFlagBits(const VkSubgroupFeatureFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSubgroupFeatureFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkPeerMemoryFeatureFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT";
    case (1 << 1): return "VK_PEER_MEMORY_FEATURE_COPY_DST_BIT";
    case (1 << 2): return "VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT";
    case (1 << 3): return "VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT";
   }
   return NULL;
}
void print_VkPeerMemoryFeatureFlagBits(const VkPeerMemoryFeatureFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPeerMemoryFeatureFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkMemoryAllocateFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT";
    case (1 << 1): return "VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT";
    case (1 << 2): return "VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT";
   }
   return NULL;
}
void print_VkMemoryAllocateFlagBits(const VkMemoryAllocateFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkMemoryAllocateFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkPointClippingBehavior_map(int o) {
switch (o) {
    case 0: return "VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES";
    case 1: return "VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY";
   }
   return NULL;
}
void print_VkPointClippingBehavior(const VkPointClippingBehavior* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPointClippingBehavior_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkTessellationDomainOrigin_map(int o) {
switch (o) {
    case 0: return "VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT";
    case 1: return "VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT";
   }
   return NULL;
}
void print_VkTessellationDomainOrigin(const VkTessellationDomainOrigin* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkTessellationDomainOrigin_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkSamplerYcbcrModelConversion_map(int o) {
switch (o) {
    case 0: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY";
    case 1: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY";
    case 2: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709";
    case 3: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601";
    case 4: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020";
   }
   return NULL;
}
void print_VkSamplerYcbcrModelConversion(const VkSamplerYcbcrModelConversion* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSamplerYcbcrModelConversion_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkSamplerYcbcrRange_map(int o) {
switch (o) {
    case 0: return "VK_SAMPLER_YCBCR_RANGE_ITU_FULL";
    case 1: return "VK_SAMPLER_YCBCR_RANGE_ITU_NARROW";
   }
   return NULL;
}
void print_VkSamplerYcbcrRange(const VkSamplerYcbcrRange* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSamplerYcbcrRange_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkChromaLocation_map(int o) {
switch (o) {
    case 0: return "VK_CHROMA_LOCATION_COSITED_EVEN";
    case 1: return "VK_CHROMA_LOCATION_MIDPOINT";
   }
   return NULL;
}
void print_VkChromaLocation(const VkChromaLocation* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkChromaLocation_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkExternalMemoryHandleTypeFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT";
    case (1 << 1): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT";
    case (1 << 2): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
    case (1 << 3): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT";
    case (1 << 4): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT";
    case (1 << 5): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT";
    case (1 << 6): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT";
    case (1 << 9): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT";
    case (1 << 10): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID";
    case (1 << 7): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT";
    case (1 << 8): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT";
    case (1 << 11): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA";
    case (1 << 12): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV";
    case (1 << 13): return "VK_EXTERNAL_MEMORY_HANDLE_TYPE_RESERVED_13_BIT_NV";
   }
   return NULL;
}
void print_VkExternalMemoryHandleTypeFlagBits(const VkExternalMemoryHandleTypeFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkExternalMemoryHandleTypeFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkExternalMemoryFeatureFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT";
    case (1 << 1): return "VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT";
    case (1 << 2): return "VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT";
   }
   return NULL;
}
void print_VkExternalMemoryFeatureFlagBits(const VkExternalMemoryFeatureFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkExternalMemoryFeatureFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkExternalFenceHandleTypeFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT";
    case (1 << 1): return "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT";
    case (1 << 2): return "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
    case (1 << 3): return "VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT";
    case (1 << 4): return "VK_EXTERNAL_FENCE_HANDLE_TYPE_RESERVED_4_BIT_NV";
    case (1 << 5): return "VK_EXTERNAL_FENCE_HANDLE_TYPE_RESERVED_5_BIT_NV";
   }
   return NULL;
}
void print_VkExternalFenceHandleTypeFlagBits(const VkExternalFenceHandleTypeFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkExternalFenceHandleTypeFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkExternalFenceFeatureFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT";
    case (1 << 1): return "VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT";
   }
   return NULL;
}
void print_VkExternalFenceFeatureFlagBits(const VkExternalFenceFeatureFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkExternalFenceFeatureFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkFenceImportFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_FENCE_IMPORT_TEMPORARY_BIT";
   }
   return NULL;
}
void print_VkFenceImportFlagBits(const VkFenceImportFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFenceImportFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkSemaphoreImportFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SEMAPHORE_IMPORT_TEMPORARY_BIT";
   }
   return NULL;
}
void print_VkSemaphoreImportFlagBits(const VkSemaphoreImportFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSemaphoreImportFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkExternalSemaphoreHandleTypeFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT";
    case (1 << 1): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT";
    case (1 << 2): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
    case (1 << 3): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT";
    case (1 << 4): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT";
    case (1 << 7): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA";
    case (1 << 5): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_RESERVED_5_BIT_NV";
    case (1 << 6): return "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_RESERVED_6_BIT_NV";
   }
   return NULL;
}
void print_VkExternalSemaphoreHandleTypeFlagBits(const VkExternalSemaphoreHandleTypeFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkExternalSemaphoreHandleTypeFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
static const char* VkExternalSemaphoreFeatureFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT";
    case (1 << 1): return "VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT";
   }
   return NULL;
}
void print_VkExternalSemaphoreFeatureFlagBits(const VkExternalSemaphoreFeatureFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkExternalSemaphoreFeatureFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkSubgroupFeatureFlags(const VkSubgroupFeatureFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSubgroupFeatureFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSubgroupFeatureFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPeerMemoryFeatureFlags(const VkPeerMemoryFeatureFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkPeerMemoryFeatureFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkPeerMemoryFeatureFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkMemoryAllocateFlags(const VkMemoryAllocateFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkMemoryAllocateFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkMemoryAllocateFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalMemoryHandleTypeFlags(const VkExternalMemoryHandleTypeFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkExternalMemoryHandleTypeFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkExternalMemoryHandleTypeFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalMemoryFeatureFlags(const VkExternalMemoryFeatureFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkExternalMemoryFeatureFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkExternalMemoryFeatureFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalFenceHandleTypeFlags(const VkExternalFenceHandleTypeFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkExternalFenceHandleTypeFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkExternalFenceHandleTypeFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalFenceFeatureFlags(const VkExternalFenceFeatureFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkExternalFenceFeatureFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkExternalFenceFeatureFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkFenceImportFlags(const VkFenceImportFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkFenceImportFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkFenceImportFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkSemaphoreImportFlags(const VkSemaphoreImportFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSemaphoreImportFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSemaphoreImportFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalSemaphoreHandleTypeFlags(const VkExternalSemaphoreHandleTypeFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkExternalSemaphoreHandleTypeFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkExternalSemaphoreHandleTypeFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalSemaphoreFeatureFlags(const VkExternalSemaphoreFeatureFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkExternalSemaphoreFeatureFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkExternalSemaphoreFeatureFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceSubgroupProperties(const VkPhysicalDeviceSubgroupProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->subgroupSize, "subgroupSize", 1);

     print_VkShaderStageFlags(&obj->supportedStages, "supportedStages", 1);

     print_VkSubgroupFeatureFlags(&obj->supportedOperations, "supportedOperations", 1);

     print_VkBool32(&obj->quadOperationsInAllStages, "quadOperationsInAllStages", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkBindBufferMemoryInfo(const VkBindBufferMemoryInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"memory\" : \"\",\n");

     print_VkDeviceSize(&obj->memoryOffset, "memoryOffset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkBindImageMemoryInfo(const VkBindImageMemoryInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"image\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"memory\" : \"\",\n");

     print_VkDeviceSize(&obj->memoryOffset, "memoryOffset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDevice16BitStorageFeatures(const VkPhysicalDevice16BitStorageFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->storageBuffer16BitAccess, "storageBuffer16BitAccess", 1);

     print_VkBool32(&obj->uniformAndStorageBuffer16BitAccess, "uniformAndStorageBuffer16BitAccess", 1);

     print_VkBool32(&obj->storagePushConstant16, "storagePushConstant16", 1);

     print_VkBool32(&obj->storageInputOutput16, "storageInputOutput16", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkMemoryDedicatedRequirements(const VkMemoryDedicatedRequirements * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->prefersDedicatedAllocation, "prefersDedicatedAllocation", 1);

     print_VkBool32(&obj->requiresDedicatedAllocation, "requiresDedicatedAllocation", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkMemoryDedicatedAllocateInfo(const VkMemoryDedicatedAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"image\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkMemoryAllocateFlagsInfo(const VkMemoryAllocateFlagsInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkMemoryAllocateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->deviceMask, "deviceMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkDeviceGroupRenderPassBeginInfo(const VkDeviceGroupRenderPassBeginInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->deviceMask, "deviceMask", 1);

     print_uint32_t(&obj->deviceRenderAreaCount, "deviceRenderAreaCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDeviceRenderAreas\" :");
     if (obj->pDeviceRenderAreas) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->deviceRenderAreaCount); i++) {
             if (i+1 == *(&obj->deviceRenderAreaCount))
                 print_VkRect2D(&obj->pDeviceRenderAreas[i], "pDeviceRenderAreas", 0);
             else
                 print_VkRect2D(&obj->pDeviceRenderAreas[i], "pDeviceRenderAreas", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkDeviceGroupCommandBufferBeginInfo(const VkDeviceGroupCommandBufferBeginInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->deviceMask, "deviceMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkDeviceGroupSubmitInfo(const VkDeviceGroupSubmitInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->waitSemaphoreCount, "waitSemaphoreCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pWaitSemaphoreDeviceIndices\" :");
     if (obj->pWaitSemaphoreDeviceIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->waitSemaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pWaitSemaphoreDeviceIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->waitSemaphoreCount);
            print_uint32_t(&obj->pWaitSemaphoreDeviceIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->commandBufferCount, "commandBufferCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCommandBufferDeviceMasks\" :");
     if (obj->pCommandBufferDeviceMasks) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->commandBufferCount); i++) {
            char tmp[100];
            sprintf(tmp, "pCommandBufferDeviceMasks_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->commandBufferCount);
            print_uint32_t(&obj->pCommandBufferDeviceMasks[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->signalSemaphoreCount, "signalSemaphoreCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSignalSemaphoreDeviceIndices\" :");
     if (obj->pSignalSemaphoreDeviceIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->signalSemaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSignalSemaphoreDeviceIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->signalSemaphoreCount);
            print_uint32_t(&obj->pSignalSemaphoreDeviceIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkBindBufferMemoryDeviceGroupInfo(const VkBindBufferMemoryDeviceGroupInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->deviceIndexCount, "deviceIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDeviceIndices\" :");
     if (obj->pDeviceIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->deviceIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDeviceIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->deviceIndexCount);
            print_uint32_t(&obj->pDeviceIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkBindImageMemoryDeviceGroupInfo(const VkBindImageMemoryDeviceGroupInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->deviceIndexCount, "deviceIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDeviceIndices\" :");
     if (obj->pDeviceIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->deviceIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDeviceIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->deviceIndexCount);
            print_uint32_t(&obj->pDeviceIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->splitInstanceBindRegionCount, "splitInstanceBindRegionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSplitInstanceBindRegions\" :");
     if (obj->pSplitInstanceBindRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->splitInstanceBindRegionCount); i++) {
             if (i+1 == *(&obj->splitInstanceBindRegionCount))
                 print_VkRect2D(&obj->pSplitInstanceBindRegions[i], "pSplitInstanceBindRegions", 0);
             else
                 print_VkRect2D(&obj->pSplitInstanceBindRegions[i], "pSplitInstanceBindRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceGroupProperties(const VkPhysicalDeviceGroupProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->physicalDeviceCount, "physicalDeviceCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"physicalDevices\" :");
     if (obj->physicalDevices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DEVICE_GROUP_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "physicalDevices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DEVICE_GROUP_SIZE);
            print_VkPhysicalDevice(&obj->physicalDevices[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkBool32(&obj->subsetAllocation, "subsetAllocation", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkDeviceGroupDeviceCreateInfo(const VkDeviceGroupDeviceCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->physicalDeviceCount, "physicalDeviceCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPhysicalDevices\" :");
     if (obj->pPhysicalDevices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->physicalDeviceCount); i++) {
            char tmp[100];
            sprintf(tmp, "pPhysicalDevices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->physicalDeviceCount);
            print_VkPhysicalDevice(&obj->pPhysicalDevices[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkBufferMemoryRequirementsInfo2(const VkBufferMemoryRequirementsInfo2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkImageMemoryRequirementsInfo2(const VkImageMemoryRequirementsInfo2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"image\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkMemoryRequirements2(const VkMemoryRequirements2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"memoryRequirements\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkMemoryRequirements(&obj->memoryRequirements, "memoryRequirements", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceFeatures2(const VkPhysicalDeviceFeatures2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"features\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPhysicalDeviceFeatures(&obj->features, "features", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceProperties2(const VkPhysicalDeviceProperties2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"properties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPhysicalDeviceProperties(&obj->properties, "properties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkFormatProperties2(const VkFormatProperties2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"formatProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkFormatProperties(&obj->formatProperties, "formatProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkImageFormatProperties2(const VkImageFormatProperties2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageFormatProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageFormatProperties(&obj->imageFormatProperties, "imageFormatProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceImageFormatInfo2(const VkPhysicalDeviceImageFormatInfo2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkFormat(&obj->format, "format", 1);

     print_VkImageType(&obj->type, "type", 1);

     print_VkImageTiling(&obj->tiling, "tiling", 1);

     print_VkImageUsageFlags(&obj->usage, "usage", 1);

     print_VkImageCreateFlags(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkQueueFamilyProperties2(const VkQueueFamilyProperties2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"queueFamilyProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkQueueFamilyProperties(&obj->queueFamilyProperties, "queueFamilyProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceMemoryProperties2(const VkPhysicalDeviceMemoryProperties2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"memoryProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPhysicalDeviceMemoryProperties(&obj->memoryProperties, "memoryProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDevicePointClippingProperties(const VkPhysicalDevicePointClippingProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPointClippingBehavior(&obj->pointClippingBehavior, "pointClippingBehavior", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkInputAttachmentAspectReference(const VkInputAttachmentAspectReference * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->subpass, "subpass", 1);

     print_uint32_t(&obj->inputAttachmentIndex, "inputAttachmentIndex", 1);

     print_VkImageAspectFlags(&obj->aspectMask, "aspectMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkRenderPassInputAttachmentAspectCreateInfo(const VkRenderPassInputAttachmentAspectCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->aspectReferenceCount, "aspectReferenceCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAspectReferences\" :");
     if (obj->pAspectReferences) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->aspectReferenceCount); i++) {
             if (i+1 == *(&obj->aspectReferenceCount))
                 print_VkInputAttachmentAspectReference(&obj->pAspectReferences[i], "pAspectReferences", 0);
             else
                 print_VkInputAttachmentAspectReference(&obj->pAspectReferences[i], "pAspectReferences", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkImageViewUsageCreateInfo(const VkImageViewUsageCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageUsageFlags(&obj->usage, "usage", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPipelineTessellationDomainOriginStateCreateInfo(const VkPipelineTessellationDomainOriginStateCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkTessellationDomainOrigin(&obj->domainOrigin, "domainOrigin", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkRenderPassMultiviewCreateInfo(const VkRenderPassMultiviewCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->subpassCount, "subpassCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pViewMasks\" :");
     if (obj->pViewMasks) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->subpassCount); i++) {
            char tmp[100];
            sprintf(tmp, "pViewMasks_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->subpassCount);
            print_uint32_t(&obj->pViewMasks[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->dependencyCount, "dependencyCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pViewOffsets\" :");
     if (obj->pViewOffsets) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->dependencyCount); i++) {
            char tmp[100];
            sprintf(tmp, "pViewOffsets_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->dependencyCount);
            print_int32_t(&obj->pViewOffsets[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->correlationMaskCount, "correlationMaskCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCorrelationMasks\" :");
     if (obj->pCorrelationMasks) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->correlationMaskCount); i++) {
            char tmp[100];
            sprintf(tmp, "pCorrelationMasks_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->correlationMaskCount);
            print_uint32_t(&obj->pCorrelationMasks[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceMultiviewFeatures(const VkPhysicalDeviceMultiviewFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->multiview, "multiview", 1);

     print_VkBool32(&obj->multiviewGeometryShader, "multiviewGeometryShader", 1);

     print_VkBool32(&obj->multiviewTessellationShader, "multiviewTessellationShader", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceMultiviewProperties(const VkPhysicalDeviceMultiviewProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxMultiviewViewCount, "maxMultiviewViewCount", 1);

     print_uint32_t(&obj->maxMultiviewInstanceIndex, "maxMultiviewInstanceIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceVariablePointersFeatures(const VkPhysicalDeviceVariablePointersFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->variablePointersStorageBuffer, "variablePointersStorageBuffer", 1);

     print_VkBool32(&obj->variablePointers, "variablePointers", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
typedef VkPhysicalDeviceVariablePointersFeatures VkPhysicalDeviceVariablePointerFeatures;

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceProtectedMemoryFeatures(const VkPhysicalDeviceProtectedMemoryFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->protectedMemory, "protectedMemory", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceProtectedMemoryProperties(const VkPhysicalDeviceProtectedMemoryProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->protectedNoFault, "protectedNoFault", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkDeviceQueueInfo2(const VkDeviceQueueInfo2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceQueueCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->queueFamilyIndex, "queueFamilyIndex", 1);

     print_uint32_t(&obj->queueIndex, "queueIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkProtectedSubmitInfo(const VkProtectedSubmitInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->protectedSubmit, "protectedSubmit", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkSamplerYcbcrConversionCreateInfo(const VkSamplerYcbcrConversionCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkFormat(&obj->format, "format", 1);

     print_VkSamplerYcbcrModelConversion(&obj->ycbcrModel, "ycbcrModel", 1);

     print_VkSamplerYcbcrRange(&obj->ycbcrRange, "ycbcrRange", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"components\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkComponentMapping(&obj->components, "components", 1);
     }

     print_VkChromaLocation(&obj->xChromaOffset, "xChromaOffset", 1);

     print_VkChromaLocation(&obj->yChromaOffset, "yChromaOffset", 1);

     print_VkFilter(&obj->chromaFilter, "chromaFilter", 1);

     print_VkBool32(&obj->forceExplicitReconstruction, "forceExplicitReconstruction", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkSamplerYcbcrConversionInfo(const VkSamplerYcbcrConversionInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"conversion\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkBindImagePlaneMemoryInfo(const VkBindImagePlaneMemoryInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageAspectFlagBits(&obj->planeAspect, "planeAspect", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkImagePlaneMemoryRequirementsInfo(const VkImagePlaneMemoryRequirementsInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageAspectFlagBits(&obj->planeAspect, "planeAspect", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceSamplerYcbcrConversionFeatures(const VkPhysicalDeviceSamplerYcbcrConversionFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->samplerYcbcrConversion, "samplerYcbcrConversion", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkSamplerYcbcrConversionImageFormatProperties(const VkSamplerYcbcrConversionImageFormatProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->combinedImageSamplerDescriptorCount, "combinedImageSamplerDescriptorCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalMemoryProperties(const VkExternalMemoryProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkExternalMemoryFeatureFlags(&obj->externalMemoryFeatures, "externalMemoryFeatures", 1);

     print_VkExternalMemoryHandleTypeFlags(&obj->exportFromImportedHandleTypes, "exportFromImportedHandleTypes", 1);

     print_VkExternalMemoryHandleTypeFlags(&obj->compatibleHandleTypes, "compatibleHandleTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceExternalImageFormatInfo(const VkPhysicalDeviceExternalImageFormatInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalMemoryHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalImageFormatProperties(const VkExternalImageFormatProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"externalMemoryProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExternalMemoryProperties(&obj->externalMemoryProperties, "externalMemoryProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceExternalBufferInfo(const VkPhysicalDeviceExternalBufferInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBufferCreateFlags(&obj->flags, "flags", 1);

     print_VkBufferUsageFlags(&obj->usage, "usage", 1);

     print_VkExternalMemoryHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalBufferProperties(const VkExternalBufferProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"externalMemoryProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExternalMemoryProperties(&obj->externalMemoryProperties, "externalMemoryProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceIDProperties(const VkPhysicalDeviceIDProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"deviceUUID\" :");
     if (obj->deviceUUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "deviceUUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->deviceUUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"driverUUID\" :");
     if (obj->driverUUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "driverUUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->driverUUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"deviceLUID\" :");
     if (obj->deviceLUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_LUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "deviceLUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_LUID_SIZE);
            print_uint8_t(&obj->deviceLUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->deviceNodeMask, "deviceNodeMask", 1);

     print_VkBool32(&obj->deviceLUIDValid, "deviceLUIDValid", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalMemoryImageCreateInfo(const VkExternalMemoryImageCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalMemoryHandleTypeFlags(&obj->handleTypes, "handleTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalMemoryBufferCreateInfo(const VkExternalMemoryBufferCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalMemoryHandleTypeFlags(&obj->handleTypes, "handleTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExportMemoryAllocateInfo(const VkExportMemoryAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalMemoryHandleTypeFlags(&obj->handleTypes, "handleTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceExternalFenceInfo(const VkPhysicalDeviceExternalFenceInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalFenceHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalFenceProperties(const VkExternalFenceProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalFenceHandleTypeFlags(&obj->exportFromImportedHandleTypes, "exportFromImportedHandleTypes", 1);

     print_VkExternalFenceHandleTypeFlags(&obj->compatibleHandleTypes, "compatibleHandleTypes", 1);

     print_VkExternalFenceFeatureFlags(&obj->externalFenceFeatures, "externalFenceFeatures", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExportFenceCreateInfo(const VkExportFenceCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalFenceHandleTypeFlags(&obj->handleTypes, "handleTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExportSemaphoreCreateInfo(const VkExportSemaphoreCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalSemaphoreHandleTypeFlags(&obj->handleTypes, "handleTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceExternalSemaphoreInfo(const VkPhysicalDeviceExternalSemaphoreInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalSemaphoreHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkExternalSemaphoreProperties(const VkExternalSemaphoreProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalSemaphoreHandleTypeFlags(&obj->exportFromImportedHandleTypes, "exportFromImportedHandleTypes", 1);

     print_VkExternalSemaphoreHandleTypeFlags(&obj->compatibleHandleTypes, "compatibleHandleTypes", 1);

     print_VkExternalSemaphoreFeatureFlags(&obj->externalSemaphoreFeatures, "externalSemaphoreFeatures", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceMaintenance3Properties(const VkPhysicalDeviceMaintenance3Properties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxPerSetDescriptors, "maxPerSetDescriptors", 1);

     print_VkDeviceSize(&obj->maxMemoryAllocationSize, "maxMemoryAllocationSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkDescriptorSetLayoutSupport(const VkDescriptorSetLayoutSupport * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->supported, "supported", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
void print_VkPhysicalDeviceShaderDrawParametersFeatures(const VkPhysicalDeviceShaderDrawParametersFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderDrawParameters, "shaderDrawParameters", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_1
typedef VkPhysicalDeviceShaderDrawParametersFeatures VkPhysicalDeviceShaderDrawParameterFeatures;

#endif
#ifdef VK_VERSION_1_2
static const char* VkDriverId_map(int o) {
switch (o) {
    case 1: return "VK_DRIVER_ID_AMD_PROPRIETARY";
    case 2: return "VK_DRIVER_ID_AMD_OPEN_SOURCE";
    case 3: return "VK_DRIVER_ID_MESA_RADV";
    case 4: return "VK_DRIVER_ID_NVIDIA_PROPRIETARY";
    case 5: return "VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS";
    case 6: return "VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA";
    case 7: return "VK_DRIVER_ID_IMAGINATION_PROPRIETARY";
    case 8: return "VK_DRIVER_ID_QUALCOMM_PROPRIETARY";
    case 9: return "VK_DRIVER_ID_ARM_PROPRIETARY";
    case 10: return "VK_DRIVER_ID_GOOGLE_SWIFTSHADER";
    case 11: return "VK_DRIVER_ID_GGP_PROPRIETARY";
    case 12: return "VK_DRIVER_ID_BROADCOM_PROPRIETARY";
    case 13: return "VK_DRIVER_ID_MESA_LLVMPIPE";
    case 14: return "VK_DRIVER_ID_MOLTENVK";
    case 15: return "VK_DRIVER_ID_COREAVI_PROPRIETARY";
    case 16: return "VK_DRIVER_ID_JUICE_PROPRIETARY";
    case 17: return "VK_DRIVER_ID_VERISILICON_PROPRIETARY";
    case 18: return "VK_DRIVER_ID_MESA_TURNIP";
    case 19: return "VK_DRIVER_ID_MESA_V3DV";
    case 20: return "VK_DRIVER_ID_MESA_PANVK";
    case 21: return "VK_DRIVER_ID_SAMSUNG_PROPRIETARY";
   }
   return NULL;
}
void print_VkDriverId(const VkDriverId* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDriverId_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
static const char* VkShaderFloatControlsIndependence_map(int o) {
switch (o) {
    case 0: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY";
    case 1: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL";
    case 2: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE";
   }
   return NULL;
}
void print_VkShaderFloatControlsIndependence(const VkShaderFloatControlsIndependence* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkShaderFloatControlsIndependence_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
static const char* VkResolveModeFlagBits_map(int o) {
switch (o) {
    case 0: return "VK_RESOLVE_MODE_NONE";
    case (1 << 0): return "VK_RESOLVE_MODE_SAMPLE_ZERO_BIT";
    case (1 << 1): return "VK_RESOLVE_MODE_AVERAGE_BIT";
    case (1 << 2): return "VK_RESOLVE_MODE_MIN_BIT";
    case (1 << 3): return "VK_RESOLVE_MODE_MAX_BIT";
   }
   return NULL;
}
void print_VkResolveModeFlagBits(const VkResolveModeFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkResolveModeFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
static const char* VkDescriptorBindingFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT";
    case (1 << 1): return "VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT";
    case (1 << 2): return "VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT";
    case (1 << 3): return "VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT";
    case (1 << 4): return "VK_DESCRIPTOR_BINDING_RESERVED_4_BIT_QCOM";
   }
   return NULL;
}
void print_VkDescriptorBindingFlagBits(const VkDescriptorBindingFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDescriptorBindingFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
static const char* VkSamplerReductionMode_map(int o) {
switch (o) {
    case 0: return "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE";
    case 1: return "VK_SAMPLER_REDUCTION_MODE_MIN";
    case 2: return "VK_SAMPLER_REDUCTION_MODE_MAX";
   }
   return NULL;
}
void print_VkSamplerReductionMode(const VkSamplerReductionMode* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSamplerReductionMode_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
static const char* VkSemaphoreType_map(int o) {
switch (o) {
    case 0: return "VK_SEMAPHORE_TYPE_BINARY";
    case 1: return "VK_SEMAPHORE_TYPE_TIMELINE";
   }
   return NULL;
}
void print_VkSemaphoreType(const VkSemaphoreType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSemaphoreType_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
static const char* VkSemaphoreWaitFlagBits_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SEMAPHORE_WAIT_ANY_BIT";
   }
   return NULL;
}
void print_VkSemaphoreWaitFlagBits(const VkSemaphoreWaitFlagBits* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSemaphoreWaitFlagBits_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkResolveModeFlags(const VkResolveModeFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkResolveModeFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkResolveModeFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkDescriptorBindingFlags(const VkDescriptorBindingFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDescriptorBindingFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDescriptorBindingFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSemaphoreWaitFlags(const VkSemaphoreWaitFlags * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSemaphoreWaitFlagBits_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSemaphoreWaitFlagBits_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceVulkan11Features(const VkPhysicalDeviceVulkan11Features * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->storageBuffer16BitAccess, "storageBuffer16BitAccess", 1);

     print_VkBool32(&obj->uniformAndStorageBuffer16BitAccess, "uniformAndStorageBuffer16BitAccess", 1);

     print_VkBool32(&obj->storagePushConstant16, "storagePushConstant16", 1);

     print_VkBool32(&obj->storageInputOutput16, "storageInputOutput16", 1);

     print_VkBool32(&obj->multiview, "multiview", 1);

     print_VkBool32(&obj->multiviewGeometryShader, "multiviewGeometryShader", 1);

     print_VkBool32(&obj->multiviewTessellationShader, "multiviewTessellationShader", 1);

     print_VkBool32(&obj->variablePointersStorageBuffer, "variablePointersStorageBuffer", 1);

     print_VkBool32(&obj->variablePointers, "variablePointers", 1);

     print_VkBool32(&obj->protectedMemory, "protectedMemory", 1);

     print_VkBool32(&obj->samplerYcbcrConversion, "samplerYcbcrConversion", 1);

     print_VkBool32(&obj->shaderDrawParameters, "shaderDrawParameters", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceVulkan11Properties(const VkPhysicalDeviceVulkan11Properties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"deviceUUID\" :");
     if (obj->deviceUUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "deviceUUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->deviceUUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"driverUUID\" :");
     if (obj->driverUUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "driverUUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->driverUUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"deviceLUID\" :");
     if (obj->deviceLUID) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_LUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "deviceLUID_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_LUID_SIZE);
            print_uint8_t(&obj->deviceLUID[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->deviceNodeMask, "deviceNodeMask", 1);

     print_VkBool32(&obj->deviceLUIDValid, "deviceLUIDValid", 1);

     print_uint32_t(&obj->subgroupSize, "subgroupSize", 1);

     print_VkShaderStageFlags(&obj->subgroupSupportedStages, "subgroupSupportedStages", 1);

     print_VkSubgroupFeatureFlags(&obj->subgroupSupportedOperations, "subgroupSupportedOperations", 1);

     print_VkBool32(&obj->subgroupQuadOperationsInAllStages, "subgroupQuadOperationsInAllStages", 1);

     print_VkPointClippingBehavior(&obj->pointClippingBehavior, "pointClippingBehavior", 1);

     print_uint32_t(&obj->maxMultiviewViewCount, "maxMultiviewViewCount", 1);

     print_uint32_t(&obj->maxMultiviewInstanceIndex, "maxMultiviewInstanceIndex", 1);

     print_VkBool32(&obj->protectedNoFault, "protectedNoFault", 1);

     print_uint32_t(&obj->maxPerSetDescriptors, "maxPerSetDescriptors", 1);

     print_VkDeviceSize(&obj->maxMemoryAllocationSize, "maxMemoryAllocationSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceVulkan12Features(const VkPhysicalDeviceVulkan12Features * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->samplerMirrorClampToEdge, "samplerMirrorClampToEdge", 1);

     print_VkBool32(&obj->drawIndirectCount, "drawIndirectCount", 1);

     print_VkBool32(&obj->storageBuffer8BitAccess, "storageBuffer8BitAccess", 1);

     print_VkBool32(&obj->uniformAndStorageBuffer8BitAccess, "uniformAndStorageBuffer8BitAccess", 1);

     print_VkBool32(&obj->storagePushConstant8, "storagePushConstant8", 1);

     print_VkBool32(&obj->shaderBufferInt64Atomics, "shaderBufferInt64Atomics", 1);

     print_VkBool32(&obj->shaderSharedInt64Atomics, "shaderSharedInt64Atomics", 1);

     print_VkBool32(&obj->shaderFloat16, "shaderFloat16", 1);

     print_VkBool32(&obj->shaderInt8, "shaderInt8", 1);

     print_VkBool32(&obj->descriptorIndexing, "descriptorIndexing", 1);

     print_VkBool32(&obj->shaderInputAttachmentArrayDynamicIndexing, "shaderInputAttachmentArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderUniformTexelBufferArrayDynamicIndexing, "shaderUniformTexelBufferArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderStorageTexelBufferArrayDynamicIndexing, "shaderStorageTexelBufferArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderUniformBufferArrayNonUniformIndexing, "shaderUniformBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderSampledImageArrayNonUniformIndexing, "shaderSampledImageArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderStorageBufferArrayNonUniformIndexing, "shaderStorageBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderStorageImageArrayNonUniformIndexing, "shaderStorageImageArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderInputAttachmentArrayNonUniformIndexing, "shaderInputAttachmentArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderUniformTexelBufferArrayNonUniformIndexing, "shaderUniformTexelBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderStorageTexelBufferArrayNonUniformIndexing, "shaderStorageTexelBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->descriptorBindingUniformBufferUpdateAfterBind, "descriptorBindingUniformBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingSampledImageUpdateAfterBind, "descriptorBindingSampledImageUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingStorageImageUpdateAfterBind, "descriptorBindingStorageImageUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingStorageBufferUpdateAfterBind, "descriptorBindingStorageBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingUniformTexelBufferUpdateAfterBind, "descriptorBindingUniformTexelBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingStorageTexelBufferUpdateAfterBind, "descriptorBindingStorageTexelBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingUpdateUnusedWhilePending, "descriptorBindingUpdateUnusedWhilePending", 1);

     print_VkBool32(&obj->descriptorBindingPartiallyBound, "descriptorBindingPartiallyBound", 1);

     print_VkBool32(&obj->descriptorBindingVariableDescriptorCount, "descriptorBindingVariableDescriptorCount", 1);

     print_VkBool32(&obj->runtimeDescriptorArray, "runtimeDescriptorArray", 1);

     print_VkBool32(&obj->samplerFilterMinmax, "samplerFilterMinmax", 1);

     print_VkBool32(&obj->scalarBlockLayout, "scalarBlockLayout", 1);

     print_VkBool32(&obj->imagelessFramebuffer, "imagelessFramebuffer", 1);

     print_VkBool32(&obj->uniformBufferStandardLayout, "uniformBufferStandardLayout", 1);

     print_VkBool32(&obj->shaderSubgroupExtendedTypes, "shaderSubgroupExtendedTypes", 1);

     print_VkBool32(&obj->separateDepthStencilLayouts, "separateDepthStencilLayouts", 1);

     print_VkBool32(&obj->hostQueryReset, "hostQueryReset", 1);

     print_VkBool32(&obj->timelineSemaphore, "timelineSemaphore", 1);

     print_VkBool32(&obj->bufferDeviceAddress, "bufferDeviceAddress", 1);

     print_VkBool32(&obj->bufferDeviceAddressCaptureReplay, "bufferDeviceAddressCaptureReplay", 1);

     print_VkBool32(&obj->bufferDeviceAddressMultiDevice, "bufferDeviceAddressMultiDevice", 1);

     print_VkBool32(&obj->vulkanMemoryModel, "vulkanMemoryModel", 1);

     print_VkBool32(&obj->vulkanMemoryModelDeviceScope, "vulkanMemoryModelDeviceScope", 1);

     print_VkBool32(&obj->vulkanMemoryModelAvailabilityVisibilityChains, "vulkanMemoryModelAvailabilityVisibilityChains", 1);

     print_VkBool32(&obj->shaderOutputViewportIndex, "shaderOutputViewportIndex", 1);

     print_VkBool32(&obj->shaderOutputLayer, "shaderOutputLayer", 1);

     print_VkBool32(&obj->subgroupBroadcastDynamicId, "subgroupBroadcastDynamicId", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkConformanceVersion(const VkConformanceVersion * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint8_t(&obj->major, "major", 1);

     print_uint8_t(&obj->minor, "minor", 1);

     print_uint8_t(&obj->subminor, "subminor", 1);

     print_uint8_t(&obj->patch, "patch", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceVulkan12Properties(const VkPhysicalDeviceVulkan12Properties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDriverId(&obj->driverID, "driverID", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"driverName\" :");
     if (obj->driverName) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DRIVER_NAME_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "driverName_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DRIVER_NAME_SIZE);
            print_char(&obj->driverName[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"driverInfo\" :");
     if (obj->driverInfo) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DRIVER_INFO_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "driverInfo_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DRIVER_INFO_SIZE);
            print_char(&obj->driverInfo[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"conformanceVersion\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkConformanceVersion(&obj->conformanceVersion, "conformanceVersion", 1);
     }

     print_VkShaderFloatControlsIndependence(&obj->denormBehaviorIndependence, "denormBehaviorIndependence", 1);

     print_VkShaderFloatControlsIndependence(&obj->roundingModeIndependence, "roundingModeIndependence", 1);

     print_VkBool32(&obj->shaderSignedZeroInfNanPreserveFloat16, "shaderSignedZeroInfNanPreserveFloat16", 1);

     print_VkBool32(&obj->shaderSignedZeroInfNanPreserveFloat32, "shaderSignedZeroInfNanPreserveFloat32", 1);

     print_VkBool32(&obj->shaderSignedZeroInfNanPreserveFloat64, "shaderSignedZeroInfNanPreserveFloat64", 1);

     print_VkBool32(&obj->shaderDenormPreserveFloat16, "shaderDenormPreserveFloat16", 1);

     print_VkBool32(&obj->shaderDenormPreserveFloat32, "shaderDenormPreserveFloat32", 1);

     print_VkBool32(&obj->shaderDenormPreserveFloat64, "shaderDenormPreserveFloat64", 1);

     print_VkBool32(&obj->shaderDenormFlushToZeroFloat16, "shaderDenormFlushToZeroFloat16", 1);

     print_VkBool32(&obj->shaderDenormFlushToZeroFloat32, "shaderDenormFlushToZeroFloat32", 1);

     print_VkBool32(&obj->shaderDenormFlushToZeroFloat64, "shaderDenormFlushToZeroFloat64", 1);

     print_VkBool32(&obj->shaderRoundingModeRTEFloat16, "shaderRoundingModeRTEFloat16", 1);

     print_VkBool32(&obj->shaderRoundingModeRTEFloat32, "shaderRoundingModeRTEFloat32", 1);

     print_VkBool32(&obj->shaderRoundingModeRTEFloat64, "shaderRoundingModeRTEFloat64", 1);

     print_VkBool32(&obj->shaderRoundingModeRTZFloat16, "shaderRoundingModeRTZFloat16", 1);

     print_VkBool32(&obj->shaderRoundingModeRTZFloat32, "shaderRoundingModeRTZFloat32", 1);

     print_VkBool32(&obj->shaderRoundingModeRTZFloat64, "shaderRoundingModeRTZFloat64", 1);

     print_uint32_t(&obj->maxUpdateAfterBindDescriptorsInAllPools, "maxUpdateAfterBindDescriptorsInAllPools", 1);

     print_VkBool32(&obj->shaderUniformBufferArrayNonUniformIndexingNative, "shaderUniformBufferArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderSampledImageArrayNonUniformIndexingNative, "shaderSampledImageArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderStorageBufferArrayNonUniformIndexingNative, "shaderStorageBufferArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderStorageImageArrayNonUniformIndexingNative, "shaderStorageImageArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderInputAttachmentArrayNonUniformIndexingNative, "shaderInputAttachmentArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->robustBufferAccessUpdateAfterBind, "robustBufferAccessUpdateAfterBind", 1);

     print_VkBool32(&obj->quadDivergentImplicitLod, "quadDivergentImplicitLod", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindSamplers, "maxPerStageDescriptorUpdateAfterBindSamplers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindUniformBuffers, "maxPerStageDescriptorUpdateAfterBindUniformBuffers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindStorageBuffers, "maxPerStageDescriptorUpdateAfterBindStorageBuffers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindSampledImages, "maxPerStageDescriptorUpdateAfterBindSampledImages", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindStorageImages, "maxPerStageDescriptorUpdateAfterBindStorageImages", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindInputAttachments, "maxPerStageDescriptorUpdateAfterBindInputAttachments", 1);

     print_uint32_t(&obj->maxPerStageUpdateAfterBindResources, "maxPerStageUpdateAfterBindResources", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindSamplers, "maxDescriptorSetUpdateAfterBindSamplers", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindUniformBuffers, "maxDescriptorSetUpdateAfterBindUniformBuffers", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindStorageBuffers, "maxDescriptorSetUpdateAfterBindStorageBuffers", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindSampledImages, "maxDescriptorSetUpdateAfterBindSampledImages", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindStorageImages, "maxDescriptorSetUpdateAfterBindStorageImages", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindInputAttachments, "maxDescriptorSetUpdateAfterBindInputAttachments", 1);

     print_VkResolveModeFlags(&obj->supportedDepthResolveModes, "supportedDepthResolveModes", 1);

     print_VkResolveModeFlags(&obj->supportedStencilResolveModes, "supportedStencilResolveModes", 1);

     print_VkBool32(&obj->independentResolveNone, "independentResolveNone", 1);

     print_VkBool32(&obj->independentResolve, "independentResolve", 1);

     print_VkBool32(&obj->filterMinmaxSingleComponentFormats, "filterMinmaxSingleComponentFormats", 1);

     print_VkBool32(&obj->filterMinmaxImageComponentMapping, "filterMinmaxImageComponentMapping", 1);

     print_uint64_t(&obj->maxTimelineSemaphoreValueDifference, "maxTimelineSemaphoreValueDifference", 1);

     print_VkSampleCountFlags(&obj->framebufferIntegerColorSampleCounts, "framebufferIntegerColorSampleCounts", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkImageFormatListCreateInfo(const VkImageFormatListCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->viewFormatCount, "viewFormatCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pViewFormats\" :");
     if (obj->pViewFormats) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->viewFormatCount); i++) {
            char tmp[100];
            sprintf(tmp, "pViewFormats_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->viewFormatCount);
            print_VkFormat(&obj->pViewFormats[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkAttachmentDescription2(const VkAttachmentDescription2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkAttachmentDescriptionFlags(&obj->flags, "flags", 1);

     print_VkFormat(&obj->format, "format", 1);

     print_VkSampleCountFlagBits(&obj->samples, "samples", 1);

     print_VkAttachmentLoadOp(&obj->loadOp, "loadOp", 1);

     print_VkAttachmentStoreOp(&obj->storeOp, "storeOp", 1);

     print_VkAttachmentLoadOp(&obj->stencilLoadOp, "stencilLoadOp", 1);

     print_VkAttachmentStoreOp(&obj->stencilStoreOp, "stencilStoreOp", 1);

     print_VkImageLayout(&obj->initialLayout, "initialLayout", 1);

     print_VkImageLayout(&obj->finalLayout, "finalLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkAttachmentReference2(const VkAttachmentReference2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->attachment, "attachment", 1);

     print_VkImageLayout(&obj->layout, "layout", 1);

     print_VkImageAspectFlags(&obj->aspectMask, "aspectMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSubpassDescription2(const VkSubpassDescription2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSubpassDescriptionFlags(&obj->flags, "flags", 1);

     print_VkPipelineBindPoint(&obj->pipelineBindPoint, "pipelineBindPoint", 1);

     print_uint32_t(&obj->viewMask, "viewMask", 1);

     print_uint32_t(&obj->inputAttachmentCount, "inputAttachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pInputAttachments\" :");
     if (obj->pInputAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->inputAttachmentCount); i++) {
             if (i+1 == *(&obj->inputAttachmentCount))
                 print_VkAttachmentReference2(&obj->pInputAttachments[i], "pInputAttachments", 0);
             else
                 print_VkAttachmentReference2(&obj->pInputAttachments[i], "pInputAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->colorAttachmentCount, "colorAttachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pColorAttachments\" :");
     if (obj->pColorAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->colorAttachmentCount); i++) {
             if (i+1 == *(&obj->colorAttachmentCount))
                 print_VkAttachmentReference2(&obj->pColorAttachments[i], "pColorAttachments", 0);
             else
                 print_VkAttachmentReference2(&obj->pColorAttachments[i], "pColorAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pResolveAttachments\" :");
     if (obj->pResolveAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->colorAttachmentCount); i++) {
             if (i+1 == *(&obj->colorAttachmentCount))
                 print_VkAttachmentReference2(&obj->pResolveAttachments[i], "pResolveAttachments", 0);
             else
                 print_VkAttachmentReference2(&obj->pResolveAttachments[i], "pResolveAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDepthStencilAttachment\" :");
     if (obj->pDepthStencilAttachment) {
         vk_json_printf(_OUT, "\n");
         print_VkAttachmentReference2(*(&obj->pDepthStencilAttachment), "pDepthStencilAttachment", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->preserveAttachmentCount, "preserveAttachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPreserveAttachments\" :");
     if (obj->pPreserveAttachments) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->preserveAttachmentCount); i++) {
            char tmp[100];
            sprintf(tmp, "pPreserveAttachments_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->preserveAttachmentCount);
            print_uint32_t(&obj->pPreserveAttachments[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSubpassDependency2(const VkSubpassDependency2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->srcSubpass, "srcSubpass", 1);

     print_uint32_t(&obj->dstSubpass, "dstSubpass", 1);

     print_VkPipelineStageFlags(&obj->srcStageMask, "srcStageMask", 1);

     print_VkPipelineStageFlags(&obj->dstStageMask, "dstStageMask", 1);

     print_VkAccessFlags(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkAccessFlags(&obj->dstAccessMask, "dstAccessMask", 1);

     print_VkDependencyFlags(&obj->dependencyFlags, "dependencyFlags", 1);

     print_int32_t(&obj->viewOffset, "viewOffset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkRenderPassCreateInfo2(const VkRenderPassCreateInfo2 * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkRenderPassCreateFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->attachmentCount, "attachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachments\" :");
     if (obj->pAttachments) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->attachmentCount); i++) {
             if (i+1 == *(&obj->attachmentCount))
                 print_VkAttachmentDescription2(&obj->pAttachments[i], "pAttachments", 0);
             else
                 print_VkAttachmentDescription2(&obj->pAttachments[i], "pAttachments", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->subpassCount, "subpassCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSubpasses\" :");
     if (obj->pSubpasses) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->subpassCount); i++) {
             if (i+1 == *(&obj->subpassCount))
                 print_VkSubpassDescription2(&obj->pSubpasses[i], "pSubpasses", 0);
             else
                 print_VkSubpassDescription2(&obj->pSubpasses[i], "pSubpasses", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->dependencyCount, "dependencyCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDependencies\" :");
     if (obj->pDependencies) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->dependencyCount); i++) {
             if (i+1 == *(&obj->dependencyCount))
                 print_VkSubpassDependency2(&obj->pDependencies[i], "pDependencies", 0);
             else
                 print_VkSubpassDependency2(&obj->pDependencies[i], "pDependencies", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->correlatedViewMaskCount, "correlatedViewMaskCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCorrelatedViewMasks\" :");
     if (obj->pCorrelatedViewMasks) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->correlatedViewMaskCount); i++) {
            char tmp[100];
            sprintf(tmp, "pCorrelatedViewMasks_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->correlatedViewMaskCount);
            print_uint32_t(&obj->pCorrelatedViewMasks[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSubpassBeginInfo(const VkSubpassBeginInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSubpassContents(&obj->contents, "contents", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSubpassEndInfo(const VkSubpassEndInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDevice8BitStorageFeatures(const VkPhysicalDevice8BitStorageFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->storageBuffer8BitAccess, "storageBuffer8BitAccess", 1);

     print_VkBool32(&obj->uniformAndStorageBuffer8BitAccess, "uniformAndStorageBuffer8BitAccess", 1);

     print_VkBool32(&obj->storagePushConstant8, "storagePushConstant8", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceDriverProperties(const VkPhysicalDeviceDriverProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDriverId(&obj->driverID, "driverID", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"driverName\" :");
     if (obj->driverName) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DRIVER_NAME_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "driverName_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DRIVER_NAME_SIZE);
            print_char(&obj->driverName[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"driverInfo\" :");
     if (obj->driverInfo) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DRIVER_INFO_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "driverInfo_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DRIVER_INFO_SIZE);
            print_char(&obj->driverInfo[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"conformanceVersion\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkConformanceVersion(&obj->conformanceVersion, "conformanceVersion", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceShaderAtomicInt64Features(const VkPhysicalDeviceShaderAtomicInt64Features * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderBufferInt64Atomics, "shaderBufferInt64Atomics", 1);

     print_VkBool32(&obj->shaderSharedInt64Atomics, "shaderSharedInt64Atomics", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceShaderFloat16Int8Features(const VkPhysicalDeviceShaderFloat16Int8Features * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderFloat16, "shaderFloat16", 1);

     print_VkBool32(&obj->shaderInt8, "shaderInt8", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceFloatControlsProperties(const VkPhysicalDeviceFloatControlsProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkShaderFloatControlsIndependence(&obj->denormBehaviorIndependence, "denormBehaviorIndependence", 1);

     print_VkShaderFloatControlsIndependence(&obj->roundingModeIndependence, "roundingModeIndependence", 1);

     print_VkBool32(&obj->shaderSignedZeroInfNanPreserveFloat16, "shaderSignedZeroInfNanPreserveFloat16", 1);

     print_VkBool32(&obj->shaderSignedZeroInfNanPreserveFloat32, "shaderSignedZeroInfNanPreserveFloat32", 1);

     print_VkBool32(&obj->shaderSignedZeroInfNanPreserveFloat64, "shaderSignedZeroInfNanPreserveFloat64", 1);

     print_VkBool32(&obj->shaderDenormPreserveFloat16, "shaderDenormPreserveFloat16", 1);

     print_VkBool32(&obj->shaderDenormPreserveFloat32, "shaderDenormPreserveFloat32", 1);

     print_VkBool32(&obj->shaderDenormPreserveFloat64, "shaderDenormPreserveFloat64", 1);

     print_VkBool32(&obj->shaderDenormFlushToZeroFloat16, "shaderDenormFlushToZeroFloat16", 1);

     print_VkBool32(&obj->shaderDenormFlushToZeroFloat32, "shaderDenormFlushToZeroFloat32", 1);

     print_VkBool32(&obj->shaderDenormFlushToZeroFloat64, "shaderDenormFlushToZeroFloat64", 1);

     print_VkBool32(&obj->shaderRoundingModeRTEFloat16, "shaderRoundingModeRTEFloat16", 1);

     print_VkBool32(&obj->shaderRoundingModeRTEFloat32, "shaderRoundingModeRTEFloat32", 1);

     print_VkBool32(&obj->shaderRoundingModeRTEFloat64, "shaderRoundingModeRTEFloat64", 1);

     print_VkBool32(&obj->shaderRoundingModeRTZFloat16, "shaderRoundingModeRTZFloat16", 1);

     print_VkBool32(&obj->shaderRoundingModeRTZFloat32, "shaderRoundingModeRTZFloat32", 1);

     print_VkBool32(&obj->shaderRoundingModeRTZFloat64, "shaderRoundingModeRTZFloat64", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkDescriptorSetLayoutBindingFlagsCreateInfo(const VkDescriptorSetLayoutBindingFlagsCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->bindingCount, "bindingCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pBindingFlags\" :");
     if (obj->pBindingFlags) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->bindingCount); i++) {
            char tmp[100];
            sprintf(tmp, "pBindingFlags_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->bindingCount);
            print_VkDescriptorBindingFlags(&obj->pBindingFlags[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceDescriptorIndexingFeatures(const VkPhysicalDeviceDescriptorIndexingFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderInputAttachmentArrayDynamicIndexing, "shaderInputAttachmentArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderUniformTexelBufferArrayDynamicIndexing, "shaderUniformTexelBufferArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderStorageTexelBufferArrayDynamicIndexing, "shaderStorageTexelBufferArrayDynamicIndexing", 1);

     print_VkBool32(&obj->shaderUniformBufferArrayNonUniformIndexing, "shaderUniformBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderSampledImageArrayNonUniformIndexing, "shaderSampledImageArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderStorageBufferArrayNonUniformIndexing, "shaderStorageBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderStorageImageArrayNonUniformIndexing, "shaderStorageImageArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderInputAttachmentArrayNonUniformIndexing, "shaderInputAttachmentArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderUniformTexelBufferArrayNonUniformIndexing, "shaderUniformTexelBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->shaderStorageTexelBufferArrayNonUniformIndexing, "shaderStorageTexelBufferArrayNonUniformIndexing", 1);

     print_VkBool32(&obj->descriptorBindingUniformBufferUpdateAfterBind, "descriptorBindingUniformBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingSampledImageUpdateAfterBind, "descriptorBindingSampledImageUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingStorageImageUpdateAfterBind, "descriptorBindingStorageImageUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingStorageBufferUpdateAfterBind, "descriptorBindingStorageBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingUniformTexelBufferUpdateAfterBind, "descriptorBindingUniformTexelBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingStorageTexelBufferUpdateAfterBind, "descriptorBindingStorageTexelBufferUpdateAfterBind", 1);

     print_VkBool32(&obj->descriptorBindingUpdateUnusedWhilePending, "descriptorBindingUpdateUnusedWhilePending", 1);

     print_VkBool32(&obj->descriptorBindingPartiallyBound, "descriptorBindingPartiallyBound", 1);

     print_VkBool32(&obj->descriptorBindingVariableDescriptorCount, "descriptorBindingVariableDescriptorCount", 1);

     print_VkBool32(&obj->runtimeDescriptorArray, "runtimeDescriptorArray", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceDescriptorIndexingProperties(const VkPhysicalDeviceDescriptorIndexingProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxUpdateAfterBindDescriptorsInAllPools, "maxUpdateAfterBindDescriptorsInAllPools", 1);

     print_VkBool32(&obj->shaderUniformBufferArrayNonUniformIndexingNative, "shaderUniformBufferArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderSampledImageArrayNonUniformIndexingNative, "shaderSampledImageArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderStorageBufferArrayNonUniformIndexingNative, "shaderStorageBufferArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderStorageImageArrayNonUniformIndexingNative, "shaderStorageImageArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->shaderInputAttachmentArrayNonUniformIndexingNative, "shaderInputAttachmentArrayNonUniformIndexingNative", 1);

     print_VkBool32(&obj->robustBufferAccessUpdateAfterBind, "robustBufferAccessUpdateAfterBind", 1);

     print_VkBool32(&obj->quadDivergentImplicitLod, "quadDivergentImplicitLod", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindSamplers, "maxPerStageDescriptorUpdateAfterBindSamplers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindUniformBuffers, "maxPerStageDescriptorUpdateAfterBindUniformBuffers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindStorageBuffers, "maxPerStageDescriptorUpdateAfterBindStorageBuffers", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindSampledImages, "maxPerStageDescriptorUpdateAfterBindSampledImages", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindStorageImages, "maxPerStageDescriptorUpdateAfterBindStorageImages", 1);

     print_uint32_t(&obj->maxPerStageDescriptorUpdateAfterBindInputAttachments, "maxPerStageDescriptorUpdateAfterBindInputAttachments", 1);

     print_uint32_t(&obj->maxPerStageUpdateAfterBindResources, "maxPerStageUpdateAfterBindResources", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindSamplers, "maxDescriptorSetUpdateAfterBindSamplers", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindUniformBuffers, "maxDescriptorSetUpdateAfterBindUniformBuffers", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindStorageBuffers, "maxDescriptorSetUpdateAfterBindStorageBuffers", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindSampledImages, "maxDescriptorSetUpdateAfterBindSampledImages", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindStorageImages, "maxDescriptorSetUpdateAfterBindStorageImages", 1);

     print_uint32_t(&obj->maxDescriptorSetUpdateAfterBindInputAttachments, "maxDescriptorSetUpdateAfterBindInputAttachments", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkDescriptorSetVariableDescriptorCountAllocateInfo(const VkDescriptorSetVariableDescriptorCountAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->descriptorSetCount, "descriptorSetCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDescriptorCounts\" :");
     if (obj->pDescriptorCounts) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->descriptorSetCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDescriptorCounts_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->descriptorSetCount);
            print_uint32_t(&obj->pDescriptorCounts[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkDescriptorSetVariableDescriptorCountLayoutSupport(const VkDescriptorSetVariableDescriptorCountLayoutSupport * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxVariableDescriptorCount, "maxVariableDescriptorCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSubpassDescriptionDepthStencilResolve(const VkSubpassDescriptionDepthStencilResolve * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkResolveModeFlagBits(&obj->depthResolveMode, "depthResolveMode", 1);

     print_VkResolveModeFlagBits(&obj->stencilResolveMode, "stencilResolveMode", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDepthStencilResolveAttachment\" :");
     if (obj->pDepthStencilResolveAttachment) {
         vk_json_printf(_OUT, "\n");
         print_VkAttachmentReference2(*(&obj->pDepthStencilResolveAttachment), "pDepthStencilResolveAttachment", 0);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceDepthStencilResolveProperties(const VkPhysicalDeviceDepthStencilResolveProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkResolveModeFlags(&obj->supportedDepthResolveModes, "supportedDepthResolveModes", 1);

     print_VkResolveModeFlags(&obj->supportedStencilResolveModes, "supportedStencilResolveModes", 1);

     print_VkBool32(&obj->independentResolveNone, "independentResolveNone", 1);

     print_VkBool32(&obj->independentResolve, "independentResolve", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceScalarBlockLayoutFeatures(const VkPhysicalDeviceScalarBlockLayoutFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->scalarBlockLayout, "scalarBlockLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkImageStencilUsageCreateInfo(const VkImageStencilUsageCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageUsageFlags(&obj->stencilUsage, "stencilUsage", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSamplerReductionModeCreateInfo(const VkSamplerReductionModeCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSamplerReductionMode(&obj->reductionMode, "reductionMode", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceSamplerFilterMinmaxProperties(const VkPhysicalDeviceSamplerFilterMinmaxProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->filterMinmaxSingleComponentFormats, "filterMinmaxSingleComponentFormats", 1);

     print_VkBool32(&obj->filterMinmaxImageComponentMapping, "filterMinmaxImageComponentMapping", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceVulkanMemoryModelFeatures(const VkPhysicalDeviceVulkanMemoryModelFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->vulkanMemoryModel, "vulkanMemoryModel", 1);

     print_VkBool32(&obj->vulkanMemoryModelDeviceScope, "vulkanMemoryModelDeviceScope", 1);

     print_VkBool32(&obj->vulkanMemoryModelAvailabilityVisibilityChains, "vulkanMemoryModelAvailabilityVisibilityChains", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceImagelessFramebufferFeatures(const VkPhysicalDeviceImagelessFramebufferFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->imagelessFramebuffer, "imagelessFramebuffer", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkFramebufferAttachmentImageInfo(const VkFramebufferAttachmentImageInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageCreateFlags(&obj->flags, "flags", 1);

     print_VkImageUsageFlags(&obj->usage, "usage", 1);

     print_uint32_t(&obj->width, "width", 1);

     print_uint32_t(&obj->height, "height", 1);

     print_uint32_t(&obj->layerCount, "layerCount", 1);

     print_uint32_t(&obj->viewFormatCount, "viewFormatCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pViewFormats\" :");
     if (obj->pViewFormats) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->viewFormatCount); i++) {
            char tmp[100];
            sprintf(tmp, "pViewFormats_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->viewFormatCount);
            print_VkFormat(&obj->pViewFormats[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkFramebufferAttachmentsCreateInfo(const VkFramebufferAttachmentsCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->attachmentImageInfoCount, "attachmentImageInfoCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachmentImageInfos\" :");
     if (obj->pAttachmentImageInfos) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->attachmentImageInfoCount); i++) {
             if (i+1 == *(&obj->attachmentImageInfoCount))
                 print_VkFramebufferAttachmentImageInfo(&obj->pAttachmentImageInfos[i], "pAttachmentImageInfos", 0);
             else
                 print_VkFramebufferAttachmentImageInfo(&obj->pAttachmentImageInfos[i], "pAttachmentImageInfos", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkRenderPassAttachmentBeginInfo(const VkRenderPassAttachmentBeginInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->attachmentCount, "attachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachments\" :");
     if (obj->pAttachments) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->attachmentCount); i++) {
            char tmp[100];
            sprintf(tmp, "pAttachments_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->attachmentCount);
            print_VkImageView(&obj->pAttachments[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(const VkPhysicalDeviceUniformBufferStandardLayoutFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->uniformBufferStandardLayout, "uniformBufferStandardLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderSubgroupExtendedTypes, "shaderSubgroupExtendedTypes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->separateDepthStencilLayouts, "separateDepthStencilLayouts", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkAttachmentReferenceStencilLayout(const VkAttachmentReferenceStencilLayout * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageLayout(&obj->stencilLayout, "stencilLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkAttachmentDescriptionStencilLayout(const VkAttachmentDescriptionStencilLayout * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageLayout(&obj->stencilInitialLayout, "stencilInitialLayout", 1);

     print_VkImageLayout(&obj->stencilFinalLayout, "stencilFinalLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceHostQueryResetFeatures(const VkPhysicalDeviceHostQueryResetFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->hostQueryReset, "hostQueryReset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceTimelineSemaphoreFeatures(const VkPhysicalDeviceTimelineSemaphoreFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->timelineSemaphore, "timelineSemaphore", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceTimelineSemaphoreProperties(const VkPhysicalDeviceTimelineSemaphoreProperties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint64_t(&obj->maxTimelineSemaphoreValueDifference, "maxTimelineSemaphoreValueDifference", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSemaphoreTypeCreateInfo(const VkSemaphoreTypeCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSemaphoreType(&obj->semaphoreType, "semaphoreType", 1);

     print_uint64_t(&obj->initialValue, "initialValue", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkTimelineSemaphoreSubmitInfo(const VkTimelineSemaphoreSubmitInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->waitSemaphoreValueCount, "waitSemaphoreValueCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pWaitSemaphoreValues\" :");
     if (obj->pWaitSemaphoreValues) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->waitSemaphoreValueCount); i++) {
            char tmp[100];
            sprintf(tmp, "pWaitSemaphoreValues_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->waitSemaphoreValueCount);
            print_uint64_t(&obj->pWaitSemaphoreValues[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->signalSemaphoreValueCount, "signalSemaphoreValueCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSignalSemaphoreValues\" :");
     if (obj->pSignalSemaphoreValues) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->signalSemaphoreValueCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSignalSemaphoreValues_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->signalSemaphoreValueCount);
            print_uint64_t(&obj->pSignalSemaphoreValues[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSemaphoreWaitInfo(const VkSemaphoreWaitInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSemaphoreWaitFlags(&obj->flags, "flags", 1);

     print_uint32_t(&obj->semaphoreCount, "semaphoreCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSemaphores\" :");
     if (obj->pSemaphores) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->semaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSemaphores_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->semaphoreCount);
            print_VkSemaphore(&obj->pSemaphores[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pValues\" :");
     if (obj->pValues) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->semaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pValues_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->semaphoreCount);
            print_uint64_t(&obj->pValues[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkSemaphoreSignalInfo(const VkSemaphoreSignalInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"semaphore\" : \"\",\n");

     print_uint64_t(&obj->value, "value", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkPhysicalDeviceBufferDeviceAddressFeatures(const VkPhysicalDeviceBufferDeviceAddressFeatures * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->bufferDeviceAddress, "bufferDeviceAddress", 1);

     print_VkBool32(&obj->bufferDeviceAddressCaptureReplay, "bufferDeviceAddressCaptureReplay", 1);

     print_VkBool32(&obj->bufferDeviceAddressMultiDevice, "bufferDeviceAddressMultiDevice", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkBufferDeviceAddressInfo(const VkBufferDeviceAddressInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkBufferOpaqueCaptureAddressCreateInfo(const VkBufferOpaqueCaptureAddressCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint64_t(&obj->opaqueCaptureAddress, "opaqueCaptureAddress", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkMemoryOpaqueCaptureAddressAllocateInfo(const VkMemoryOpaqueCaptureAddressAllocateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint64_t(&obj->opaqueCaptureAddress, "opaqueCaptureAddress", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_VERSION_1_2
void print_VkDeviceMemoryOpaqueCaptureAddressInfo(const VkDeviceMemoryOpaqueCaptureAddressInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"memory\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
static const char* VkFaultLevel_map(int o) {
switch (o) {
    case 0: return "VK_FAULT_LEVEL_UNASSIGNED";
    case 1: return "VK_FAULT_LEVEL_CRITICAL";
    case 2: return "VK_FAULT_LEVEL_RECOVERABLE";
    case 3: return "VK_FAULT_LEVEL_WARNING";
   }
   return NULL;
}
void print_VkFaultLevel(const VkFaultLevel* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFaultLevel_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
static const char* VkFaultType_map(int o) {
switch (o) {
    case 0: return "VK_FAULT_TYPE_INVALID";
    case 1: return "VK_FAULT_TYPE_UNASSIGNED";
    case 2: return "VK_FAULT_TYPE_IMPLEMENTATION";
    case 3: return "VK_FAULT_TYPE_SYSTEM";
    case 4: return "VK_FAULT_TYPE_PHYSICAL_DEVICE";
    case 5: return "VK_FAULT_TYPE_COMMAND_BUFFER_FULL";
    case 6: return "VK_FAULT_TYPE_INVALID_API_USAGE";
   }
   return NULL;
}
void print_VkFaultType(const VkFaultType* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFaultType_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
static const char* VkFaultQueryBehavior_map(int o) {
switch (o) {
    case 0: return "VK_FAULT_QUERY_BEHAVIOR_GET_AND_CLEAR_ALL_FAULTS";
   }
   return NULL;
}
void print_VkFaultQueryBehavior(const VkFaultQueryBehavior* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFaultQueryBehavior_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
static const char* VkPipelineMatchControl_map(int o) {
switch (o) {
    case 0: return "VK_PIPELINE_MATCH_CONTROL_APPLICATION_UUID_EXACT_MATCH";
   }
   return NULL;
}
void print_VkPipelineMatchControl(const VkPipelineMatchControl* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineMatchControl_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
static const char* VkPipelineCacheValidationVersion_map(int o) {
switch (o) {
    case 1: return "VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE";
   }
   return NULL;
}
void print_VkPipelineCacheValidationVersion(const VkPipelineCacheValidationVersion* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineCacheValidationVersion_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPhysicalDeviceVulkanSC10Features(const VkPhysicalDeviceVulkanSC10Features * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderAtomicInstructions, "shaderAtomicInstructions", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPhysicalDeviceVulkanSC10Properties(const VkPhysicalDeviceVulkanSC10Properties * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->deviceNoDynamicHostAllocations, "deviceNoDynamicHostAllocations", 1);

     print_VkBool32(&obj->deviceDestroyFreesMemory, "deviceDestroyFreesMemory", 1);

     print_VkBool32(&obj->commandPoolMultipleCommandBuffersRecording, "commandPoolMultipleCommandBuffersRecording", 1);

     print_VkBool32(&obj->commandPoolResetCommandBuffer, "commandPoolResetCommandBuffer", 1);

     print_VkBool32(&obj->commandBufferSimultaneousUse, "commandBufferSimultaneousUse", 1);

     print_VkBool32(&obj->secondaryCommandBufferNullOrImagelessFramebuffer, "secondaryCommandBufferNullOrImagelessFramebuffer", 1);

     print_VkBool32(&obj->recycleDescriptorSetMemory, "recycleDescriptorSetMemory", 1);

     print_VkBool32(&obj->recyclePipelineMemory, "recyclePipelineMemory", 1);

     print_uint32_t(&obj->maxRenderPassSubpasses, "maxRenderPassSubpasses", 1);

     print_uint32_t(&obj->maxRenderPassDependencies, "maxRenderPassDependencies", 1);

     print_uint32_t(&obj->maxSubpassInputAttachments, "maxSubpassInputAttachments", 1);

     print_uint32_t(&obj->maxSubpassPreserveAttachments, "maxSubpassPreserveAttachments", 1);

     print_uint32_t(&obj->maxFramebufferAttachments, "maxFramebufferAttachments", 1);

     print_uint32_t(&obj->maxDescriptorSetLayoutBindings, "maxDescriptorSetLayoutBindings", 1);

     print_uint32_t(&obj->maxQueryFaultCount, "maxQueryFaultCount", 1);

     print_uint32_t(&obj->maxCallbackFaultCount, "maxCallbackFaultCount", 1);

     print_uint32_t(&obj->maxCommandPoolCommandBuffers, "maxCommandPoolCommandBuffers", 1);

     print_VkDeviceSize(&obj->maxCommandBufferSize, "maxCommandBufferSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPipelinePoolSize(const VkPipelinePoolSize * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->poolEntrySize, "poolEntrySize", 1);

     print_uint32_t(&obj->poolEntryCount, "poolEntryCount", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkDeviceObjectReservationCreateInfo(const VkDeviceObjectReservationCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->pipelineCacheCreateInfoCount, "pipelineCacheCreateInfoCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPipelineCacheCreateInfos\" :");
     if (obj->pPipelineCacheCreateInfos) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->pipelineCacheCreateInfoCount); i++) {
             if (i+1 == *(&obj->pipelineCacheCreateInfoCount))
                 print_VkPipelineCacheCreateInfo(&obj->pPipelineCacheCreateInfos[i], "pPipelineCacheCreateInfos", 0);
             else
                 print_VkPipelineCacheCreateInfo(&obj->pPipelineCacheCreateInfos[i], "pPipelineCacheCreateInfos", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->pipelinePoolSizeCount, "pipelinePoolSizeCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPipelinePoolSizes\" :");
     if (obj->pPipelinePoolSizes) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->pipelinePoolSizeCount); i++) {
             if (i+1 == *(&obj->pipelinePoolSizeCount))
                 print_VkPipelinePoolSize(&obj->pPipelinePoolSizes[i], "pPipelinePoolSizes", 0);
             else
                 print_VkPipelinePoolSize(&obj->pPipelinePoolSizes[i], "pPipelinePoolSizes", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->semaphoreRequestCount, "semaphoreRequestCount", 1);

     print_uint32_t(&obj->commandBufferRequestCount, "commandBufferRequestCount", 1);

     print_uint32_t(&obj->fenceRequestCount, "fenceRequestCount", 1);

     print_uint32_t(&obj->deviceMemoryRequestCount, "deviceMemoryRequestCount", 1);

     print_uint32_t(&obj->bufferRequestCount, "bufferRequestCount", 1);

     print_uint32_t(&obj->imageRequestCount, "imageRequestCount", 1);

     print_uint32_t(&obj->eventRequestCount, "eventRequestCount", 1);

     print_uint32_t(&obj->queryPoolRequestCount, "queryPoolRequestCount", 1);

     print_uint32_t(&obj->bufferViewRequestCount, "bufferViewRequestCount", 1);

     print_uint32_t(&obj->imageViewRequestCount, "imageViewRequestCount", 1);

     print_uint32_t(&obj->layeredImageViewRequestCount, "layeredImageViewRequestCount", 1);

     print_uint32_t(&obj->pipelineCacheRequestCount, "pipelineCacheRequestCount", 1);

     print_uint32_t(&obj->pipelineLayoutRequestCount, "pipelineLayoutRequestCount", 1);

     print_uint32_t(&obj->renderPassRequestCount, "renderPassRequestCount", 1);

     print_uint32_t(&obj->graphicsPipelineRequestCount, "graphicsPipelineRequestCount", 1);

     print_uint32_t(&obj->computePipelineRequestCount, "computePipelineRequestCount", 1);

     print_uint32_t(&obj->descriptorSetLayoutRequestCount, "descriptorSetLayoutRequestCount", 1);

     print_uint32_t(&obj->samplerRequestCount, "samplerRequestCount", 1);

     print_uint32_t(&obj->descriptorPoolRequestCount, "descriptorPoolRequestCount", 1);

     print_uint32_t(&obj->descriptorSetRequestCount, "descriptorSetRequestCount", 1);

     print_uint32_t(&obj->framebufferRequestCount, "framebufferRequestCount", 1);

     print_uint32_t(&obj->commandPoolRequestCount, "commandPoolRequestCount", 1);

     print_uint32_t(&obj->samplerYcbcrConversionRequestCount, "samplerYcbcrConversionRequestCount", 1);

     print_uint32_t(&obj->surfaceRequestCount, "surfaceRequestCount", 1);

     print_uint32_t(&obj->swapchainRequestCount, "swapchainRequestCount", 1);

     print_uint32_t(&obj->displayModeRequestCount, "displayModeRequestCount", 1);

     print_uint32_t(&obj->subpassDescriptionRequestCount, "subpassDescriptionRequestCount", 1);

     print_uint32_t(&obj->attachmentDescriptionRequestCount, "attachmentDescriptionRequestCount", 1);

     print_uint32_t(&obj->descriptorSetLayoutBindingRequestCount, "descriptorSetLayoutBindingRequestCount", 1);

     print_uint32_t(&obj->descriptorSetLayoutBindingLimit, "descriptorSetLayoutBindingLimit", 1);

     print_uint32_t(&obj->maxImageViewMipLevels, "maxImageViewMipLevels", 1);

     print_uint32_t(&obj->maxImageViewArrayLayers, "maxImageViewArrayLayers", 1);

     print_uint32_t(&obj->maxLayeredImageViewMipLevels, "maxLayeredImageViewMipLevels", 1);

     print_uint32_t(&obj->maxOcclusionQueriesPerPool, "maxOcclusionQueriesPerPool", 1);

     print_uint32_t(&obj->maxPipelineStatisticsQueriesPerPool, "maxPipelineStatisticsQueriesPerPool", 1);

     print_uint32_t(&obj->maxTimestampQueriesPerPool, "maxTimestampQueriesPerPool", 1);

     print_uint32_t(&obj->maxImmutableSamplersPerDescriptorSetLayout, "maxImmutableSamplersPerDescriptorSetLayout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkCommandPoolMemoryReservationCreateInfo(const VkCommandPoolMemoryReservationCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->commandPoolReservedSize, "commandPoolReservedSize", 1);

     print_uint32_t(&obj->commandPoolMaxCommandBuffers, "commandPoolMaxCommandBuffers", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkCommandPoolMemoryConsumption(const VkCommandPoolMemoryConsumption * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->commandPoolAllocated, "commandPoolAllocated", 1);

     print_VkDeviceSize(&obj->commandPoolReservedSize, "commandPoolReservedSize", 1);

     print_VkDeviceSize(&obj->commandBufferAllocated, "commandBufferAllocated", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkFaultData(const VkFaultData * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkFaultLevel(&obj->faultLevel, "faultLevel", 1);

     print_VkFaultType(&obj->faultType, "faultType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkFaultCallbackInfo(const VkFaultCallbackInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->faultCount, "faultCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pFaults\" :");
     if (obj->pFaults) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->faultCount); i++) {
             if (i+1 == *(&obj->faultCount))
                 print_VkFaultData(&obj->pFaults[i], "pFaults", 0);
             else
                 print_VkFaultData(&obj->pFaults[i], "pFaults", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     /** Note: Ignoring function pointer (PFN_vkFaultCallbackFunction). **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPipelineOfflineCreateInfo(const VkPipelineOfflineCreateInfo * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pipelineIdentifier\" :");
     if (obj->pipelineIdentifier) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "pipelineIdentifier_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->pipelineIdentifier[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkPipelineMatchControl(&obj->matchControl, "matchControl", 1);

     print_VkDeviceSize(&obj->poolEntrySize, "poolEntrySize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPipelineCacheStageValidationIndexEntry(const VkPipelineCacheStageValidationIndexEntry * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint64_t(&obj->codeSize, "codeSize", 1);

     print_uint64_t(&obj->codeOffset, "codeOffset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPipelineCacheSafetyCriticalIndexEntry(const VkPipelineCacheSafetyCriticalIndexEntry * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pipelineIdentifier\" :");
     if (obj->pipelineIdentifier) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "pipelineIdentifier_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->pipelineIdentifier[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint64_t(&obj->pipelineMemorySize, "pipelineMemorySize", 1);

     print_uint64_t(&obj->jsonSize, "jsonSize", 1);

     print_uint64_t(&obj->jsonOffset, "jsonOffset", 1);

     print_uint32_t(&obj->stageIndexCount, "stageIndexCount", 1);

     print_uint32_t(&obj->stageIndexStride, "stageIndexStride", 1);

     print_uint64_t(&obj->stageIndexOffset, "stageIndexOffset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VKSC_VERSION_1_0
void print_VkPipelineCacheHeaderVersionSafetyCriticalOne(const VkPipelineCacheHeaderVersionSafetyCriticalOne * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"headerVersionOne\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkPipelineCacheHeaderVersionOne(&obj->headerVersionOne, "headerVersionOne", 1);
     }

     print_VkPipelineCacheValidationVersion(&obj->validationVersion, "validationVersion", 1);

     print_uint32_t(&obj->implementationData, "implementationData", 1);

     print_uint32_t(&obj->pipelineIndexCount, "pipelineIndexCount", 1);

     print_uint32_t(&obj->pipelineIndexStride, "pipelineIndexStride", 1);

     print_uint64_t(&obj->pipelineIndexOffset, "pipelineIndexOffset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
void print_VkSurfaceKHR(const VkSurfaceKHR  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
static const char* VkSurfaceTransformFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR";
    case (1 << 1): return "VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR";
    case (1 << 2): return "VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR";
    case (1 << 3): return "VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR";
    case (1 << 4): return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR";
    case (1 << 5): return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR";
    case (1 << 6): return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR";
    case (1 << 7): return "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR";
    case (1 << 8): return "VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR";
   }
   return NULL;
}
void print_VkSurfaceTransformFlagBitsKHR(const VkSurfaceTransformFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSurfaceTransformFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
static const char* VkPresentModeKHR_map(int o) {
switch (o) {
    case 0: return "VK_PRESENT_MODE_IMMEDIATE_KHR";
    case 1: return "VK_PRESENT_MODE_MAILBOX_KHR";
    case 2: return "VK_PRESENT_MODE_FIFO_KHR";
    case 3: return "VK_PRESENT_MODE_FIFO_RELAXED_KHR";
    case 1000111000: return "VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR";
    case 1000111001: return "VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR";
   }
   return NULL;
}
void print_VkPresentModeKHR(const VkPresentModeKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPresentModeKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
static const char* VkColorSpaceKHR_map(int o) {
switch (o) {
    case 0: return "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR";
    case 1000104001: return "VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT";
    case 1000104002: return "VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT";
    case 1000104003: return "VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT";
    case 1000104004: return "VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT";
    case 1000104005: return "VK_COLOR_SPACE_BT709_LINEAR_EXT";
    case 1000104006: return "VK_COLOR_SPACE_BT709_NONLINEAR_EXT";
    case 1000104007: return "VK_COLOR_SPACE_BT2020_LINEAR_EXT";
    case 1000104008: return "VK_COLOR_SPACE_HDR10_ST2084_EXT";
    case 1000104009: return "VK_COLOR_SPACE_DOLBYVISION_EXT";
    case 1000104010: return "VK_COLOR_SPACE_HDR10_HLG_EXT";
    case 1000104011: return "VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT";
    case 1000104012: return "VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT";
    case 1000104013: return "VK_COLOR_SPACE_PASS_THROUGH_EXT";
    case 1000104014: return "VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT";
    case 1000213000: return "VK_COLOR_SPACE_DISPLAY_NATIVE_AMD";
   }
   return NULL;
}
void print_VkColorSpaceKHR(const VkColorSpaceKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkColorSpaceKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
static const char* VkCompositeAlphaFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR";
    case (1 << 1): return "VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR";
    case (1 << 2): return "VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR";
    case (1 << 3): return "VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR";
   }
   return NULL;
}
void print_VkCompositeAlphaFlagBitsKHR(const VkCompositeAlphaFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkCompositeAlphaFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
void print_VkCompositeAlphaFlagsKHR(const VkCompositeAlphaFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkCompositeAlphaFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkCompositeAlphaFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkSurfaceTransformFlagsKHR(const VkSurfaceTransformFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSurfaceTransformFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSurfaceTransformFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
void print_VkSurfaceCapabilitiesKHR(const VkSurfaceCapabilitiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->minImageCount, "minImageCount", 1);

     print_uint32_t(&obj->maxImageCount, "maxImageCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"currentExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->currentExtent, "currentExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minImageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->minImageExtent, "minImageExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxImageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxImageExtent, "maxImageExtent", 1);
     }

     print_uint32_t(&obj->maxImageArrayLayers, "maxImageArrayLayers", 1);

     print_VkSurfaceTransformFlagsKHR(&obj->supportedTransforms, "supportedTransforms", 1);

     print_VkSurfaceTransformFlagBitsKHR(&obj->currentTransform, "currentTransform", 1);

     print_VkCompositeAlphaFlagsKHR(&obj->supportedCompositeAlpha, "supportedCompositeAlpha", 1);

     print_VkImageUsageFlags(&obj->supportedUsageFlags, "supportedUsageFlags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_surface
void print_VkSurfaceFormatKHR(const VkSurfaceFormatKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkFormat(&obj->format, "format", 1);

     print_VkColorSpaceKHR(&obj->colorSpace, "colorSpace", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkSwapchainKHR(const VkSwapchainKHR  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
static const char* VkSwapchainCreateFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR";
    case (1 << 1): return "VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR";
    case (1 << 2): return "VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR";
   }
   return NULL;
}
void print_VkSwapchainCreateFlagBitsKHR(const VkSwapchainCreateFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSwapchainCreateFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
static const char* VkDeviceGroupPresentModeFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR";
    case (1 << 1): return "VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR";
    case (1 << 2): return "VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR";
    case (1 << 3): return "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR";
   }
   return NULL;
}
void print_VkDeviceGroupPresentModeFlagBitsKHR(const VkDeviceGroupPresentModeFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDeviceGroupPresentModeFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkSwapchainCreateFlagsKHR(const VkSwapchainCreateFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSwapchainCreateFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSwapchainCreateFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkDeviceGroupPresentModeFlagsKHR(const VkDeviceGroupPresentModeFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDeviceGroupPresentModeFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDeviceGroupPresentModeFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkSwapchainCreateInfoKHR(const VkSwapchainCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSwapchainCreateFlagsKHR(&obj->flags, "flags", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"surface\" : \"\",\n");

     print_uint32_t(&obj->minImageCount, "minImageCount", 1);

     print_VkFormat(&obj->imageFormat, "imageFormat", 1);

     print_VkColorSpaceKHR(&obj->imageColorSpace, "imageColorSpace", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->imageExtent, "imageExtent", 1);
     }

     print_uint32_t(&obj->imageArrayLayers, "imageArrayLayers", 1);

     print_VkImageUsageFlags(&obj->imageUsage, "imageUsage", 1);

     print_VkSharingMode(&obj->imageSharingMode, "imageSharingMode", 1);

     print_uint32_t(&obj->queueFamilyIndexCount, "queueFamilyIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueueFamilyIndices\" :");
     if (obj->pQueueFamilyIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->queueFamilyIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pQueueFamilyIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->queueFamilyIndexCount);
            print_uint32_t(&obj->pQueueFamilyIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkSurfaceTransformFlagBitsKHR(&obj->preTransform, "preTransform", 1);

     print_VkCompositeAlphaFlagBitsKHR(&obj->compositeAlpha, "compositeAlpha", 1);

     print_VkPresentModeKHR(&obj->presentMode, "presentMode", 1);

     print_VkBool32(&obj->clipped, "clipped", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"oldSwapchain\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkPresentInfoKHR(const VkPresentInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->waitSemaphoreCount, "waitSemaphoreCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pWaitSemaphores\" :");
     if (obj->pWaitSemaphores) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->waitSemaphoreCount); i++) {
            char tmp[100];
            sprintf(tmp, "pWaitSemaphores_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->waitSemaphoreCount);
            print_VkSemaphore(&obj->pWaitSemaphores[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->swapchainCount, "swapchainCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSwapchains\" :");
     if (obj->pSwapchains) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->swapchainCount); i++) {
            char tmp[100];
            sprintf(tmp, "pSwapchains_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->swapchainCount);
            print_VkSwapchainKHR(&obj->pSwapchains[i], tmp, isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pImageIndices\" :");
     if (obj->pImageIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->swapchainCount); i++) {
            char tmp[100];
            sprintf(tmp, "pImageIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->swapchainCount);
            print_uint32_t(&obj->pImageIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pResults\" :");
     if (obj->pResults) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->swapchainCount); i++) {
            char tmp[100];
            sprintf(tmp, "pResults_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->swapchainCount);
            print_VkResult(&obj->pResults[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkImageSwapchainCreateInfoKHR(const VkImageSwapchainCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"swapchain\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkBindImageMemorySwapchainInfoKHR(const VkBindImageMemorySwapchainInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"swapchain\" : \"\",\n");

     print_uint32_t(&obj->imageIndex, "imageIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkAcquireNextImageInfoKHR(const VkAcquireNextImageInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"swapchain\" : \"\",\n");

     print_uint64_t(&obj->timeout, "timeout", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"semaphore\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"fence\" : \"\",\n");

     print_uint32_t(&obj->deviceMask, "deviceMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkDeviceGroupPresentCapabilitiesKHR(const VkDeviceGroupPresentCapabilitiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"presentMask\" :");
     if (obj->presentMask) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DEVICE_GROUP_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "presentMask_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DEVICE_GROUP_SIZE);
            print_uint32_t(&obj->presentMask[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkDeviceGroupPresentModeFlagsKHR(&obj->modes, "modes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkDeviceGroupPresentInfoKHR(const VkDeviceGroupPresentInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->swapchainCount, "swapchainCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDeviceMasks\" :");
     if (obj->pDeviceMasks) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->swapchainCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDeviceMasks_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->swapchainCount);
            print_uint32_t(&obj->pDeviceMasks[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkDeviceGroupPresentModeFlagBitsKHR(&obj->mode, "mode", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_swapchain
void print_VkDeviceGroupSwapchainCreateInfoKHR(const VkDeviceGroupSwapchainCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceGroupPresentModeFlagsKHR(&obj->modes, "modes", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayKHR(const VkDisplayKHR  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayModeKHR(const VkDisplayModeKHR  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
static const char* VkDisplayPlaneAlphaFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR";
    case (1 << 1): return "VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR";
    case (1 << 2): return "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR";
    case (1 << 3): return "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR";
   }
   return NULL;
}
void print_VkDisplayPlaneAlphaFlagBitsKHR(const VkDisplayPlaneAlphaFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDisplayPlaneAlphaFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayModeCreateFlagsKHR(const VkDisplayModeCreateFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayPlaneAlphaFlagsKHR(const VkDisplayPlaneAlphaFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDisplayPlaneAlphaFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDisplayPlaneAlphaFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplaySurfaceCreateFlagsKHR(const VkDisplaySurfaceCreateFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayModeParametersKHR(const VkDisplayModeParametersKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"visibleRegion\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->visibleRegion, "visibleRegion", 1);
     }

     print_uint32_t(&obj->refreshRate, "refreshRate", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayModeCreateInfoKHR(const VkDisplayModeCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDisplayModeCreateFlagsKHR(&obj->flags, "flags", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"parameters\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkDisplayModeParametersKHR(&obj->parameters, "parameters", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayModePropertiesKHR(const VkDisplayModePropertiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"displayMode\" : \"\",\n");

     PRINT_SPACE
     vk_json_printf(_OUT, "\"parameters\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkDisplayModeParametersKHR(&obj->parameters, "parameters", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayPlaneCapabilitiesKHR(const VkDisplayPlaneCapabilitiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkDisplayPlaneAlphaFlagsKHR(&obj->supportedAlpha, "supportedAlpha", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minSrcPosition\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset2D(&obj->minSrcPosition, "minSrcPosition", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxSrcPosition\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset2D(&obj->maxSrcPosition, "maxSrcPosition", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minSrcExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->minSrcExtent, "minSrcExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxSrcExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxSrcExtent, "maxSrcExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minDstPosition\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset2D(&obj->minDstPosition, "minDstPosition", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxDstPosition\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset2D(&obj->maxDstPosition, "maxDstPosition", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minDstExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->minDstExtent, "minDstExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxDstExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxDstExtent, "maxDstExtent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayPlanePropertiesKHR(const VkDisplayPlanePropertiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"currentDisplay\" : \"\",\n");

     print_uint32_t(&obj->currentStackIndex, "currentStackIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplayPropertiesKHR(const VkDisplayPropertiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"display\" : \"\",\n");

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayName\" : \"%s\",\n", (char*)obj->displayName);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"physicalDimensions\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->physicalDimensions, "physicalDimensions", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"physicalResolution\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->physicalResolution, "physicalResolution", 1);
     }

     print_VkSurfaceTransformFlagsKHR(&obj->supportedTransforms, "supportedTransforms", 1);

     print_VkBool32(&obj->planeReorderPossible, "planeReorderPossible", 1);

     print_VkBool32(&obj->persistentContent, "persistentContent", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display
void print_VkDisplaySurfaceCreateInfoKHR(const VkDisplaySurfaceCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDisplaySurfaceCreateFlagsKHR(&obj->flags, "flags", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"displayMode\" : \"\",\n");

     print_uint32_t(&obj->planeIndex, "planeIndex", 1);

     print_uint32_t(&obj->planeStackIndex, "planeStackIndex", 1);

     print_VkSurfaceTransformFlagBitsKHR(&obj->transform, "transform", 1);

     print_float(&obj->globalAlpha, "globalAlpha", 1);

     print_VkDisplayPlaneAlphaFlagBitsKHR(&obj->alphaMode, "alphaMode", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->imageExtent, "imageExtent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_display_swapchain
void print_VkDisplayPresentInfoKHR(const VkDisplayPresentInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcRect\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkRect2D(&obj->srcRect, "srcRect", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstRect\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkRect2D(&obj->dstRect, "dstRect", 1);
     }

     print_VkBool32(&obj->persistent, "persistent", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_memory_fd
void print_VkImportMemoryFdInfoKHR(const VkImportMemoryFdInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalMemoryHandleTypeFlagBits(&obj->handleType, "handleType", 1);

     print_int(&obj->fd, "fd", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_memory_fd
void print_VkMemoryFdPropertiesKHR(const VkMemoryFdPropertiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->memoryTypeBits, "memoryTypeBits", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_memory_fd
void print_VkMemoryGetFdInfoKHR(const VkMemoryGetFdInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"memory\" : \"\",\n");

     print_VkExternalMemoryHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_semaphore_fd
void print_VkImportSemaphoreFdInfoKHR(const VkImportSemaphoreFdInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"semaphore\" : \"\",\n");

     print_VkSemaphoreImportFlags(&obj->flags, "flags", 1);

     print_VkExternalSemaphoreHandleTypeFlagBits(&obj->handleType, "handleType", 1);

     print_int(&obj->fd, "fd", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_semaphore_fd
void print_VkSemaphoreGetFdInfoKHR(const VkSemaphoreGetFdInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"semaphore\" : \"\",\n");

     print_VkExternalSemaphoreHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_incremental_present
void print_VkRectLayerKHR(const VkRectLayerKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"offset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset2D(&obj->offset, "offset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->extent, "extent", 1);
     }

     print_uint32_t(&obj->layer, "layer", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_incremental_present
void print_VkPresentRegionKHR(const VkPresentRegionKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->rectangleCount, "rectangleCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRectangles\" :");
     if (obj->pRectangles) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->rectangleCount); i++) {
             if (i+1 == *(&obj->rectangleCount))
                 print_VkRectLayerKHR(&obj->pRectangles[i], "pRectangles", 0);
             else
                 print_VkRectLayerKHR(&obj->pRectangles[i], "pRectangles", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_incremental_present
void print_VkPresentRegionsKHR(const VkPresentRegionsKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->swapchainCount, "swapchainCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->swapchainCount); i++) {
             if (i+1 == *(&obj->swapchainCount))
                 print_VkPresentRegionKHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkPresentRegionKHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_shared_presentable_image
void print_VkSharedPresentSurfaceCapabilitiesKHR(const VkSharedPresentSurfaceCapabilitiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageUsageFlags(&obj->sharedPresentSupportedUsageFlags, "sharedPresentSupportedUsageFlags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_fence_fd
void print_VkImportFenceFdInfoKHR(const VkImportFenceFdInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"fence\" : \"\",\n");

     print_VkFenceImportFlags(&obj->flags, "flags", 1);

     print_VkExternalFenceHandleTypeFlagBits(&obj->handleType, "handleType", 1);

     print_int(&obj->fd, "fd", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_external_fence_fd
void print_VkFenceGetFdInfoKHR(const VkFenceGetFdInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"fence\" : \"\",\n");

     print_VkExternalFenceHandleTypeFlagBits(&obj->handleType, "handleType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
static const char* VkPerformanceCounterUnitKHR_map(int o) {
switch (o) {
    case 0: return "VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR";
    case 1: return "VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR";
    case 2: return "VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR";
    case 3: return "VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR";
    case 4: return "VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR";
    case 5: return "VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR";
    case 6: return "VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR";
    case 7: return "VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR";
    case 8: return "VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR";
    case 9: return "VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR";
    case 10: return "VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR";
   }
   return NULL;
}
void print_VkPerformanceCounterUnitKHR(const VkPerformanceCounterUnitKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPerformanceCounterUnitKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
static const char* VkPerformanceCounterScopeKHR_map(int o) {
switch (o) {
    case 0: return "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR";
    case 1: return "VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR";
    case 2: return "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR";
   }
   return NULL;
}
void print_VkPerformanceCounterScopeKHR(const VkPerformanceCounterScopeKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPerformanceCounterScopeKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
static const char* VkPerformanceCounterStorageKHR_map(int o) {
switch (o) {
    case 0: return "VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR";
    case 1: return "VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR";
    case 2: return "VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR";
    case 3: return "VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR";
    case 4: return "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR";
    case 5: return "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR";
   }
   return NULL;
}
void print_VkPerformanceCounterStorageKHR(const VkPerformanceCounterStorageKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPerformanceCounterStorageKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
static const char* VkPerformanceCounterDescriptionFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR";
    case (1 << 1): return "VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR";
   }
   return NULL;
}
void print_VkPerformanceCounterDescriptionFlagBitsKHR(const VkPerformanceCounterDescriptionFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPerformanceCounterDescriptionFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
static const char* VkAcquireProfilingLockFlagBitsKHR_map(int o) {
switch (o) {
   }
   return NULL;
}
void print_VkAcquireProfilingLockFlagBitsKHR(const VkAcquireProfilingLockFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkAcquireProfilingLockFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPerformanceCounterDescriptionFlagsKHR(const VkPerformanceCounterDescriptionFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkPerformanceCounterDescriptionFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkPerformanceCounterDescriptionFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkAcquireProfilingLockFlagsKHR(const VkAcquireProfilingLockFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkAcquireProfilingLockFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkAcquireProfilingLockFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPhysicalDevicePerformanceQueryFeaturesKHR(const VkPhysicalDevicePerformanceQueryFeaturesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->performanceCounterQueryPools, "performanceCounterQueryPools", 1);

     print_VkBool32(&obj->performanceCounterMultipleQueryPools, "performanceCounterMultipleQueryPools", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPhysicalDevicePerformanceQueryPropertiesKHR(const VkPhysicalDevicePerformanceQueryPropertiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->allowCommandBufferQueryCopies, "allowCommandBufferQueryCopies", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPerformanceCounterKHR(const VkPerformanceCounterKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPerformanceCounterUnitKHR(&obj->unit, "unit", 1);

     print_VkPerformanceCounterScopeKHR(&obj->scope, "scope", 1);

     print_VkPerformanceCounterStorageKHR(&obj->storage, "storage", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"uuid\" :");
     if (obj->uuid) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_UUID_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "uuid_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_UUID_SIZE);
            print_uint8_t(&obj->uuid[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPerformanceCounterDescriptionKHR(const VkPerformanceCounterDescriptionKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPerformanceCounterDescriptionFlagsKHR(&obj->flags, "flags", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"name\" :");
     if (obj->name) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DESCRIPTION_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "name_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DESCRIPTION_SIZE);
            print_char(&obj->name[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"category\" :");
     if (obj->category) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DESCRIPTION_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "category_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DESCRIPTION_SIZE);
            print_char(&obj->category[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"description\" :");
     if (obj->description) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_DESCRIPTION_SIZE); i++) {
            char tmp[100];
            sprintf(tmp, "description_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_DESCRIPTION_SIZE);
            print_char(&obj->description[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkQueryPoolPerformanceCreateInfoKHR(const VkQueryPoolPerformanceCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->queueFamilyIndex, "queueFamilyIndex", 1);

     print_uint32_t(&obj->counterIndexCount, "counterIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCounterIndices\" :");
     if (obj->pCounterIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->counterIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pCounterIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->counterIndexCount);
            print_uint32_t(&obj->pCounterIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPerformanceCounterResultKHR(const VkPerformanceCounterResultKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_int32_t(&obj->int32, "int32", 1);

     print_int64_t(&obj->int64, "int64", 1);

     print_uint32_t(&obj->uint32, "uint32", 1);

     print_uint64_t(&obj->uint64, "uint64", 1);

     print_float(&obj->float32, "float32", 1);

     print_double(&obj->float64, "float64", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkAcquireProfilingLockInfoKHR(const VkAcquireProfilingLockInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkAcquireProfilingLockFlagsKHR(&obj->flags, "flags", 1);

     print_uint64_t(&obj->timeout, "timeout", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPerformanceQuerySubmitInfoKHR(const VkPerformanceQuerySubmitInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->counterPassIndex, "counterPassIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_performance_query
void print_VkPerformanceQueryReservationInfoKHR(const VkPerformanceQueryReservationInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxPerformanceQueriesPerPool, "maxPerformanceQueriesPerPool", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_surface_capabilities2
void print_VkPhysicalDeviceSurfaceInfo2KHR(const VkPhysicalDeviceSurfaceInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"surface\" : \"\"\n");

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_surface_capabilities2
void print_VkSurfaceCapabilities2KHR(const VkSurfaceCapabilities2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"surfaceCapabilities\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkSurfaceCapabilitiesKHR(&obj->surfaceCapabilities, "surfaceCapabilities", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_surface_capabilities2
void print_VkSurfaceFormat2KHR(const VkSurfaceFormat2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"surfaceFormat\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkSurfaceFormatKHR(&obj->surfaceFormat, "surfaceFormat", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_display_properties2
void print_VkDisplayProperties2KHR(const VkDisplayProperties2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkDisplayPropertiesKHR(&obj->displayProperties, "displayProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_display_properties2
void print_VkDisplayPlaneProperties2KHR(const VkDisplayPlaneProperties2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayPlaneProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkDisplayPlanePropertiesKHR(&obj->displayPlaneProperties, "displayPlaneProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_display_properties2
void print_VkDisplayModeProperties2KHR(const VkDisplayModeProperties2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayModeProperties\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkDisplayModePropertiesKHR(&obj->displayModeProperties, "displayModeProperties", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_display_properties2
void print_VkDisplayPlaneInfo2KHR(const VkDisplayPlaneInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"mode\" : \"\",\n");

     print_uint32_t(&obj->planeIndex, "planeIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_get_display_properties2
void print_VkDisplayPlaneCapabilities2KHR(const VkDisplayPlaneCapabilities2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"capabilities\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkDisplayPlaneCapabilitiesKHR(&obj->capabilities, "capabilities", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_shader_clock
void print_VkPhysicalDeviceShaderClockFeaturesKHR(const VkPhysicalDeviceShaderClockFeaturesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderSubgroupClock, "shaderSubgroupClock", 1);

     print_VkBool32(&obj->shaderDeviceClock, "shaderDeviceClock", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_shader_terminate_invocation
void print_VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR(const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderTerminateInvocation, "shaderTerminateInvocation", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_fragment_shading_rate
static const char* VkFragmentShadingRateCombinerOpKHR_map(int o) {
switch (o) {
    case 0: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR";
    case 1: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR";
    case 2: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR";
    case 3: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR";
    case 4: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR";
   }
   return NULL;
}
void print_VkFragmentShadingRateCombinerOpKHR(const VkFragmentShadingRateCombinerOpKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFragmentShadingRateCombinerOpKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_fragment_shading_rate
void print_VkFragmentShadingRateAttachmentInfoKHR(const VkFragmentShadingRateAttachmentInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pFragmentShadingRateAttachment\" :");
     if (obj->pFragmentShadingRateAttachment) {
         vk_json_printf(_OUT, "\n");
         print_VkAttachmentReference2(*(&obj->pFragmentShadingRateAttachment), "pFragmentShadingRateAttachment", 1);
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"shadingRateAttachmentTexelSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->shadingRateAttachmentTexelSize, "shadingRateAttachmentTexelSize", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_fragment_shading_rate
void print_VkPipelineFragmentShadingRateStateCreateInfoKHR(const VkPipelineFragmentShadingRateStateCreateInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"fragmentSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->fragmentSize, "fragmentSize", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"combinerOps\" :");
     if (obj->combinerOps) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "combinerOps_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_VkFragmentShadingRateCombinerOpKHR(&obj->combinerOps[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_fragment_shading_rate
void print_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(const VkPhysicalDeviceFragmentShadingRateFeaturesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->pipelineFragmentShadingRate, "pipelineFragmentShadingRate", 1);

     print_VkBool32(&obj->primitiveFragmentShadingRate, "primitiveFragmentShadingRate", 1);

     print_VkBool32(&obj->attachmentFragmentShadingRate, "attachmentFragmentShadingRate", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_fragment_shading_rate
void print_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minFragmentShadingRateAttachmentTexelSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->minFragmentShadingRateAttachmentTexelSize, "minFragmentShadingRateAttachmentTexelSize", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxFragmentShadingRateAttachmentTexelSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxFragmentShadingRateAttachmentTexelSize, "maxFragmentShadingRateAttachmentTexelSize", 1);
     }

     print_uint32_t(&obj->maxFragmentShadingRateAttachmentTexelSizeAspectRatio, "maxFragmentShadingRateAttachmentTexelSizeAspectRatio", 1);

     print_VkBool32(&obj->primitiveFragmentShadingRateWithMultipleViewports, "primitiveFragmentShadingRateWithMultipleViewports", 1);

     print_VkBool32(&obj->layeredShadingRateAttachments, "layeredShadingRateAttachments", 1);

     print_VkBool32(&obj->fragmentShadingRateNonTrivialCombinerOps, "fragmentShadingRateNonTrivialCombinerOps", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxFragmentSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxFragmentSize, "maxFragmentSize", 1);
     }

     print_uint32_t(&obj->maxFragmentSizeAspectRatio, "maxFragmentSizeAspectRatio", 1);

     print_uint32_t(&obj->maxFragmentShadingRateCoverageSamples, "maxFragmentShadingRateCoverageSamples", 1);

     print_VkSampleCountFlagBits(&obj->maxFragmentShadingRateRasterizationSamples, "maxFragmentShadingRateRasterizationSamples", 1);

     print_VkBool32(&obj->fragmentShadingRateWithShaderDepthStencilWrites, "fragmentShadingRateWithShaderDepthStencilWrites", 1);

     print_VkBool32(&obj->fragmentShadingRateWithSampleMask, "fragmentShadingRateWithSampleMask", 1);

     print_VkBool32(&obj->fragmentShadingRateWithShaderSampleMask, "fragmentShadingRateWithShaderSampleMask", 1);

     print_VkBool32(&obj->fragmentShadingRateWithConservativeRasterization, "fragmentShadingRateWithConservativeRasterization", 1);

     print_VkBool32(&obj->fragmentShadingRateWithFragmentShaderInterlock, "fragmentShadingRateWithFragmentShaderInterlock", 1);

     print_VkBool32(&obj->fragmentShadingRateWithCustomSampleLocations, "fragmentShadingRateWithCustomSampleLocations", 1);

     print_VkBool32(&obj->fragmentShadingRateStrictMultiplyCombiner, "fragmentShadingRateStrictMultiplyCombiner", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_fragment_shading_rate
void print_VkPhysicalDeviceFragmentShadingRateKHR(const VkPhysicalDeviceFragmentShadingRateKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSampleCountFlags(&obj->sampleCounts, "sampleCounts", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"fragmentSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->fragmentSize, "fragmentSize", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_object_refresh
static const char* VkRefreshObjectFlagBitsKHR_map(int o) {
switch (o) {
   }
   return NULL;
}
void print_VkRefreshObjectFlagBitsKHR(const VkRefreshObjectFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkRefreshObjectFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_object_refresh
void print_VkRefreshObjectFlagsKHR(const VkRefreshObjectFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkRefreshObjectFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkRefreshObjectFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_object_refresh
void print_VkRefreshObjectKHR(const VkRefreshObjectKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkObjectType(&obj->objectType, "objectType", 1);

     print_uint64_t(&obj->objectHandle, "objectHandle", 1);

     print_VkRefreshObjectFlagsKHR(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_object_refresh
void print_VkRefreshObjectListKHR(const VkRefreshObjectListKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->objectCount, "objectCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pObjects\" :");
     if (obj->pObjects) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->objectCount); i++) {
             if (i+1 == *(&obj->objectCount))
                 print_VkRefreshObjectKHR(&obj->pObjects[i], "pObjects", 0);
             else
                 print_VkRefreshObjectKHR(&obj->pObjects[i], "pObjects", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkFlags64(const VkFlags64 * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%" PRIu64 "\"%s\n", str, *obj, commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
static const char* VkPipelineStageFlagBits2KHR_map(int o) {
switch (o) {
    case 0: return "VK_PIPELINE_STAGE_2_NONE_KHR";
    case (1 << 0): return "VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT_KHR";
    case (1 << 1): return "VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT_KHR";
    case (1 << 2): return "VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT_KHR";
    case (1 << 3): return "VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT_KHR";
    case (1 << 4): return "VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT_KHR";
    case (1 << 5): return "VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT_KHR";
    case (1 << 6): return "VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT_KHR";
    case (1 << 7): return "VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT_KHR";
    case (1 << 8): return "VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT_KHR";
    case (1 << 9): return "VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT_KHR";
    case (1 << 10): return "VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT_KHR";
    case (1 << 11): return "VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT_KHR";
    case (1 << 12): return "VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT_KHR";
    case (1 << 13): return "VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT_KHR";
    case (1 << 14): return "VK_PIPELINE_STAGE_2_HOST_BIT_KHR";
    case (1 << 15): return "VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT_KHR";
    case (1 << 16): return "VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT_KHR";
    case (1 << 32): return "VK_PIPELINE_STAGE_2_COPY_BIT_KHR";
    case (1 << 33): return "VK_PIPELINE_STAGE_2_RESOLVE_BIT_KHR";
    case (1 << 34): return "VK_PIPELINE_STAGE_2_BLIT_BIT_KHR";
    case (1 << 35): return "VK_PIPELINE_STAGE_2_CLEAR_BIT_KHR";
    case (1 << 36): return "VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT_KHR";
    case (1 << 37): return "VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT_KHR";
    case (1 << 38): return "VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT_KHR";
    case (1 << 26): return "VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR";
    case (1 << 27): return "VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR";
    case (1 << 24): return "VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT";
    case (1 << 18): return "VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
    case (1 << 17): return "VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV";
    case (1 << 22): return "VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case (1 << 25): return "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
    case (1 << 21): return "VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR";
    case (1 << 23): return "VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
    case (1 << 19): return "VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_NV";
    case (1 << 20): return "VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_NV";
    case (1 << 39): return "VK_PIPELINE_STAGE_2_SUBPASS_SHADING_BIT_HUAWEI";
    case (1 << 40): return "VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI";
    case (1 << 28): return "VK_PIPELINE_STAGE_2_RESERVED_387_BIT_KHR";
   }
   return NULL;
}
void print_VkPipelineStageFlagBits2KHR(const VkPipelineStageFlagBits2KHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkPipelineStageFlagBits2KHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
static const char* VkAccessFlagBits2KHR_map(int o) {
switch (o) {
    case 0: return "VK_ACCESS_2_NONE_KHR";
    case (1 << 0): return "VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT_KHR";
    case (1 << 1): return "VK_ACCESS_2_INDEX_READ_BIT_KHR";
    case (1 << 2): return "VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT_KHR";
    case (1 << 3): return "VK_ACCESS_2_UNIFORM_READ_BIT_KHR";
    case (1 << 4): return "VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT_KHR";
    case (1 << 5): return "VK_ACCESS_2_SHADER_READ_BIT_KHR";
    case (1 << 6): return "VK_ACCESS_2_SHADER_WRITE_BIT_KHR";
    case (1 << 7): return "VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT_KHR";
    case (1 << 8): return "VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT_KHR";
    case (1 << 9): return "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT_KHR";
    case (1 << 10): return "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT_KHR";
    case (1 << 11): return "VK_ACCESS_2_TRANSFER_READ_BIT_KHR";
    case (1 << 12): return "VK_ACCESS_2_TRANSFER_WRITE_BIT_KHR";
    case (1 << 13): return "VK_ACCESS_2_HOST_READ_BIT_KHR";
    case (1 << 14): return "VK_ACCESS_2_HOST_WRITE_BIT_KHR";
    case (1 << 15): return "VK_ACCESS_2_MEMORY_READ_BIT_KHR";
    case (1 << 16): return "VK_ACCESS_2_MEMORY_WRITE_BIT_KHR";
    case (1 << 32): return "VK_ACCESS_2_SHADER_SAMPLED_READ_BIT_KHR";
    case (1 << 33): return "VK_ACCESS_2_SHADER_STORAGE_READ_BIT_KHR";
    case (1 << 34): return "VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT_KHR";
    case (1 << 35): return "VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR";
    case (1 << 36): return "VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR";
    case (1 << 37): return "VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR";
    case (1 << 38): return "VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR";
    case (1 << 25): return "VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
    case (1 << 26): return "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
    case (1 << 27): return "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
    case (1 << 20): return "VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT";
    case (1 << 17): return "VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV";
    case (1 << 18): return "VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV";
    case (1 << 23): return "VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
    case (1 << 21): return "VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR";
    case (1 << 22): return "VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
    case (1 << 24): return "VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
    case (1 << 19): return "VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
    case (1 << 41): return "VK_ACCESS_2_RESERVED_41_BIT_AMD";
    case (1 << 39): return "VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI";
    case (1 << 40): return "VK_ACCESS_2_RESERVED_387_BIT_KHR";
   }
   return NULL;
}
void print_VkAccessFlagBits2KHR(const VkAccessFlagBits2KHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkAccessFlagBits2KHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
static const char* VkSubmitFlagBitsKHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SUBMIT_PROTECTED_BIT_KHR";
   }
   return NULL;
}
void print_VkSubmitFlagBitsKHR(const VkSubmitFlagBitsKHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSubmitFlagBitsKHR_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkPipelineStageFlags2KHR(const VkPipelineStageFlags2KHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkAccessFlags2KHR(const VkAccessFlags2KHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkSubmitFlagsKHR(const VkSubmitFlagsKHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSubmitFlagBitsKHR_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSubmitFlagBitsKHR_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkMemoryBarrier2KHR(const VkMemoryBarrier2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineStageFlags2KHR(&obj->srcStageMask, "srcStageMask", 1);

     print_VkAccessFlags2KHR(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkPipelineStageFlags2KHR(&obj->dstStageMask, "dstStageMask", 1);

     print_VkAccessFlags2KHR(&obj->dstAccessMask, "dstAccessMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkBufferMemoryBarrier2KHR(const VkBufferMemoryBarrier2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineStageFlags2KHR(&obj->srcStageMask, "srcStageMask", 1);

     print_VkAccessFlags2KHR(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkPipelineStageFlags2KHR(&obj->dstStageMask, "dstStageMask", 1);

     print_VkAccessFlags2KHR(&obj->dstAccessMask, "dstAccessMask", 1);

     print_uint32_t(&obj->srcQueueFamilyIndex, "srcQueueFamilyIndex", 1);

     print_uint32_t(&obj->dstQueueFamilyIndex, "dstQueueFamilyIndex", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"buffer\" : \"\",\n");

     print_VkDeviceSize(&obj->offset, "offset", 1);

     print_VkDeviceSize(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkImageMemoryBarrier2KHR(const VkImageMemoryBarrier2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineStageFlags2KHR(&obj->srcStageMask, "srcStageMask", 1);

     print_VkAccessFlags2KHR(&obj->srcAccessMask, "srcAccessMask", 1);

     print_VkPipelineStageFlags2KHR(&obj->dstStageMask, "dstStageMask", 1);

     print_VkAccessFlags2KHR(&obj->dstAccessMask, "dstAccessMask", 1);

     print_VkImageLayout(&obj->oldLayout, "oldLayout", 1);

     print_VkImageLayout(&obj->newLayout, "newLayout", 1);

     print_uint32_t(&obj->srcQueueFamilyIndex, "srcQueueFamilyIndex", 1);

     print_uint32_t(&obj->dstQueueFamilyIndex, "dstQueueFamilyIndex", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"image\" : \"\",\n");

     PRINT_SPACE
     vk_json_printf(_OUT, "\"subresourceRange\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceRange(&obj->subresourceRange, "subresourceRange", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkDependencyInfoKHR(const VkDependencyInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDependencyFlags(&obj->dependencyFlags, "dependencyFlags", 1);

     print_uint32_t(&obj->memoryBarrierCount, "memoryBarrierCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pMemoryBarriers\" :");
     if (obj->pMemoryBarriers) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->memoryBarrierCount); i++) {
             if (i+1 == *(&obj->memoryBarrierCount))
                 print_VkMemoryBarrier2KHR(&obj->pMemoryBarriers[i], "pMemoryBarriers", 0);
             else
                 print_VkMemoryBarrier2KHR(&obj->pMemoryBarriers[i], "pMemoryBarriers", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->bufferMemoryBarrierCount, "bufferMemoryBarrierCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pBufferMemoryBarriers\" :");
     if (obj->pBufferMemoryBarriers) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->bufferMemoryBarrierCount); i++) {
             if (i+1 == *(&obj->bufferMemoryBarrierCount))
                 print_VkBufferMemoryBarrier2KHR(&obj->pBufferMemoryBarriers[i], "pBufferMemoryBarriers", 0);
             else
                 print_VkBufferMemoryBarrier2KHR(&obj->pBufferMemoryBarriers[i], "pBufferMemoryBarriers", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->imageMemoryBarrierCount, "imageMemoryBarrierCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pImageMemoryBarriers\" :");
     if (obj->pImageMemoryBarriers) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->imageMemoryBarrierCount); i++) {
             if (i+1 == *(&obj->imageMemoryBarrierCount))
                 print_VkImageMemoryBarrier2KHR(&obj->pImageMemoryBarriers[i], "pImageMemoryBarriers", 0);
             else
                 print_VkImageMemoryBarrier2KHR(&obj->pImageMemoryBarriers[i], "pImageMemoryBarriers", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkSemaphoreSubmitInfoKHR(const VkSemaphoreSubmitInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"semaphore\" : \"\",\n");

     print_uint64_t(&obj->value, "value", 1);

     print_VkPipelineStageFlags2KHR(&obj->stageMask, "stageMask", 1);

     print_uint32_t(&obj->deviceIndex, "deviceIndex", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkCommandBufferSubmitInfoKHR(const VkCommandBufferSubmitInfoKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"commandBuffer\" : \"\",\n");

     print_uint32_t(&obj->deviceMask, "deviceMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkSubmitInfo2KHR(const VkSubmitInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSubmitFlagsKHR(&obj->flags, "flags", 1);

     print_uint32_t(&obj->waitSemaphoreInfoCount, "waitSemaphoreInfoCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pWaitSemaphoreInfos\" :");
     if (obj->pWaitSemaphoreInfos) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->waitSemaphoreInfoCount); i++) {
             if (i+1 == *(&obj->waitSemaphoreInfoCount))
                 print_VkSemaphoreSubmitInfoKHR(&obj->pWaitSemaphoreInfos[i], "pWaitSemaphoreInfos", 0);
             else
                 print_VkSemaphoreSubmitInfoKHR(&obj->pWaitSemaphoreInfos[i], "pWaitSemaphoreInfos", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->commandBufferInfoCount, "commandBufferInfoCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCommandBufferInfos\" :");
     if (obj->pCommandBufferInfos) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->commandBufferInfoCount); i++) {
             if (i+1 == *(&obj->commandBufferInfoCount))
                 print_VkCommandBufferSubmitInfoKHR(&obj->pCommandBufferInfos[i], "pCommandBufferInfos", 0);
             else
                 print_VkCommandBufferSubmitInfoKHR(&obj->pCommandBufferInfos[i], "pCommandBufferInfos", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->signalSemaphoreInfoCount, "signalSemaphoreInfoCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSignalSemaphoreInfos\" :");
     if (obj->pSignalSemaphoreInfos) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->signalSemaphoreInfoCount); i++) {
             if (i+1 == *(&obj->signalSemaphoreInfoCount))
                 print_VkSemaphoreSubmitInfoKHR(&obj->pSignalSemaphoreInfos[i], "pSignalSemaphoreInfos", 0);
             else
                 print_VkSemaphoreSubmitInfoKHR(&obj->pSignalSemaphoreInfos[i], "pSignalSemaphoreInfos", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkPhysicalDeviceSynchronization2FeaturesKHR(const VkPhysicalDeviceSynchronization2FeaturesKHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->synchronization2, "synchronization2", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkQueueFamilyCheckpointProperties2NV(const VkQueueFamilyCheckpointProperties2NV * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineStageFlags2KHR(&obj->checkpointExecutionStageMask, "checkpointExecutionStageMask", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_synchronization2
void print_VkCheckpointData2NV(const VkCheckpointData2NV * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineStageFlags2KHR(&obj->stage, "stage", 1);

     /** Note: Ignoring void* data. **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkBufferCopy2KHR(const VkBufferCopy2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->srcOffset, "srcOffset", 1);

     print_VkDeviceSize(&obj->dstOffset, "dstOffset", 1);

     print_VkDeviceSize(&obj->size, "size", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkCopyBufferInfo2KHR(const VkCopyBufferInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcBuffer\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstBuffer\" : \"\",\n");

     print_uint32_t(&obj->regionCount, "regionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->regionCount); i++) {
             if (i+1 == *(&obj->regionCount))
                 print_VkBufferCopy2KHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkBufferCopy2KHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkImageCopy2KHR(const VkImageCopy2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->srcSubresource, "srcSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->srcOffset, "srcOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->dstSubresource, "dstSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->dstOffset, "dstOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->extent, "extent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkCopyImageInfo2KHR(const VkCopyImageInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcImage\" : \"\",\n");

     print_VkImageLayout(&obj->srcImageLayout, "srcImageLayout", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstImage\" : \"\",\n");

     print_VkImageLayout(&obj->dstImageLayout, "dstImageLayout", 1);

     print_uint32_t(&obj->regionCount, "regionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->regionCount); i++) {
             if (i+1 == *(&obj->regionCount))
                 print_VkImageCopy2KHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkImageCopy2KHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkBufferImageCopy2KHR(const VkBufferImageCopy2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->bufferOffset, "bufferOffset", 1);

     print_uint32_t(&obj->bufferRowLength, "bufferRowLength", 1);

     print_uint32_t(&obj->bufferImageHeight, "bufferImageHeight", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->imageSubresource, "imageSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->imageOffset, "imageOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"imageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->imageExtent, "imageExtent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkCopyBufferToImageInfo2KHR(const VkCopyBufferToImageInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcBuffer\" : \"\",\n");

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstImage\" : \"\",\n");

     print_VkImageLayout(&obj->dstImageLayout, "dstImageLayout", 1);

     print_uint32_t(&obj->regionCount, "regionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->regionCount); i++) {
             if (i+1 == *(&obj->regionCount))
                 print_VkBufferImageCopy2KHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkBufferImageCopy2KHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkCopyImageToBufferInfo2KHR(const VkCopyImageToBufferInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcImage\" : \"\",\n");

     print_VkImageLayout(&obj->srcImageLayout, "srcImageLayout", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstBuffer\" : \"\",\n");

     print_uint32_t(&obj->regionCount, "regionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->regionCount); i++) {
             if (i+1 == *(&obj->regionCount))
                 print_VkBufferImageCopy2KHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkBufferImageCopy2KHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkImageBlit2KHR(const VkImageBlit2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->srcSubresource, "srcSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcOffsets\" :");
     if (obj->srcOffsets) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "srcOffsets_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_VkOffset3D(&obj->srcOffsets[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->dstSubresource, "dstSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstOffsets\" :");
     if (obj->dstOffsets) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "dstOffsets_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_VkOffset3D(&obj->dstOffsets[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkBlitImageInfo2KHR(const VkBlitImageInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcImage\" : \"\",\n");

     print_VkImageLayout(&obj->srcImageLayout, "srcImageLayout", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstImage\" : \"\",\n");

     print_VkImageLayout(&obj->dstImageLayout, "dstImageLayout", 1);

     print_uint32_t(&obj->regionCount, "regionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->regionCount); i++) {
             if (i+1 == *(&obj->regionCount))
                 print_VkImageBlit2KHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkImageBlit2KHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_VkFilter(&obj->filter, "filter", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkImageResolve2KHR(const VkImageResolve2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->srcSubresource, "srcSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"srcOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->srcOffset, "srcOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstSubresource\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkImageSubresourceLayers(&obj->dstSubresource, "dstSubresource", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"dstOffset\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkOffset3D(&obj->dstOffset, "dstOffset", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"extent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent3D(&obj->extent, "extent", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_KHR_copy_commands2
void print_VkResolveImageInfo2KHR(const VkResolveImageInfo2KHR * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"srcImage\" : \"\",\n");

     print_VkImageLayout(&obj->srcImageLayout, "srcImageLayout", 1);

     /** Note: printing just an empty entry here **/
     PRINT_SPACE    vk_json_printf(_OUT, "\"dstImage\" : \"\",\n");

     print_VkImageLayout(&obj->dstImageLayout, "dstImageLayout", 1);

     print_uint32_t(&obj->regionCount, "regionCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pRegions\" :");
     if (obj->pRegions) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->regionCount); i++) {
             if (i+1 == *(&obj->regionCount))
                 print_VkImageResolve2KHR(&obj->pRegions[i], "pRegions", 0);
             else
                 print_VkImageResolve2KHR(&obj->pRegions[i], "pRegions", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_texture_compression_astc_hdr
void print_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT(const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->textureCompressionASTC_HDR, "textureCompressionASTC_HDR", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_astc_decode_mode
void print_VkImageViewASTCDecodeModeEXT(const VkImageViewASTCDecodeModeEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkFormat(&obj->decodeMode, "decodeMode", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_astc_decode_mode
void print_VkPhysicalDeviceASTCDecodeFeaturesEXT(const VkPhysicalDeviceASTCDecodeFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->decodeModeSharedExponent, "decodeModeSharedExponent", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_surface_counter
static const char* VkSurfaceCounterFlagBitsEXT_map(int o) {
switch (o) {
    case (1 << 0): return "VK_SURFACE_COUNTER_VBLANK_BIT_EXT";
   }
   return NULL;
}
void print_VkSurfaceCounterFlagBitsEXT(const VkSurfaceCounterFlagBitsEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkSurfaceCounterFlagBitsEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_surface_counter
void print_VkSurfaceCounterFlagsEXT(const VkSurfaceCounterFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkSurfaceCounterFlagBitsEXT_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkSurfaceCounterFlagBitsEXT_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_surface_counter
void print_VkSurfaceCapabilities2EXT(const VkSurfaceCapabilities2EXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->minImageCount, "minImageCount", 1);

     print_uint32_t(&obj->maxImageCount, "maxImageCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"currentExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->currentExtent, "currentExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"minImageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->minImageExtent, "minImageExtent", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxImageExtent\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxImageExtent, "maxImageExtent", 1);
     }

     print_uint32_t(&obj->maxImageArrayLayers, "maxImageArrayLayers", 1);

     print_VkSurfaceTransformFlagsKHR(&obj->supportedTransforms, "supportedTransforms", 1);

     print_VkSurfaceTransformFlagBitsKHR(&obj->currentTransform, "currentTransform", 1);

     print_VkCompositeAlphaFlagsKHR(&obj->supportedCompositeAlpha, "supportedCompositeAlpha", 1);

     print_VkImageUsageFlags(&obj->supportedUsageFlags, "supportedUsageFlags", 1);

     print_VkSurfaceCounterFlagsEXT(&obj->supportedSurfaceCounters, "supportedSurfaceCounters", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
static const char* VkDisplayPowerStateEXT_map(int o) {
switch (o) {
    case 0: return "VK_DISPLAY_POWER_STATE_OFF_EXT";
    case 1: return "VK_DISPLAY_POWER_STATE_SUSPEND_EXT";
    case 2: return "VK_DISPLAY_POWER_STATE_ON_EXT";
   }
   return NULL;
}
void print_VkDisplayPowerStateEXT(const VkDisplayPowerStateEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDisplayPowerStateEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
static const char* VkDeviceEventTypeEXT_map(int o) {
switch (o) {
    case 0: return "VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT";
   }
   return NULL;
}
void print_VkDeviceEventTypeEXT(const VkDeviceEventTypeEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDeviceEventTypeEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
static const char* VkDisplayEventTypeEXT_map(int o) {
switch (o) {
    case 0: return "VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT";
   }
   return NULL;
}
void print_VkDisplayEventTypeEXT(const VkDisplayEventTypeEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDisplayEventTypeEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
void print_VkDisplayPowerInfoEXT(const VkDisplayPowerInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDisplayPowerStateEXT(&obj->powerState, "powerState", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
void print_VkDeviceEventInfoEXT(const VkDeviceEventInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceEventTypeEXT(&obj->deviceEvent, "deviceEvent", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
void print_VkDisplayEventInfoEXT(const VkDisplayEventInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDisplayEventTypeEXT(&obj->displayEvent, "displayEvent", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_display_control
void print_VkSwapchainCounterCreateInfoEXT(const VkSwapchainCounterCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSurfaceCounterFlagsEXT(&obj->surfaceCounters, "surfaceCounters", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_discard_rectangles
static const char* VkDiscardRectangleModeEXT_map(int o) {
switch (o) {
    case 0: return "VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT";
    case 1: return "VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT";
   }
   return NULL;
}
void print_VkDiscardRectangleModeEXT(const VkDiscardRectangleModeEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDiscardRectangleModeEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_discard_rectangles
void print_VkPipelineDiscardRectangleStateCreateFlagsEXT(const VkPipelineDiscardRectangleStateCreateFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_discard_rectangles
void print_VkPhysicalDeviceDiscardRectanglePropertiesEXT(const VkPhysicalDeviceDiscardRectanglePropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxDiscardRectangles, "maxDiscardRectangles", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_discard_rectangles
void print_VkPipelineDiscardRectangleStateCreateInfoEXT(const VkPipelineDiscardRectangleStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineDiscardRectangleStateCreateFlagsEXT(&obj->flags, "flags", 1);

     print_VkDiscardRectangleModeEXT(&obj->discardRectangleMode, "discardRectangleMode", 1);

     print_uint32_t(&obj->discardRectangleCount, "discardRectangleCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDiscardRectangles\" :");
     if (obj->pDiscardRectangles) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->discardRectangleCount); i++) {
             if (i+1 == *(&obj->discardRectangleCount))
                 print_VkRect2D(&obj->pDiscardRectangles[i], "pDiscardRectangles", 0);
             else
                 print_VkRect2D(&obj->pDiscardRectangles[i], "pDiscardRectangles", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_conservative_rasterization
static const char* VkConservativeRasterizationModeEXT_map(int o) {
switch (o) {
    case 0: return "VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT";
    case 1: return "VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT";
    case 2: return "VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT";
   }
   return NULL;
}
void print_VkConservativeRasterizationModeEXT(const VkConservativeRasterizationModeEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkConservativeRasterizationModeEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_conservative_rasterization
void print_VkPipelineRasterizationConservativeStateCreateFlagsEXT(const VkPipelineRasterizationConservativeStateCreateFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_conservative_rasterization
void print_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_float(&obj->primitiveOverestimationSize, "primitiveOverestimationSize", 1);

     print_float(&obj->maxExtraPrimitiveOverestimationSize, "maxExtraPrimitiveOverestimationSize", 1);

     print_float(&obj->extraPrimitiveOverestimationSizeGranularity, "extraPrimitiveOverestimationSizeGranularity", 1);

     print_VkBool32(&obj->primitiveUnderestimation, "primitiveUnderestimation", 1);

     print_VkBool32(&obj->conservativePointAndLineRasterization, "conservativePointAndLineRasterization", 1);

     print_VkBool32(&obj->degenerateTrianglesRasterized, "degenerateTrianglesRasterized", 1);

     print_VkBool32(&obj->degenerateLinesRasterized, "degenerateLinesRasterized", 1);

     print_VkBool32(&obj->fullyCoveredFragmentShaderInputVariable, "fullyCoveredFragmentShaderInputVariable", 1);

     print_VkBool32(&obj->conservativeRasterizationPostDepthCoverage, "conservativeRasterizationPostDepthCoverage", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_conservative_rasterization
void print_VkPipelineRasterizationConservativeStateCreateInfoEXT(const VkPipelineRasterizationConservativeStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineRasterizationConservativeStateCreateFlagsEXT(&obj->flags, "flags", 1);

     print_VkConservativeRasterizationModeEXT(&obj->conservativeRasterizationMode, "conservativeRasterizationMode", 1);

     print_float(&obj->extraPrimitiveOverestimationSize, "extraPrimitiveOverestimationSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_depth_clip_enable
void print_VkPipelineRasterizationDepthClipStateCreateFlagsEXT(const VkPipelineRasterizationDepthClipStateCreateFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_depth_clip_enable
void print_VkPhysicalDeviceDepthClipEnableFeaturesEXT(const VkPhysicalDeviceDepthClipEnableFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->depthClipEnable, "depthClipEnable", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_depth_clip_enable
void print_VkPipelineRasterizationDepthClipStateCreateInfoEXT(const VkPipelineRasterizationDepthClipStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkPipelineRasterizationDepthClipStateCreateFlagsEXT(&obj->flags, "flags", 1);

     print_VkBool32(&obj->depthClipEnable, "depthClipEnable", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_hdr_metadata
void print_VkXYColorEXT(const VkXYColorEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_float(&obj->x, "x", 1);

     print_float(&obj->y, "y", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_hdr_metadata
void print_VkHdrMetadataEXT(const VkHdrMetadataEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayPrimaryRed\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkXYColorEXT(&obj->displayPrimaryRed, "displayPrimaryRed", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayPrimaryGreen\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkXYColorEXT(&obj->displayPrimaryGreen, "displayPrimaryGreen", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"displayPrimaryBlue\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkXYColorEXT(&obj->displayPrimaryBlue, "displayPrimaryBlue", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"whitePoint\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkXYColorEXT(&obj->whitePoint, "whitePoint", 1);
     }

     print_float(&obj->maxLuminance, "maxLuminance", 1);

     print_float(&obj->minLuminance, "minLuminance", 1);

     print_float(&obj->maxContentLightLevel, "maxContentLightLevel", 1);

     print_float(&obj->maxFrameAverageLightLevel, "maxFrameAverageLightLevel", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessengerEXT(const VkDebugUtilsMessengerEXT  * obj, const char* str, int commaNeeded) {
     (void)  * obj;
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\"%s\n", str, commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
static const char* VkDebugUtilsMessageSeverityFlagBitsEXT_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT";
    case (1 << 4): return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT";
    case (1 << 8): return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT";
    case (1 << 12): return "VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT";
   }
   return NULL;
}
void print_VkDebugUtilsMessageSeverityFlagBitsEXT(const VkDebugUtilsMessageSeverityFlagBitsEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDebugUtilsMessageSeverityFlagBitsEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
static const char* VkDebugUtilsMessageTypeFlagBitsEXT_map(int o) {
switch (o) {
    case (1 << 0): return "VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT";
    case (1 << 1): return "VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT";
    case (1 << 2): return "VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT";
   }
   return NULL;
}
void print_VkDebugUtilsMessageTypeFlagBitsEXT(const VkDebugUtilsMessageTypeFlagBitsEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkDebugUtilsMessageTypeFlagBitsEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessengerCallbackDataFlagsEXT(const VkDebugUtilsMessengerCallbackDataFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessageTypeFlagsEXT(const VkDebugUtilsMessageTypeFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDebugUtilsMessageTypeFlagBitsEXT_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDebugUtilsMessageTypeFlagBitsEXT_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessageSeverityFlagsEXT(const VkDebugUtilsMessageSeverityFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : ", str);
     const unsigned int max_bits = 64; 
     unsigned int _count = 0;
     unsigned int checkBit = 1;
     unsigned int n = *obj;
     while (n) {
        n &= (n-1);
        _count++;
     }
     unsigned int b = *obj;
     checkBit = 1;
     vk_json_printf(_OUT, "\"");
     if (*obj == 0) vk_json_printf(_OUT, "0");
     for (unsigned int i = 0, bitCount = 0; i < max_bits; i++, checkBit <<= 1) {
         unsigned int res = b & checkBit;
         if (res) {
             bitCount++;
             if (bitCount < _count) {
                 vk_json_printf(_OUT, "%s | ", VkDebugUtilsMessageSeverityFlagBitsEXT_map(1<<i));
             } else {
                 vk_json_printf(_OUT, "%s", VkDebugUtilsMessageSeverityFlagBitsEXT_map(1<<i));
             }
         }
     }
     vk_json_printf(_OUT, "\"%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessengerCreateFlagsEXT(const VkDebugUtilsMessengerCreateFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsLabelEXT(const VkDebugUtilsLabelEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pLabelName\" : \"%s\",\n", (char*)obj->pLabelName);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"color\" :");
     if (obj->color) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (4); i++) {
            char tmp[100];
            sprintf(tmp, "color_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (4);
            print_float(&obj->color[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsObjectNameInfoEXT(const VkDebugUtilsObjectNameInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkObjectType(&obj->objectType, "objectType", 1);

     print_uint64_t(&obj->objectHandle, "objectHandle", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pObjectName\" : \"%s\",\n", (char*)obj->pObjectName);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessengerCallbackDataEXT(const VkDebugUtilsMessengerCallbackDataEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDebugUtilsMessengerCallbackDataFlagsEXT(&obj->flags, "flags", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pMessageIdName\" : \"%s\",\n", (char*)obj->pMessageIdName);

     print_int32_t(&obj->messageIdNumber, "messageIdNumber", 1);

     /** Printing string inline. **/
     PRINT_SPACE
     vk_json_printf(_OUT, "\"pMessage\" : \"%s\",\n", (char*)obj->pMessage);

     print_uint32_t(&obj->queueLabelCount, "queueLabelCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueueLabels\" :");
     if (obj->pQueueLabels) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->queueLabelCount); i++) {
             if (i+1 == *(&obj->queueLabelCount))
                 print_VkDebugUtilsLabelEXT(&obj->pQueueLabels[i], "pQueueLabels", 0);
             else
                 print_VkDebugUtilsLabelEXT(&obj->pQueueLabels[i], "pQueueLabels", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->cmdBufLabelCount, "cmdBufLabelCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pCmdBufLabels\" :");
     if (obj->pCmdBufLabels) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->cmdBufLabelCount); i++) {
             if (i+1 == *(&obj->cmdBufLabelCount))
                 print_VkDebugUtilsLabelEXT(&obj->pCmdBufLabels[i], "pCmdBufLabels", 0);
             else
                 print_VkDebugUtilsLabelEXT(&obj->pCmdBufLabels[i], "pCmdBufLabels", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->objectCount, "objectCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pObjects\" :");
     if (obj->pObjects) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->objectCount); i++) {
             if (i+1 == *(&obj->objectCount))
                 print_VkDebugUtilsObjectNameInfoEXT(&obj->pObjects[i], "pObjects", 0);
             else
                 print_VkDebugUtilsObjectNameInfoEXT(&obj->pObjects[i], "pObjects", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsMessengerCreateInfoEXT(const VkDebugUtilsMessengerCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDebugUtilsMessengerCreateFlagsEXT(&obj->flags, "flags", 1);

     print_VkDebugUtilsMessageSeverityFlagsEXT(&obj->messageSeverity, "messageSeverity", 1);

     print_VkDebugUtilsMessageTypeFlagsEXT(&obj->messageType, "messageType", 1);

     /** Note: Ignoring function pointer (PFN_vkDebugUtilsMessengerCallbackEXT). **/

     /** Note: Ignoring void* data. **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_debug_utils
void print_VkDebugUtilsObjectTagInfoEXT(const VkDebugUtilsObjectTagInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkObjectType(&obj->objectType, "objectType", 1);

     print_uint64_t(&obj->objectHandle, "objectHandle", 1);

     print_uint64_t(&obj->tagName, "tagName", 1);

     print_size_t(&obj->tagSize, "tagSize", 1);

     /** Note: Ignoring void* data. **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkSampleLocationEXT(const VkSampleLocationEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_float(&obj->x, "x", 1);

     print_float(&obj->y, "y", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkSampleLocationsInfoEXT(const VkSampleLocationsInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSampleCountFlagBits(&obj->sampleLocationsPerPixel, "sampleLocationsPerPixel", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"sampleLocationGridSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->sampleLocationGridSize, "sampleLocationGridSize", 1);
     }

     print_uint32_t(&obj->sampleLocationsCount, "sampleLocationsCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pSampleLocations\" :");
     if (obj->pSampleLocations) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->sampleLocationsCount); i++) {
             if (i+1 == *(&obj->sampleLocationsCount))
                 print_VkSampleLocationEXT(&obj->pSampleLocations[i], "pSampleLocations", 0);
             else
                 print_VkSampleLocationEXT(&obj->pSampleLocations[i], "pSampleLocations", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkAttachmentSampleLocationsEXT(const VkAttachmentSampleLocationsEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->attachmentIndex, "attachmentIndex", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"sampleLocationsInfo\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkSampleLocationsInfoEXT(&obj->sampleLocationsInfo, "sampleLocationsInfo", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkSubpassSampleLocationsEXT(const VkSubpassSampleLocationsEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->subpassIndex, "subpassIndex", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"sampleLocationsInfo\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkSampleLocationsInfoEXT(&obj->sampleLocationsInfo, "sampleLocationsInfo", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkRenderPassSampleLocationsBeginInfoEXT(const VkRenderPassSampleLocationsBeginInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->attachmentInitialSampleLocationsCount, "attachmentInitialSampleLocationsCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pAttachmentInitialSampleLocations\" :");
     if (obj->pAttachmentInitialSampleLocations) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->attachmentInitialSampleLocationsCount); i++) {
             if (i+1 == *(&obj->attachmentInitialSampleLocationsCount))
                 print_VkAttachmentSampleLocationsEXT(&obj->pAttachmentInitialSampleLocations[i], "pAttachmentInitialSampleLocations", 0);
             else
                 print_VkAttachmentSampleLocationsEXT(&obj->pAttachmentInitialSampleLocations[i], "pAttachmentInitialSampleLocations", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "],\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->postSubpassSampleLocationsCount, "postSubpassSampleLocationsCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPostSubpassSampleLocations\" :");
     if (obj->pPostSubpassSampleLocations) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->postSubpassSampleLocationsCount); i++) {
             if (i+1 == *(&obj->postSubpassSampleLocationsCount))
                 print_VkSubpassSampleLocationsEXT(&obj->pPostSubpassSampleLocations[i], "pPostSubpassSampleLocations", 0);
             else
                 print_VkSubpassSampleLocationsEXT(&obj->pPostSubpassSampleLocations[i], "pPostSubpassSampleLocations", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkPipelineSampleLocationsStateCreateInfoEXT(const VkPipelineSampleLocationsStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->sampleLocationsEnable, "sampleLocationsEnable", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"sampleLocationsInfo\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkSampleLocationsInfoEXT(&obj->sampleLocationsInfo, "sampleLocationsInfo", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkPhysicalDeviceSampleLocationsPropertiesEXT(const VkPhysicalDeviceSampleLocationsPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkSampleCountFlags(&obj->sampleLocationSampleCounts, "sampleLocationSampleCounts", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxSampleLocationGridSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxSampleLocationGridSize, "maxSampleLocationGridSize", 1);
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"sampleLocationCoordinateRange\" :");
     if (obj->sampleLocationCoordinateRange) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (2); i++) {
            char tmp[100];
            sprintf(tmp, "sampleLocationCoordinateRange_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (2);
            print_float(&obj->sampleLocationCoordinateRange[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->sampleLocationSubPixelBits, "sampleLocationSubPixelBits", 1);

     print_VkBool32(&obj->variableSampleLocations, "variableSampleLocations", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_sample_locations
void print_VkMultisamplePropertiesEXT(const VkMultisamplePropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"maxSampleLocationGridSize\" :");
     {
         vk_json_printf(_OUT, "\n");
         print_VkExtent2D(&obj->maxSampleLocationGridSize, "maxSampleLocationGridSize", 0);
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_blend_operation_advanced
static const char* VkBlendOverlapEXT_map(int o) {
switch (o) {
    case 0: return "VK_BLEND_OVERLAP_UNCORRELATED_EXT";
    case 1: return "VK_BLEND_OVERLAP_DISJOINT_EXT";
    case 2: return "VK_BLEND_OVERLAP_CONJOINT_EXT";
   }
   return NULL;
}
void print_VkBlendOverlapEXT(const VkBlendOverlapEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkBlendOverlapEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_blend_operation_advanced
void print_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->advancedBlendCoherentOperations, "advancedBlendCoherentOperations", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_blend_operation_advanced
void print_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->advancedBlendMaxColorAttachments, "advancedBlendMaxColorAttachments", 1);

     print_VkBool32(&obj->advancedBlendIndependentBlend, "advancedBlendIndependentBlend", 1);

     print_VkBool32(&obj->advancedBlendNonPremultipliedSrcColor, "advancedBlendNonPremultipliedSrcColor", 1);

     print_VkBool32(&obj->advancedBlendNonPremultipliedDstColor, "advancedBlendNonPremultipliedDstColor", 1);

     print_VkBool32(&obj->advancedBlendCorrelatedOverlap, "advancedBlendCorrelatedOverlap", 1);

     print_VkBool32(&obj->advancedBlendAllOperations, "advancedBlendAllOperations", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_blend_operation_advanced
void print_VkPipelineColorBlendAdvancedStateCreateInfoEXT(const VkPipelineColorBlendAdvancedStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->srcPremultiplied, "srcPremultiplied", 1);

     print_VkBool32(&obj->dstPremultiplied, "dstPremultiplied", 1);

     print_VkBlendOverlapEXT(&obj->blendOverlap, "blendOverlap", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
static const char* VkFormatFeatureFlagBits2KHR_map(int o) {
switch (o) {
    case (1 << 0): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT_KHR";
    case (1 << 1): return "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT_KHR";
    case (1 << 2): return "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT_KHR";
    case (1 << 3): return "VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR";
    case (1 << 4): return "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT_KHR";
    case (1 << 5): return "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT_KHR";
    case (1 << 6): return "VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT_KHR";
    case (1 << 7): return "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT_KHR";
    case (1 << 8): return "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT_KHR";
    case (1 << 9): return "VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT_KHR";
    case (1 << 10): return "VK_FORMAT_FEATURE_2_BLIT_SRC_BIT_KHR";
    case (1 << 11): return "VK_FORMAT_FEATURE_2_BLIT_DST_BIT_KHR";
    case (1 << 12): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT_KHR";
    case (1 << 13): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT";
    case (1 << 14): return "VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT_KHR";
    case (1 << 15): return "VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT_KHR";
    case (1 << 16): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT_KHR";
    case (1 << 17): return "VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT_KHR";
    case (1 << 18): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR";
    case (1 << 19): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR";
    case (1 << 20): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR";
    case (1 << 21): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR";
    case (1 << 22): return "VK_FORMAT_FEATURE_2_DISJOINT_BIT_KHR";
    case (1 << 23): return "VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT_KHR";
    case (1 << 31): return "VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT_KHR";
    case (1 << 32): return "VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT_KHR";
    case (1 << 33): return "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT_KHR";
    case (1 << 25): return "VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR";
    case (1 << 26): return "VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR";
    case (1 << 29): return "VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
    case (1 << 24): return "VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT";
    case (1 << 30): return "VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    case (1 << 27): return "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR";
    case (1 << 28): return "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR";
   }
   return NULL;
}
void print_VkFormatFeatureFlagBits2KHR(const VkFormatFeatureFlagBits2KHR* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkFormatFeatureFlagBits2KHR_map(*obj), commaNeeded ? "," : "");
}

void print_VkFormatFeatureFlags2KHR(const VkFormatFeatureFlags2KHR * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#ifdef VK_EXT_image_drm_format_modifier
void print_VkDrmFormatModifierPropertiesEXT(const VkDrmFormatModifierPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint64_t(&obj->drmFormatModifier, "drmFormatModifier", 1);

     print_uint32_t(&obj->drmFormatModifierPlaneCount, "drmFormatModifierPlaneCount", 1);

     print_VkFormatFeatureFlags(&obj->drmFormatModifierTilingFeatures, "drmFormatModifierTilingFeatures", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkDrmFormatModifierPropertiesListEXT(const VkDrmFormatModifierPropertiesListEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->drmFormatModifierCount, "drmFormatModifierCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDrmFormatModifierProperties\" :");
     if (obj->pDrmFormatModifierProperties) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->drmFormatModifierCount); i++) {
             if (i+1 == *(&obj->drmFormatModifierCount))
                 print_VkDrmFormatModifierPropertiesEXT(&obj->pDrmFormatModifierProperties[i], "pDrmFormatModifierProperties", 0);
             else
                 print_VkDrmFormatModifierPropertiesEXT(&obj->pDrmFormatModifierProperties[i], "pDrmFormatModifierProperties", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(const VkPhysicalDeviceImageDrmFormatModifierInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint64_t(&obj->drmFormatModifier, "drmFormatModifier", 1);

     print_VkSharingMode(&obj->sharingMode, "sharingMode", 1);

     print_uint32_t(&obj->queueFamilyIndexCount, "queueFamilyIndexCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pQueueFamilyIndices\" :");
     if (obj->pQueueFamilyIndices) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->queueFamilyIndexCount); i++) {
            char tmp[100];
            sprintf(tmp, "pQueueFamilyIndices_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->queueFamilyIndexCount);
            print_uint32_t(&obj->pQueueFamilyIndices[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkImageDrmFormatModifierListCreateInfoEXT(const VkImageDrmFormatModifierListCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->drmFormatModifierCount, "drmFormatModifierCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDrmFormatModifiers\" :");
     if (obj->pDrmFormatModifiers) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->drmFormatModifierCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDrmFormatModifiers_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->drmFormatModifierCount);
            print_uint64_t(&obj->pDrmFormatModifiers[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkImageDrmFormatModifierExplicitCreateInfoEXT(const VkImageDrmFormatModifierExplicitCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint64_t(&obj->drmFormatModifier, "drmFormatModifier", 1);

     print_uint32_t(&obj->drmFormatModifierPlaneCount, "drmFormatModifierPlaneCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pPlaneLayouts\" :");
     if (obj->pPlaneLayouts) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->drmFormatModifierPlaneCount); i++) {
             if (i+1 == *(&obj->drmFormatModifierPlaneCount))
                 print_VkSubresourceLayout(&obj->pPlaneLayouts[i], "pPlaneLayouts", 0);
             else
                 print_VkSubresourceLayout(&obj->pPlaneLayouts[i], "pPlaneLayouts", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkImageDrmFormatModifierPropertiesEXT(const VkImageDrmFormatModifierPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint64_t(&obj->drmFormatModifier, "drmFormatModifier", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkDrmFormatModifierProperties2EXT(const VkDrmFormatModifierProperties2EXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint64_t(&obj->drmFormatModifier, "drmFormatModifier", 1);

     print_uint32_t(&obj->drmFormatModifierPlaneCount, "drmFormatModifierPlaneCount", 1);

     print_VkFormatFeatureFlags2KHR(&obj->drmFormatModifierTilingFeatures, "drmFormatModifierTilingFeatures", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_drm_format_modifier
void print_VkDrmFormatModifierPropertiesList2EXT(const VkDrmFormatModifierPropertiesList2EXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->drmFormatModifierCount, "drmFormatModifierCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDrmFormatModifierProperties\" :");
     if (obj->pDrmFormatModifierProperties) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->drmFormatModifierCount); i++) {
             if (i+1 == *(&obj->drmFormatModifierCount))
                 print_VkDrmFormatModifierProperties2EXT(&obj->pDrmFormatModifierProperties[i], "pDrmFormatModifierProperties", 0);
             else
                 print_VkDrmFormatModifierProperties2EXT(&obj->pDrmFormatModifierProperties[i], "pDrmFormatModifierProperties", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_filter_cubic
void print_VkPhysicalDeviceImageViewImageFormatInfoEXT(const VkPhysicalDeviceImageViewImageFormatInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkImageViewType(&obj->imageViewType, "imageViewType", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_filter_cubic
void print_VkFilterCubicImageViewImageFormatPropertiesEXT(const VkFilterCubicImageViewImageFormatPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->filterCubic, "filterCubic", 1);

     print_VkBool32(&obj->filterCubicMinmax, "filterCubicMinmax", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_global_priority
static const char* VkQueueGlobalPriorityEXT_map(int o) {
switch (o) {
    case 128: return "VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT";
    case 256: return "VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT";
    case 512: return "VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT";
    case 1024: return "VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT";
   }
   return NULL;
}
void print_VkQueueGlobalPriorityEXT(const VkQueueGlobalPriorityEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkQueueGlobalPriorityEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_global_priority
void print_VkDeviceQueueGlobalPriorityCreateInfoEXT(const VkDeviceQueueGlobalPriorityCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkQueueGlobalPriorityEXT(&obj->globalPriority, "globalPriority", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_external_memory_host
void print_VkImportMemoryHostPointerInfoEXT(const VkImportMemoryHostPointerInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkExternalMemoryHandleTypeFlagBits(&obj->handleType, "handleType", 1);

     /** Note: Ignoring void* data. **/

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_external_memory_host
void print_VkMemoryHostPointerPropertiesEXT(const VkMemoryHostPointerPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->memoryTypeBits, "memoryTypeBits", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_external_memory_host
void print_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->minImportedHostPointerAlignment, "minImportedHostPointerAlignment", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_calibrated_timestamps
static const char* VkTimeDomainEXT_map(int o) {
switch (o) {
    case 0: return "VK_TIME_DOMAIN_DEVICE_EXT";
    case 1: return "VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT";
    case 2: return "VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT";
    case 3: return "VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT";
   }
   return NULL;
}
void print_VkTimeDomainEXT(const VkTimeDomainEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkTimeDomainEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_calibrated_timestamps
void print_VkCalibratedTimestampInfoEXT(const VkCalibratedTimestampInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkTimeDomainEXT(&obj->timeDomain, "timeDomain", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_attribute_divisor
void print_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxVertexAttribDivisor, "maxVertexAttribDivisor", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_attribute_divisor
void print_VkVertexInputBindingDivisorDescriptionEXT(const VkVertexInputBindingDivisorDescriptionEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_uint32_t(&obj->binding, "binding", 1);

     print_uint32_t(&obj->divisor, "divisor", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_attribute_divisor
void print_VkPipelineVertexInputDivisorStateCreateInfoEXT(const VkPipelineVertexInputDivisorStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->vertexBindingDivisorCount, "vertexBindingDivisorCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pVertexBindingDivisors\" :");
     if (obj->pVertexBindingDivisors) {
         vk_json_printf(_OUT, "\n");
         PRINT_SPACE
         vk_json_printf(_OUT, "[\n");
         for (unsigned int i = 0; i < *(&obj->vertexBindingDivisorCount); i++) {
             if (i+1 == *(&obj->vertexBindingDivisorCount))
                 print_VkVertexInputBindingDivisorDescriptionEXT(&obj->pVertexBindingDivisors[i], "pVertexBindingDivisors", 0);
             else
                 print_VkVertexInputBindingDivisorDescriptionEXT(&obj->pVertexBindingDivisors[i], "pVertexBindingDivisors", 1);
         }
         PRINT_SPACE
         vk_json_printf(_OUT, "]\n");
     }
     else 
     {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_attribute_divisor
void print_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->vertexAttributeInstanceRateDivisor, "vertexAttributeInstanceRateDivisor", 1);

     print_VkBool32(&obj->vertexAttributeInstanceRateZeroDivisor, "vertexAttributeInstanceRateZeroDivisor", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_pci_bus_info
void print_VkPhysicalDevicePCIBusInfoPropertiesEXT(const VkPhysicalDevicePCIBusInfoPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->pciDomain, "pciDomain", 1);

     print_uint32_t(&obj->pciBus, "pciBus", 1);

     print_uint32_t(&obj->pciDevice, "pciDevice", 1);

     print_uint32_t(&obj->pciFunction, "pciFunction", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_subgroup_size_control
void print_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT(const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->subgroupSizeControl, "subgroupSizeControl", 1);

     print_VkBool32(&obj->computeFullSubgroups, "computeFullSubgroups", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_subgroup_size_control
void print_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT(const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->minSubgroupSize, "minSubgroupSize", 1);

     print_uint32_t(&obj->maxSubgroupSize, "maxSubgroupSize", 1);

     print_uint32_t(&obj->maxComputeWorkgroupSubgroups, "maxComputeWorkgroupSubgroups", 1);

     print_VkShaderStageFlags(&obj->requiredSubgroupSizeStages, "requiredSubgroupSizeStages", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_subgroup_size_control
void print_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT(const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->requiredSubgroupSize, "requiredSubgroupSize", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_shader_image_atomic_int64
void print_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderImageInt64Atomics, "shaderImageInt64Atomics", 1);

     print_VkBool32(&obj->sparseImageInt64Atomics, "sparseImageInt64Atomics", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_memory_budget
void print_VkPhysicalDeviceMemoryBudgetPropertiesEXT(const VkPhysicalDeviceMemoryBudgetPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"heapBudget\" :");
     if (obj->heapBudget) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_MEMORY_HEAPS); i++) {
            char tmp[100];
            sprintf(tmp, "heapBudget_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_MEMORY_HEAPS);
            print_VkDeviceSize(&obj->heapBudget[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     PRINT_SPACE
     vk_json_printf(_OUT, "\"heapUsage\" :");
     if (obj->heapUsage) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < (VK_MAX_MEMORY_HEAPS); i++) {
            char tmp[100];
            sprintf(tmp, "heapUsage_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != (VK_MAX_MEMORY_HEAPS);
            print_VkDeviceSize(&obj->heapUsage[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_validation_features
static const char* VkValidationFeatureEnableEXT_map(int o) {
switch (o) {
    case 0: return "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT";
    case 1: return "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT";
    case 2: return "VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT";
    case 3: return "VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT";
    case 4: return "VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT";
   }
   return NULL;
}
void print_VkValidationFeatureEnableEXT(const VkValidationFeatureEnableEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkValidationFeatureEnableEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_validation_features
static const char* VkValidationFeatureDisableEXT_map(int o) {
switch (o) {
    case 0: return "VK_VALIDATION_FEATURE_DISABLE_ALL_EXT";
    case 1: return "VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT";
    case 2: return "VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT";
    case 3: return "VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT";
    case 4: return "VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT";
    case 5: return "VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT";
    case 6: return "VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT";
    case 7: return "VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT";
   }
   return NULL;
}
void print_VkValidationFeatureDisableEXT(const VkValidationFeatureDisableEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkValidationFeatureDisableEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_validation_features
void print_VkValidationFeaturesEXT(const VkValidationFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->enabledValidationFeatureCount, "enabledValidationFeatureCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pEnabledValidationFeatures\" :");
     if (obj->pEnabledValidationFeatures) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->enabledValidationFeatureCount); i++) {
            char tmp[100];
            sprintf(tmp, "pEnabledValidationFeatures_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->enabledValidationFeatureCount);
            print_VkValidationFeatureEnableEXT(&obj->pEnabledValidationFeatures[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "],\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\",\n");
     }

     print_uint32_t(&obj->disabledValidationFeatureCount, "disabledValidationFeatureCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pDisabledValidationFeatures\" :");
     if (obj->pDisabledValidationFeatures) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->disabledValidationFeatureCount); i++) {
            char tmp[100];
            sprintf(tmp, "pDisabledValidationFeatures_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->disabledValidationFeatureCount);
            print_VkValidationFeatureDisableEXT(&obj->pDisabledValidationFeatures[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_fragment_shader_interlock
void print_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->fragmentShaderSampleInterlock, "fragmentShaderSampleInterlock", 1);

     print_VkBool32(&obj->fragmentShaderPixelInterlock, "fragmentShaderPixelInterlock", 1);

     print_VkBool32(&obj->fragmentShaderShadingRateInterlock, "fragmentShaderShadingRateInterlock", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_ycbcr_image_arrays
void print_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->ycbcrImageArrays, "ycbcrImageArrays", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_headless_surface
void print_VkHeadlessSurfaceCreateFlagsEXT(const VkHeadlessSurfaceCreateFlagsEXT * obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     vk_json_printf(_OUT, "\"%s\" : \"%d\"%s\n", str, (int)(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_headless_surface
void print_VkHeadlessSurfaceCreateInfoEXT(const VkHeadlessSurfaceCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkHeadlessSurfaceCreateFlagsEXT(&obj->flags, "flags", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_line_rasterization
static const char* VkLineRasterizationModeEXT_map(int o) {
switch (o) {
    case 0: return "VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT";
    case 1: return "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT";
    case 2: return "VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT";
    case 3: return "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT";
   }
   return NULL;
}
void print_VkLineRasterizationModeEXT(const VkLineRasterizationModeEXT* obj, const char* str, int commaNeeded) {
     PRINT_SPACE
     if (strncmp(str, "", 255)) vk_json_printf(_OUT, "\"%s\" : ", str);
     vk_json_printf(_OUT, "\"%s\"%s\n", VkLineRasterizationModeEXT_map(*obj), commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_line_rasterization
void print_VkPhysicalDeviceLineRasterizationFeaturesEXT(const VkPhysicalDeviceLineRasterizationFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->rectangularLines, "rectangularLines", 1);

     print_VkBool32(&obj->bresenhamLines, "bresenhamLines", 1);

     print_VkBool32(&obj->smoothLines, "smoothLines", 1);

     print_VkBool32(&obj->stippledRectangularLines, "stippledRectangularLines", 1);

     print_VkBool32(&obj->stippledBresenhamLines, "stippledBresenhamLines", 1);

     print_VkBool32(&obj->stippledSmoothLines, "stippledSmoothLines", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_line_rasterization
void print_VkPhysicalDeviceLineRasterizationPropertiesEXT(const VkPhysicalDeviceLineRasterizationPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->lineSubPixelPrecisionBits, "lineSubPixelPrecisionBits", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_line_rasterization
void print_VkPipelineRasterizationLineStateCreateInfoEXT(const VkPipelineRasterizationLineStateCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkLineRasterizationModeEXT(&obj->lineRasterizationMode, "lineRasterizationMode", 1);

     print_VkBool32(&obj->stippledLineEnable, "stippledLineEnable", 1);

     print_uint32_t(&obj->lineStippleFactor, "lineStippleFactor", 1);

     print_uint16_t(&obj->lineStipplePattern, "lineStipplePattern", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_shader_atomic_float
void print_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderBufferFloat32Atomics, "shaderBufferFloat32Atomics", 1);

     print_VkBool32(&obj->shaderBufferFloat32AtomicAdd, "shaderBufferFloat32AtomicAdd", 1);

     print_VkBool32(&obj->shaderBufferFloat64Atomics, "shaderBufferFloat64Atomics", 1);

     print_VkBool32(&obj->shaderBufferFloat64AtomicAdd, "shaderBufferFloat64AtomicAdd", 1);

     print_VkBool32(&obj->shaderSharedFloat32Atomics, "shaderSharedFloat32Atomics", 1);

     print_VkBool32(&obj->shaderSharedFloat32AtomicAdd, "shaderSharedFloat32AtomicAdd", 1);

     print_VkBool32(&obj->shaderSharedFloat64Atomics, "shaderSharedFloat64Atomics", 1);

     print_VkBool32(&obj->shaderSharedFloat64AtomicAdd, "shaderSharedFloat64AtomicAdd", 1);

     print_VkBool32(&obj->shaderImageFloat32Atomics, "shaderImageFloat32Atomics", 1);

     print_VkBool32(&obj->shaderImageFloat32AtomicAdd, "shaderImageFloat32AtomicAdd", 1);

     print_VkBool32(&obj->sparseImageFloat32Atomics, "sparseImageFloat32Atomics", 1);

     print_VkBool32(&obj->sparseImageFloat32AtomicAdd, "sparseImageFloat32AtomicAdd", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_index_type_uint8
void print_VkPhysicalDeviceIndexTypeUint8FeaturesEXT(const VkPhysicalDeviceIndexTypeUint8FeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->indexTypeUint8, "indexTypeUint8", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_extended_dynamic_state
void print_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->extendedDynamicState, "extendedDynamicState", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_shader_demote_to_helper_invocation
void print_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT(const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->shaderDemoteToHelperInvocation, "shaderDemoteToHelperInvocation", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_texel_buffer_alignment
void print_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->texelBufferAlignment, "texelBufferAlignment", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_texel_buffer_alignment
void print_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT(const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->storageTexelBufferOffsetAlignmentBytes, "storageTexelBufferOffsetAlignmentBytes", 1);

     print_VkBool32(&obj->storageTexelBufferOffsetSingleTexelAlignment, "storageTexelBufferOffsetSingleTexelAlignment", 1);

     print_VkDeviceSize(&obj->uniformTexelBufferOffsetAlignmentBytes, "uniformTexelBufferOffsetAlignmentBytes", 1);

     print_VkBool32(&obj->uniformTexelBufferOffsetSingleTexelAlignment, "uniformTexelBufferOffsetSingleTexelAlignment", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_robustness2
void print_VkPhysicalDeviceRobustness2FeaturesEXT(const VkPhysicalDeviceRobustness2FeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->robustBufferAccess2, "robustBufferAccess2", 1);

     print_VkBool32(&obj->robustImageAccess2, "robustImageAccess2", 1);

     print_VkBool32(&obj->nullDescriptor, "nullDescriptor", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_robustness2
void print_VkPhysicalDeviceRobustness2PropertiesEXT(const VkPhysicalDeviceRobustness2PropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkDeviceSize(&obj->robustStorageBufferAccessSizeAlignment, "robustStorageBufferAccessSizeAlignment", 1);

     print_VkDeviceSize(&obj->robustUniformBufferAccessSizeAlignment, "robustUniformBufferAccessSizeAlignment", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_custom_border_color
void print_VkSamplerCustomBorderColorCreateInfoEXT(const VkSamplerCustomBorderColorCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkClearColorValue(&obj->customBorderColor, "customBorderColor", 1);

     print_VkFormat(&obj->format, "format", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_custom_border_color
void print_VkPhysicalDeviceCustomBorderColorPropertiesEXT(const VkPhysicalDeviceCustomBorderColorPropertiesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->maxCustomBorderColorSamplers, "maxCustomBorderColorSamplers", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_custom_border_color
void print_VkPhysicalDeviceCustomBorderColorFeaturesEXT(const VkPhysicalDeviceCustomBorderColorFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->customBorderColors, "customBorderColors", 1);

     print_VkBool32(&obj->customBorderColorWithoutFormat, "customBorderColorWithoutFormat", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_ycbcr_2plane_444_formats
void print_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->ycbcr2plane444Formats, "ycbcr2plane444Formats", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_image_robustness
void print_VkPhysicalDeviceImageRobustnessFeaturesEXT(const VkPhysicalDeviceImageRobustnessFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->robustImageAccess, "robustImageAccess", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_4444_formats
void print_VkPhysicalDevice4444FormatsFeaturesEXT(const VkPhysicalDevice4444FormatsFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->formatA4R4G4B4, "formatA4R4G4B4", 1);

     print_VkBool32(&obj->formatA4B4G4R4, "formatA4B4G4R4", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_input_dynamic_state
void print_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->vertexInputDynamicState, "vertexInputDynamicState", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_input_dynamic_state
void print_VkVertexInputBindingDescription2EXT(const VkVertexInputBindingDescription2EXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->binding, "binding", 1);

     print_uint32_t(&obj->stride, "stride", 1);

     print_VkVertexInputRate(&obj->inputRate, "inputRate", 1);

     print_uint32_t(&obj->divisor, "divisor", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_vertex_input_dynamic_state
void print_VkVertexInputAttributeDescription2EXT(const VkVertexInputAttributeDescription2EXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->location, "location", 1);

     print_uint32_t(&obj->binding, "binding", 1);

     print_VkFormat(&obj->format, "format", 1);

     print_uint32_t(&obj->offset, "offset", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_extended_dynamic_state2
void print_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->extendedDynamicState2, "extendedDynamicState2", 1);

     print_VkBool32(&obj->extendedDynamicState2LogicOp, "extendedDynamicState2LogicOp", 1);

     print_VkBool32(&obj->extendedDynamicState2PatchControlPoints, "extendedDynamicState2PatchControlPoints", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_color_write_enable
void print_VkPhysicalDeviceColorWriteEnableFeaturesEXT(const VkPhysicalDeviceColorWriteEnableFeaturesEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_VkBool32(&obj->colorWriteEnable, "colorWriteEnable", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_color_write_enable
void print_VkPipelineColorWriteCreateInfoEXT(const VkPipelineColorWriteCreateInfoEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->attachmentCount, "attachmentCount", 1);

     PRINT_SPACE
     vk_json_printf(_OUT, "\"pColorWriteEnables\" :");
     if (obj->pColorWriteEnables) {
        vk_json_printf(_OUT, "\n"); PRINT_SPACE
        vk_json_printf(_OUT, "[\n");
        for (unsigned int i = 0; i < *(&obj->attachmentCount); i++) {
            char tmp[100];
            sprintf(tmp, "pColorWriteEnables_%u", i);
            INDENT(4);
            int isCommaNeeded = (i+1) != *(&obj->attachmentCount);
            print_VkBool32(&obj->pColorWriteEnables[i], "", isCommaNeeded);
            INDENT(-4);
        }
        PRINT_SPACE
        vk_json_printf(_OUT, "]\n");
     } else {
         vk_json_printf(_OUT, " \"NULL\"\n");
     }

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
#ifdef VK_EXT_application_parameters
void print_VkApplicationParametersEXT(const VkApplicationParametersEXT * obj, const char* s, int commaNeeded) {
     (void)s;
     PRINT_SPACE
     vk_json_printf(_OUT, "{\n");
     INDENT(4);

     print_VkStructureType(&obj->sType, "sType", 1);

     if (obj->pNext) {
         dumpPNextChain(obj->pNext);
     } else {
         PRINT_SPACE
         vk_json_printf(_OUT, "\"pNext\" : \"NULL\",\n");
     }

     print_uint32_t(&obj->vendorID, "vendorID", 1);

     print_uint32_t(&obj->deviceID, "deviceID", 1);

     print_uint32_t(&obj->key, "key", 1);

     print_uint64_t(&obj->value, "value", 0);

     INDENT(-4);
     PRINT_SPACE
     vk_json_printf(_OUT, "}%s\n", commaNeeded ? "," : "");
}

#endif
