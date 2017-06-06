#ifndef COMPONENT_INCLUDED_8D8668F9_ADB3_4E9D_B78C_591CBB296159
#define COMPONENT_INCLUDED_8D8668F9_ADB3_4E9D_B78C_591CBB296159


#include <roa/object.hpp>


namespace ROA {


using generic_hook_fn = void(*)(Entity entity, uintptr_t user_data);


class Component final : public Object
{
  friend class      Entity;
  
  explicit          Component(uint32_t instance_id);

public:

  explicit          Component();
  
  
  // ----------------------------------------------------------- [ Settings ] --
  
  
  void              set_startup_fn(const generic_hook_fn &fn);
  void              set_think_early_fn(const generic_hook_fn &fn);
  void              set_think_fn(const generic_hook_fn &fn);
  void              set_think_late_fn(const generic_hook_fn &fn);
  void              set_shutdown_fn(const generic_hook_fn &fn);
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t          get_type_id() const override;
  const char*       get_type_name() const override;
  const char*       get_instance_name() const override;

};


} // ns


#endif // inc guard
