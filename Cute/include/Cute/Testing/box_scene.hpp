#ifndef CUTE_TESTING_BOX_SCENE_HPP
#define CUTE_TESTING_BOX_SCENE_HPP

#include <cute/engine/scene.hpp>

#include <cute/graphics/shapes/box.hpp>
#include <cute/graphics/shaders/shader.hpp>
#include <cute/graphics/transform/model.hpp>
#include <cute/graphics/transform/projection.hpp>

#include <memory>
#include <cute/graphics/camera/camera.hpp>

namespace Cute::Testing
{
class BoxScene : public Cute::Engine::Scene
{
 public:
  BoxScene() = default;

  ~BoxScene() override = default;

 protected:
  void doRender() override;

  void doInitialize() override;

  void doFinalize() override;

 protected:
  std::unique_ptr<Cute::Graphics::Box> boxShape_;
  std::unique_ptr<Cute::Graphics::Shader> boxShader_;
  std::unique_ptr<Cute::Graphics::Model> model_;
  std::unique_ptr<Cute::Graphics::Camera> camera_;
  std::unique_ptr<Cute::Graphics::Projection> projection_;
  glm::vec3 backgroundColor_;
  bool EnableMatrixWindow = false;
};
}

#endif //CUTE_TESTING_BOX_SCENE_HPP
