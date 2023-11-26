#pragma once

#include "entity.hpp"
#include "types.hpp"

struct Sphere : Entity {
  Sphere( Color c, FPType x, FPType y, FPType z, FPType r );
  bool collides( [[maybe_unused]] const Position &cam,
                 [[maybe_unused]] const Position &dir ) const;
  FPType radius() const;

private:
  FPType m_r;
};