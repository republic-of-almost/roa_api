#ifndef DATA_INCLUDED_919D3AB2_5B2E_436A_AF46_42C4799AA2DB
#define DATA_INCLUDED_919D3AB2_5B2E_436A_AF46_42C4799AA2DB


#include <nil/fwd.hpp>


namespace ROA_detail {


// -------------------------------------------------------------- [ Context ] --


Nil::Node
get_context_node();


// ---------------------------------------------------------------- [ Input ] --


Nil::Node
get_mice_node();


Nil::Node
get_keyboards_node();


Nil::Node
get_gamepads_node();


// ---------------------------------------------------------------- [ Audio ] --


Nil::Node
get_audio_sample_node();


// --------------------------------------------------------------- [ Entity ] --


Nil::Node
get_entity_node();


// ---------------------------------------------------------------- [ Other ] --


Nil::Node
get_debug_line_node();



} // ns


#endif // inc guard
