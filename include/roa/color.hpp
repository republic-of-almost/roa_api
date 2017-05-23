#ifndef COLOR_AD8C2428_817F_4BD8_B335_D8AB5904A2DB
#define COLOR_AD8C2428_817F_4BD8_B335_D8AB5904A2DB


#include <roa/foundation/types.hpp>


namespace ROA {


class Color final
{
public:

  explicit        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

  uint8_t         get_red() const;
  float           get_red_f() const;
  
  uint8_t         get_green() const;
  float           get_green_f() const;
  
  uint8_t         get_blue() const;
  float           get_blue_f() const;
  
  uint8_t         get_alpha() const;
  float           get_alpha_f() const;

private:

  uint32_t        m_color;

};


} // ns


#endif // inc guard
