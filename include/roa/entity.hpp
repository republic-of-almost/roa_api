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

  explicit        Entity(uint32_t instance);


public:


  explicit        Entity();
  
  
  // ------------------------------------------------------------ [ General ] --
  
  
  const char*     get_name() const;
  void            set_name(const char *new_name);
  
  void            set_parent(Entity entity);
//  void            set_parent(nullptr_t entity);
  Entity          get_parent() const;
  
  size_t          child_count() const;
  Entity          get_child(const size_t child);
  
  
  // --------------------------------------------------------------- [ Data ] --
  

  Transform       get_transform() const;
  void            set_transform(const Transform other);
  
  Camera          get_camera() const;
  void            set_camera(const Camera other);
  
  Material        get_material() const;
  void            set_material(const Material mat);
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t        get_type_id() const override;
  const char*     get_type_name() const override;
  const char*     get_instance_name() const override;

};


} // ns


#endif // inc guard
