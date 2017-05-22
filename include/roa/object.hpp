#ifndef OBJECT_INCLUDED_D23D0D85_29D1_4843_9CA8_3FA5D28061B5
#define OBJECT_INCLUDED_D23D0D85_29D1_4843_9CA8_3FA5D28061B5


#include <roa/foundation/types.hpp>


namespace ROA {


class Object
{
protected:

  explicit              Object();

  void                  set_instance_id(const uint32_t id);

public:

  virtual               ~Object();

  virtual uint32_t      get_type_id() const;
  virtual const char*   get_type_name() const;
  virtual const char*   get_instance_name() const;

  void                  destroy();
  uint32_t              get_instance() const;
  bool                  is_valid() const;

private:

  uint32_t              m_instance_id;

};


} // ns


#endif // inc guard
