#include "Window.hpp"
#include <iostream>

namespace vl
{
    Window::Window()
    {
        settings = GlobalSettings::get();

        initWindow();
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);

        glfwTerminate();
    }

    GLFWwindow *Window::getGLFWwindow()
    {
        return window;
    }

    void Window::initWindow()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Window: failed to initialize GLFW!");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        window = glfwCreateWindow(settings.width, settings.height, settings.applicationName.c_str(), nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("Window: failed to create GLFW window!");
        }

        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

        std::cout << "Window: GLFW successfully initialized!" << std::endl;
    }

    void Window::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto self = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
        self->framebufferResized = true;
    }
}
