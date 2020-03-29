#pragma once
#include <string>
#include <map>

#define GLEW_STATIC
#include "GL/glew.h"
#include "glm/glm.hpp"

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

    void setUniform(const GLchar* name, const glm::vec2& v);
    void setUniform(const GLchar* name, const glm::vec3& v);
    void setUniform(const GLchar* name, const glm::vec4& v);

  private:
    string fileToString(const string& filename);
    void checkCompileErrors(GLuint shader, ShaderType type);
    GLint getUniformLocation(const GLchar* name);

    GLuint mProgram;
    std::map<string, GLint> mUniformLocations;
};