#include <data/data.hpp>
#include <nil/nil.hpp>
#include <nil/node.hpp>


namespace ROA_detail {


// -------------------------------------------------------------- [ Context ] --


Nil::Node
get_context_node()
{
  static Nil::Node node;
  return node;
}


// ---------------------------------------------------------------- [ Input ] --


Nil::Node
get_mice_node()
{
  static Nil::Node node;
  return node;
}


Nil::Node
get_keyboards_node()
{
  static Nil::Node node;
  return node;
}


Nil::Node
get_gamepads_node()
{
  static Nil::Node node;
  return node;
}


// ---------------------------------------------------------------- [ Audio ] --


Nil::Node
get_audio_sample_node()
{
  static Nil::Node node;
  return node;
}


// --------------------------------------------------------------- [ Entity ] --


Nil::Node
get_entity_node()
{
  static Nil::Node node;
  return node;
}


// ---------------------------------------------------------------- [ Other ] --


Nil::Node
get_debug_line_node()
{
  static Nil::Node node;
  return node;
}


} // ns
