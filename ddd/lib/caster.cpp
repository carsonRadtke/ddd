#include "caster.hpp"

static Color s_cast_nocollision( const Position &cam, const Position &dir )
{
  auto dp = dir.dot( Position( 0, 0, 1 ) );
  if ( dp < 0 )
    return Color( 0, 0, 255 );

  ssize_t x, y;
  if ( dir.z() > 0 || dir.z() < 0 ) {
    auto t = cam.z() / dir.z();
    x = static_cast<ssize_t>( cam.x() + dir.x() * t );
    y = static_cast<ssize_t>( cam.y() + dir.y() * t );
  }
  else {
    x = cam.x();
    y = cam.y();
  }

  ssize_t xm = x & 1;
  ssize_t ym = y & 1;

  if ( xm == ym )
    return Color( 255, 255, 255 );
  return Color( 0, 0, 0 );
}

static Color s_cast( const std::vector<EntityUPtr> &entities,
                     const Position &cam, const Position &dir )
{
  for ( const auto &e : entities ) {
    if ( e->collides( cam, dir ) ) {
      return e->color();
    }
  }
  return s_cast_nocollision( cam, dir );
};

namespace Caster {
Color raycast( const std::vector<EntityUPtr> &entities, size_t x, size_t z,
               const Screen &screen )
{
  auto dx = x - static_cast<FPType>( screen.width() ) / 2;
  auto dy = static_cast<FPType>( 100 );
  auto dz = z - static_cast<FPType>( screen.height() ) / 2;
  Position dir( dx, dy, dz );
  dir.resize( 1 );

  return s_cast( entities, Position( 0, 0, 5 ), dir );
}
} // namespace Caster