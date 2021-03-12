#include <Cute/Testing/BoxScene.hpp>

#include "../Internal/GlWrappers.hpp"

#include <Cute/Graphics/Shapes/Box.hpp>
#include <Cute/Graphics/Shaders/Shader.hpp>
#include <Cute/Graphics/Transform/Model.hpp>
#include <Cute/Graphics/Transform/View.hpp>
#include <Cute/Graphics/Transform/Projection.hpp>
#include <imgui.h>

namespace Cute::Testing
{

static auto PrintMatrix4x4(const std::string& name, const glm::mat4& mat4)
{
  ImGui::Text("%s", name.c_str());
  for (auto i = 0; i < 4; ++i)
  {
      ImGui::Text("| %+.3f %+.3f %+.3f %+.3f |\n", mat4[0][i], mat4[1][i], mat4[2][i], mat4[3][i]);
  }
}

void BoxScene::doRender()
{
  const auto PlusPi = glm::pi<float>();
  const auto MinusPi = -glm::pi<float>();
  const auto model = model_->toMatrix();
  const auto view = camera_->toMatrix();
  const auto projection = projection_->toMatrix();
  const auto mvp = projection * view * model;

  ImGui::Begin("Box Scene Control");
  if (ImGui::Button("Reset"))
  {
    *model_ = Cute::Graphics::Model();
  }
  if (ImGui::Button("Open MatrixView"))
  {
     EnableMatrixWindow = true;
  }

  if (ImGui::Begin("MatrixView", &EnableMatrixWindow))
  {
    PrintMatrix4x4("Model", model);
    PrintMatrix4x4("View", view);
    PrintMatrix4x4("Projection", projection);
    PrintMatrix4x4("MVP", mvp);
    ImGui::End();
  }

  ImGui::SliderFloat3("BoxPosition", model_->GetPositionPtr(), -1.0f, 1.0f);
  ImGui::SliderFloat3("BoxScale", model_->GetScalePtr(), 0.0f, 2.0f);
  ImGui::SliderFloat("BoxPitch", model_->GetPitchPtr(), MinusPi, PlusPi);
  ImGui::SliderFloat("BoxYaw", model_->GetYawPtr(), MinusPi, PlusPi);
  ImGui::SliderFloat("BoxRoll", model_->GetRollPtr(), MinusPi, PlusPi);

  ImGui::End();

  Gl::ClearColor(backgroundColor_.r, backgroundColor_.g, backgroundColor_.b, 1.0f);

  boxShader_->Bind();
  boxShader_->SetUniform("u_Model", model);
  boxShader_->SetUniform("u_View", view);
  boxShader_->SetUniform("u_Projection", projection);

  boxShape_->Draw(*boxShader_);
}

void BoxScene::doInitialize()
{
  constexpr auto vShaderPath = "Resources/Shaders/v_box.glsl";
  constexpr auto fShaderPath = "Resources/Shaders/f_box.glsl";

  boxShape_ = std::make_unique<Cute::Graphics::Box>();
  boxShader_ = std::make_unique<Cute::Graphics::Shader>(vShaderPath, fShaderPath);
  model_ = std::make_unique<Cute::Graphics::Model>();
  camera_ = std::make_unique<Cute::Graphics::Camera>();
  projection_ = std::make_unique<Cute::Graphics::Projection>();
  backgroundColor_ = {0.0f, 0.0f, 0.0f};

  camera_->setPosition({-1.0f, 1.0f, 2.f});
  camera_->lookAt({0.0f, 0.0f, 0.0f});
}

void BoxScene::doFinalize()
{
  boxShape_.reset();
  boxShader_.reset();
  model_.reset();
  camera_.reset();
  projection_.reset();
}
}
