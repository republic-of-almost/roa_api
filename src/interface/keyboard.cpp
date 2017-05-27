#include <roa/keyboard.hpp>
#include <roa/foundation/type_ids.hpp>
#include <data/data.hpp>
#include <nil/node.hpp>
#include <nil/data/keyboard.hpp>
#include <utilities/logging.hpp>
#include <utilities/assert.hpp>
#include "helpers/key_convert.hpp"


namespace {


constexpr char keyboard_type_name[]  = "Keyboard";
constexpr char keyboard_node_name[]  = "roa-kb";
constexpr char keyboard_msg_found_out_of_place_node[] = "Found suspect node in keyboard branch";


} // anon ns


namespace ROA {


Keyboard::Keyboard(const uint32_t which)
: Object(nullptr)
{
  Nil::Node input_node = ROA_detail::get_keyboards_node();
  
  // Look for child
  Nil::Node keyboard(nullptr);
  
  const size_t child_count = input_node.get_child_count();
  
  for(size_t i = 0; i < child_count; ++i)
  {
    Nil::Node child = input_node.get_child(i);
    
    if(Nil::Data::has_keyboard(child))
    {
      keyboard = child;
      Nil::Data::Keyboard data{};
      Nil::Data::get(keyboard, data);
      
      if(data.id == which)
      {
        break;
      }
    }
    else
    {
      LOG_WARNING(keyboard_msg_found_out_of_place_node);
    }
  }
  
  if(!keyboard)
  {
    keyboard = Nil::Node();
    keyboard.set_name(keyboard_node_name);
    keyboard.set_parent(input_node);
    
    Nil::Data::Keyboard data{};
    data.id = which;
    
    Nil::Data::set(keyboard, data);
  }
  
  set_instance_id(keyboard.get_id());
}


// ------------------------------------------------------------- [ Settings ] --


bool
Keyboard::is_key_down(uint32_t key_id) const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Keyboard data{};
  Nil::Data::get(node, data);
  
  const uint32_t key_code = ROA_detail::roa_key_to_id(key_id);
  
  const uint32_t *key_states = (uint32_t*)data.key_state;
  
  return (key_states[key_code] == Nil::Data::KeyState::DOWN) ||
         (key_states[key_code] == Nil::Data::KeyState::DOWN_ON_FRAME);
}


bool
Keyboard::is_key_down_on_frame(uint32_t key_id) const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Keyboard data{};
  Nil::Data::get(node, data);
  
  const uint32_t key_code = ROA_detail::roa_key_to_id(key_id);
  
  const uint32_t *key_states = (uint32_t*)data.key_state;
  
  return key_states[key_code] == Nil::Data::KeyState::DOWN_ON_FRAME;
}

  
bool
Keyboard::is_key_up(uint32_t key_id) const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Keyboard data{};
  Nil::Data::get(node, data);
  
  const uint32_t *key_states = (uint32_t*)data.key_state;
  
  const uint32_t key_code = ROA_detail::roa_key_to_id(key_id);
  
  return (key_states[key_code] == Nil::Data::KeyState::UP) ||
         (key_states[key_code] == Nil::Data::KeyState::UP_ON_FRAME);
}


bool
Keyboard::is_key_up_on_frame(uint32_t key_id) const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Keyboard data{};
  Nil::Data::get(node, data);
  
  const uint32_t *key_states = (uint32_t*)data.key_state;
  
  const uint32_t key_code = ROA_detail::roa_key_to_id(key_id);
  
  return key_states[key_code] == Nil::Data::KeyState::UP_ON_FRAME;
}
 
  
uint32_t
Keyboard::get_which() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Keyboard data{};
  Nil::Data::get(node, data);
  
  return data.id;
}


/*static*/ const char *
get_key_name(uint32_t key_id)
{
  return "";
}


// ------------------------------------------------------------ [ Inherited ] --
  
  
uint32_t
Keyboard::get_type_id() const
{
  return ROA::Type::Keyboard_ID;
}


const char*
Keyboard::get_type_name() const
{
  return keyboard_type_name;
}


const char*
Keyboard::get_instance_name() const
{
  return keyboard_node_name;
}
  
  
} // ns
