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


} // ns
