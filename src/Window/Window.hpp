#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(const char* WINDOW_NAME, const int width, const int height);

    void CreateWindow(void);

    bool IsWindowOpen();
    bool ShouldWindowClose();

    bool Update();

    GLFWwindow& GetWindow();
private:

    /* Window Properties */
    const char* m_cWindowName = 0;
    uint16_t m_iWindowWidth = 800;
    uint16_t m_iWindowHeight = 600;

    /* GLFW Window Pointer */
    GLFWwindow* m_glfwWindow = 0;
    
    /* Is Window Open Boolean */
    bool m_bIsWindowOpen = false;
};     
#endif