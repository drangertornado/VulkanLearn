# Vulkan Hello Triangle

A fun project focused on understanding the core foundations of the Vulkan graphics pipeline.

This repository implements the classic **Hello Triangle** example using **modern Vulkan**, **CMake**, and a minimal supporting stack.

## What This Project Covers

This project walks through the essential building blocks required to render a triangle with Vulkan:

- Vulkan instance and device initialization
- Swapchain creation and presentation
- Graphics pipeline setup
- Shader compilation to SPIR-V
- Command buffers and synchronization
- A minimal render loop

## Dependencies

You will need:

- **Vulkan SDK** (with `glslc`)
- **CMake ≥ 3.15**
- **C++17 compatible compiler**
- **GLFW** (included as a submodule)
- **GLM** (header-only, included)

Make sure the `VULKAN_SDK` environment variable is set correctly.

## Building the Project

```bash
git clone --recursive <repo-url>
cd VulkanHelloTriangle

mkdir build
cd build
cmake ..
cmake --build .

References:
https://vulkan-tutorial.com/
