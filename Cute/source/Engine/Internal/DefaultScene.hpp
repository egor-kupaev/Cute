#ifndef CUTE_SOURCES_ENGINE_INTERNAL_DEFAULT_SCENE_HPP
#define CUTE_SOURCES_ENGINE_INTERNAL_DEFAULT_SCENE_HPP

#include <Cute/Engine/Scene.hpp>

#include "../Internal/GlWrappers.hpp"

namespace Cute::Engine::Internal
{
class DefaultScene : public Scene
{
 public:
  DefaultScene() = default;

  ~DefaultScene() override = default;

 private:
  void doRender() override
  {
    Gl::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  }

  void doInitialize() override
  {
    // Initialize nothing
  }

  void doFinalize() override
  {
    // Finalize nothing
  }
};
}

#endif //CUTE_SOURCES_ENGINE_INTERNAL_DEFAULT_SCENE_HPP
