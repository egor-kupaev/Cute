#ifndef CUTE_GRAPHICS_TRANSFORM_MODEL_HPP
#define CUTE_GRAPHICS_TRANSFORM_MODEL_HPP

#include <glm/glm.hpp>

namespace Cute::Graphics
{
class Model
{
 public:
  Model() : _position(0.0f, 0.0f, 0.0f), _scale(1.0f, 1.0f, 1.0f), _pitch(0.0f), _yaw(0.0f), _roll(0.0f)
  {}

  [[nodiscard]] auto toMatrix() const
  {
    const auto identity = glm::mat4(1.0f);
    const auto xBase = glm::vec3(1.0f, 0.0f, 0.0f);
    const auto yBase = glm::vec3(0.0f, 1.0f, 0.0f);
    const auto zBase = glm::vec3(0.0f, 0.0f, 1.0f);

    const auto scale = glm::scale(identity, _scale);

    const auto rotateX = glm::rotate(identity, _pitch, xBase);
    const auto rotateY = glm::rotate(identity, _yaw, yBase);
    const auto rotateZ = glm::rotate(identity, _roll, zBase);
    const auto rotation = rotateX * rotateY * rotateZ;

    const auto translate = glm::translate(identity, _position);

    const auto modelMatrix = translate * rotation * scale;

    return modelMatrix;
  }

  auto GetPositionPtr()
  {
    return glm::value_ptr(_position);
  }

  auto GetScalePtr()
  {
    return glm::value_ptr(_scale);
  }

  auto GetPitchPtr()
  {
    return &_pitch;
  }

  auto GetYawPtr()
  {
    return &_yaw;
  }

  auto GetRollPtr()
  {
    return &_roll;
  }

 private:
  glm::vec3 _position;
  glm::vec3 _scale;
  float _pitch;
  float _yaw;
  float _roll;
};
}

#endif //CUTE_GRAPHICS_TRANSFORM_MODEL_HPP
