#pragma once

#include "types.hpp"

class Position {
public:
  Position( FPType x, FPType y, FPType z );
  Position operator-( const Position &other ) const;
  void resize( FPType size );
  FPType magnitude() const;
  FPType dot( const Position &other ) const;
  FPType x() const;
  FPType y() const;
  FPType z() const;

private:
  FPType m_x;
  FPType m_y;
  FPType m_z;
};
