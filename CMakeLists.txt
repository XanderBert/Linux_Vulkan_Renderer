cmake_minimum_required (VERSION 3.28)

project (TestProject)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
file (GLOB source_files "${source_dir}/*.cpp")

# Find GLFW
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)


#option(GLFW_USE_WAYLAND "Use Wayland for window creation" ON)

add_executable (TestProject ${source_files})
target_link_libraries(TestProject PRIVATE glfw OpenGL::GL Vulkan::Vulkan)
