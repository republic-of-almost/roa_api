#ifndef MATH_EXTENSIONS_INCLDUED_72C9E03E_532D_454E_B8A1_33C7B2C2F554
#define MATH_EXTENSIONS_INCLDUED_72C9E03E_532D_454E_B8A1_33C7B2C2F554


#include <math/fwd.hpp>
#include <roa/foundation/fwd.hpp>


namespace ROA_detail {


math::vec3
vec3_init(ROA::Vector3 vec);


ROA::Vector3
vec3_to_roa(math::vec3 vec);


math::quat
quat_init(ROA::Quaternion quat);


ROA::Quaternion
quat_to_roa(math::quat quat);



} // ns


#endif // inc guard
