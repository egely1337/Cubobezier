#include <Camera/Camera.hpp>
#include "Camera.hpp"

/*
 *  Purpose: Camera Constructor
 *  Author: @egely1337
 *  Date: 10/25/2023
 * 
 */
Camera::Camera() {
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
 *  Purpose: This method called every frame.
 *  Author: @egely1337
 *  Date: 10/25/2023
 * 
 */
void Camera::Tick(void)
{
    this->Think();

    this->m_vCameraPosition -= glm::vec3(0, 0, 0.001f);
    glScissor(0, 0, 800, 600);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadMatrixf(&this->GetView(40, 800, 600)[0][0]);
    glMatrixMode(GL_MODELVIEW);
}

/*
 *  Purpose: Camera thinks and sets their variables
 *  Author: @egely1337
 *  Date: 10/25/2023
 * 
 */
void Camera::Think(void)
{
    // Set Camera Direction, Camera Right, Camera Up and View.
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
 *  Author: @egely1337
 *  Date: 10/25/2023
 * 
 */
glm::mat4& Camera::GetMatrixView() {
    return this->view;
}

/*
 *  Purpose: Returns calculated perspective view.
 *  Author: @egely1337
 *  Date: 10/25/2023
 * 
 */
glm::mat4 Camera::GetView(float fov, float width, float height)
{
    return this->GetMatrixView() * glm::perspective(fov, (float)width / (float)height, 0.05f, 100.f);
}