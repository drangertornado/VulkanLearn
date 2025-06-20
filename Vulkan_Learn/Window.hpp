#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Settings.hpp"

namespace vl
{
    class Window
    {
    public:
        bool framebufferResized = false;

        Window();
        ~Window();

        GLFWwindow *getGLFWwindow();
        void render();

    private:
        Settings settings;

        GLFWwindow *window;

        void initWindow();

        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
    };
}
