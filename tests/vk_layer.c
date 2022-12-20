#include "vulkan/vk_layer.h"

// Use helper macro intended for vulkan layers to export functions
VK_LAYER_EXPORT int foobar()
{
    return 0;
}
