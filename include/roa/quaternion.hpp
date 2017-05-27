#ifndef QUATERNION_INCLUDED_AF22D8AC_6EAD_43DB_B588_903FB0720342
#define QUATERNION_INCLUDED_AF22D8AC_6EAD_43DB_B588_903FB0720342


namespace ROA {


class Quaternion
{
public:

  explicit  Quaternion(float x, float y, float z, float w);

  float     x() const;
  float     y() const;
  float     z() const;
  float     w() const;
  
private:

  float     m_data[4];

};


} // ns


#endif // inc guard
