#pragma once

#include "Settings.hpp"
#include <vulkan/vulkan.h>
#include <vector>

namespace vl
{
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    class Vulkan
    {
    public:
        Vulkan();
        ~Vulkan();

    private:
        Settings settings;

        VkInstance instance;
        VkDebugUtilsMessengerEXT debugMessenger;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

        void initVulkan();
        void createInstance();
        void setupDebugMessenger();
        void pickPhysicalDevice();

        // Create instance
        std::vector<const char *> getRequiredExtensions();
        bool checkValidationLayerSupport();
        // Setup Debug Messenger
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData);
        static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDebugUtilsMessengerEXT *pDebugMessenger);
        static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks *pAllocator);
        // Pick physical device
        bool isDeviceSuitable(VkPhysicalDevice device);
    };
};
