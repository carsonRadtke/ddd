#include "entity.hpp"
#include "position.hpp"
#include "screen.hpp"
#include "types.hpp"

namespace Caster {
Color raycast( const std::vector<EntityUPtr> &entities, size_t x, size_t z,
               const Screen &screen );
}