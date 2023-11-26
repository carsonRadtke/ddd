#pragma once

#include <memory>

#include "types.hpp"
#include "position.hpp"

class Entity {
public:
  Entity(Color color, FPType x, FPType y, FPType z)
      : m_color(color), m_x(x), m_y(y), m_z(z) {}
  virtual ~Entity() {}
  virtual bool collides(const Position &cam, const Position &dir) const = 0;
  Color color() const { return m_color; };
  auto x() const { return m_x; }
  auto y() const { return m_y; }
  auto z() const { return m_z; }

private:
  Color m_color;
  FPType m_x;
  FPType m_y;
  FPType m_z;
};
using EntityUPtr = std::unique_ptr<Entity>;