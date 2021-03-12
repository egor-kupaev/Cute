#include <Cute/Engine/MakeEngine.hpp>
#include <Cute/Testing/ClearScene.hpp>
#include <Cute/Testing/BoxScene.hpp>
#include <Cute/Testing/CameraScene.hpp>

int main()
{
  auto engine = Cute::Engine::MakeEngine();

  engine->addScene("ClearScene", std::make_unique<Cute::Testing::ClearScene>());
  engine->addScene("BoxScene", std::make_unique<Cute::Testing::BoxScene>());
  engine->addScene("CameraScene", std::make_unique<Cute::Testing::CameraScene>());

  return engine->run();
}
