#ifndef APPLICATION_INCLUDED_FF5EBD52_E996_433D_8001_A64293576011
#define APPLICATION_INCLUDED_FF5EBD52_E996_433D_8001_A64293576011


#include <roa/foundation/types.hpp>
#include <roa/object.hpp>


namespace ROA {


class Application : public Object
{
public:

  explicit      Application();
                ~Application();
  
  
  // ----------------------------------------------------------- [ Settings ] --
  
  
  const char*   get_title() const;
  void          set_title(const char *title);

  uint32_t      get_width() const;
  void          set_width(const uint32_t width);

  uint32_t      get_height() const;
  void          set_height(const uint32_t height);

  bool          is_fullscreen() const;
  void          set_fullscreen(const bool set);
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t      get_type_id() const override;
  const char*   get_type_name() const override;
  const char*   get_instance_name() const override;


};


} // ns


#endif // inc guard
