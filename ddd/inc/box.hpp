#pragma once

#include "types.hpp"
#include "entity.hpp"

struct Box : Entity {
  Box(Color c, FPType x, FPType y, FPType z, FPType b, FPType w, FPType h)
      : Entity(c, x, y, z), m_b(b), m_w(w), m_h(h) {}
  bool collides([[maybe_unused]] const Position &cam,
                [[maybe_unused]] const Position &dir) const {
    return false;
  }
  auto base() const { return m_b; }
  auto width() const { return m_w; }
  auto height() const { return m_h; }

private:
  FPType m_b;
  FPType m_w;
  FPType m_h;
};