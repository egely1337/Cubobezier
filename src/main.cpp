#include <iostream>

#include <Window/Window.hpp>
#include <Object/Object.hpp>
#include <Shader/Shader.hpp>
#include <Camera/Camera.hpp>

int main(int argc, char* argv[]) {
    Window gameWindow("My Engine", 800, 600);
    gameWindow.CreateWindow();

    Object object("monkey.obj");
    object.SetPosition(glm::vec3(0.0f,0.f,0.f));
    
    Camera gameCamera;


    do {
        glClear(GL_COLOR_BUFFER_BIT);
        
        gameCamera.Tick();
        object.Render();

        glfwSwapBuffers(&gameWindow.GetWindow());
        glfwPollEvents();
    } while(!gameWindow.ShouldWindowClose());

    return EXIT_SUCCESS;
}