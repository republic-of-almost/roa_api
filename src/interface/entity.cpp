#include <roa/entity.hpp>
#include <roa/foundation/type_ids.hpp>
#include <roa/transform.hpp>
#include <roa/camera.hpp>
#include <roa/material.hpp>
#include <nil/node.hpp>
#include <nil/data/data.hpp>
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


// -------------------------------------------------------------- [ General ] --



const char*
Entity::get_name() const
{
  if(get_instance())
  {
    return Nil::Node(get_instance()).get_name();
  }
  
  return "";
}


void
Entity::set_name(const char *name)
{
  if(get_instance())
  {
    Nil::Node(get_instance()).set_name(name);
  }
}



// ----------------------------------------------------------------- [ Data ] --


Transform
Entity::get_transform() const
{
  return Transform(this->get_instance());
}


void
Entity::set_transform(const Transform other)
{
  const Nil::Node other_node(other.get_instance());
  Nil::Data::Transform other_data{};
  Nil::Data::get(other_node, other_data);
  
  Nil::Node node(get_instance());
  Nil::Data::set(node, other_data);
}


Camera
Entity::get_camera() const
{
//  return Camera(*this);
  return Camera();
}


Material
Entity::get_material() const
{
  return Material(this->get_instance());
}


void
Entity::set_material(const ROA::Material other)
{
  Nil::Node other_node(other.get_instance());
  Nil::Data::Material other_data{};
  Nil::Data::get(other_node, other_data);
  
  Nil::Node node(get_instance());
  Nil::Data::set(node, other_data);
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
