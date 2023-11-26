#include "position.hpp"
#include "types.hpp"
#include <assert.h>
#include <cmath>
#include <iostream>

Position::Position( FPType x, FPType y, FPType z )
    : m_x( x ), m_y( y ), m_z( z )
{
}

FPType Position::magnitude() const
{
  return std::sqrt( m_x * m_x + m_y * m_y + m_z * m_z );
}

FPType Position::dot( const Position &other ) const
{
  auto [ x, y, z ] = other;
  return x * m_x + y * m_y + z * m_z;
}

void Position::resize( FPType size )
{
  auto M = magnitude();
  auto sqSize = std::sqrt( size );
  auto [ x, y, z ] = *this;
  m_x = sqSize * x / M;
  m_y = sqSize * y / M;
  m_z = sqSize * z / M;
  assert( std::fabs( std::pow( magnitude(), 2 ) - size ) < 0.001 );
}

Position Position::operator-( const Position &other ) const
{
  auto [ x, y, z ] = other;
  return Position( m_x - x, m_y - y, m_z - z );
}

FPType Position::x() const { return m_x; }
FPType Position::y() const { return m_y; }
FPType Position::z() const { return m_z; }
