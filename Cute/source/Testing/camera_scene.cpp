#include <cute/testing/camera_scene.hpp>

#include "../internal/GlWrappers.hpp"
#include "../engine/internal/global_timer.hpp"

#include <GLFW/glfw3.h>

#include <imgui.h>

namespace Cute::Engine
{
extern GLFWwindow *gWindow;
}

namespace Cute::Testing
{
static auto currentX = 0.0f;
static auto lastX = 0.0f;
static auto currentY = 0.0f;
static auto lastY = 0.0f;

static auto ProcessInput(Cute::Graphics::Camera &camera)
{
  auto dt = Engine::gTimer.Delta();

  if (glfwGetKey(Engine::gWindow, GLFW_KEY_W) == GLFW_PRESS)
    camera.MoveForward(dt);
  if (glfwGetKey(Engine::gWindow, GLFW_KEY_A) == GLFW_PRESS)
    camera.MoveLeft(dt);
  if (glfwGetKey(Engine::gWindow, GLFW_KEY_S) == GLFW_PRESS)
    camera.MoveBackward(dt);
  if (glfwGetKey(Engine::gWindow, GLFW_KEY_D) == GLFW_PRESS)
    camera.MoveRight(dt);
}

static auto MouseCallback(GLFWwindow *, double x, double y)
{
  currentX = static_cast<float>(x);
  currentY = static_cast<float>(y);
}

void CameraScene::doRender()
{
  const auto MinPitch = -89.0f;
  const auto MaxPitch = 89.0f;
  const auto MinYaw = -180.0f;
  const auto MaxYaw = 180.0f;

  ImGui::Begin("CameraControl");
  ImGui::SliderFloat3("Position", glm::value_ptr(camera_->getPosition()), -2.0f, 2.0f);
  ImGui::SliderFloat3("Direction", glm::value_ptr(camera_->getDirection()), -2.0f, 2.0f);
  ImGui::SliderFloat("Camera Pitch", &camera_->getPitch(), MinPitch, MaxPitch);
  ImGui::SliderFloat("Camera Yaw  ", &camera_->getYaw(), MinYaw, MaxYaw);
  if (EnableManualControl)
  {
    if (ImGui::IsKeyPressed(GLFW_KEY_ESCAPE))
    {
      EnableManualControl = false;
      glfwSetCursorPosCallback(Engine::gWindow, nullptr);
      glfwSetInputMode(Engine::gWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    ImGui::Text("Press ESC to disable manual control");

    ProcessInput(*camera_);
  }
  if (!EnableManualControl && ImGui::Button("Manual camera control"))
  {
    EnableManualControl = true;
    glfwSetCursorPosCallback(Engine::gWindow, MouseCallback);
    glfwSetInputMode(Engine::gWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }

  ImGui::End();

  camera_->AddPitch(lastY - currentY);
  camera_->AddYaw(currentX - lastX);
  lastX = currentX;
  lastY = currentY;

  BoxScene::doRender();
}

void CameraScene::doInitialize()
{
  BoxScene::doInitialize();
}

void CameraScene::doFinalize()
{
  BoxScene::doFinalize();
}
}
