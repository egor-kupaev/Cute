#ifndef CUTE_ENGINE_BASIC_ENGINE_HPP
#define CUTE_ENGINE_BASIC_ENGINE_HPP

#include <Cute/Engine/Engine.hpp>
#include <unordered_map>

namespace Cute::Engine
{
class BasicEngine: public Engine
{
 public:
  BasicEngine();
  ~BasicEngine() override = default;

 private:
  int doRun() override;

  void doAddScene(const std::string &name, std::unique_ptr<Scene> &&scene) override;

 private:
  std::unordered_map<std::string, std::unique_ptr<Scene>> scenes_;
};
}

#endif //CUTE_ENGINE_BASIC_ENGINE_HPP
