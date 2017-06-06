#ifndef TRANSFORM_INCLUDED_456E7614_47F6_4B87_8160_3E59B89F1C26
#define TRANSFORM_INCLUDED_456E7614_47F6_4B87_8160_3E59B89F1C26


#include <roa/object.hpp>
#include <roa/foundation/fwd.hpp>
#include <roa/foundation/types.hpp>


namespace ROA {


class Transform : public Object
{
  friend class    Entity;

  explicit        Transform(uint32_t instance_id);

public:

  explicit        Transform();
  
  
  // ----------------------------------------------------------- [ Settings ] --
  
  
  Vector3         get_position() const;
  void            set_position(Vector3 pos);

  Vector3         get_scale() const;
  void            set_scale(Vector3 scale);

  Quaternion      get_rotation() const;
  void            set_rotation(Quaternion quat);

  Vector3         get_forward() const;
  Vector3         get_up() const;
  Vector3         get_left() const;
  
  static Vector3  get_world_forward();
  static Vector3  get_world_up();
  static Vector3  get_world_left();
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t        get_type_id() const override;
  const char*     get_type_name() const override;
  const char*     get_instance_name() const override;

};


} // ns


#endif // inc guard
