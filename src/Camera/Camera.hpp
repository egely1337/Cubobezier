#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext.hpp>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Camera {
public:
    Camera();
    void Tick(void);
    void Think(void);

    glm::mat4& GetMatrixView();
    glm::mat4 GetView(float fov, float width, float height);

private:
    glm::vec3 m_vCameraPosition = glm::vec3(0, 0, 3.0f);
    glm::vec3 m_vCameraTarget = glm::vec3(0.f, 0.f, 0.f);
    glm::vec3 m_vCameraDirection = glm::vec3(0.f, 0.f, 0.f);

    glm::vec3 m_vCameraFront = glm::vec3(0.f, 0.f, -1.f);
    glm::vec3 m_vCameraUp = glm::vec3(0.f, 1.f, 0.f);
    glm::vec3 m_vCameraRight = glm::vec3(0.f, 0.f, 0.f);

    glm::mat4 view;
};


#endif