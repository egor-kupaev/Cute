#ifndef CUTE_GRAPHICS_VERTICES_VERTEX_ARRAY_HPP
#define CUTE_GRAPHICS_VERTICES_VERTEX_ARRAY_HPP

#include <Cute/Graphics/Vertices/DataType.hpp>

#include <vector>

namespace Cute::Graphics
{

class Layout
{
 public:
  template <IsDataType DataTypeT>
  Layout(DataTypeT dataType, size_t count): type(dataType), count(int(count))
  {}

  [[nodiscard]] auto GetCount() const { return count; }
  [[nodiscard]] auto GetType() const { return type; }
  [[nodiscard]] auto GetSize() const { return DataType::SizeOf(type); }

 private:
  int type;
  int count;
};

class VertexArray
{
 public:
  VertexArray();
  ~VertexArray();

  VertexArray(VertexArray&& other) noexcept : id_(other.id_)
  {
    other.id_ = 0;
  }

  void Bind() const;

  void AddLayouts(const std::vector<Layout> &layouts);

 private:
  unsigned id_;
};
}

#endif //CUTE_GRAPHICS_VERTICES_VERTEX_ARRAY_HPP
