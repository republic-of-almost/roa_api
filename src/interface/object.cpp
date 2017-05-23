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


Object::Object(uint32_t instance_id)
{
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
  
  set_instance_id(node.get_id());
}


Object::~Object()
{
  Nil::Node node(m_instance_id);
  node.destroy();
}


void
Object::set_instance_id(const uint32_t id)
{
  m_instance_id = id;
}


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


void
Object::destroy()
{
  if(m_instance_id)
  {
    Nil::Node node(m_instance_id);
    node.destroy();
  }
}


uint32_t
Object::get_instance() const
{
  return m_instance_id;
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
  return Entity(*this);
}


} // ns
