#include <roa/object.hpp>
#include <roa/foundation/type_ids.hpp>
#include <nil/node.hpp>


namespace {

constexpr char object_type_name[] = "Unknown";
constexpr char object_no_instance_name[] = "Invalid Object";

}


namespace ROA {


Object::Object()
: m_instance_id(0)
{
}


Object::~Object()
{
  
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


} // ns
