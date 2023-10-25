#ifndef SHADER_H
#define SHADER_H

#include <iostream>

#include <GLFW/glfw3.h>
#include <GL/gl.h> // OH NOOOO
#include <File/File.hpp>

class Shader{
public:
    Shader(const char* path);
private:
    GLuint m_iShaderId;
};


#endif