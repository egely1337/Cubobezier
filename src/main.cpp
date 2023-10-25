#include <iostream>

#include <Window/Window.hpp>
#include <Object/Object.hpp>
#include <Shader/Shader.hpp>

int main(int argc, char* argv[]) {
    Window gameWindow("My Engine");
    gameWindow.CreateWindow();

    Object object("monkey.obj");

    do {
        glClear(GL_COLOR_BUFFER_BIT);

        object.Render();
        object.SetPosition(glm::vec3(0.f,0.f,0.f));

        glfwSwapBuffers(&gameWindow.GetWindow());
        glfwPollEvents();
    } while(!gameWindow.ShouldWindowClose());

    return EXIT_SUCCESS;
}