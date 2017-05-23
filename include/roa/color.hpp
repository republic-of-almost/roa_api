#ifndef COLOR_AD8C2428_817F_4BD8_B335_D8AB5904A2DB
#define COLOR_AD8C2428_817F_4BD8_B335_D8AB5904A2DB


#include <roa/foundation/types.hpp>


namespace ROA {


class Color final
{
public:

  explicit        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

  uint8_t         get_red() const;
  uint8_t         get_green() const;
  uint8_t         get_blue() const;
  uint8_t         get_alpha() const;

private:

  uint32_t        m_color;

};


} // ns


#endif // inc guard
