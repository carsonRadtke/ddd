#pragma once

#include <vector>

#include "entity.hpp"
#include "types.hpp"

class Screen
{
public:
  Screen( size_t width, size_t height );
  ~Screen();
  Color & operator[]( size_t idx );
  void save() const;
  size_t width() const;
  size_t height() const;
  size_t pixels() const;
  void render( const std::vector<EntityUPtr> & entities );

private:
  size_t m_width;
  size_t m_height;
  std::vector<Color> m_raster;
};