#ifndef DEBUG_LINE_INCLUDED_6DDC3357_2BF2_4FA0_B06D_08F21C3A9D6F
#define DEBUG_LINE_INCLUDED_6DDC3357_2BF2_4FA0_B06D_08F21C3A9D6F


#include <roa/foundation/fwd.hpp>


namespace ROA {
namespace Debug {


void
draw_line(Vector3 start, Vector3 end, Color color);

void
draw_line(Nav_mesh mesh, Color color);


} // ns
} // ns


#endif // inc guard
