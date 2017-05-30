//#include <roa/mesh.hpp>
//#include <string.h>
//#include <utilities/assert.hpp>
//
//
//namespace ROA {
//
//
//struct Mesh::Impl
//{
//  float     *positions;
//  size_t    positions_count;
//  
//  float     *normals;
//  size_t    normals_count;
//  
//  float     *uvs;
//  size_t    uvs_count;
//  
//  uint32_t  *triangles;
//  size_t    tri_count;
//};
//
//
//Mesh::Mesh()
//: m_impl(new Impl)
//{
//  m_impl->positions = nullptr;
//  m_impl->positions_count = 0;
//  
//  m_impl->normals = nullptr;
//  m_impl->normals_count = 0;
//  
//  m_impl->uvs = nullptr;
//  m_impl->uvs_count = 0;
//  
//  m_impl->triangles = nullptr;
//  m_impl->tri_count = 0;
//}
//
//
//const float*
//Mesh::get_positions() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return nullptr;
//  }
//  
//  return m_impl->positions;
//}
//
//
//size_t
//Mesh::get_positions_count() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return 0;
//  }
//
//  return m_impl->positions_count;
//}
//
//
//void
//Mesh::set_positions(const float pos[], size_t count)
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return;
//  }
//  
//  if(m_impl->positions)
//  {
//    free(m_impl->positions);
//  }
//  
//  const size_t bytes_to_alloc = sizeof(float) * (count * 3);
//  
//  m_impl->positions = (float*)malloc(bytes_to_alloc);
//  
//  if(m_impl->positions)
//  {
//    memcpy(m_impl->positions, pos, bytes_to_alloc);
//  }
//  else
//  {
//    LOG_ERROR("Failed to apply positions");
//  }
//}
//
//
//const float*
//Mesh::get_normals() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return nullptr;
//  }
//
//  return m_impl->normals;
//}
//
//
//size_t
//Mesh::get_normals_count() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return 0;
//  }
//
//  return m_impl->normals_count;
//}
//
//
//void
//Mesh::set_normals(const float norms[], size_t count)
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return;
//  }
//  
//  if(m_impl->normals)
//  {
//    free(m_impl->normals);
//  }
//  
//  const size_t bytes_to_alloc = sizeof(float) * (count * 3);
//  
//  m_impl->normals = (float*)malloc(bytes_to_alloc);
//  
//  if(m_impl->normals)
//  {
//    memcpy(m_impl->normals, norms, bytes_to_alloc);
//  }
//  else
//  {
//    LOG_ERROR("Failed to apply normals");
//  }
//}
//
//
//const float*
//Mesh::get_uvs() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return nullptr;
//  }
//
//  return m_impl->uvs;
//}
//
//
//size_t
//Mesh::get_uvs_count() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return 0;
//  }
//
//  return m_impl->uvs_count;
//}
//
//
//void
//Mesh::set_uvs(const float uvs[], size_t count)
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return;
//  }
//  
//  if(m_impl->uvs)
//  {
//    free(m_impl->uvs);
//  }
//  
//  const size_t bytes_to_alloc = sizeof(float) * (count * 2);
//  
//  m_impl->uvs = (float*)malloc(bytes_to_alloc);
//  
//  if(m_impl->uvs)
//  {
//    memcpy(m_impl->normals, uvs, bytes_to_alloc);
//  }
//  else
//  {
//    LOG_ERROR("Failed to apply uvs");
//  }
//}
//
//
//const uint32_t*
//Mesh::get_triangles()
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return nullptr;
//  }
//
//  return m_impl->triangles;
//}
//
//
//size_t
//Mesh::get_triangles_count() const
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return 0;
//  }
//
//  return m_impl->tri_count;
//}
//
//
//void
//Mesh::set_triangles(const uint32_t tris[], size_t count)
//{
//  LIB_ASSERT(m_impl);
//  
//  if(!m_impl)
//  {
//    return;
//  }
//  
//  if(m_impl->triangles)
//  {
//    free(m_impl->triangles);
//  }
//  
//  const size_t bytes_to_alloc = sizeof(uint32_t) * (count * 3);
//  
//  m_impl->triangles = (uint32_t*)malloc(bytes_to_alloc);
//  
//  if(m_impl->triangles)
//  {
//    memcpy(m_impl->triangles, tris, bytes_to_alloc);
//  }
//  else
//  {
//    LOG_ERROR("Failed to apply triangles");
//  }
//}
//
//
//} // ns
