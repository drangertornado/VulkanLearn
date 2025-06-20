#pragma once

#include "Settings.hpp"
#include "Window.hpp"
#include "Vulkan.hpp"

namespace vl
{
    class Application
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        Settings settings;

        Window window;
        Vulkan vulkan;
    };
}
