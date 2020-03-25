#include "events.h"

bool gWireFrame = false;

void onKey(GLFWwindow* window, int key, int scanCode, int action, int mode) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }

  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
    gWireFrame = !gWireFrame;

    if (gWireFrame)
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }
}