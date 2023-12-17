#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    void CreateWindow(const char* window_name, int width, int height);

    bool IsWindowOpen();
    bool ShouldWindowClose();

    bool Update();

    GLFWwindow* GetWindow();
    static Window& GetInstance();

    uint16_t& GetWindowWidth();
    uint16_t& GetWindowHeight();
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