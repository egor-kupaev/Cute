#include <Cute/Engine/BasicEngine.hpp>

#include <GL/glew.h>
#include <gl/GL.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>

#include "Internal/DefaultScene.hpp"

namespace Cute::Engine
{

int BasicEngine::doRun()
{
  glfwSetErrorCallback([](int error, const char *description)
                       {
                         std::cerr << "GLFW Error " << error << ": " << description << std::endl;
                       });

  if (!glfwInit())
  {
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  auto window = glfwCreateWindow(1280, 720, "Cute", nullptr, nullptr);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetFramebufferSizeCallback(window, [](auto, int x, int y) {
    glViewport( 0, 0, x, y);
  });
  glfwSetWindowAspectRatio(window, 16, 9);

  if (glewInit() != GLEW_OK)
  {
    std::cerr << "Failed to load OpenGL" << std::endl;
    glfwTerminate();
    return -1;
  }

  if (!glGetError())
  {}

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  glEnable(GL_DEPTH_TEST);

  bool ShowDemoWindow = true;

  std::string currentSceneName = "Default";
  auto *currentScene = scenes_[currentSceneName].get();
  currentScene->Initialize();

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    currentScene->Render();

    if (ShowDemoWindow)
    {
      ImGui::ShowDemoWindow(&ShowDemoWindow);
    }

    ImGui::Begin("Scene Selector");



    ImGui::Text("Select Scene to render");

    if (ImGui::BeginListBox("Scenes"))
    {
      for (auto &scene: scenes_)
      {
        const bool is_selected = (currentSceneName == scene.first);

        if (ImGui::Selectable(scene.first.data(), is_selected))
        {
          currentSceneName = scene.first;
          currentScene->Finalize();
          currentScene = scenes_[currentSceneName].get();
          currentScene->Initialize();
        }

        if (is_selected)
          ImGui::SetItemDefaultFocus();

      }
      ImGui::EndListBox();
    }

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  currentScene->Finalize();

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}

void BasicEngine::doAddScene(const std::string &name, std::unique_ptr<Scene> &&scene)
{
  scenes_.emplace(std::make_pair(name, std::move(scene)));
}

BasicEngine::BasicEngine() : scenes_()
{
  using namespace std::string_literals;

  scenes_.emplace(std::make_pair("Default"s, std::make_unique<Internal::DefaultScene>()));
}
}
