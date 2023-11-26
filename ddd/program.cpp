#include <cstdint>
#include <iostream>

template <typename T> using Vec3 = std::tuple<T, T, T>;

using Color = Vec3<uint8_t>;

using FPType = float;

class Position
{
  public:
  Position(FPType x, FPType y, FPType z) : m_x(x), m_y(y), m_z(z){}
  FPType dot(const Position & other) const
  {
    auto [x, y, z] = other;
    return x * m_x + y * m_y + z * m_z;
  }
  void resize(FPType size)
  {
    auto sum = m_x * m_x + m_y * m_y + m_z * m_z;
    m_x *= size/sum;
    m_y *= size/sum;
    m_z *= size/sum;
  }
  Position operator-(const Position & other) const
  {
    auto [x, y, z] = other;
    return Position(m_x - x, m_y - y, m_z - z);
  }
  auto x() const { return m_x; }
  auto y() const { return m_y; }
  auto z() const { return m_z; }
  private:
  FPType m_x;
  FPType m_y;
  FPType m_z;
};

class Screen {
public:
  Screen(size_t width, size_t height)
      : m_width(width), m_height(height), m_raster(width * height) {}
  size_t width() const { return m_width; }
  size_t height() const { return m_height; }
  size_t pixels() const { return m_width * m_height; }
  Color &operator[](size_t idx) { return m_raster[idx]; }
  void save() const {
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

Color cast(
  [[maybe_unused]] const Position & cam,
  [[maybe_unused]] const Position & dir)
{
  auto dp = dir.dot(Position(0, 0, 1));
  if (dp < 0) return Color(0, 0, 255);
  
  ssize_t x, y;
  if (dir.z() > 0 || dir.z() < 0)
  {
    auto t = cam.z() / dir.z();
    x = static_cast<ssize_t>(cam.x() + dir.x() * t);
    y = static_cast<ssize_t>(cam.y() + dir.y() * t);
  }
  else
  {
    x = cam.x();
    y = cam.y();
  }

  ssize_t xm = x & 1;
  ssize_t ym = y & 1;

  if (xm == ym) return Color(255, 255, 255);
  return Color(0, 0, 0);
}

Color raycast(size_t x, size_t z, const Screen &screen) {
  auto dx = x - static_cast<FPType>(screen.width()) / 2;
  auto dy = static_cast<FPType>(100);
  auto dz = z - static_cast<FPType>(screen.height()) / 2;
  Position dir(dx, dy, dz);
  dir.resize(1);

  return cast(Position(0, 0, 5), dir);
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
