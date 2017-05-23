#include <roa/entity.hpp>
#include <roa/foundation/type_ids.hpp>
#include <roa/transform.hpp>
#include <roa/camera.hpp>
#include <nil/node.hpp>
#include <data/data.hpp>


namespace {


constexpr char entity_type_name[] = "Entity";


} // anon ns


namespace ROA {


Entity::Entity(Object object)
: Object(object.get_instance())
{
  set_instance_id(object.get_instance());
}


Entity::Entity()
: Object()
{
}


// ----------------------------------------------------------------- [ Data ] --


Transform
Entity::get_transform() const
{
  return Transform(*this);
}


Camera
Entity::get_camera() const
{
  return Camera(*this);
}


// ------------------------------------------------------------ [ Inherited ] --


uint32_t
Entity::get_type_id() const
{
  return ROA::Type::Entity_ID;
}


const char*
Entity::get_type_name() const
{
  return entity_type_name;
}


const char*
Entity::get_instance_name() const
{
  return Object::get_instance_name();
}



} // ns
