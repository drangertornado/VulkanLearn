#include "Application.hpp"
#include <iostream>

namespace vl
{
    Application::Application()
    {
        settings = GlobalSettings::get();

        window = Window();
        std::cout << "\nWindow initialized!" << std::endl;
        vulkan = Vulkan(&window);
        std::cout << "\nVulkan initialized!" << std::endl;
    }

    Application::~Application() {}

    void Application::run()
    {
        window.render();
        std::cout << "\nApp is running!" << std::endl;
    }
}
