#include <Object/Object.hpp>

/*
 * Purpose: Object::Object() constructor
 */
Object::Object(const char* path){

    // Load Model
    this->m_cObjLoader.load((char*)path);
};

float vertices[] = {
    // Front face
    -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    
    // Back face
    -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f
};

/*
 * Purpose: Object Tick
 */
void Object::Tick(void)
{   
    glLoadIdentity();

    glTranslatef(
     this->m_vObjectPosition.x,
     this->m_vObjectPosition.y,
     this->m_vObjectPosition.z
    );

    glScalef(1.f, 1.f, 1.f);

    glBegin(GL_POLYGON);
    for(int i = 0; i < sizeof(vertices) / sizeof(float); i += 3) {
        glVertex3f(vertices[i], vertices[i+1], vertices[i+2]);
    }
    glEnd();;
}

/*
 * Purpose: Returns m_vObjectPosition
 */
glm::vec3 &Object::GetPosition(void)
{
    return this->m_vObjectPosition;
}

/*
 * Purpose: Returns m_vObjectRotation
 */
glm::vec3 &Object::GetRotation(void)
{
    return this->m_vObjectRotation;
}

/*
 * Purpose: Sets a new glm::vec3 as position
 */
void Object::SetPosition(glm::vec3 newPosition)
{
    this->m_vObjectPosition = newPosition;
}

/*
 * Purpose: Sets a new glm::vec3 as rotation
 */
void Object::SetRotation(glm::vec3 newRotation)
{
    this->m_vObjectRotation = newRotation;
}
