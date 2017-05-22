#ifndef MOUSE_INCLUDED_E5AE2FA2_4159_4FB1_BA07_D6503AD7ED89
#define MOUSE_INCLUDED_E5AE2FA2_4159_4FB1_BA07_D6503AD7ED89


#include <roa/object.hpp>
#include <roa/foundation/fwd.hpp>
#include <roa/foundation/types.hpp>


namespace ROA {


class Mouse : public Object
{
public:

  explicit      Mouse(const uint32_t which);
  
  // ----------------------------------------------------------- [ Settings ] --

  Point         get_position() const;
  Point         get_delta() const;
  uint32_t      get_which() const;
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  uint32_t      get_type_id() const override;
  const char*   get_type_name() const override;
  const char*   get_instance_name() const override;

};


} // ns


#endif // inc guard
