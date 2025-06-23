#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Settings.hpp"

namespace vl
{
    class Window
    {
    public:
        Window();
        ~Window();
        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        GLFWwindow *getGLFWwindow();
        bool getFrameBufferResized();
        void setFrameBufferResized(bool value);

    private:
        Settings settings;
        
        GLFWwindow *window;

        bool framebufferResized = false;

        void initWindow();

        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
    };
}
