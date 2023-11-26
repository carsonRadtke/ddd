#pragma once

#include "types.hpp"
#include "entity.hpp"

struct Sphere : Entity {
  Sphere(Color c, FPType x, FPType y, FPType z, FPType r)
      : Entity(c, x, y, z), m_r(r) {}
  bool collides([[maybe_unused]] const Position &cam,
                [[maybe_unused]] const Position &dir) const {
    return false;
  }
  auto radius() const { return m_r; }

private:
  FPType m_r;
};