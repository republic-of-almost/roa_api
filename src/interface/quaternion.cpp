#include <roa/quaternion.hpp>
#include <roa/vector3.hpp>
#include <math/quat/quat.hpp>


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


/* static */ Quaternion
Quaternion::from_axis_angle(Vector3 axis, float angle)
{
  const math::quat rot = math::quat_init_with_axis_angle(
    axis.x(),
    axis.y(),
    axis.z(),
    angle
  );
  
  return Quaternion(
    math::quat_get_x(rot),
    math::quat_get_y(rot),
    math::quat_get_z(rot),
    math::quat_get_w(rot)
  );
}


} // ns
