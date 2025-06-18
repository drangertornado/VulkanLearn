#pragma once

#include "Settings.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace vl
{
    class Window
    {
    public:
        Window();
        ~Window();

        GLFWwindow* getGLFWwindow();

    private:
        Settings settings;

        GLFWwindow* window;

        void initWindow();
        static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    };
};
