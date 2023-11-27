#pragma once

#include <cstdint>
#include <tuple>

#include "types.hpp"
class Color {
public:
  Color();
  Color( uint8_t red, uint8_t green, uint8_t blue );
  Color operator*( FPType frac ) const;
  Color operator+( const Color &other ) const;
  uint8_t red() const;
  uint8_t green() const;
  uint8_t blue() const;
  std::tuple<uint8_t, uint8_t, uint8_t> as_tuple() const;

private:
  uint8_t m_red;
  uint8_t m_green;
  uint8_t m_blue;
};
