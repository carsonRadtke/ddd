#include <cstdint>
#include <iostream>

template <typename T> using Vec3 = std::tuple<T, T, T>;

using Color = Vec3<uint8_t>;

static void writePPM(const size_t &width, const size_t &height,
                     const std::vector<Color> &raster) {
  std::cout << "P3"
            << "\n";
  std::cout << width << " " << height << "\n";
  std::cout << UINT8_MAX << "\n";
  int counter = 0;
  for (const auto &c : raster) {
    std::cout << static_cast<int>(std::get<0>(c)) << " "
              << static_cast<int>(std::get<1>(c)) << " "
              << static_cast<int>(std::get<2>(c)) << "\t";
    counter++;
    counter %= width;
    if (!counter)
      std::cout << "\n";
  }
}

Color raycast([[maybe_unused]] size_t x, [[maybe_unused]] size_t y) {
  return Color(255, 0, 0);
}

static int ddd_main(void) {
  size_t width = 800;
  size_t height = 600;
  std::vector<Color> raster(width * height);
  for (size_t h = 0; h < height; h++) {
    for (size_t w = 0; w < width; w++) {
      raster[h * width + w] = raycast(w, h);
    }
  }
  writePPM(width, height, raster);
  return 0;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) {
  return ddd_main();
}
