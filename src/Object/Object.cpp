#include <Object/Object.hpp>


const char* ObjectShader = "R(
    #version 330 core
    layout (location = 0) in vec objectPosition;

    void main() {

    }
)";

// Purpose: Object::Object() constructor.
// Author: @egely1337
// Date: 10/25/2023
Object::Object(const char* path){
    // Load Model
    this->m_cObjLoader.load((char*)path);
};

// Purpose: Object::Render this should be called every frame.
// Author: @egely1337
// Date: 10/25/2023
void Object::Render(void)
{   
    // Reset Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set Client State GL_VERTEX_ARRAY
    glEnableClientState(GL_VERTEX_ARRAY);

    // Set Pointers
    glVertexPointer(8, GL_FLOAT, 0, &cube_vertices[0]);

    // Change Position
    glTranslatef(
        this->m_vObjectPosition.x, // X Angle
        this->m_vObjectPosition.y, // Y Angle
        this->m_vObjectPosition.z // Z Angle
    );

    // Draw Array
    glDrawArrays(GL_TRIANGLES, 0, 8);

    // Disable GL_VERTEX_ARRAY Client State
    glDisableClientState(GL_VERTEX_ARRAY);

    // Change Matrix Mode GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
}

// Purpose: Returns m_vObjectPosition
// Author: @egely1337
// Date: 10/25/2023
glm::vec3 &Object::GetPosition(void)
{
    return this->m_vObjectPosition;
}

// Purpose: Returns m_vObjectRotation
// Author: @egely1337
// Date: 10/25/2023
glm::vec3 &Object::GetRotation(void)
{
    return this->m_vObjectRotation;
}

// Purpose: Sets m_vObjectPosition
// Author: @egely1337
// Date: 10/25/2023
void Object::SetPosition(glm::vec3 newPosition)
{
    this->m_vObjectPosition = newPosition;
}

// Purpose: Returns m_vObjectRotation
// Author: @egely1337
// Date: 10/25/2023
void Object::SetRotation(glm::vec3 newRotation)
{
    this->m_vObjectRotation = newRotation;
}
