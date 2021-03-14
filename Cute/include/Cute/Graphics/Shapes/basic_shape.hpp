#ifndef CUTE_GRAPHICS_SHAPES_BASIC_SHAPE_HPP
#define CUTE_GRAPHICS_SHAPES_BASIC_SHAPE_HPP

#include <cute/graphics/shapes/shape.hpp>

#include <cute/graphics/vertices/vertex_array.hpp>
#include <cute/graphics/vertices/vertex_buffer.hpp>

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
