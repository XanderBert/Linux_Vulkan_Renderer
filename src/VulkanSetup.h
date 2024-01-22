#pragma once

#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string.h>

class VulkanSetup final
{
public:
    VulkanSetup() = default;
    ~VulkanSetup();

    VkInstance* InitVulkan();

private:
    void Setup();
    bool CheckValidationLayerSupport();
    std::vector<const char*> GetRequiredExtensions();
    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
    void SetupDebugMessenger();
    void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    VkResult CreateDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator);
    void DestroyDebugUtilsMessengerEXT(VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
    void PickPhysicalDevice();




    const std::vector<const char*> m_ValidationLayers = 
    {
        "VK_LAYER_KHRONOS_validation"
    };

    VkInstance m_Instance;
    bool m_PrintAvailableExtensiosn{ true };
    bool m_EnableValidationLayers{ false };
    VkDebugUtilsMessengerEXT m_DebugMessenger;
};