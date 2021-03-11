#ifndef CUTE_GRAPHICS_SHAPES_BOX_HPP
#define CUTE_GRAPHICS_SHAPES_BOX_HPP

#include <Cute/Graphics/Shapes/BasicShape.hpp>

namespace Cute::Graphics
{
class Box: public BasicShape
{
 public:
  Box();
  ~Box() override = default;

 protected:
  void doDraw(const Shader &shader) const override;
};
}

#endif //CUTE_GRAPHICS_SHAPES_BOX_HPP
