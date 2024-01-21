#define GLFW_INCLUDE_VULKAN
#include <GL/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
//#include <vulkan/vulkan.h>


int main(void)
{




    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) return -1;

    if (glfwVulkanSupported() == GLFW_TRUE)
    {
        std::cout << "Vulkan support\n";
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
