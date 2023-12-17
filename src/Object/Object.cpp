#include <Object/Object.hpp>

/*
 * Purpose: Object::Object() constructor
 */
Object::Object(const char* path){

    // Load Model
    this->m_cObjLoader.load((char*)path);
};

/*
 * Purpose: Object Tick
 */
void Object::Tick(void)
{   
    glMatrixMode(GL_MODELVIEW);    
    glLoadIdentity();

    glTranslatef(
     this->m_vObjectPosition.x,
     this->m_vObjectPosition.y,
     this->m_vObjectPosition.z
    );

    glBegin(GL_POLYGON);
        int b = 0;
        for(int i = 0; i < this->m_cObjLoader.getVertCount(); i++) {
            glVertex3f(this->m_cObjLoader.getPositions()[b], this->m_cObjLoader.getPositions()[b+1], this->m_cObjLoader.getPositions()[b+2]);
            b += 3;
        }
    glEnd();

    glMatrixMode(GL_PROJECTION);
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
