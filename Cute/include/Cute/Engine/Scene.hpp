#ifndef CUTE_ENGINE_SCENE_HPP
#define CUTE_ENGINE_SCENE_HPP

namespace Cute::Engine
{
class Scene
{
 public:
  Scene() = default;

  virtual ~Scene() = default;

 public:
  void Initialize()
  {
    doInitialize();
  }

  void Finalize()
  {
    doFinalize();
  }

  void Render()
  {
    doRender();
  }

 protected:
  virtual void doRender() = 0;

  virtual void doInitialize() = 0;

  virtual void doFinalize() = 0;
};
}

#endif //CUTE_ENGINE_SCENE_HPP
