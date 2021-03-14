#ifndef CUTE_ENGINE_ENGINE_HPP
#define CUTE_ENGINE_ENGINE_HPP

#include <cute/engine/scene.hpp>

#include <memory>
#include <string>
#include <iostream>

namespace Cute::Engine
{
class Engine
{
 public:
  Engine() = default;

  virtual ~Engine() = default;

 public:
  int run()
  {
    try
    {
      return doRun();

    }
    catch (std::exception &ex)
    {
      std::cerr << ex.what() << std::endl;
      return -1;
    }
  }

  void addScene(const std::string &name, std::unique_ptr<Scene> &&scene)
  {
    doAddScene(name, std::move(scene));
  }

 private:
  virtual int doRun() = 0;

  virtual void doAddScene(const std::string &name, std::unique_ptr<Scene> &&scene) = 0;
};
}

#endif //CUTE_ENGINE_ENGINE_HPP
