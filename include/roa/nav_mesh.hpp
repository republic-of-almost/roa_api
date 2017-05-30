#ifndef NAV_MESH_INCLUDED_579F3269_8747_4302_A95F_A24505E25EBF
#define NAV_MESH_INCLUDED_579F3269_8747_4302_A95F_A24505E25EBF


#include <roa/foundation/types.hpp>
#include <roa/foundation/fwd.hpp>


namespace ROA {


class Nav_mesh final
{
public:

  explicit        Nav_mesh();
  
  
  // ----------------------------------------------------------- [ Settings ] --
  
  
  void            set_triangles(const float *tris, size_t tri_count);
  bool            ray_test(Ray ray, Vector3 &out_position);
  
private:

  struct Impl;
  Impl *m_impl;

};


} // ns


#endif // inc guard
