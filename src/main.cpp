#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "window.h"
#include "events.h"

using namespace std;

const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"layout (location = 1) in vec3 color;"
"out vec3 vert_color;"
"void main()"
"{"
"   vert_color = color;"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* framentShaderSrc =
"#version 330 core\n"
"in vec3 vert_color;"
"out vec4 frag_color;"
"void main()"
"{"
"   frag_color = vec4(vert_color, 1.0f);"
"}";

int main() {
  GLFWwindow* pWindow = createGLFWContext();
  initializeGLEW();
  glfwSetKeyCallback(pWindow, onKey);

  GLfloat vert_pos[] = {
    // position
     0.0f,  0.5f, 0.0f, // top
     0.5f, -0.5f, 0.0f, // right
    -0.5f, -0.5f, 0.0f, // left
  };

  GLfloat vert_color[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
  };

  GLuint vbo, vbo2, vao;

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vert_pos), vert_pos, GL_STATIC_DRAW);

  glGenBuffers(1, &vbo2);
  glBindBuffer(GL_ARRAY_BUFFER, vbo2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vert_color), vert_color, GL_STATIC_DRAW);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // position
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glEnableVertexAttribArray(0);

  // color
  glBindBuffer(GL_ARRAY_BUFFER, vbo2);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glEnableVertexAttribArray(1);

  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vs, 1, &vertexShaderSrc, NULL);
  glCompileShader(vs);

  GLint result;
  GLchar infoLog[512];
  glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
  if (!result) {
    glGetShaderInfoLog(vs, sizeof(infoLog), NULL, infoLog);
    cout << "Error: Vertex shader failed to compile. " << infoLog << endl;
  }

  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fs, 1, &framentShaderSrc, NULL);
  glCompileShader(fs);

  glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
  if (!result) {
    glGetShaderInfoLog(fs, sizeof(infoLog), NULL, infoLog);
    cout << "Error: Fragment shader failed to compile. " << infoLog << endl;
  }

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vs);
  glAttachShader(shaderProgram, fs);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);

  if (!result) {
    glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
    cout << "Error: Shader Program linker failure. " << infoLog << endl;
  }

  glDeleteShader(vs);
  glDeleteShader(fs);

  // Main loop
  while (!glfwWindowShouldClose(pWindow)) {
    showFPS(pWindow);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    glfwSwapBuffers(pWindow);
  }

  glDeleteProgram(shaderProgram);
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  shutdown(pWindow);
  exit(EXIT_SUCCESS);
}