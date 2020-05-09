#pragma once

#include <string>

#define GLEW_STATIC
#include "GL/glew.h"

using std::string;

class Texture2D {
  public:
    Texture2D();
    virtual ~Texture2D();

    bool loadTexture(const string& filename, bool generateMipMaps = true);
    void bind(GLuint texUnit = 0);

  private:
    GLuint mTexture;
};