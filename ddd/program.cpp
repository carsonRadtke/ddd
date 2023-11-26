#include <cstdint>
#include <iostream>

template <typename T> using Vec3 = std::tuple<T, T, T>;

using Color = Vec3<uint8_t>;

using Position = Vec3<float>;

void resize(Position &pos, float size) {
  auto &[x, y, z] = pos;
  float sum = x * x + y * y + z * z;
  x *= size / sum;
  y *= size / sum;
  z *= size / sum;
}

float dot(const Position &a, const Position &b) {
  auto [ax, ay, az] = a;
  auto [bx, by, bz] = b;
  return ax * bx + ay * by + az * bz;
}

class Screen {
public:
  Screen(size_t width, size_t height)
      : m_width(width), m_height(height), m_raster(width * height) {}
  size_t width() const { return m_width; }
  size_t height() const { return m_height; }
  size_t pixels() const { return m_width * m_height; }
  Color &operator[](size_t idx) { return m_raster[idx]; }
  void save() {
    std::cout << "P3"
              << "\n";
    std::cout << m_width << " " << m_height << "\n";
    std::cout << UINT8_MAX << "\n";
    int counter = 0;
    for (const auto &c : m_raster) {
      auto [r, g, b] = c;
      std::cout << static_cast<int>(r) << " " << static_cast<int>(g) << " "
                << static_cast<int>(b) << "\t";
      counter++;
      counter %= m_width;
      if (!counter)
        std::cout << "\n";
    }
  }

private:
  size_t m_width;
  size_t m_height;
  std::vector<Color> m_raster;
};

Color raycast([[maybe_unused]] size_t x, [[maybe_unused]] size_t y,
              [[maybe_unused]] const Screen &screen) {
  float dx = x - static_cast<float>(screen.width()) / 2;
  float dy = y - static_cast<float>(screen.height()) / 2;
  float dz = 0;
  Position dir(dx, dy, dz);
  resize(dir, 1);

  float dp = dot(dir, Position(0, 1, 0));
  if (dp < 0)
    return Color(0, 0, 255);
  return Color(255, 0, 0);
}

static int ddd_main(void) {
  Screen screen(800, 600);
  std::vector<Color> raster(screen.pixels());
  for (size_t h = 0; h < screen.height(); h++) {
    for (size_t w = 0; w < screen.width(); w++) {
      screen[h * screen.width() + w] = raycast(w, h, screen);
    }
  }
  screen.save();
  return 0;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) {
  return ddd_main();
}
