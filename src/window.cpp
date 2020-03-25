#include <iostream>

#include "window.h"

using namespace std;

const char* APP_TITLE = "OpenGL Demo";

GLFWwindow* createGLFWContext() {
  if (!glfwInit()) {
    cerr << "GLFW: failed to initialize GLFW context" << endl;
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  clog << "GLFW: initialized" << endl;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* pWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, APP_TITLE, NULL, NULL);

  if (pWindow == NULL) {
    cerr << "GLFW: failed to create window" << endl;
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  clog << "GLFW: window created" << endl;

  glfwMakeContextCurrent(pWindow);

  return pWindow;
}

void initializeGLEW() {
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    cerr << "GLEW: failed to initialize" << endl;
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}