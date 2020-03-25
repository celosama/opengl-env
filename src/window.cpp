#include <iostream>

#include "window.h"

using namespace std;

const char* APP_TITLE = "OpenGL Demo";

GLFWwindow* createGLFWContext() {
  if (!glfwInit()) {
    cerr << "GLFW: failed to initialize" << endl;

    return NULL;
  }

  clog << "GLFW: initialized" << endl;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* pWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, APP_TITLE, NULL, NULL);

  if (pWindow == NULL) {
    cerr << "GLFW: failed to create window" << endl;
    glfwTerminate();

    return NULL;
  }

  clog << "GLFW: window created" << endl;

  glfwMakeContextCurrent(pWindow);

  return pWindow;
}

bool createGLEWContext() {
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    cerr << "GLEW: failed to initialize" << endl;
    glfwTerminate();

    return false;
  }

  return true;
}