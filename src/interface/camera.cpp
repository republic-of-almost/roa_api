#include <roa/camera.hpp>
#include <roa/foundation/type_ids.hpp>
#include <roa/object.hpp>
#include <roa/color.hpp>
#include <nil/node.hpp>
#include <nil/data/camera.hpp>
#include <utilities/assert.hpp>


namespace ROA {


Camera::Camera(Object obj)
: Object(obj.get_instance())
{
  
}


Camera::Camera()
: Object()
{
  Nil::Node node(get_instance());
  Nil::Data::Camera data{};
  Nil::Data::set(node, data);
}


// ------------------------------------------------------------- [ Settings ] --


void
Camera::set_priority(const uint32_t id)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.priority = id;
    
    Nil::Data::set(node, data);
  }
}


uint32_t
Camera::get_priority() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    return data.priority;
  }
  
  LIB_ASSERT(false); // no data
  
  return 0;
}


void
Camera::set_width(float width)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.width = width;
    
    Nil::Data::set(node, data);
  }
}


float
Camera::get_width() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    return data.width;
  }
  
  LIB_ASSERT(false); // no data
  
  return 0;
}


void
Camera::get_height(float height)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.height = height;
    
    Nil::Data::set(node, data);
  }
}


float
Camera::get_height() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    return data.height;
  }
  
  LIB_ASSERT(false); // no data
  
  return 0;
}


void
Camera::set_fov(float fov)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.fov = fov;
    
    Nil::Data::set(node, data);
  }
}


float
Camera::get_fov() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    return data.fov;
  }
  
  LIB_ASSERT(false); // no data
  
  return 0;
}


void
Camera::set_near_plane(float plane)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.near_plane = plane;
    
    Nil::Data::set(node, data);
  }
}


float
Camera::get_near_plane() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    return data.near_plane;
  }
  
  LIB_ASSERT(false); // no data
  
  return 0;
}


void
Camera::set_far_plane(float plane)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.far_plane = plane;
    
    Nil::Data::set(node, data);
  }
}


float
Camera::get_far_plane() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    return data.far_plane;
  }
  
  LIB_ASSERT(false); // no data
  
  return 0;
}


void
Camera::set_clear_color(Color color)
{
}


Color
Camera::get_clear_color() const
{
}


void
Camera::clear_color_buffer(bool set)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.clear_color_buffer = set;
    
    Nil::Data::set(node, data);
  }
}


void
Camera::clear_depth_buffer(bool set)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  if(Nil::Data::has_camera(node))
  {
    Nil::Data::Camera data{};
    Nil::Data::get(node, data);

    data.clear_depth_buffer = set;
    
    Nil::Data::set(node, data);
  }
}


// ------------------------------------------------------------ [ Inherited ] --


uint32_t
Camera::get_type_id() const
{
  return ROA::Type::Camera_ID;
}


const char*
Camera::get_type_name() const
{
  return "Camera";
}


const char*
Camera::get_instance_name() const
{
  Object::get_instance_name();
}


} // ns
