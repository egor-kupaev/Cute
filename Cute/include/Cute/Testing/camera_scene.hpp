#ifndef CUTE_TESTING_CAMERA_SCENE_HPP
#define CUTE_TESTING_CAMERA_SCENE_HPP

#include <cute/testing/box_scene.hpp>
#include <cute/graphics/camera/camera.hpp>

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
