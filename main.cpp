#include <cute/engine/make_engine.hpp>
#include <cute/testing/clear_scene.hpp>
#include <cute/testing/box_scene.hpp>
#include <cute/testing/camera_scene.hpp>

int main()
{
  auto engine = Cute::Engine::MakeEngine();

  engine->addScene("ClearScene", std::make_unique<Cute::Testing::ClearScene>());
  engine->addScene("BoxScene", std::make_unique<Cute::Testing::BoxScene>());
  engine->addScene("CameraScene", std::make_unique<Cute::Testing::CameraScene>());

  return engine->run();
}
