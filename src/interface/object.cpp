#include <roa/object.hpp>
#include <roa/entity.hpp>
#include <data/data.hpp>
#include <roa/foundation/type_ids.hpp>
#include <nil/node.hpp>


namespace {

constexpr char object_type_name[]        = "Unknown";
constexpr char object_no_instance_name[] = "Invalid Object";
constexpr char object_name[]             = "roa-ent";

}


namespace ROA {


// ---------------------------------------------------------- [ Protected ] --


Object::Object(uint32_t instance_id, bool owning)
{
  m_owning = owning;
  set_instance_id(instance_id);
}


Object::Object(nullptr_t)
: Object(uint32_t{0})
{
}


Object::Object()
{
  Nil::Node node;
  node.set_name(object_name);
  node.set_parent(ROA_detail::get_entity_node());
  
  m_owning = true;
  
  set_instance_id(node.get_id());
}


Object::Object(const Object &obj)
: m_instance_id(obj.m_instance_id)
, m_owning(false)
{
}


Object&
Object::operator=(const Object &obj)
{
  m_instance_id = obj.m_instance_id;
  m_owning = false;
  
  return *this;
}


void
Object::set_instance_id(uint32_t id)
{
  m_instance_id = id;
}


void
Object::set_ownership(bool ownership)
{
  m_owning = ownership;
}


// ------------------------------------------------------------- [ Lifetime ] --


Object::~Object()
{
  if(m_owning)
  {
    Nil::Node node(m_instance_id);
    node.destroy();
  }
}


void
Object::destroy()
{
  if(m_instance_id)
  {
    Nil::Node node(m_instance_id);
    node.destroy();
  }
}


bool
Object::is_valid() const
{
  if(m_instance_id)
  {
    return Nil::Node(m_instance_id).is_valid();
  }
  
  return false;
}


Entity
Object::get_entity() const
{
  return Entity(get_instance());
}


// ------------------------------------------------------------ [ Type info ] --


uint32_t
Object::get_type_id() const
{
  return ROA::Type::Object_ID;
}


const char*
Object::get_type_name() const
{
  return object_type_name;
}


// -------------------------------------------------------- [ Instance info ] --


const char*
Object::get_instance_name() const
{
  if(get_instance())
  {
    Nil::Node node(get_instance());
    return node.get_name();
  }

  return object_no_instance_name;
}


uint32_t
Object::get_instance() const
{
  return m_instance_id;
}


} // ns
