#pragma once

#include <string>
#include <vulkan/vulkan.h>

namespace vl
{
    class Settings
    {
    public:
        // Application information
        std::string applicationName = "Hello Triangle";
        uint32_t applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        std::string engineName = "No engine";
        uint32_t engineVersion = VK_MAKE_VERSION(1, 0, 0);
        uint32_t apiVersion = VK_API_VERSION_1_0;

        // Resolution
        unsigned int width = 800;
        unsigned int height = 600;

        // Double buffering
        unsigned int maxFramesInFlight = 2;
    };

    class GlobalSettings
    {
    public:
        static Settings &get()
        {
            static Settings instance;
            return instance;
        }

        GlobalSettings(const GlobalSettings &) = delete;
        GlobalSettings &operator=(const GlobalSettings &) = delete;
    };
};