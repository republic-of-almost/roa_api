#ifndef VECTOR3_INCLUDED_488B8225_A37E_4F03_AFC7_17C6EC2D6CA9
#define VECTOR3_INCLUDED_488B8225_A37E_4F03_AFC7_17C6EC2D6CA9


namespace ROA {


class Vector3
{
public:

  explicit      Vector3(float x = 0, float y = 0, float z = 0);
  
  float         x() const;
  float         y() const;
  float         z() const;
  
  void          set_x(float x);
  void          set_y(float y);
  void          set_z(float z);
  
private:

  float         m_data[3];

};


} // ns


#endif // inc guard
