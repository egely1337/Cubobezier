#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <ObjLoader/objloader.h>

class Object {
public:
    Object(const char* path);

    void Render();

    glm::vec3& GetPosition(void);
    glm::vec3& GetRotation(void);

    void SetPosition(glm::vec3 newPosition);
    void SetRotation(glm::vec3 newRotation);
private:
    GLfloat** m_fPVBOArray;

    glm::vec3 m_vObjectPosition;
    glm::vec3 m_vObjectRotation;

    sp::ObjLoader m_cObjLoader;
};

#endif