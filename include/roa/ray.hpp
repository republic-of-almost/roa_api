#ifndef RAY_INCLUDED_0B069DA4_26DE_4651_B6E4_D3ACEDA67E1B
#define RAY_INCLUDED_0B069DA4_26DE_4651_B6E4_D3ACEDA67E1B


#include <roa/vector3.hpp>


namespace ROA {


class Ray final
{
public:

  explicit          Ray(Vector3 origin, Vector3 direction);

  Vector3           get_origin() const;
  Vector3           get_direction() const;

private:

  Vector3           m_origin;
  Vector3           m_direction;

};


} // ns


#endif // inc guard
