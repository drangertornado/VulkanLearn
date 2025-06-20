#include "Window.hpp"
#include "Application.hpp"

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

    void Window::render()
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
        }
    }

    void Window::initWindow()
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        window = glfwCreateWindow(settings.width, settings.height, settings.applicationName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }

    void Window::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto self = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
        self->framebufferResized = true;
    }
}
