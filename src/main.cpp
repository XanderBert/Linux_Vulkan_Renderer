#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanSetup.h"

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) return -1;

    //Don't use OpenGl but Vulkan
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    constexpr int width{640};
    constexpr int height{480};

    window = glfwCreateWindow(width, height, "Vulkan", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    VulkanSetup vulkan{};
    vulkan.InitVulkan();

    

    
    /* Make the window's context current */
    // glfwMakeContextCurrent(window);
    // glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

    // /* Loop until the user closes the window */
    // while (!glfwWindowShouldClose(window))
    // {
    //     /* Render here */
    //     glClear(GL_COLOR_BUFFER_BIT);

    //     /* Swap front and back buffers */
    //     glfwSwapBuffers(window);

    //     /* Poll for and process events */
    //     glfwPollEvents();
    // }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}