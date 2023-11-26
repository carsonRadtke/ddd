#pragma once

#include <memory>

#include "position.hpp"
#include "types.hpp"

class Entity {
public:
  Entity( Color color, FPType x, FPType y, FPType z )
      : m_color( color ), m_x( x ), m_y( y ), m_z( z )
  {
  }
  virtual ~Entity() {}
  virtual bool collides( const Position &cam, const Position &dir ) const = 0;
  Color color() const { return m_color; };
  FPType x() const { return m_x; }
  FPType y() const { return m_y; }
  FPType z() const { return m_z; }

private:
  Color m_color;
  FPType m_x;
  FPType m_y;
  FPType m_z;
};
using EntityUPtr = std::unique_ptr<Entity>;