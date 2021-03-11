#ifndef CUTE_GRAPHICS_TRANSFORM_VIEW_HPP
#define CUTE_GRAPHICS_TRANSFORM_VIEW_HPP

#include <glm/glm.hpp>

namespace Cute::Graphics
{
class View
{
 public:
  View()
      : _position(0.0f, 0.0f, 0.0f), _target(0.0f, 0.0f, -1.0f)
  {}

  [[nodiscard]] auto toMatrix() const
  {
    const auto yBase = glm::vec3(0.0f, 1.0f, 0.0f);

    const auto viewMatrix = glm::lookAt(_position, _target, yBase);

    return viewMatrix;
  }

  void Set(const glm::vec3& newPosition, const glm::vec3& newTarget)
  {
    _position = newPosition;
    _target = newTarget;
  }

 private:
  glm::vec3 _position;
  glm::vec3 _target;
};
}

#endif //CUTE_GRAPHICS_TRANSFORM_VIEW_HPP
