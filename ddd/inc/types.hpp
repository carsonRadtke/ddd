#pragma once

#include <tuple>
#include <cstdint>

template <typename T> using Vec3 = std::tuple<T, T, T>;
using Color = Vec3<uint8_t>;
using FPType = float;
