#include <roa/material.hpp>
#include <roa/color.hpp>
#include <roa/foundation/type_ids.hpp>
#include <nil/node.hpp>
#include <nil/data/material.hpp>
#include <utilities/logging.hpp>
#include <utilities/assert.hpp>


namespace {


constexpr char material_type_name[] = "Material";


} // anon ns


namespace ROA {


Material::Material(uint32_t instance_id)
: Object(instance_id)
{
}


Material::Material()
: Object()
{
  Nil::Node node(get_instance());
  Nil::Data::Material data{};
  Nil::Data::set(node, data);
}


// ------------------------------------------------------------- [ Settings ] --


Color
Material::get_color() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Material data{};
  Nil::Data::get(node, data);
  
  return Color(
    data.color[0],
    data.color[1],
    data.color[2],
    data.color[3]
  );
}


void
Material::set_color(Color col)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Material data{};
  Nil::Data::get(node, data);
  
  data.color[0] = col.get_red_f();
  data.color[1] = col.get_green_f();
  data.color[2] = col.get_blue_f();
  data.color[3] = col.get_alpha_f();
  
  Nil::Data::set(node, data);
}


uint32_t
Material::get_shader_type() const
{
  const Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Material data{};
  Nil::Data::get(node, data);
  
  return data.shader;
}


void
Material::set_shader_type(uint32_t id)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Material data{};
  Nil::Data::get(node, data);
  
  data.shader = id;
  
  Nil::Data::set(node, data);
}


// ------------------------------------------------------------ [ Inherited ] --
  
  
uint32_t
Material::get_type_id() const
{
  return ROA::Type::Material_ID;
}


const char*
Material::get_type_name() const
{
  return material_type_name;
}


const char*
Material::get_instance_name() const
{
  return Object::get_instance_name();
}




} // ns
