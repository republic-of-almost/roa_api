#include <roa/mouse.hpp>
#include <roa/point.hpp>
#include <roa/foundation/type_ids.hpp>
#include <data/data.hpp>
#include <nil/node.hpp>
#include <nil/data/mouse.hpp>
#include <utilities/assert.hpp>
#include <utilities/logging.hpp>
#include <string.h>


namespace {


constexpr char mouse_type_name[] = "Mouse";
constexpr char mouse_node_name[] = "roa-mouse";
constexpr char mouse_msg_found_out_of_place_node[] = "Found suspect node in mice branch";


} // anon ns


namespace ROA {


Mouse::Mouse(const uint32_t which)
: Object()
{
  Nil::Node input_node = ROA_detail::get_mice_node();
  
  // Look for child
  Nil::Node mouse(nullptr);
  
  const size_t child_count = input_node.get_child_count();
  
  for(size_t i = 0; i < child_count; ++i)
  {
    Nil::Node child = input_node.get_child(i);
    
    if(Nil::Data::has_mouse(child))
    {
      mouse = child;
      Nil::Data::Mouse mouse_data{};
      Nil::Data::get(mouse, mouse_data);
      
      if(mouse_data.id == which)
      {
        break;
      }
    }
    else
    {
      LOG_WARNING(mouse_msg_found_out_of_place_node);
    }
  }
  
  if(!mouse)
  {
    mouse = Nil::Node();
    mouse.set_name(mouse_node_name);
    mouse.set_parent(input_node);
    
    Nil::Data::Mouse mouse_data{};
    mouse_data.id = which;
    
    Nil::Data::set(mouse, mouse_data);
  }
  
  set_instance_id(mouse.get_id());
}


// ------------------------------------------------------------- [ Settings ] --


Point
Mouse::get_position() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Mouse data{};
  Nil::Data::get(node, data);
  
  return Point{
    (float)data.position[0],
    (float)data.position[1]
  };
}


Point
Mouse::get_delta() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Mouse data{};
  Nil::Data::get(node, data);
  
  return Point{
    (float)data.delta[0],
    (float)data.delta[1]
  };
}


uint32_t
Mouse::get_which() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Mouse data{};
  Nil::Data::get(node, data);
  
  return data.id;
}


// ------------------------------------------------------------ [ Inherited ] --
  
  
uint32_t
Mouse::get_type_id() const
{
  return ROA::Type::Mouse_ID;
}


const char*
Mouse::get_type_name() const
{
  return mouse_type_name;
}


const char*
Mouse::get_instance_name() const
{
  return mouse_node_name;
}



} // ns
