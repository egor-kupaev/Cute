#include <cute/graphics/shaders/shader.hpp>
#include <fstream>
#include <vector>

#include "../../internal/GlWrappers.hpp"

namespace Cute::Graphics
{

static std::vector<char> ParseFile(const std::string &path)
{
  auto is = std::ifstream(path, std::ios::binary | std::ios::ate);

  if (!is) throw std::runtime_error("There is no such file: " + path);

  auto result = std::vector<char>(is.tellg());
  is.seekg(0, std::ios::beg);
  is.read(result.data(), static_cast<std::streamsize>(result.size()));
  result.push_back('\0');

  return result;
}

Shader::Shader(const std::string &vShaderPath, const std::string &fShaderPath) : id_()
{
  auto vShaderId = Gl::CreateShader(GL_VERTEX_SHADER);
  auto vShaderSource = ParseFile(vShaderPath);
  Gl::SetShaderSource(vShaderId, vShaderSource.data());
  Gl::CompileShader(vShaderId);

  auto fShaderId = Gl::CreateShader(GL_FRAGMENT_SHADER);
  auto fShaderSource = ParseFile(fShaderPath);
  Gl::SetShaderSource(fShaderId, fShaderSource.data());
  Gl::CompileShader(fShaderId);

  id_ = Gl::CreateProgram();
  Gl::AttachShader(id_, vShaderId);
  Gl::AttachShader(id_, fShaderId);
  Gl::LinkProgram(id_);

  Gl::DeleteShader(vShaderId);
  Gl::DeleteShader(fShaderId);
}

void Shader::Bind() const
{
  Gl::UseProgram(id_);
}

Shader::~Shader()
{
  Gl::UseProgram(0u);
  Gl::DeleteProgram(id_);
}

void Shader::SetUniform(const std::string &path, const int i) const
{
  auto location = Gl::GetUniformLocation(id_, path.c_str());
  Gl::Uniform1i(location, i);
}

void Shader::SetUniform(const std::string &path, const float f) const
{
  auto location = Gl::GetUniformLocation(id_, path.c_str());
  Gl::Uniform1f(location, f);
}

void Shader::SetUniform(const std::string &path, const glm::mat4 &mat_4) const
{
  auto location = Gl::GetUniformLocation(id_, path.c_str());
  Gl::UniformMatrix4fv(location, glm::value_ptr(mat_4));
}

void Shader::SetUniform(const std::string &path, const glm::mat3 &mat_3) const
{
  auto location = Gl::GetUniformLocation(id_, path.c_str());
  Gl::UniformMatrix3fv(location, glm::value_ptr(mat_3));
}

void Shader::SetUniform(const std::string &path, const glm::vec3 &vec_3) const
{
  auto location = Gl::GetUniformLocation(id_, path.c_str());
  Gl::Uniform3f(location, vec_3.x, vec_3.y, vec_3.z);
}
}
