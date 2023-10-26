#include <iostream>

#include <Window/Window.hpp>
#include <Object/Object.hpp>
#include <Shader/Shader.hpp>
#include <Camera/Camera.hpp>

//#include <imgui/imgui.h>
//#include <imgui/imgui_impl_glfw.h>
//#include <imgui/imgui_impl_opengl3.h>

Camera gameCamera;
Object gameObject("./monkey.obj");

int main(int argc, char* argv[]) {
    Window::GetInstance().CreateWindow("Cubobezier", 800, 600);

    do {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        gameCamera.Tick();
        gameObject.Tick();

        glfwSwapBuffers(Window::GetInstance().GetWindow());
    } while(!Window::GetInstance().ShouldWindowClose());

    return EXIT_SUCCESS;
}