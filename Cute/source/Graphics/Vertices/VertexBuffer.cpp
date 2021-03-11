#include <Cute/Graphics/Vertices/VertexBuffer.hpp>

#include "../../Internal/GlWrappers.hpp"

namespace Cute::Graphics
{

VertexBuffer::VertexBuffer() : id_(Gl::CreateBuffer())
{
}

VertexBuffer::~VertexBuffer()
{
  Gl::BindBuffer(GL_ARRAY_BUFFER, 0u);
  Gl::DeleteBuffer(id_);
}

void VertexBuffer::Bind() const
{
  Gl::BindBuffer(GL_ARRAY_BUFFER, id_);
}

void VertexBuffer::SetData(void *pData, size_t size) const
{
  Bind();
  Gl::SetBufferData(GL_ARRAY_BUFFER, GLuint(size), pData, GL_STATIC_DRAW);
}
}
