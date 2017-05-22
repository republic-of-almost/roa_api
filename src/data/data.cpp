#include <data/data.hpp>
#include <nil/nil.hpp>
#include <nil/node.hpp>


namespace ROA_detail {


Nil::Node
get_context_node()
{
  static Nil::Node node;
  return node;
}


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


} // ns
