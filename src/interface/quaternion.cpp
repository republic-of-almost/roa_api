#include <roa/quaternion.hpp>


namespace ROA {


Quaternion::Quaternion(float x, float y, float z, float w)
: m_data{x, y, z, w}
{
}


float
Quaternion::x() const
{
  return m_data[0];
}


float
Quaternion::y() const
{
  return m_data[1];
}


float
Quaternion::z() const
{
  return m_data[2];
}


float
Quaternion::w() const
{
  return m_data[3];
}


} // ns
