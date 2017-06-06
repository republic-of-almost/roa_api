#ifndef AUDIO_PLAYER_INCLUDED_E10E2D47_44B1_4B60_8003_D105AFA28195
#define AUDIO_PLAYER_INCLUDED_E10E2D47_44B1_4B60_8003_D105AFA28195


#include <roa/object.hpp>
#include <roa/foundation/fwd.hpp>


namespace ROA {


class Audio_player : public Object
{
private:

  friend class Entity;

  explicit      Audio_player(uint32_t instance);

public:


  // ----------------------------------------------------------- [ Lifetime ] --


  explicit      Audio_player();
  
  
  // ----------------------------------------------------------- [ Settings ] --
  
  
  void          play();

  bool          is_playing() const;
  
  void          set_volume(float vol);
  float         get_volume() const;
  
  void          set_sample(Audio_sample &sample);
  Audio_sample  get_sample() const;
  
  
  // ---------------------------------------------------------- [ Inherited ] --
  
  
  uint32_t      get_type_id() const override;
  const char*   get_type_name() const override;
  const char*   get_instance_name() const override;

};


} // ns


#endif // inc guard
