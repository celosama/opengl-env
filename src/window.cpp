#include <iostream>
#include <sstream>

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
  glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

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

void showFPS(GLFWwindow* window) {
  static double previousSeconds = 0.0;
  static int frameCount = 0;
  double elapsedSeconds;
  double currentSeconds = glfwGetTime();

  elapsedSeconds = currentSeconds - previousSeconds;

  if (elapsedSeconds > 0.25) {
    previousSeconds = currentSeconds;
    double fps = (double) frameCount / elapsedSeconds;
    double msPerFrame = 1000.0 / fps;

    ostringstream outs;
    outs.precision(2);
    outs << fixed << APP_TITLE << " | FPS: " << fps << " | Frame time: " << msPerFrame << " (ms)";

    glfwSetWindowTitle(window, outs.str().c_str());

    frameCount = 0;
  }

  frameCount++;
}

void shutdown(GLFWwindow* window) {
  glfwDestroyWindow(window);
  clog << "GLFW: window terminated" << endl;

  glfwTerminate();
}