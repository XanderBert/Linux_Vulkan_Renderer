cmake_minimum_required (VERSION 3.28)

project (VulkanProject)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

# Find GLFW and Vulkan
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)

# Add the executable and include the main.cpp and additional.cpp
add_executable(VulkanProject 
    "${source_dir}/main.cpp"
    "${source_dir}/VulkanSetup.cpp"
)

# Include the header files
target_include_directories(VulkanProject PRIVATE "${source_dir}")

# Link against GLFW and Vulkan
target_link_libraries(VulkanProject PRIVATE glfw Vulkan::Vulkan)