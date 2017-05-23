#include <roa/camera.hpp>
#include <roa/object.hpp>
#include <roa/color.hpp>


namespace ROA {


Camera::Camera(Object obj)
: Object(obj.get_instance())
{
}


Camera::Camera()
: Object()
{
}


// ------------------------------------------------------------- [ Settings ] --


void
Camera::set_priority(const uint32_t id)
{
}


uint32_t
Camera::get_priority() const
{
}


void
Camera::set_width(float width)
{
}


float
Camera::get_width() const
{
}


void
Camera::get_height(float height)
{
}


float
Camera::get_height() const
{
}


void
Camera::set_fov(float fov)
{
}


float
Camera::get_fov() const
{
}


void
Camera::set_near_plane(float plane)
{
}


float
Camera::get_near_plane() const
{
}


void
Camera::set_far_plane(float plane)
{
}


float
Camera::get_far_plane() const
{
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
}


void
Camera::clear_depth_buffer(bool set)
{
}


// ------------------------------------------------------------ [ Inherited ] --


uint32_t
Camera::get_type_id() const
{
}


const char*
Camera::get_type_name() const
{
}


const char*
Camera::get_instance_name() const
{
}


} // ns
