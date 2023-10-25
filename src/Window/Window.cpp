#include <Window/Window.hpp>


Window::Window(const char* WINDOW_NAME, const int width, const int height) : m_cWindowName(WINDOW_NAME),
m_iWindowHeight(height),
m_iWindowWidth(width)
{
    // Not Implemented
};

// Purpose: Create a GLFW Window
// Author: @egely1337
// Date: 10/23/2023
void Window::CreateWindow(void) {

    // Init GLFW 
    if(!glfwInit()) {
        fprintf(stderr, "Window::CreateWindow() glfw init failed.\n\r");
    }

    // Create GLFWWindow and make it m_glfwWindow
    this->m_glfwWindow = glfwCreateWindow(
        this->m_iWindowWidth, 
        this->m_iWindowHeight,
        this->m_cWindowName,
        0, 0
    );

    // Return a error message if window creation is failed.
    if(this->m_glfwWindow == nullptr) {
        fprintf(stderr, "Window::CreateWindow(void) failed.\n\r");
    }

    // Make m_glfwWindow as context renderer.
    glfwMakeContextCurrent(this->m_glfwWindow);

    // Change value m_bIsWindowOpen is m_glfwWindow is not nullptr (0)
    this->m_bIsWindowOpen = (this->m_glfwWindow != nullptr) ? true : false;
}

// Purpose: Get m_bIsWindowOpen private variable.
// Author: @egely1337
// Date: 10/23/2023
bool Window::IsWindowOpen() {
    return this->m_bIsWindowOpen;
}

// Purpose: Returns should m_glfwWindow close.
// Author: @egely1337
// Date: 10/23/2023
bool Window::ShouldWindowClose()
{
    return glfwWindowShouldClose(this->m_glfwWindow);
}

// Purpose: Returns should m_glfwWindow close.
// Author: @egely1337
// Date: 10/23/2023
bool Window::Update()
{   
    glClear(GL_COLOR_BUFFER_BIT);


    glfwSwapBuffers(this->m_glfwWindow);
    glfwPollEvents();
    return true;
}

// Purpose: Get m_glfwWindow private variable.
// Author: @egely1337
// Date: 10/23/2023
GLFWwindow& Window::GetWindow() {
    return *this->m_glfwWindow;
}