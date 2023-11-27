#include "sphere.hpp"
#include "types.hpp"

#include <math.h>

Sphere::Sphere( Color c, FPType x, FPType y, FPType z, FPType r )
    : Entity( c, x, y, z ), m_r( r )
{
}

bool Sphere::collides( [[maybe_unused]] const Position &cam,
                       [[maybe_unused]] const Position &dir ) const
{
  Position dist = pos() - cam;

  float theta_s = std::atan( m_r / dist.magnitude() );
  float theta_d = std::acos( dist.dot( dir ) / dist.magnitude() );

  return theta_s >= theta_d;
}

std::pair<Position, Position>
Sphere::collision_info( [[maybe_unused]] const Position &com, [[maybe_unused]] const Position &dir ) const {
  return { com, dir };
}

FPType Sphere::radius() const { return m_r; }