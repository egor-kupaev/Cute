#ifndef CUTE_TESTING_CLEAR_SCENE_HPP
#define CUTE_TESTING_CLEAR_SCENE_HPP

#include <Cute/Engine/Scene.hpp>

namespace Cute::Testing
{
class ClearScene : public Cute::Engine::Scene
{
 public:
  ClearScene(): colors_{0.0f, 0.0f, 0.0f} {}

  ~ClearScene() override = default;

 private:
  void doRender() override;

  void doInitialize() override;

  void doFinalize() override;

 private:
  float colors_[3u];
};
}

#endif //CUTE_TESTING_CLEAR_SCENE_HPP
