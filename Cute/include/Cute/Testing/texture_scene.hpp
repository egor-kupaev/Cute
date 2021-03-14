#ifndef CUTE_TESTING_TEXTURE_SCENE_HPP
#define CUTE_TESTING_TEXTURE_SCENE_HPP

#include <Cute/Engine/Scene.hpp>

#include <Cute/Graphics/Shapes/Box.hpp>
#include <Cute/Graphics/Shaders/Shader.hpp>
#include <Cute/Graphics/Textures/Texture.hpp>
#include <Cute/Graphics/Transform/Model.hpp>
#include <Cute/Graphics/Transform/View.hpp>
#include <Cute/Graphics/Transform/Projection.hpp>

#include <memory>
#include <Cute/Graphics/Camera/Camera.hpp>

namespace Cute::Testing
{
class TextureScene : public Cute::Engine::Scene
{
 public:
  TextureScene() = default;

  ~TextureScene() override = default;

 protected:
  void doRender() override;

  void doInitialize() override;

  void doFinalize() override;

 protected:
  std::unique_ptr<Cute::Graphics::Box> _boxShape;
  std::unique_ptr<Cute::Graphics::Shader> _boxShader;
  std::unique_ptr<Cute::Graphics::Texture> _texture;
  std::unique_ptr<Cute::Graphics::Model> _model;
  std::unique_ptr<Cute::Graphics::Camera> _camera;
  std::unique_ptr<Cute::Graphics::Projection> _projection;
  glm::vec3 _backgroundColor;
  std::string _texturesPath;
  std::vector<std::string> _textures;
  std::string _currentTexture;
};
}

#endif //CUTE_TESTING_TEXTURE_SCENE_HPP
