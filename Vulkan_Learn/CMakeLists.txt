cmake_minimum_required(VERSION 3.15)

project(VulkanLearn VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vulkan Setup
find_package(Vulkan REQUIRED)

if (NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan SDK not found! Please set VULKAN_SDK environment variable.")
endif()

# Shader Compilation
set(SHADER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/shaders")
set(SHADER_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/shaders")
file(MAKE_DIRECTORY ${SHADER_OUTPUT_DIR})

# Find glslc
find_program(GLSLC_COMPILER glslc
    PATHS "$ENV{VULKAN_SDK}/Bin"
    REQUIRED
    DOC "Path to the glslc compiler (from Vulkan SDK)"
)
message(STATUS "Using glslc compiler: ${GLSLC_COMPILER}")

# Gather shaders
file(GLOB SHADER_SOURCE_FILES
    "${SHADER_SOURCE_DIR}/*.vert"
    "${SHADER_SOURCE_DIR}/*.frag"
    "${SHADER_SOURCE_DIR}/*.comp"
)

set(GENERATED_SPV_FILES "")
foreach(SHADER ${SHADER_SOURCE_FILES})
    get_filename_component(FILE_NAME ${SHADER} NAME)
    set(OUTPUT_SPV "${SHADER_OUTPUT_DIR}/${FILE_NAME}.spv")

    add_custom_command(
        OUTPUT ${OUTPUT_SPV}
        COMMAND ${GLSLC_COMPILER} ${SHADER} -o ${OUTPUT_SPV}
        DEPENDS ${SHADER}
        COMMENT "Compiling shader: ${FILE_NAME}"
    )

    list(APPEND GENERATED_SPV_FILES ${OUTPUT_SPV})
endforeach()

add_custom_target(compile_shaders ALL DEPENDS ${GENERATED_SPV_FILES})

# Executable and Source Files
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
    VulkanInstance.h
    VulkanInstance.cpp
)

add_dependencies(${PROJECT_NAME} compile_shaders)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GENERATED_SPV_FILES}
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders
    COMMENT "Copying compiled shaders to executable 'shaders/' directory"
)

# Include Directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${Vulkan_INCLUDE_DIRS}
)

# Vulkan Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Vulkan::Vulkan
)

# Compiler Optimization Flags
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Release>:/O2>"
        "$<$<CONFIG:Debug>:/Od;/Zi;/Ob0;/RTC1>"
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Release>:-O3 -DNDEBUG>"
        "$<$<CONFIG:Debug>:-Og -g>"
    )
endif()

# GLFW
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/external/glfw/include)

# GLM
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glm EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/external/glm)

# Optional install targets (commented out, for later use)
# install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
# install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/shaders DESTINATION bin)
