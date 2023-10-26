#include <iostream>

#include <Window/Window.hpp>
#include <Object/Object.hpp>
#include <Shader/Shader.hpp>
#include <Camera/Camera.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

Camera gameCamera;
Object gameObject("./monkey.obj");

int main(int argc, char* argv[]) {
    Window::GetInstance().CreateWindow("Cubobezier", 800, 600);

    gameObject.SetPosition(glm::vec3(0, 0, 0));

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(Window::GetInstance().GetWindow(), true);


    do {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        

        gameCamera.Tick();
        gameObject.Tick();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Camera Properties", (bool*)1);
            ImGui::Text("Hello");

        ImGui::End();


        ImGui::Render();
        ImGui::EndFrame();
        glfwSwapBuffers(Window::GetInstance().GetWindow());
    } while(!Window::GetInstance().ShouldWindowClose());

    return EXIT_SUCCESS;
}