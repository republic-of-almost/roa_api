#ifndef KEYBOARD_INCLUDED_73DCFCCD_55E2_4479_BB2E_438A21A13A44
#define KEYBOARD_INCLUDED_73DCFCCD_55E2_4479_BB2E_438A21A13A44


#include <roa/object.hpp>
#include <roa/foundation/fwd.hpp>
#include <roa/foundation/types.hpp>


namespace ROA {


class Keyboard : public Object
{
public:

  explicit              Keyboard(const uint32_t which);
  
  
  // ----------------------------------------------------------- [ Settings ] --


  bool                  is_key_down(uint32_t key_id) const;
  bool                  is_key_down_on_frame(uint32_t key_id) const;
  
  bool                  is_key_up(uint32_t key_id) const;
  bool                  is_key_up_on_frame(uint32_t key_id) const;
  
  uint32_t              get_which() const;
  
  static const char *   get_key_name(uint32_t key_id);


  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t              get_type_id() const override;
  const char*           get_type_name() const override;
  const char*           get_instance_name() const override;

};


} // ns


#endif // inc guard
