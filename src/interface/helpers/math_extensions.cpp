#include "math_extensions.hpp"
#include <math/vec/vec3.hpp>
#include <math/quat/quat.hpp>
#include <roa/vector3.hpp>
#include <roa/quaternion.hpp>


namespace ROA_detail {


math::vec3
vec3_init(ROA::Vector3 vec)
{
  return math::vec3_init(vec.x(), vec.y(), vec.z());
}


ROA::Vector3
vec3_to_roa(math::vec3 vec)
{
  return ROA::Vector3(math::get_x(vec), math::get_y(vec), math::get_z(vec));
}


math::quat
quat_init(ROA::Quaternion quat)
{
  return math::quat_init(quat.x(), quat.y(), quat.z(), quat.w());
}


ROA::Quaternion
quat_to_roa(math::quat quat)
{
  return ROA::Quaternion(
    math::get_x(quat),
    math::get_y(quat),
    math::get_z(quat),
    math::get_w(quat)
  );
}


} // ns
