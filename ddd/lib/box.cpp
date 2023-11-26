#include "box.hpp"
#include "types.hpp"

Box::Box(Color c, FPType x, FPType y, FPType z, FPType b, FPType w, FPType h)
    : Entity(c, x, y, z), m_b(b), m_w(w), m_h(h) {}
bool Box::collides([[maybe_unused]] const Position &cam,
                   [[maybe_unused]] const Position &dir) const {
  return false;
}
FPType Box::base() const { return m_b; }
FPType Box::width() const { return m_w; }
FPType Box::height() const { return m_h; }
