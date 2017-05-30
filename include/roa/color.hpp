#ifndef COLOR_AD8C2428_817F_4BD8_B335_D8AB5904A2DB
#define COLOR_AD8C2428_817F_4BD8_B335_D8AB5904A2DB


#include <roa/foundation/types.hpp>


namespace ROA {


class Color final
{
public:

  explicit        Color();
  explicit        Color(float red, float green, float blue, float alpha);

  uint8_t         get_red() const;
  float           get_red_f() const;
  void            set_red_f(float val);
  
  uint8_t         get_green() const;
  float           get_green_f() const;
  void            set_green_f(float val);
  
  uint8_t         get_blue() const;
  float           get_blue_f() const;
  void            set_blue_f(float val);
  
  uint8_t         get_alpha() const;
  float           get_alpha_f() const;
  void            set_alpha_f(float val);

private:

  uint32_t        m_color;

};


} // ns


#endif // inc guard
