#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <string>


class Instance
{
public:
    void create();
    void destroy();
    VkInstance get() const;
private:
    VkInstance instance = VK_NULL_HANDLE;
};