#include "caster.hpp"
#include "color.hpp"
#include "types.hpp"

static Color s_cast( const std::vector<EntityUPtr> &entities,
                     const Position &cam, const Position &dir, size_t bounces );
static Color s_cast_nocollision( const std::vector<EntityUPtr> &entities,
                                 const Position &cam, const Position &dir,
                                 size_t bounces )
{
  auto dp = dir.dot( Position( 0, 0, 1 ) );
  if ( dp <= 0 )
    return Color( 50, 50, 50 );

  auto t = cam.z() / dir.z();
  [[maybe_unused]] auto x = cam.x() + dir.x() * t;
  [[maybe_unused]] auto y = cam.y() + dir.y() * t;

  auto mx = std::abs( static_cast<ssize_t>( x ) ) % 100 < 50;
  auto my = std::abs( static_cast<ssize_t>( y ) ) % 100 < 50;

  Color color = mx == my ? Color( 255, 255, 255 ) : Color( 0, 0, 0 );
  return bounces == 0 ? color : color + s_cast( entities, cam, dir, --bounces );
}

static Color s_cast( const std::vector<EntityUPtr> &entities,
                     const Position &cam, const Position &dir, size_t bounces )
{
  for ( const auto &e : entities ) {
    if ( e->collides( cam, dir ) ) {
      Color entityColor = e->color();
      if ( bounces == 0 )
        return entityColor;
      auto [ coll_pos, coll_norm ] = e->collision_info( cam, dir );
      return entityColor +
             s_cast( entities, coll_pos, coll_norm, --bounces ) * 0.75;
    }
  }
  return s_cast_nocollision( entities, cam, dir, bounces );
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