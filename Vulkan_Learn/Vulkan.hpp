#pragma once

#include "Window.hpp"
#include "Settings.hpp"
#include <optional>
#include <vector>

namespace vl
{
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    struct QueueFamilyIndices
    {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool isComplete()
        {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    class Vulkan
    {
    public:
        Vulkan(Window *window);
        ~Vulkan();
        Vulkan(const Vulkan &) = delete;
        Vulkan &operator=(const Vulkan &) = delete;

    private:
        Settings settings;

        VkInstance instance;
        VkDebugUtilsMessengerEXT debugMessenger;
        VkSurfaceKHR surface;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice device;
        VkQueue graphicsQueue;
        VkQueue presentQueue;

        void initVulkan(Window *window);
        void createInstance();
        void setupDebugMessenger();
        void createSurface(Window *window);
        void pickPhysicalDevice();
        void createLogicalDevice();

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
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        // Swap chain
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    };
}
