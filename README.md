# Vulkan Hello Triangle

A learning project created to understand the core foundations of the Vulkan graphics pipeline.

This repository implements the classic **Hello Triangle** example using **modern Vulkan**, **CMake**, and a minimal supporting stack. It was created as a hands-on exercise while following the Vulkan Tutorial.

## Prerequisites

You will need:

- **Vulkan SDK** (with `glslc` shader compiler)
- **CMake** ≥ 3.15
- **C++17** compatible compiler
- **GLFW** (included as a submodule)
- **GLM** (header-only, included as a submodule)

> **Note:** Make sure the `VULKAN_SDK` environment variable is set correctly.

## Building the Project
```bash
git clone --recursive <repo-url>
cd VulkanHelloTriangle
mkdir build
cd build
cmake ..
cmake --build .
```

## Running

After building, run the executable:
```bash
# On Linux/macOS
./VulkanHelloTriangle

# On Windows
.\VulkanHelloTriangle.exe
```

You should see a window with a colorful triangle!

## Learning Resources

This project was created while following the excellent [Vulkan Tutorial](https://vulkan-tutorial.com/) by Alexander Overvoorde.

- **Tutorial content:** Licensed under [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)
- **Tutorial code examples:** [CC0 1.0 Universal](https://creativecommons.org/publicdomain/zero/1.0/)
