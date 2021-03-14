#include <Cute/Graphics/Textures/Texture.hpp>

#include "../../Internal/GlWrappers.hpp"
#include <stb_image.h>

namespace Cute::Graphics
{
Texture::Texture(const std::string &path, unsigned slot) : id_(Gl::CreateTexture()), _slot(slot)
{
  Gl::BindTexture(GL_TEXTURE_2D, id_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int tWidth, tHeight, tColorChannels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load(path.c_str(), &tWidth, &tHeight, &tColorChannels, 4);
  if (data)
  {
    Gl::TexImage2D(tWidth, tHeight, data);
    Gl::GenerateMipmap();
  } else
  {
    throw std::runtime_error("Wrong path: " + path);
  }
  stbi_image_free(data);
}

Texture::~Texture()
{
  Gl::BindTexture(GL_TEXTURE_2D, 0u);
  Gl::DeleteTexture(id_);
}

void Texture::Bind() const
{
  Gl::ActiveTexture(_slot);
  Gl::BindTexture(GL_TEXTURE_2D, id_);
}
}
