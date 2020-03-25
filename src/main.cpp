#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "window.h"
#include "events.h"

using namespace std;

int main() {
  GLFWwindow* pWindow = createGLFWContext();
  initializeGLEW();

  glfwSetKeyCallback(pWindow, onKey);

  // Main loop
  while (!glfwWindowShouldClose(pWindow)) {
    showFPS(pWindow);
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(pWindow);
  }

  glfwDestroyWindow(pWindow);
  clog << "GLFW: window terminated" << endl;

  glfwTerminate();
  exit(EXIT_SUCCESS);
}