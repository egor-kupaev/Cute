#ifndef CUTE_GRAPHICS_SHAPES_SHAPE_HPP
#define CUTE_GRAPHICS_SHAPES_SHAPE_HPP

#include <Cute/Graphics/Shaders/Shader.hpp>

namespace Cute::Graphics
{
class Shape
{
 public:
  Shape() = default;
  virtual ~Shape() = default;

  void Draw(const Shader& shader) const
  {
    doDraw(shader);
  }

 protected:
  virtual void doDraw(const Shader& shader) const = 0;
};
}

#endif //CUTE_GRAPHICS_SHAPES_SHAPE_HPP
