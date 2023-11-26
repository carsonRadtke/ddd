#include "caster.hpp"
#include "types.hpp"
#include "color.hpp"

static Color s_cast_nocollision( [[maybe_unused]] const Position &cam,
                                 const Position &dir )
{
  auto dp = dir.dot( Position( 0, 0, 1 ) );
  if ( dp <= 0 )
    return Color( 0, 0, 255 );

  auto t = cam.z() / dir.z();
  [[maybe_unused]] auto x = cam.x() + dir.x() * t;
  [[maybe_unused]] auto y = cam.y() + dir.y() * t;

  auto mx = std::abs( static_cast<ssize_t>( x ) ) % 100 < 50;
  auto my = std::abs( static_cast<ssize_t>( y ) ) % 100 < 50;

  if ( mx == my ) {
    return Color( 255, 255, 255 );
  }

  return Color( 0, 0, 0 );
}

static Color s_cast( const std::vector<EntityUPtr> &entities,
                     const Position &cam, const Position &dir,
                     size_t bounces )
{
  for ( const auto &e : entities ) {
    if ( e->collides( cam, dir ) )
    {
      Color entityColor = e->color();
      if (bounces == 0) return entityColor;
      return entityColor * 0.9;
    }
  }
  return s_cast_nocollision( cam, dir );
};

namespace Caster {
Color raycast( const std::vector<EntityUPtr> &entities, size_t x, size_t z,
               const Screen &screen )
{
  auto wf = static_cast<FPType>( screen.width() );
  auto hf = static_cast<FPType>( screen.height() );

  auto dx = x - wf / 2;
  auto dy = static_cast<FPType>( hf / 2 );
  auto dz = z - hf / 2;
  Position dir( dx, dy, dz );
  dir.resize( 1 );

  return s_cast( entities, Position( 0, 0, hf / 2 ), dir, 1 );
}
} // namespace Caster