#include <Camera/Camera.hpp>
#include "Camera.hpp"

/*
 *  Purpose: Camera Constructor
 */
Camera::Camera() {
    this->Think();
}

/*
 *  Purpose: This method called every frame.
 */
void Camera::Tick(void)
{
    this->Think();

    float x = cos(glfwGetTime()) * 5;
    float z = sin(glfwGetTime()) * 5;

    this->m_vCameraPosition = glm::vec3(x, 0, 5);

    glMatrixMode(GL_PROJECTION);
    glScissor(0, 0, 800, 600);
    glViewport(0, 0, 800, 600);
    glLoadIdentity();
    glLoadMatrixf(&this->GetView(40, 800, 600)[0][0]);
    glMatrixMode(GL_MODELVIEW);
}

/*
 *  Purpose: Camera thinks and sets their variables
 */
void Camera::Think(void)
{
    // Set Camera Direction, Camera Right, Camera Up and View.
    m_vCameraFront = glm::normalize(m_vCameraDirection);

    this->m_vCameraDirection = glm::normalize(this->m_vCameraPosition - this->m_vCameraTarget);
    this->m_vCameraRight = glm::normalize(glm::cross(this->m_vCameraUp, this->m_vCameraDirection));
    this->m_vCameraUp = glm::cross(this->m_vCameraDirection, this->m_vCameraRight);
    this->view = glm::lookAt(
        this->m_vCameraPosition,
        this->m_vCameraPosition + this->m_vCameraFront,
        this->m_vCameraUp
    );
}

/*
 *  Purpose: Returns view
 */
glm::mat4& Camera::GetMatrixView() {
    return this->view;
}

/*
 *  Purpose: Returns calculated perspective view.
 */
glm::mat4 Camera::GetView(float fov, float width, float height)
{
    return  glm::perspective(fov, (float)width / (float)height, 0.05f, 1000.f) * this->GetMatrixView();
}