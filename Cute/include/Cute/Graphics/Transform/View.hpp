#ifndef CUTE_GRAPHICS_TRANSFORM_VIEW_HPP
#define CUTE_GRAPHICS_TRANSFORM_VIEW_HPP

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Cute::Graphics
{
class View
{
 public:
  View()
      : _position(0.0f, 0.0f, 0.0f), _direction(glm::normalize(_position - glm::vec3(0.0f)))
  {}

  [[nodiscard]] auto toMatrix() const
  {
    const auto yBase = glm::vec3(0.0f, 1.0f, 0.0f);

    const auto viewMatrix = glm::lookAt(_position, _direction, yBase);

    return viewMatrix;
  }

  void Set(const glm::vec3& newPosition, const glm::vec3& newDirection)
  {
    _position = newPosition;
    _direction = newDirection;
  }

  auto& getPosition()
  {
    return _position;
  }

  auto& getDirection()
  {
    return _direction;
  }

 private:
  glm::vec3 _position;
  glm::vec3 _direction;
};
}

#endif //CUTE_GRAPHICS_TRANSFORM_VIEW_HPP
