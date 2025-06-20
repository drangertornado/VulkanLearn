#pragma once

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
        Window window;
        Vulkan vulkan;
    };
}
