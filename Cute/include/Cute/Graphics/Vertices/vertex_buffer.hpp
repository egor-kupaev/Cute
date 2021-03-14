#ifndef CUTE_GRAPHICS_VERTICES_VERTEX_BUFFER_HPP
#define CUTE_GRAPHICS_VERTICES_VERTEX_BUFFER_HPP

namespace Cute::Graphics
{
class VertexBuffer
{
 public:
  VertexBuffer();

  ~VertexBuffer();

  VertexBuffer(VertexBuffer &&other) noexcept: id_(other.id_)
  {
    other.id_ = 0;
  }

  void Bind() const;

  void SetData(void *pData, size_t count) const;

 private:
  unsigned id_;
};
}

#endif //CUTE_GRAPHICS_VERTICES_VERTEX_BUFFER_HPP
