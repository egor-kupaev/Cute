#include <Cute/Testing/TextureScene.hpp>

#include "../Internal/GlWrappers.hpp"

#include <filesystem>

#include <imgui.h>

namespace Cute::Testing
{

void TextureScene::doRender()
{
  const auto PlusPi = glm::pi<float>();
  const auto MinusPi = -glm::pi<float>();
  const auto model = _model->toMatrix();
  const auto view = _camera->toMatrix();
  const auto projection = _projection->toMatrix();

  ImGui::Begin("Box Scene Control");
  if (ImGui::Button("Reset"))
  {
    *_model = Cute::Graphics::Model();
  }

  ImGui::SliderFloat3("BoxPosition", _model->GetPositionPtr(), -1.0f, 1.0f);
  ImGui::SliderFloat3("BoxScale", _model->GetScalePtr(), 0.0f, 2.0f);
  ImGui::SliderFloat("BoxPitch", _model->GetPitchPtr(), MinusPi, PlusPi);
  ImGui::SliderFloat("BoxYaw", _model->GetYawPtr(), MinusPi, PlusPi);
  ImGui::SliderFloat("BoxRoll", _model->GetRollPtr(), MinusPi, PlusPi);

  if (ImGui::BeginListBox("Textures"))
  {
    for (auto &texture: _textures)
    {
      const bool is_selected = (_currentTexture == texture);

      if (ImGui::Selectable(texture.c_str(), is_selected))
      {
        _currentTexture = texture;
        _texture = std::make_unique<Cute::Graphics::Texture>(_texturesPath + _currentTexture, 0u);
      }

      if (is_selected)
      {
        ImGui::SetItemDefaultFocus();
      }
    }
    ImGui::EndListBox();
  }

  ImGui::End();

  Gl::ClearColor(_backgroundColor.r, _backgroundColor.g, _backgroundColor.b, 1.0f);

  _texture->Bind();
  _boxShader->Bind();
  _boxShader->SetUniform("u_Model", model);
  _boxShader->SetUniform("u_View", view);
  _boxShader->SetUniform("u_Projection", projection);
  _boxShader->SetUniform("u_Texture1", static_cast<int>(_texture->getSlot()));

  _boxShape->Draw(*_boxShader);
}

void TextureScene::doInitialize()
{
  constexpr auto vShaderPath = "Resources/Shaders/v_textured_box.glsl";
  constexpr auto fShaderPath = "Resources/Shaders/f_textured_box.glsl";

  _texturesPath = "Resources/Textures/";
  _currentTexture = "default.png";

  const auto textureDirectory = std::filesystem::directory_iterator(_texturesPath);

  for (const auto &file : textureDirectory)
  {
    if (file.is_regular_file())
    {
      if (file.path().extension() == ".png")
      {
        _textures.emplace_back(file.path().filename().string());
      }
    }
  }

  _boxShape = std::make_unique<Cute::Graphics::Box>();
  _boxShader = std::make_unique<Cute::Graphics::Shader>(vShaderPath, fShaderPath);
  _texture = std::make_unique<Cute::Graphics::Texture>(_texturesPath + _currentTexture, 0u);
  _model = std::make_unique<Cute::Graphics::Model>();
  _camera = std::make_unique<Cute::Graphics::Camera>();
  _projection = std::make_unique<Cute::Graphics::Projection>();
  _backgroundColor = {0.0f, 0.0f, 0.0f};

  _camera->setPosition({-1.0f, 1.0f, 2.f});
  _camera->lookAt({0.0f, 0.0f, 0.0f});
}

void TextureScene::doFinalize()
{
  _boxShape.reset();
  _boxShader.reset();
  _model.reset();
  _camera.reset();
  _projection.reset();
  _texture.reset();
}
}
