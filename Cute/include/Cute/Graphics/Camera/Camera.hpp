#ifndef CUTE_GRAPHICS_CAMERA_CAMERA_HPP_
#define CUTE_GRAPHICS_CAMERA_CAMERA_HPP_

#include <Cute/Graphics/Transform/View.hpp>

namespace Cute::Graphics
{
class Camera
{
 public:
  explicit Camera()
  {}

  void MoveForward(float magnifier)
  {
    _position += magnifier * _speed * _direction;
    _direction += magnifier * _speed * _direction;
  }

  auto MoveBackward(float magnifier)
  {
    _position -= magnifier * _speed * _direction;
    _direction -= magnifier * _speed * _direction;
  }

  void MoveLeft(float magnifier)
  {
    const auto yAxis = glm::vec3(0.0f, 1.0f, 0.0f);
    const auto left = glm::cross(yAxis, _direction);

    _position += magnifier * _speed * left;
  }

  auto MoveRight(float magnifier)
  {
    const auto yAxis = glm::vec3(0.0f, 1.0f, 0.0f);
    const auto right = glm::cross(_direction, yAxis);

    _position += magnifier * _speed * right;
  }

  void AddPitch(float magnifier)
  {
    _pitchAngle += magnifier * _sensitivity;

    if (_pitchAngle < -89.0f)
    {
      _pitchAngle = -89.0f;
    }
    if (89.0f < _pitchAngle)
    {
      _pitchAngle = 89.0f;
    }
  }

  void AddYaw(float magnifier)
  {
    _yawAngle += magnifier * _sensitivity;
  }

  auto toMatrix()
  {
    _direction.x = glm::cos(glm::radians(_yawAngle)) * glm::cos(glm::radians(_pitchAngle));
    _direction.y = glm::sin(glm::radians(_pitchAngle));
    _direction.z = glm::sin(glm::radians(_yawAngle)) * glm::cos(glm::radians(_pitchAngle));
    _direction = glm::normalize(_direction);

    const auto yBase = glm::vec3(0.0f, 1.0f, 0.0f);

    return glm::lookAt(_position, _position + _direction, yBase);
//    return glm::lookAt(_position, {0.0f, 0.0f, 0.0f}, yBase);
  }

  auto &getPosition()
  {
    return _position;
  }

  auto setPosition(const glm::vec3 &position)
  {
    _position = position;
  }

  auto lookAt(const glm::vec3 &target)
  {
    const auto xAxis = glm::vec3(1.0f, 0.0f, 0.0f);
    const auto zAxis = glm::vec3(0.0f, 0.0f, 1.0f);

    const auto sqr = [](auto x) { return x * x; };

    _direction = -glm::normalize(_position - target);
    const auto x = _direction.x;
    const auto y = _direction.y;
    const auto z = _direction.z;
    _pitchAngle = glm::degrees(glm::asin(y));
    _yawAngle = glm::degrees(glm::atan(z, x));
  }

  auto &getPitch()
  {
    return _pitchAngle;
  }

  auto &getYaw()
  {
    return _yawAngle;
  }

  auto &getDirection()
  {
    return _direction;
  }

 private:
  glm::vec3 _position = {0.0f, 0.0f, 0.0f};
  glm::vec3 _direction = {0.0f, 0.0f, -1.0f};
  float _pitchAngle = 0.0f;
  float _yawAngle = -90.0f;
  float _speed = 1.0f;
  float _sensitivity = 0.05f;
};
}

#endif //CUTE_GRAPHICS_CAMERA_CAMERA_HPP_
