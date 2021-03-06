#ifndef MATERIAL_INCLUDED_1CE3A2CD_20E6_4092_A089_2CDC11F5F671
#define MATERIAL_INCLUDED_1CE3A2CD_20E6_4092_A089_2CDC11F5F671


#include <roa/foundation/fwd.hpp>
#include <roa/foundation/types.hpp>
#include <roa/object.hpp>


namespace ROA {


constexpr uint32_t ShaderID_fullbright        = 0;
constexpr uint32_t ShaderID_light             = 1;
constexpr uint32_t ShaderID_directionalLight  = 2;


class Material : public Object
{
private:

  friend class      Entity;
  
  explicit          Material(uint32_t instance_id);
  
public:

  explicit          Material();
  
  
  // ----------------------------------------------------------- [ Settings ] --
  
  
  Color             get_color() const;
  void              set_color(Color color);
  
  
  uint32_t          get_shader_type() const;
  void              set_shader_type(uint32_t id);
  

  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t          get_type_id() const override;
  const char*       get_type_name() const override;
  const char*       get_instance_name() const override;
  
};


} // ns


#endif // inc guard
