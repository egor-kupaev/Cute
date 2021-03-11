#ifndef CUTE_ENGINE_MODEL_HPP
#define CUTE_ENGINE_MODEL_HPP

#include <Cute/Engine/Model.hpp>

namespace Cute::Engine
{
class Model
{
 public:
  Model() = default;
  virtual ~Model() = default;

 public:
  void draw()
  {
    doDraw();
  }

 private:
  virtual void doDraw() = 0;
};
}

#endif //CUTE_ENGINE_MODEL_HPP
