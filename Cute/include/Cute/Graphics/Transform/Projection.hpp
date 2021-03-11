#ifndef CUTE_GRAPHICS_TRANSFORM_PROJECTION_HPP
#define CUTE_GRAPHICS_TRANSFORM_PROJECTION_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Cute::Graphics
{
class Projection
{
 public:
  Projection()
      : _fov(glm::radians(45.0f)), _aspectRatio(16.0f / 9.0f), minDistance(0.1f), maxDistance(10.0f)
  {}

  [[nodiscard]] auto toMatrix() const
  {
    const auto projectionMatrix = glm::perspective(_fov, _aspectRatio, minDistance, maxDistance);

    return projectionMatrix;
  }

 private:
  float _fov;
  float _aspectRatio;
  float minDistance;
  float maxDistance;
};
}

#endif //CUTE_GRAPHICS_TRANSFORM_PROJECTION_HPP
