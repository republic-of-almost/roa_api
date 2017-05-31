#include <roa/debug_line.hpp>
#include <roa/vector3.hpp>
#include <roa/nav_mesh.hpp>
#include <roa/color.hpp>
#include "../data/data.hpp"
#include <nil/node.hpp>
#include <nil/data/developer.hpp>
#include <utilities/array.hpp>


namespace {


constexpr char dbg_line_data_name[] = "roa-dbg-line";
lib::array<float> line_data;


} // anon ns


namespace ROA {
namespace Debug {


void
draw_line(Vector3 start, Vector3 end, Color color)
{
  Nil::Node node = ROA_detail::get_debug_line_node();

  if(strcmp(node.get_name(), dbg_line_data_name) != 0)
  {
    node.set_name(dbg_line_data_name);

    line_data.resize(128);

    Nil::Data::Developer dev{};
    dev.type_id = 2;

    Nil::Data::set(node, dev);
  }

  Nil::Data::Developer dev{};
  Nil::Data::get(node, dev);

  if(dev.aux_02 == 0)
  {
    line_data.clear();
  }

  line_data.emplace_back(start.x());
  line_data.emplace_back(start.y());
  line_data.emplace_back(start.z());

  line_data.emplace_back(end.x());
  line_data.emplace_back(end.y());
  line_data.emplace_back(end.z());

  line_data.emplace_back(color.get_red_f());
  line_data.emplace_back(color.get_green_f());
  line_data.emplace_back(color.get_blue_f());

  // Update data

  dev.aux_01 = (uintptr_t)line_data.data();
  dev.aux_02 = (uintptr_t)line_data.size();
  Nil::Data::set(node, dev);
}


void
draw_line(Nav_mesh mesh, Color color)
{
  const float *tris = mesh.get_triangles();
  const size_t count = mesh.get_triangle_count();
  
  for(size_t i = 0; i < count; ++i)
  {
    const size_t index = i * 9;
    
    Vector3 v0(tris[index + 0], tris[index + 1], tris[index + 2]);
    Vector3 v1(tris[index + 3], tris[index + 4], tris[index + 5]);
    Vector3 v2(tris[index + 6], tris[index + 7], tris[index + 8]);
    
    draw_line(v0, v1, color);
    draw_line(v1, v2, color);
    draw_line(v2, v0, color);
  }
}


} // ns
} // ns
