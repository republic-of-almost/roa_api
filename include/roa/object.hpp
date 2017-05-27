#ifndef OBJECT_INCLUDED_D23D0D85_29D1_4843_9CA8_3FA5D28061B5
#define OBJECT_INCLUDED_D23D0D85_29D1_4843_9CA8_3FA5D28061B5


#include <roa/foundation/fwd.hpp>
#include <roa/foundation/types.hpp>


namespace ROA {


class Object
{
protected:


  // ---------------------------------------------------------- [ Protected ] --
  

  explicit              Object(uint32_t instance_id, bool owning = false);
  explicit              Object(nullptr_t);
  explicit              Object();
  
                        Object(const Object &obj);
  Object&               operator=(const Object &obj);

  void                  set_instance_id(const uint32_t id);


public:


  // ----------------------------------------------------------- [ Lifetime ] --


  virtual               ~Object();
  void                  destroy();
  bool                  is_valid() const;
  Entity                get_entity() const;

  
  // ---------------------------------------------------------- [ Type info ] --


  virtual uint32_t      get_type_id() const;
  virtual const char*   get_type_name() const;
  
  
  // ------------------------------------------------------ [ Instance info ] --
  
  
  virtual const char*   get_instance_name() const;
  uint32_t              get_instance() const;


private:

  uint32_t              m_instance_id;
  bool                  m_owning;

};


} // ns


#endif // inc guard
