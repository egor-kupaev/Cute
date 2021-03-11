#ifndef CUTE_TESTING_BOX_SCENE_HPP
#define CUTE_TESTING_BOX_SCENE_HPP

#include <Cute/Engine/Scene.hpp>

#include <Cute/Graphics/Shapes/Box.hpp>
#include <Cute/Graphics/Shaders/Shader.hpp>
#include <Cute/Graphics/Transform/Model.hpp>
#include <Cute/Graphics/Transform/View.hpp>
#include <Cute/Graphics/Transform/Projection.hpp>

#include <memory>

namespace Cute::Testing
{
class BoxScene : public Cute::Engine::Scene
{
 public:
  BoxScene() = default;

  ~BoxScene() override = default;

 private:
  void doRender() override;

  void doInitialize() override;

  void doFinalize() override;

 private:
  std::unique_ptr<Cute::Graphics::Box> boxShape_;
  std::unique_ptr<Cute::Graphics::Shader> boxShader_;
  std::unique_ptr<Cute::Graphics::Model> model_;
  std::unique_ptr<Cute::Graphics::View> view_;
  std::unique_ptr<Cute::Graphics::Projection> projection_;
  glm::vec3 backgroundColor_;
  bool EnableMatrixWindow = false;
};
}

#endif //CUTE_TESTING_BOX_SCENE_HPP
