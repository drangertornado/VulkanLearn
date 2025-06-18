#pragma once

#include "Settings.hpp"
#include "Window.hpp"
#include "Vulkan.hpp"

namespace vl
{
    class Application
    {
    public:
        bool framebufferResized = false;
        Application();
        ~Application();

    private:
        Settings settings;

        Window window;
        Vulkan vulkan;
    };
};