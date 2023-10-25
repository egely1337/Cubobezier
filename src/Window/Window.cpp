#include <Window/Window.hpp>


Window::Window(const char* WINDOW_NAME) : m_cWindowName(WINDOW_NAME){};

// Purpose: Create a GLFW Window
// Author: @egely1337
// Date: 10/23/2023
void Window::CreateWindow(void) {
    // Init GLEW
    if(!glewInit()) {
        fprintf(stderr, "Window::CreateWindow() glew init failed.\n\r");
    }

    // Init GLFW 
    if(!glfwInit()) {
        fprintf(stderr, "Window::CreateWindow() glfw init failed.\n\r");
    }

    // Create GLFWWindow and make it m_glfwWindow
    m_glfwWindow = glfwCreateWindow(
        m_iWindowWidth, m_iWindowHeight,
        m_cWindowName,
        0, 0
    );

    // Return a error message if window creation is failed.
    if(m_glfwWindow == nullptr) {
        fprintf(stderr, "Window::CreateWindow(void) failed.\n\r");
    }

    // Make m_glfwWindow as context renderer.
    glfwMakeContextCurrent(m_glfwWindow);

    // Change value m_bIsWindowOpen is m_glfwWindow is not nullptr (0)
    m_bIsWindowOpen = (m_glfwWindow != nullptr) ? true : false;
}

// Purpose: Get m_bIsWindowOpen private variable.
// Author: @egely1337
// Date: 10/23/2023
bool Window::IsWindowOpen() {
    return m_bIsWindowOpen;
}

// Purpose: Returns should m_glfwWindow close.
// Author: @egely1337
// Date: 10/23/2023
bool Window::ShouldWindowClose()
{
    return glfwWindowShouldClose(m_glfwWindow);
}

// Purpose: Returns should m_glfwWindow close.
// Author: @egely1337
// Date: 10/23/2023
bool Window::Update()
{   
    glClear(GL_COLOR_BUFFER_BIT);


    glfwSwapBuffers(m_glfwWindow);
    glfwPollEvents();
    return true;
}

// Purpose: Get m_glfwWindow private variable.
// Author: @egely1337
// Date: 10/23/2023
GLFWwindow& Window::GetWindow() {
    return *m_glfwWindow;
}