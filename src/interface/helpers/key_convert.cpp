#include "key_convert.hpp"
#include <nil/data/keyboard.hpp>
#include <roa/keyboard.hpp>
#include <roa/foundation/key_ids.hpp>


namespace ROA_detail {


uint32_t
roa_key_to_id(uint32_t roa_key)
{
  switch(roa_key)
  {
    case(ROA::KB::A): return Nil::Data::KeyCode::A;
    case(ROA::KB::D): return Nil::Data::KeyCode::D;
    case(ROA::KB::S): return Nil::Data::KeyCode::S;
    case(ROA::KB::W): return Nil::Data::KeyCode::W;
  }
  
  return 0;
}


} // ns
