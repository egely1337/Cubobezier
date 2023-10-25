#include <Object/Object.hpp>


GLfloat vertices[] = {
    0.0f, 0.5f, 0.0f, // Vertex 1
   -0.5f, -0.5f, 0.0f, // Vertex 2
    0.5f, -0.5f, 0.0f,  // Vertex 3
    0.5f, 0.5f // Vertex 4
};


// Purpose: Object::Object() constructor.
// Author: @egely1337
// Date: 10/25/2023
Object::Object(const char* path){
    m_cObjLoader.load((char*)path);

    // Change Client State

    for(int i = 0; i < m_cObjLoader.getVertCount(); i += 3) {
        printf("%f %f %f\n", m_cObjLoader.getPositions()[i], m_cObjLoader.getPositions()[i+1], m_cObjLoader.getPositions()[i+2]);
    }

};

// Purpose: Object::Render this should be called every frame.
// Author: @egely1337
// Date: 10/25/2023
void Object::Render(void)
{
    // Reset Matrix
    glLoadIdentity();

    // Set Client State GL_VERTEX_ARRAY
    glEnableClientState(GL_VERTEX_ARRAY);

    // Set Pointers
    glVertexPointer(m_cObjLoader.getVertCount(), GL_FLOAT, 0, (float*)m_cObjLoader.getPositions());
    
    // Change Position
    glTranslatef(m_vObjectPosition.x, m_vObjectPosition.y, m_vObjectPosition.z);
    
    // Draw Array
    glDrawArrays(GL_TRIANGLES, 0, m_cObjLoader.getVertCount());

    // Disable GL_VERTEX_ARRAY Client State
    glDisableClientState(GL_VERTEX_ARRAY);
}

// Purpose: Returns m_vObjectPosition
// Author: @egely1337
// Date: 10/25/2023
glm::vec3 &Object::GetPosition(void)
{
    return m_vObjectPosition;
}

// Purpose: Returns m_vObjectRotation
// Author: @egely1337
// Date: 10/25/2023
glm::vec3 &Object::GetRotation(void)
{
    return m_vObjectRotation;
}

// Purpose: Sets m_vObjectPosition
// Author: @egely1337
// Date: 10/25/2023
void Object::SetPosition(glm::vec3 newPosition)
{
    m_vObjectPosition = newPosition;
}

// Purpose: Returns m_vObjectRotation
// Author: @egely1337
// Date: 10/25/2023
void Object::SetRotation(glm::vec3 newRotation)
{
    m_vObjectRotation = newRotation;
}
