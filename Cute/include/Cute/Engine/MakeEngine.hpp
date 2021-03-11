#ifndef CUTE_ENGINE_MAKE_ENGINE_HPP
#define CUTE_ENGINE_MAKE_ENGINE_HPP

#include <Cute/Engine/BasicEngine.hpp>

namespace Cute::Engine
{
auto MakeEngine()
{
  return std::make_unique<BasicEngine>();
}
}

#endif //CUTE_ENGINE_MAKE_ENGINE_HPP
