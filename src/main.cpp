#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "window.h"
#include "events.h"
#include "ShaderProgram.h"

using namespace std;

int main() {
  GLFWwindow* pWindow = createGLFWContext();
  initializeGLEW();
  glfwSetKeyCallback(pWindow, onKey);

  GLfloat vertices[] = {
    -0.5f,  0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
  };

  GLuint indices[] = {
    0, 1, 2, // tri 0
    0, 2, 3  // tri 1
  };

  GLuint vbo, ibo, vao;

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // position
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glEnableVertexAttribArray(0);

  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  ShaderProgram shaderProgram;
  shaderProgram.loadShaders("data/basic_vert.glsl", "data/basic_frag.glsl");

  // Main loop
  while (!glfwWindowShouldClose(pWindow)) {
    showFPS(pWindow);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);

    shaderProgram.use();

    GLfloat time = glfwGetTime();
    GLfloat blueColor = (sin(time) / 2) + 0.5f;
    glm::vec2 pos;
    pos.x = sin(time) / 2;
    pos.y = cos(time) / 2;

    shaderProgram.setUniform("vertColor", glm::vec4(0.0f, 0.0f, blueColor, 1.0f));
    shaderProgram.setUniform("posOffset", pos);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glfwSwapBuffers(pWindow);
  }

  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  shutdown(pWindow);
  exit(EXIT_SUCCESS);
}