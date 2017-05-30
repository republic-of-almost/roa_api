#include <roa/color.hpp>
#include <utilities/color.hpp>


namespace ROA {


Color::Color()
: Color(1.f, 1.f, 1.f, 1.f)
{
}


Color::Color(float red, float green, float blue, float alpha)
{
  m_color = lib::color::init(red, green, blue, alpha);
}


//Color::Color(float red, float green, float blue, float alpha)
//: Color(
//  (uint8_t)(red * 255),
//  (uint8_t)(green * 255),
//  (uint8_t)(blue * 255),
//  (uint8_t)(alpha * 255))
//{
//}


uint8_t
Color::get_red() const
{
  return lib::color::get_channel_1i(m_color);
}


float
Color::get_red_f() const
{
  return lib::color::get_channel_1f(m_color);
}


void
Color::set_red_f(float val)
{
  m_color = lib::color::init(val, get_green_f(), get_blue_f(), get_alpha_f());
}


uint8_t
Color::get_green() const
{
  return lib::color::get_channel_2i(m_color);
}


float
Color::get_green_f() const
{
  return lib::color::get_channel_2f(m_color);
}


void
Color::set_green_f(float val)
{
  m_color = lib::color::init(get_red_f(), val, get_blue_f(), get_alpha_f());
}


uint8_t
Color::get_blue() const
{
  return lib::color::get_channel_3f(m_color);
}


float
Color::get_blue_f() const
{
  return lib::color::get_channel_3f(m_color);
}


void
Color::set_blue_f(float val)
{
  m_color = lib::color::init(get_red_f(), get_green_f(), val, get_alpha_f());
}



uint8_t
Color::get_alpha() const
{
  return lib::color::get_channel_4i(m_color);
}


float
Color::get_alpha_f() const
{
  return lib::color::get_channel_4f(m_color);
}


void
Color::set_alpha_f(float val)
{
  m_color = lib::color::init(get_red_f(), get_green_f(), get_blue_f(), val);
}


} // ns
