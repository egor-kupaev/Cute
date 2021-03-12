#ifndef CUTE_TESTING_CAMERA_SCENE_HPP
#define CUTE_TESTING_CAMERA_SCENE_HPP

#include <Cute/Testing/BoxScene.hpp>
#include <Cute/Graphics/Camera/Camera.hpp>

#include <memory>

namespace Cute::Testing
{
class CameraScene : public BoxScene
{
 public:
  CameraScene() = default;

  ~CameraScene() override = default;

 protected:
  void doRender() override;

  void doInitialize() override;

  void doFinalize() override;

 private:
  bool EnableManualControl = false;
};
}

#endif //CUTE_TESTING_CAMERA_SCENE_HPP
