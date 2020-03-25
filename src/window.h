#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

extern const char* APP_TITLE;
const int gWindowWidth = 800;
const int gWindowHeight = 600;

GLFWwindow* createGLFWContext();
void initializeGLEW();
void showFPS(GLFWwindow* window);
void shutdown(GLFWwindow* window);