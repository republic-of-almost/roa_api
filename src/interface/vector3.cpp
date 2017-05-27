#include <roa/vector3.hpp>


namespace ROA {


Vector3::Vector3(float x, float y, float z)
: m_data{x,y,z}
{
}


float
Vector3::x() const
{
  return m_data[0];
}


float
Vector3::y() const
{
  return m_data[1];
}


float
Vector3::z() const
{
  return m_data[2];
}


void
Vector3::set_x(float x)
{
  m_data[0] = x;
}


void
Vector3::set_y(float y)
{
  m_data[1] = y;
}


void
Vector3::set_z(float z)
{
  m_data[2] = z;
}


} // ns
