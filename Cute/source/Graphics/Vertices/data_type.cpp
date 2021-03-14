#include <cute/graphics/vertices/data_type.hpp>

#include <GL/glew.h>
#include <stdexcept>

namespace Cute::Graphics
{
DataType::FloatTag::operator int()
{
  return GL_FLOAT;
}

DataType::UIntTag::operator int()
{
  return GL_UNSIGNED_INT;
}

unsigned DataType::SizeOf(int value)
{
  switch (value)
  {
    case GL_FLOAT: return sizeof(float);
    case GL_UNSIGNED_INT: return sizeof(int);
    default: throw std::runtime_error("Wrong data type!");
  }
}
}
