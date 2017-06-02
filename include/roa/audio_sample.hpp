#ifndef AUDIO_SAMPLE_INCLUDED_3FBBAD39_91D4_4FB5_AA92_CA90E8D2A18E
#define AUDIO_SAMPLE_INCLUDED_3FBBAD39_91D4_4FB5_AA92_CA90E8D2A18E


#include <roa/object.hpp>


namespace ROA {


class Audio_sample : public Object
{
public:


  // ----------------------------------------------------------- [ Lifetime ] --


  explicit          Audio_sample();
  explicit          Audio_sample(const char *filename);
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t          get_type_id() const override;
  const char*       get_type_name() const override;
  const char*       get_instance_name() const override;
  
};


} // ns


#endif // inc guard
