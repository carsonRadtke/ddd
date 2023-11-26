#include <iostream>
#include <memory>
#include <variant>

#include "types.hpp"
#include "position.hpp"
#include "screen.hpp"
#include "entity.hpp"
#include "sphere.hpp"
#include "box.hpp"

Color cast_nocollision(const Position &cam, const Position &dir) {
  auto dp = dir.dot(Position(0, 0, 1));
  if (dp < 0)
    return Color(0, 0, 255);

  ssize_t x, y;
  if (dir.z() > 0 || dir.z() < 0) {
    auto t = cam.z() / dir.z();
    x = static_cast<ssize_t>(cam.x() + dir.x() * t);
    y = static_cast<ssize_t>(cam.y() + dir.y() * t);
  } else {
    x = cam.x();
    y = cam.y();
  }

  ssize_t xm = x & 1;
  ssize_t ym = y & 1;

  if (xm == ym)
    return Color(255, 255, 255);
  return Color(0, 0, 0);
}

Color cast(const std::vector<EntityUPtr> &entities, const Position &cam,
           const Position &dir) {
  for (const auto &e : entities) {
    // TODO: this does not work if an eclipsed object
    if (e->collides(cam, dir)) {
      return e->color();
    }
  }
  return cast_nocollision(cam, dir);
};

Color raycast(const std::vector<EntityUPtr> &entities, size_t x, size_t z,
              const Screen &screen) {
  auto dx = x - static_cast<FPType>(screen.width()) / 2;
  auto dy = static_cast<FPType>(100);
  auto dz = z - static_cast<FPType>(screen.height()) / 2;
  Position dir(dx, dy, dz);
  dir.resize(1);

  return cast(entities, Position(0, 0, 5), dir);
}

static int ddd_main(void) {
  Screen screen(800, 600);
  std::vector<EntityUPtr> entities{};
  auto sph = std::make_unique<Sphere>(Sphere(Color(255, 0, 0), 10, 10, 10, 3));
  entities.push_back(std::move(sph));
  std::vector<Color> raster(screen.pixels());
  for (size_t h = 0; h < screen.height(); h++) {
    for (size_t w = 0; w < screen.width(); w++) {
      screen[h * screen.width() + w] = raycast(entities, w, h, screen);
    }
  }
  screen.save();
  return 0;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) {
  return ddd_main();
}
