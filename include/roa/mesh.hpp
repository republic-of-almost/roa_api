//#ifndef MESH_INCLUDED_4B64FE7F_6EE1_42B9_898C_AD760881BE20
//#define MESH_INCLUDED_4B64FE7F_6EE1_42B9_898C_AD760881BE20
//
//
//#include <roa/object.hpp>
//#include <roa/foundation/types.hpp>
//
//
//namespace ROA {
//
//
//class Mesh final : Object
//{
//public:
//
//  explicit          Mesh();
//  
//  
//  // ----------------------------------------------------------- [ Settings ] --
//  
//  
//  const float*      get_positions() const;
//  size_t            get_positions_count() const;
//  void              set_positions(const float pos[], size_t count);
//  
//  const float*      get_normals() const;
//  size_t            get_normals_count() const;
//  void              set_normals(const float norms[], size_t count);
//  
//  const float*      get_uvs() const;
//  size_t            get_uvs_count() const;
//  void              set_uvs(const float uvs[], size_t count);
//  
//  const uint32_t*   get_triangles();
//  size_t            get_triangles_count() const;
//  void              set_triangles(const uint32_t tris[], size_t count);
//  
//  
//  // ---------------------------------------------------------- [ Inherited ] --
//  
//  
//  uint32_t          get_type_id() const override;
//  const char*       get_type_name() const override;
//  const char*       get_instance_name() const override;
//
//};
//
//
//} // ns
//
//
//#endif // inc guard
