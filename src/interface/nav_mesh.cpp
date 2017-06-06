#include <roa/nav_mesh.hpp>
#include <roa/edge.hpp>
#include <roa/debug_line.hpp>
#include <roa/color.hpp>
#include <roa/ray.hpp>
#include <lib/assert.hpp>
#include <math/geometry/ray.hpp>
#include "helpers/math_extensions.hpp"


namespace ROA {


struct Nav_mesh::Impl
{
  float *tris;
  size_t tri_count;
};


Nav_mesh::Nav_mesh()
: m_impl(new Impl)
{
  m_impl->tris = nullptr;
  m_impl->tri_count = 0;
}
 
  
void
Nav_mesh::set_triangles(const float *tris, size_t tri_count)
{
  LIB_ASSERT(m_impl);
  
  if(!m_impl->tris)
  {
    free(m_impl->tris);
  }
  
  const size_t bytes = (tri_count * 3 * 3) * sizeof(float);
  
  m_impl->tris = (float*)malloc(bytes);
  
  if(m_impl->tris)
  {
    memcpy(m_impl->tris, tris, bytes);
    m_impl->tri_count = tri_count;
  }
}


float*
Nav_mesh::get_triangles() const
{
  LIB_ASSERT(m_impl);
  
  return m_impl->tris;
}


size_t
Nav_mesh::get_triangle_count() const
{
  LIB_ASSERT(m_impl);
  
  return m_impl->tri_count;
}


bool
Nav_mesh::ray_test(Ray ray, Vector3 &out_position)
{
  const math::vec3 origin = ROA_detail::vec3_init(ray.get_origin());
  const math::vec3 dir = ROA_detail::vec3_init(ray.get_direction());
  const math::vec3 end = math::vec3_add(origin, math::vec3_scale(dir, 10000000));

  const math::ray r = math::ray_init(origin, end);
  
  float out_distance = 0.f;
  if(math::ray_test_triangles(r, m_impl->tris, m_impl->tri_count, &out_distance))
  {
    const Vector3 scale = ray.get_direction().scale(out_distance);
    out_position = ray.get_origin().add(scale);
    
    return true;
  }

  return false;
}


bool
Nav_mesh::closest_edge(ROA::Vector3 pos, Edge &out_edge)
{
  math::vec3 seg[2];

  const bool match = math::ray_test_closest_edge(
    m_impl->tris,
    m_impl->tri_count,
    math::vec3_init(
      pos.x(),
      pos.y(),
      pos.z()
    ),
    seg[0],
    seg[1]
  );

  if(match)
  {
    out_edge.start_point = Vector3(math::get_x(seg[0]), math::get_y(seg[0]), math::get_z(seg[0]));
    out_edge.end_point   = Vector3(math::get_x(seg[1]), math::get_y(seg[1]), math::get_z(seg[1]));
  }
  
  return match;
}


} // ns
