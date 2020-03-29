#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include <string>
using std::string;

class ShaderProgram {
  public:
    ShaderProgram();
    ~ShaderProgram();

    enum ShaderType {
      VERTEX,
      FRAGMENT,
      PROGRAM
    };

    bool loadShaders(const char* vsFilename, const char* fsFilename);
    void use();

  private:
    string fileToString(const string& filename);
    void checkCompileErrors(GLuint shader, ShaderType type);

    GLuint mHandle;
};