#ifndef ENTITY_INCLUDED_B20E2F27_75EC_4B70_8E70_F2DEC4C00AFE
#define ENTITY_INCLUDED_B20E2F27_75EC_4B70_8E70_F2DEC4C00AFE


#include <roa/object.hpp>
#include <roa/foundation/types.hpp>
#include <roa/foundation/fwd.hpp>


namespace ROA {


class Entity : public Object
{
private:

  friend class Object;

  explicit        Entity(Object object);


public:


  explicit        Entity();
  
  
  // --------------------------------------------------------------- [ Data ] --
  

  Transform       get_transform() const;
  Camera          get_camera() const;
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t        get_type_id() const override;
  const char*     get_type_name() const override;
  const char*     get_instance_name() const override;

};


} // ns


#endif // inc guard
