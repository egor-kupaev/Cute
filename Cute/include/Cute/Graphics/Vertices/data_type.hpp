#ifndef CUTE_GRAPHICS_VERTICES_DATA_TYPE_HPP
#define CUTE_GRAPHICS_VERTICES_DATA_TYPE_HPP

#include <concepts>

namespace Cute::Graphics
{
struct DataType
{
  struct FloatTag
  {
    explicit operator int();

    static constexpr size_t Size()
    { return sizeof(float); }
  };

  struct UIntTag
  {
    explicit operator int();

    static constexpr size_t Size()
    { return sizeof(unsigned); }
  };

  static constexpr auto Float = FloatTag();
  static constexpr auto UInt = UIntTag();

  static unsigned SizeOf(int value);
};

template<typename T>
concept IsDataType = std::same_as<T, DataType::FloatTag> || std::same_as<T, DataType::UIntTag>;
}

#endif //CUTE_GRAPHICS_VERTICES_DATA_TYPE_HPP
