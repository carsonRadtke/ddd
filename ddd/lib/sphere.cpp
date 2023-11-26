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
  Position self( x(), y(), z() );
  Position dist = cam - self;

  float theta_s = std::tan( m_r / dist.magnitude() );
  float theta_d = std::acos( self.dot( dir ) / self.magnitude() );

  return std::abs( theta_d ) <= std::abs( theta_s );
}
FPType Sphere::radius() const { return m_r; }