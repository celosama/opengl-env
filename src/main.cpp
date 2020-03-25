#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "window.h"
#include "events.h"

using namespace std;

int main() {
  GLFWwindow* pWindow = createGLFWContext();

  if (pWindow == NULL) {
    cerr << "GLFW: failed to initialize GLFW context" << endl;
    glfwTerminate();
    return 1;
  }

  if (!createGLEWContext()) {
    cerr << "GLEW: failed to initialize GLEW context" << endl;
    glfwTerminate();
    return 1;
  }

  glfwSetKeyCallback(pWindow, onKey);

  // Main loop
  while (!glfwWindowShouldClose(pWindow)) {
    glfwPollEvents();

    glClearColor(0.23f, 0.38f, 0.47f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(pWindow);
  }

  clog << "GLFW: window terminated" << endl;

  glfwTerminate();
  return 0;
}