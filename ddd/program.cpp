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

static int ddd_main(void) {
  Screen screen(800, 600);
  std::vector<EntityUPtr> entities{};
  auto sph = std::make_unique<Sphere>(Sphere(Color(255, 0, 0), 10, 10, 10, 3));
  entities.push_back(std::move(sph));
  std::vector<Color> raster(screen.pixels());
  for (size_t h = 0; h < screen.height(); h++) {
    for (size_t w = 0; w < screen.width(); w++) {
      screen[h * screen.width() + w] = Caster::raycast(entities, w, h, screen);
    }
  }
  screen.save();
  return 0;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) {
  return ddd_main();
}
