#pragma once

#include <memory>

#include "color.hpp"
#include "position.hpp"
#include "types.hpp"

class Entity {
public:
  Entity( Color color, FPType x, FPType y, FPType z )
      : m_color( color ), m_pos( x, y, z )
  {
  }
  virtual ~Entity() {}
  virtual bool collides( const Position &cam, const Position &dir ) const = 0;
  virtual std::pair<Position, Position>
  collision_info( const Position &com, const Position &dir ) const = 0;
  Color color() const { return m_color; };
  Position pos() const { return m_pos; }

private:
  Color m_color;
  Position m_pos;
};
using EntityUPtr = std::unique_ptr<Entity>;