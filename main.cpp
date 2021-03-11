#include <Cute/Engine/MakeEngine.hpp>
#include <Cute/Testing/ClearScene.hpp>
#include <Cute/Testing/BoxScene.hpp>

int main()
{
  auto engine = Cute::Engine::MakeEngine();

  engine->addScene("ClearScene", std::make_unique<Cute::Testing::ClearScene>());
  engine->addScene("BoxScene", std::make_unique<Cute::Testing::BoxScene>());

  return engine->run();
}
