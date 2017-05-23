#include <roa/transform.hpp>
#include <roa/vector3.hpp>
#include <roa/quaternion.hpp>
#include <roa/foundation/type_ids.hpp>
#include <nil/node.hpp>
#include <nil/data/transform.hpp>
#include <utilities/logging.hpp>
#include <utilities/assert.hpp>



namespace {


constexpr char transform_type_name[] = "Transform";


} // anon ns


namespace ROA {


Transform::Transform(Object obj)
: Object(obj.get_instance())
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
}


Vector3
Transform::get_forward() const
{
}


Vector3
Transform::get_up() const
{
}


Vector3
Transform::get_left() const
{
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
