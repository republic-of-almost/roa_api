#include <roa/nav_mesh.hpp>
#include <roa/ray.hpp>
#include <utilities/assert.hpp>
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


bool
Nav_mesh::ray_test(Ray ray, Vector3 &out_position)
{
  const math::vec3 origin = ROA_detail::vec3_init(ray.get_origin());
  const math::vec3 dir = ROA_detail::vec3_init(ray.get_direction());
  const math::vec3 end = math::vec3_add(origin, math::vec3_scale(dir, 10000000));

  const math::ray r = math::ray_init(origin, end);
  
  float out_distance = 0.f;
  if(math::ray_test_triangles(r, m_impl->tris, m_impl->tri_count), &out_distance)
  {
   
    return true;
  }

  return false;
}


} // ns
