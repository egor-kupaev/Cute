#include <Cute/Graphics/Vertices/VertexArray.hpp>

#include <GL/glew.h>
#include <vector>
#include <algorithm>
#include <numeric>

#include "../../Internal/GlWrappers.hpp"

namespace Cute::Graphics
{
VertexArray::VertexArray() : id_(Gl::CreateVertexArray())
{
}

VertexArray::~VertexArray()
{
  Gl::BindVertexArray(0u);
  Gl::DeleteVertexArray(id_);
}

void VertexArray::AddLayouts(const std::vector<Layout> &layouts)
{
  auto stride = 0u;
  for (const auto& layout : layouts)
  {
    stride += layout.GetSize() * layout.GetCount();
  }

  std::ranges::for_each(layouts,
                        [index = 0, stride, offset = 0ull](const auto &layout) mutable
                        {
                          Gl::EnableVertexAttribArray(index);
                          Gl::VertexAttribPointer(index,
                                                  layout.GetCount(),
                                                  layout.GetType(),
                                                  GL_FALSE,
                                                  stride,
                                                  offset);
                          offset += layout.GetCount() * layout.GetSize();
                          index++;
                        });
}

void VertexArray::Bind() const
{
  Gl::BindVertexArray(id_);
}
}
