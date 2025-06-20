#include "Application.hpp"

namespace vl
{
    Application::Application() : window(), vulkan(&window) {}

    Application::~Application() {}

    void Application::run()
    {
        window.render();
    }
}
