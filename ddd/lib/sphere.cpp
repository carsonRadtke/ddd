#include "sphere.hpp"
#include "types.hpp"

Sphere::Sphere(Color c, FPType x, FPType y, FPType z, FPType r)
    : Entity(c, x, y, z), m_r(r) {}
bool Sphere::collides([[maybe_unused]] const Position &cam,
                      [[maybe_unused]] const Position &dir) const {
  return false;
}
FPType Sphere::radius() const { return m_r; }