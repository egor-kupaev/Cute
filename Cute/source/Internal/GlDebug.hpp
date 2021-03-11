#ifndef CUTE_SOURCE_INTERNAL_GL_DEBUG_HPP
#define CUTE_SOURCE_INTERNAL_GL_DEBUG_HPP

#include "GL/glew.h"

#include <vector>
#include <string>
#include <stdexcept>

#ifndef NDEBUG
#define CHECK_ERROR(msg) Cute::Gl::CheckForError(#msg)
#else
#define CHECK_ERROR(x)
#endif

#ifndef NDEBUG
#define CHECK_COMPILATION_ERROR(shader) Cute::Gl::CheckForCompilationError(shader)
#else
#define CHECK_COMPILATION_ERROR(shader)
#endif

#ifndef NDEBUG
#define CHECK_LINKAGE_ERROR(program) Cute::Gl::CheckForLinkageError(program)
#else
#define CHECK_LINKAGE_ERROR(program)
#endif

#ifndef NDEBUG
#define GL_NOEXCEPT
#else
#define GL_NOEXCEPT noexcept
#endif

namespace Cute::Gl
{
static inline auto CheckForError(std::string msg)
{
  auto error_codes = std::vector<std::string>();

  auto do_not_stop = true;
  while (do_not_stop)
  {
    switch (glGetError())
    {
      case GL_NO_ERROR: do_not_stop = false;
        break;
      case GL_INVALID_ENUM: error_codes.emplace_back("GL_INVALID_ENUM");
        break;
      case GL_INVALID_VALUE: error_codes.emplace_back("GL_INVALID_VALUE");
        break;
      case GL_INVALID_OPERATION: error_codes.emplace_back("GL_INVALID_OPERATION");
        break;
      case GL_INVALID_FRAMEBUFFER_OPERATION: error_codes.emplace_back("GL_INVALID_FRAMEBUFFER_OPERATION");
        break;
      case GL_OUT_OF_MEMORY: error_codes.emplace_back("GL_OUT_OF_MEMORY");
        break;
      case GL_STACK_UNDERFLOW: error_codes.emplace_back("GL_STACK_UNDERFLOW");
        break;
      case GL_STACK_OVERFLOW: error_codes.emplace_back("GL_STACK_OVERFLOW");
        break;
      default: error_codes.emplace_back("UnknownErrorCode");
        break;
    }
  }
  if (error_codes.empty())
  {
    return;
  } else
  {
    for (auto& error_code : error_codes)
    {
      msg += "\t";
      msg += error_code;
      msg += "\n";
    }
    using namespace std::literals::string_literals;
    throw std::runtime_error("Error occurred with following statuses:"s + "\n"s + msg);

  }
}

static inline auto CheckForCompilationError(GLuint shader)
{
  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
    auto compile_error = std::string(log_length + 1, '\0');
    glGetShaderInfoLog(shader, log_length, nullptr, compile_error.data());
    throw std::runtime_error("Shader compilation failed: \n" + compile_error);
  }
}

static inline auto CheckForLinkageError(GLuint program)
{
  GLint success;
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (success != GL_TRUE)
  {
    GLsizei log_length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
    auto linkage_error = std::string(log_length + 1, '\0');
    glGetProgramInfoLog(program, log_length, nullptr, linkage_error.data());
    throw std::runtime_error("Program linkage failed: \n" + linkage_error);
  }
}
}

#endif //CUTE_SOURCE_INTERNAL_GL_DEBUG_HPP
