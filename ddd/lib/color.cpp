#include "color.hpp"

Color::Color() : m_red(0), m_green(0), m_blue(0) {}
Color::Color(uint8_t red, uint8_t green, uint8_t blue) : m_red(red), m_green(green), m_blue(blue) {}

Color Color::operator*(FPType frac) const{
  auto r = static_cast<uint8_t>(frac * m_red);
  auto g = static_cast<uint8_t>(frac * m_green);
  auto b = static_cast<uint8_t>(frac * m_blue);
  return Color( r, g, b );
}

std::tuple<uint8_t, uint8_t, uint8_t> Color::as_tuple() const
{
  return { m_red, m_green, m_blue };
}

uint8_t Color::red() const { return m_red; }
uint8_t Color::green() const { return m_green; }
uint8_t Color::blue() const { return m_blue; }
