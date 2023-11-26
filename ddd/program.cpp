#include <iostream>
#include <memory>
#include <variant>

#include "box.hpp"
#include "caster.hpp"
#include "entity.hpp"
#include "position.hpp"
#include "screen.hpp"
#include "sphere.hpp"
#include "types.hpp"

static int ddd_main()
{
  auto sph =
      std::make_unique<Sphere>( Sphere( Color( 255, 0, 0 ), 0, 500, 10, 50 ) );
  std::vector<EntityUPtr> entities{};
  entities.push_back( std::move( sph ) );

  Screen screen( 800, 600 );
  screen.render( entities );

  return 0;
}

int main( [[maybe_unused]] int argc, [[maybe_unused]] const char *argv[] )
{
  return ddd_main();
}
