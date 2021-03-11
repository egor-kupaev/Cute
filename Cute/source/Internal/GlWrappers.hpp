#ifndef CUTE_SOURCE_INTERNAL_GL_WRAPPERS_HPP
#define CUTE_SOURCE_INTERNAL_GL_WRAPPERS_HPP

#include <GL/glew.h>
#include "GlDebug.hpp"

namespace Cute::Gl
{

static inline auto CreateBuffer() GL_NOEXCEPT
{
  GLuint id;
  glGenBuffers(1, &id);
  CHECK_ERROR("glGenBuffers failed");

  return id;
}

static inline auto CreateVertexArray() GL_NOEXCEPT
{
  GLuint id;
  glGenVertexArrays(1, &id);
  CHECK_ERROR("glGenVertexArrays failed");

  return id;
}

static inline auto CreateShader(GLenum type) GL_NOEXCEPT
{

  GLuint id = glCreateShader(type);
  CHECK_ERROR("glCreateShader failed");
  return id;
}

static inline auto CreateTexture() GL_NOEXCEPT
{
  GLuint id;
  glGenTextures(1, &id);
  CHECK_ERROR("glGenTextures failed");

  return id;
}

static inline auto SetShaderSource(GLuint shader,
                                   const GLchar *string) GL_NOEXCEPT
{
  glShaderSource(shader, 1, &string, nullptr);
  CHECK_ERROR("glShaderSource failed");
}

static inline auto CompileShader(GLuint shader) GL_NOEXCEPT
{
  glCompileShader(shader);
  CHECK_ERROR("glCompileShader failed");
  CHECK_COMPILATION_ERROR(shader);
}

static inline auto LinkProgram(GLuint program) GL_NOEXCEPT
{
  glLinkProgram(program);
  CHECK_ERROR("glLinkProgram failed");
  CHECK_LINKAGE_ERROR(program);
}

static inline auto AttachShader(GLuint program,
                                GLuint shader) GL_NOEXCEPT
{
  glAttachShader(program, shader);
  CHECK_ERROR("glAttachShader failed");
}

static inline auto CreateProgram() GL_NOEXCEPT
{
  GLuint id = glCreateProgram();
  CHECK_ERROR("glCreateProgram failed");
  return id;
}

static inline auto DeleteProgram(GLuint program) GL_NOEXCEPT
{
  glDeleteProgram(program);
}

static inline auto UseProgram(GLuint program) GL_NOEXCEPT
{
  glUseProgram(program);
  CHECK_ERROR("glUseProgram failed");
}

static inline auto DeleteShader(GLuint shader) GL_NOEXCEPT
{
  glDeleteShader(shader);
}

static inline auto DeleteBuffer(GLuint id) GL_NOEXCEPT
{
  glDeleteBuffers(1, &id);
}

static inline auto DeleteVertexArray(GLuint id) GL_NOEXCEPT
{
  glDeleteVertexArrays(1, &id);
}

static inline auto DeleteTexture(GLuint id) GL_NOEXCEPT
{
  glDeleteTextures(1, &id);
}

static inline auto BindBuffer(GLenum type, GLuint id) GL_NOEXCEPT
{
  glBindBuffer(type, id);
  CHECK_ERROR("glBindBuffer failed");
}

static inline auto BindVertexArray(GLuint id) GL_NOEXCEPT
{
  glBindVertexArray(id);
  CHECK_ERROR("glBindVertexArray failed");
}

static inline auto BindTexture(GLenum type, GLuint id) GL_NOEXCEPT
{
  glBindTexture(type, id);
  CHECK_ERROR("glBindTexture failed");
}

static inline auto SetBufferData(GLenum target,
                                 GLuint size,
                                 const GLvoid *data,
                                 GLenum usage) GL_NOEXCEPT
{
  glBufferData(target, GLsizeiptr(size), data, usage);
  CHECK_ERROR("glBufferData failed");
}

static inline auto EnableVertexAttribArray(GLuint index) GL_NOEXCEPT
{
  glEnableVertexAttribArray(index);
  CHECK_ERROR("glEnableVertexAttribArray failed");
}

static inline auto VertexAttribPointer(GLuint index,
                                       GLuint size,
                                       GLenum type,
                                       GLboolean normalized,
                                       GLuint stride,
                                       GLsizeiptr offset) GL_NOEXCEPT
{
  glVertexAttribPointer(index, GLint(size), type, normalized, GLsizei(stride), (const void *)offset);
  CHECK_ERROR("glVertexAttribPointer failed");
}

static inline auto ClearColor(GLfloat red,
                              GLfloat green,
                              GLfloat blue,
                              GLfloat alpha) GL_NOEXCEPT
{
  glClearColor(red, green, blue, alpha);
  CHECK_ERROR("glClearColor failed");
}

static inline auto Clear(GLbitfield mask) GL_NOEXCEPT
{
  glClear(mask);
  CHECK_ERROR("glClear failed");
}

static inline auto DrawElements(GLenum mode,
                                GLsizei count,
                                GLenum type) GL_NOEXCEPT
{
  glDrawElements(mode, count, type, nullptr);
  CHECK_ERROR("glDrawElements failed");
}

static inline auto DrawArrays(GLenum mode, GLint first, GLsizei count) GL_NOEXCEPT
{
  glDrawArrays(mode, first, count);
  CHECK_ERROR("glDrawArrays failed");
}

static inline auto TexImage2D(const GLsizei width, const GLsizei height, const GLvoid *data) GL_NOEXCEPT
{
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
  CHECK_ERROR("glTexImage2D failed");
}

static inline auto GenerateMipmap() GL_NOEXCEPT
{
  glGenerateMipmap(GL_TEXTURE_2D);
  CHECK_ERROR("glGenerateMipmap failed");
}

static inline auto ActiveTexture(const GLenum slot) GL_NOEXCEPT
{
  glActiveTexture(GL_TEXTURE0 + slot);
  CHECK_ERROR("glActiveTexture failed");
}

static inline auto GetUniformLocation(GLuint program, const GLchar *name) GL_NOEXCEPT
{
  auto location = glGetUniformLocation(program, name);
  CHECK_ERROR("glGetUniformLocation failed");
  return location;
}

static inline auto UniformMatrix4fv(GLint location, const GLfloat *value) GL_NOEXCEPT
{
  glUniformMatrix4fv(location, 1, GL_FALSE, value);
  CHECK_ERROR("glUniformMatrix4fv failed");
}

static inline auto UniformMatrix3fv(GLint location, const GLfloat *value) GL_NOEXCEPT
{
  glUniformMatrix3fv(location, 1, GL_FALSE, value);
  CHECK_ERROR("glUniformMatrix3fv failed");
}

static inline auto Uniform3f(GLint location, const GLfloat a, const GLfloat b, const GLfloat c) GL_NOEXCEPT
{
  glUniform3f(location, a, b, c);
  CHECK_ERROR("glUniform3f failed");
}

static inline auto Uniform1i(GLint location, const GLint i) GL_NOEXCEPT
{
  glUniform1i(location, i);
  CHECK_ERROR("glUniform1i failed");
}

static inline auto Uniform1f(GLint location, const GLfloat f) GL_NOEXCEPT
{
  glUniform1f(location, f);
  CHECK_ERROR("glUniform1f failed");
}

}

#endif //CUTE_SOURCE_INTERNAL_GL_WRAPPERS_HPP
