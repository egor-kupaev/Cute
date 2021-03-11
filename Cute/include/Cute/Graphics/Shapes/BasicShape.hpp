#ifndef CUTE_GRAPHICS_SHAPES_BASIC_SHAPE_HPP
#define CUTE_GRAPHICS_SHAPES_BASIC_SHAPE_HPP

#include <Cute/Graphics/Shapes/Shape.hpp>

#include <Cute/Graphics/Vertices/VertexArray.hpp>
#include <Cute/Graphics/Vertices/VertexBuffer.hpp>

namespace Cute::Graphics
{
class BasicShape : public Shape
{
 public:
  ~BasicShape() override = default;

 protected:
  void doDraw(const Shader &shader) const override = 0;

 protected:
  VertexArray _vertexArray;
  VertexBuffer _vertexBuffer;
};
}

#endif //CUTE_GRAPHICS_SHAPES_BASIC_SHAPE_HPP
