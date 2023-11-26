#pragma once

#include "types.hpp"

class Position {
public:
  Position(FPType x, FPType y, FPType z) : m_x(x), m_y(y), m_z(z) {}
  FPType dot(const Position &other) const {
    auto [x, y, z] = other;
    return x * m_x + y * m_y + z * m_z;
  }
  void resize(FPType size) {
    auto sum = m_x * m_x + m_y * m_y + m_z * m_z;
    m_x *= size / sum;
    m_y *= size / sum;
    m_z *= size / sum;
  }
  Position operator-(const Position &other) const {
    auto [x, y, z] = other;
    return Position(m_x - x, m_y - y, m_z - z);
  }
  auto x() const { return m_x; }
  auto y() const { return m_y; }
  auto z() const { return m_z; }

private:
  FPType m_x;
  FPType m_y;
  FPType m_z;
};
