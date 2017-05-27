#ifndef CAMERA_INCLUDED_53CA25DF_61B5_43B2_875D_2D47735BA051
#define CAMERA_INCLUDED_53CA25DF_61B5_43B2_875D_2D47735BA051


#include <roa/object.hpp>
#include <roa/foundation/fwd.hpp>
#include <roa/foundation/types.hpp>


namespace ROA {


class Camera : public Object
{
private:

  friend class Entity;

  explicit      Camera(uint32_t obj);

public:

  explicit      Camera();

  // ----------------------------------------------------------- [ Settings ] --
  
  void          set_priority(const uint32_t id);
  uint32_t      get_priority() const;
  
  void          set_width(float width);
  float         get_width() const;
  
  void          set_height(float height);
  float         get_height() const;
  
  void          set_fov(float fov);
  float         get_fov() const;
  
  void          set_near_plane(float plane);
  float         get_near_plane() const;
  
  void          set_far_plane(float plane);
  float         get_far_plane() const;
  
  void          set_clear_color(Color color);
  Color         get_clear_color() const;
  
  void          set_clear_color_buffer(bool set);
  bool          get_clear_color_buffer() const;
  
  void          set_clear_depth_buffer(bool set);
  bool          get_clear_depth_buffer() const;
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  uint32_t      get_type_id() const override;
  const char*   get_type_name() const override;
  const char*   get_instance_name() const override;
  

};


} // ns


#endif // inc guard
