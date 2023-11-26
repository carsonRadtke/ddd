#include <iostream>

#include "screen.hpp"

Screen::Screen(size_t width, size_t height)
    : m_width(width), m_height(height), m_raster(width * height) {}
size_t Screen::width() const { return m_width; }
size_t Screen::height() const { return m_height; }
size_t Screen::pixels() const { return m_width * m_height; }
Color &Screen::operator[](size_t idx) { return m_raster[idx]; }
void Screen::save() const {
  std::cout << "P3\n";
  std::cout << m_width << " " << m_height << "\n";
  std::cout << UINT8_MAX << "\n";
  int counter = 0;
  for (const auto &c : m_raster) {
    auto [r, g, b] = c;
    std::cout << static_cast<int>(r) << " " << static_cast<int>(g) << " "
              << static_cast<int>(b) << "\t";
    counter++;
    counter %= m_width;
    if (!counter)
      std::cout << "\n";
  }
}