#include <memory>
#include <variant>

#include "box.hpp"
#include "caster.hpp"
#include "entity.hpp"
#include "position.hpp"
#include "screen.hpp"
#include "sphere.hpp"
#include "types.hpp"

static void init_scene( std::vector<EntityUPtr> & entities )
{
  auto sph1 = std::make_unique<Sphere>(
      Sphere( Color( 0, 255, 255 ), 0, 500, 10, 50 ) );
  auto sph2 = std::make_unique<Sphere>(
      Sphere( Color( 255, 0, 255 ), -300, 700, 10, 100 ) );
  auto sph3 = std::make_unique<Sphere>(
      Sphere( Color( 255, 255, 0 ), 600, 100, 0, 500 ) );
  entities.push_back( std::move( sph1 ) );
  entities.push_back( std::move( sph2 ) );
  entities.push_back( std::move( sph3 ) );
}

static int ddd_main()
{
  Screen screen( 800, 600 );
  std::vector<EntityUPtr> entities{};

  init_scene( entities );
  screen.render( entities );

  return 0;
}

int main( [[maybe_unused]] int argc, [[maybe_unused]] const char * argv[] )
{
  return ddd_main();
}
