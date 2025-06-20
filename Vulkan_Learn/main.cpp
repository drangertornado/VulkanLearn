#pragma once

#include "Application.hpp"
#include <stdexcept>
#include <iostream>

int main()
{
    vl::Application app = vl::Application();
    
    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
