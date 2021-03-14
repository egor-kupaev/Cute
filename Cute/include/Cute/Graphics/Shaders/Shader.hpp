#ifndef CUTE_GRAPHICS_SHADERS_SHADER_HPP
#define CUTE_GRAPHICS_SHADERS_SHADER_HPP

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Cute::Graphics
{
class Shader
{
 public:
  Shader(const std::string &vShaderPath, const std::string &fShaderPath);

  ~Shader();

  void Bind() const;

  void SetUniform(const std::string &path, int i) const;

  void SetUniform(const std::string &path, float i) const;

  void SetUniform(const std::string &path, const glm::mat3 &mat_3) const;

  void SetUniform(const std::string &path, const glm::mat4 &mat_4) const;

  void SetUniform(const std::string &path, const glm::vec3 &vec_3) const;

 private:
  unsigned id_;
};
}

#endif //CUTE_GRAPHICS_SHADERS_SHADER_HPP
