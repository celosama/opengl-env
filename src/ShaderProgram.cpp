#include "ShaderProgram.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

ShaderProgram::ShaderProgram() 
  : mProgram(0) {
}

ShaderProgram::~ShaderProgram() {
  glDeleteProgram(mProgram);
}

bool ShaderProgram::loadShaders(const char* vsFilename, const char* fsFilename) {
  string vsString = fileToString(vsFilename);
  string fsString = fileToString(fsFilename);
  const GLchar* vsSourcePtr = vsString.c_str();
  const GLchar* fsSourcePtr = fsString.c_str();

  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vs, 1, &vsSourcePtr, NULL);
  glShaderSource(fs, 1, &fsSourcePtr, NULL);

  glCompileShader(vs);
  checkCompileErrors(vs, VERTEX);

  glCompileShader(fs);
  checkCompileErrors(vs, FRAGMENT);

  mProgram = glCreateProgram();
  glAttachShader(mProgram, vs);
  glAttachShader(mProgram, fs);
  glLinkProgram(mProgram);
  checkCompileErrors(mProgram, PROGRAM);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return true;
}

void ShaderProgram::use() {
  if (mProgram > 0) {
    glUseProgram(mProgram);
  }
}

string ShaderProgram::fileToString(const string& filename) {
  stringstream ss;
  ifstream file;

  try {
    file.open(filename, ios::in);

    if (!file.fail()) {
      ss << file.rdbuf();
    }

    file.close();
  } catch(exception ex) {
    cerr << "Error reading shader filename" << endl;
  }

  return ss.str();
}

void ShaderProgram::checkCompileErrors(GLuint shader, ShaderType type) {
  int status = 0;

  if (type == PROGRAM) {
    glGetProgramiv(mProgram, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
      GLint length = 0;
      glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &length);

      string errorLog(length, ' ');
      glGetProgramInfoLog(mProgram, length, &length, &errorLog[0]);

      cerr << "Shader Program failed to link. " << errorLog << endl;
    }
  } else {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
      GLint length = 0;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

      string errorLog(length, ' ');
      glGetShaderInfoLog(shader, length, &length, &errorLog[0]);

      cerr << "Shader failed to compile. " << errorLog << endl;
    }
  }
}

GLint ShaderProgram::getUniformLocation(const GLchar* name) {
  std::map<string, GLint>::iterator it = mUniformLocations.find(name);

  if (it == mUniformLocations.end()) {
    mUniformLocations[name] = glGetUniformLocation(mProgram, name);
  }

  return mUniformLocations[name];
}

void ShaderProgram::setUniform(const GLchar* name, const glm::vec2& v) {
  GLint loc = getUniformLocation(name);
  glUniform2f(loc, v.x, v.y);
}

void ShaderProgram::setUniform(const GLchar* name, const glm::vec3& v) {
  GLint loc = getUniformLocation(name);
  glUniform3f(loc, v.x, v.y, v.z);
}

void ShaderProgram::setUniform(const GLchar* name, const glm::vec4& v) {
  GLint loc = getUniformLocation(name);
  glUniform4f(loc, v.x, v.y, v.z, v.w);
}