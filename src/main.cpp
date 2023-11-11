#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderer.hpp"

// OpenGL error callback function
void glfwErrorCallback(int error, const char* description) {
    std::cerr << "OpenGL Error (" << error << "): " << description << std::endl;
}


int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set the error callback
    glfwSetErrorCallback(glfwErrorCallback);

    // Configure GLFW to use OpenGL 3.3 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    renderer::init();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render

        renderer::render();


        // Swap the front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}
