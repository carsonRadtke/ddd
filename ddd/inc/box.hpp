#pragma once

#include "entity.hpp"
#include "types.hpp"

struct Box : Entity {
  Box(Color c, FPType x, FPType y, FPType z, FPType b, FPType w, FPType h);
  bool collides([[maybe_unused]] const Position &cam,
                [[maybe_unused]] const Position &dir) const;
  FPType base() const;
  FPType width() const;
  FPType height() const;

private:
  FPType m_b;
  FPType m_w;
  FPType m_h;
};