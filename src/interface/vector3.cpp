#include <roa/vector3.hpp>
#include <math/vec/vec3.hpp>


namespace {

inline ROA::Vector3
from_math(math::vec3 vec)
{
  return ROA::Vector3(math::get_x(vec), math::get_y(vec), math::get_z(vec));
}


inline math::vec3
to_math(ROA::Vector3 vec)
{
  return math::vec3_init(vec.x(), vec.y(), vec.z());
}

}


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


Vector3
Vector3::add(Vector3 other) const
{
  return from_math(
    math::vec3_add(
      to_math(*this),
      to_math(other)
    )
  );
}


Vector3
Vector3::subtract(Vector3 other) const
{
  return from_math(
    math::vec3_subtract(
      to_math(*this),
      to_math(other)
    )
  );
}


Vector3
Vector3::normalize() const
{
  return from_math(
    math::vec3_normalize(
      to_math(*this)
    )
  );
}


Vector3
Vector3::scale(float scale) const
{
  return from_math(
    math::vec3_scale(
      to_math(*this),
      scale
    )
  );
}


float
Vector3::length() const
{
  return math::vec3_length(to_math(*this));
}


float
Vector3::dot(Vector3 other) const
{
  return math::vec3_dot(
    to_math(*this),
    to_math(other)
  );
}


} // ns
