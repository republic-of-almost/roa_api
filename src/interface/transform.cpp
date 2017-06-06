#include <roa/transform.hpp>
#include <roa/vector3.hpp>
#include <roa/quaternion.hpp>
#include <roa/foundation/type_ids.hpp>
#include <nil/node.hpp>
#include <nil/data/transform.hpp>
#include <lib/logging.hpp>
#include <lib/assert.hpp>
#include "helpers/math_extensions.hpp"
#include <math/quat/quat.hpp>
#include <math/vec/vec3.hpp>



namespace {


constexpr char transform_type_name[] = "Transform";


} // anon ns


namespace ROA {


Transform::Transform(uint32_t instance_id)
: Object(instance_id)
{
}


Transform::Transform()
: Object()
{
}
  

// ------------------------------------------------------------- [ Settings ] --
  
  
Vector3
Transform::get_position() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Transform data{};
  Nil::Data::get(node, data);
  
  return Vector3(
    data.position[0],
    data.position[1],
    data.position[2]
  );
}


void
Transform::set_position(Vector3 pos)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Transform data{};
  Nil::Data::get(node, data);
  
  data.position[0] = pos.x();
  data.position[1] = pos.y();
  data.position[2] = pos.z();
  
  Nil::Data::set(node, data);
}


Vector3
Transform::get_scale() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Transform data{};
  Nil::Data::get(node, data);
  
  return Vector3(
    data.scale[0],
    data.scale[1],
    data.scale[2]
  );
}


void
Transform::set_scale(Vector3 scale)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Transform data{};
  Nil::Data::get(node, data);
  
  data.scale[0] = scale.x();
  data.scale[1] = scale.y();
  data.scale[2] = scale.z();
  
  Nil::Data::set(node, data);
}


Quaternion
Transform::get_rotation() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Transform data{};
  Nil::Data::get(node, data);
  
  return Quaternion(
    data.rotation[0],
    data.rotation[1],
    data.rotation[2],
    data.rotation[3]
  );
}


void
Transform::set_rotation(Quaternion quat)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Transform data{};
  Nil::Data::get(node, data);
  
  data.rotation[0] = quat.x();
  data.rotation[1] = quat.y();
  data.rotation[2] = quat.z();
  data.rotation[3] = quat.w();
  
  Nil::Data::set(node, data);
}


Vector3
Transform::get_forward() const
{
  const math::quat rot = ROA_detail::quat_init(get_rotation());
  const math::vec3 fwd = ROA_detail::vec3_init(get_world_forward());
  
  return ROA_detail::vec3_to_roa(
    math::quat_rotate_point(rot, fwd)
  );
}


Vector3
Transform::get_up() const
{
  const math::quat rot = ROA_detail::quat_init(get_rotation());
  const math::vec3 up = ROA_detail::vec3_init(get_world_up());
  
  return ROA_detail::vec3_to_roa(
    math::quat_rotate_point(rot, up)
  );
}


Vector3
Transform::get_left() const
{
  const math::quat rot = ROA_detail::quat_init(get_rotation());
  const math::vec3 left = ROA_detail::vec3_init(get_world_left());
  
  return ROA_detail::vec3_to_roa(
    math::quat_rotate_point(rot, left)
  );
}


/*static*/ Vector3
Transform::get_world_forward()
{
  return Vector3(0,0,1);
}


/*static*/ Vector3
Transform::get_world_up()
{
  return Vector3(0,1,0);
}


/*static*/ Vector3
Transform::get_world_left()
{
  return Vector3(1,0,0);
}


// ------------------------------------------------------------ [ Inherited ] --
  
  
uint32_t
Transform::get_type_id() const
{
  return ROA::Type::Transform_ID;
}


const char*
Transform::get_type_name() const
{
  return transform_type_name;
}


const char*
Transform::get_instance_name() const
{
  return Object::get_instance_name();
}


} // ns
