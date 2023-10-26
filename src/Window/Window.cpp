#include <Window/Window.hpp>
#include "Window.hpp"


/* 
 * Purpose: Creates Window (Use this with Window::GetInstance())
 */
void Window::CreateWindow(const char *window_name, int width, int height)
{
    this->m_iWindowWidth = width;
    this->m_iWindowHeight = height;
    this->m_cWindowName = window_name;

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

/* 
 * Purpose: Returns static Window& instance
 */
bool Window::IsWindowOpen() {
    return this->m_bIsWindowOpen;
}

/* 
 * Purpose: Returns GLFWWindow Should Window Close
 */
bool Window::ShouldWindowClose()
{
    return glfwWindowShouldClose(this->m_glfwWindow);
}

/*
 * Purpose: Returns GLFWWindow Should Window Close
 */
GLFWwindow* Window::GetWindow() {
    return this->m_glfwWindow;
}

/* 
 * Purpose: Returns static Window& instance
 */
Window &Window::GetInstance()
{
    static Window instance;

    return instance;
}

/*
 * Purpose: Returns Window Height
 */
uint16_t &Window::GetWindowWidth()
{
    return this->m_iWindowWidth;
}

/*
 * Purpose: Returns Window Height
 */
uint16_t &Window::GetWindowHeight()
{
    return this->m_iWindowHeight;
}
