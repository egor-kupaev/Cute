#ifndef CUTE_GRAPHICS_TEXTURES_TEXTURE_HPP
#define CUTE_GRAPHICS_TEXTURES_TEXTURE_HPP

#include <string>

namespace Cute::Graphics
{
class Texture
{
 public:
  Texture(const std::string &path, unsigned slot);

  ~Texture();

  void Bind() const;

  [[nodiscard]] auto getSlot() const
  {
    return _slot;
  }

 private:
  unsigned id_;
  unsigned _slot;
};
}

#endif //CUTE_GRAPHICS_TEXTURES_TEXTURE_HPP
