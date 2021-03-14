#ifndef CUTE_ENGINE_MAKE_ENGINE_HPP
#define CUTE_ENGINE_MAKE_ENGINE_HPP

#include <cute/engine/basic_engine.hpp>
#include <memory>

namespace Cute::Engine
{
auto MakeEngine()
{
  return std::make_unique<BasicEngine>();
}
}

#endif //CUTE_ENGINE_MAKE_ENGINE_HPP
