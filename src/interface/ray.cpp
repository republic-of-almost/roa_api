#include <roa/ray.hpp>


namespace ROA {


Ray::Ray(Vector3 origin, Vector3 direction)
: m_origin(origin)
, m_direction(direction)
{
}


Vector3
Ray::get_origin() const
{
  return m_origin;
}


Vector3
Ray::get_direction() const
{
  return m_direction;
}


} // ns
