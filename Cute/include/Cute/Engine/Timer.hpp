#ifndef CUTE_ENGINE_TIMER_HPP
#define CUTE_ENGINE_TIMER_HPP

namespace Cute::Engine
{
  class Timer
  {
   public:
    explicit Timer(float timestamp) noexcept: _currentTimestamp(timestamp), _lastTimestamp(timestamp) {}

    auto Update(float timestamp)
    {
      _lastTimestamp = _currentTimestamp;
      _currentTimestamp = timestamp;
    }

    auto Delta()
    {
      return _currentTimestamp - _lastTimestamp;
    }

   private:
    float _currentTimestamp;
    float _lastTimestamp;
  };
};

#endif //CUTE_ENGINE_TIMER_HPP
