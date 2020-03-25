#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main() {
  if (!glfwInit()) {
    std::cerr << "GLFW Failed to initialize.";
    return 1;
  }

  std::cin.get();

  return 0;
}