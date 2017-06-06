#include <roa/audio_player.hpp>
#include <roa/audio_sample.hpp>
#include <roa/foundation/type_ids.hpp>
#include <nil/node.hpp>
#include <nil/data/audio.hpp>
#include <nil/data/audio_resource.hpp>
#include <lib/assert.hpp>
#include <math/math.hpp>


namespace {


constexpr char audio_player_type_name[] = "Audio Player";


} // anon ns


namespace ROA {


// ------------------------------------------------------------- [ Lifetime ] --


Audio_player::Audio_player(uint32_t instance)
: Object(instance)
{

}


Audio_player::Audio_player()
: Object()
{

}


// ------------------------------------------------------------- [ Settings ] --


void
Audio_player::play()
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Audio data{};
  Nil::Data::get(node, data);
  
  if(data.request_state != Nil::Data::Audio::PLAY &&
     data.current_state != Nil::Data::Audio::PLAYING)
  {
    data.request_state = Nil::Data::Audio::PLAY;
    Nil::Data::set(node, data);
  }
}


bool
Audio_player::is_playing() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Audio data{};
  Nil::Data::get(node, data);
  
  return data.current_state == Nil::Data::Audio::PLAYING;
}


void
Audio_player::set_volume(float vol)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Audio data{};
  Nil::Data::get(node, data);
  
  data.volume = math::clamp(vol, 0.f, 1.f);
  
  Nil::Data::set(node, data);
}


float
Audio_player::get_volume() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Audio data{};
  Nil::Data::get(node, data);
  
  return data.volume;
}


void
Audio_player::set_sample(Audio_sample &sample)
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Audio data{};
  Nil::Data::get(node, data);
  
  Nil::Node sample_node(sample.get_instance());
  LIB_ASSERT(sample_node.is_valid());
  LIB_ASSERT(Nil::Data::has_audio_resource(sample_node));
  
  Nil::Data::Audio_resource sample_data{};
  Nil::Data::get(sample_node, sample_data);
  
  data.audio_id = sample_data.id;
  
  Nil::Data::set(node, data);
}


Audio_sample
Audio_player::get_sample() const
{
  Nil::Node node(get_instance());
  LIB_ASSERT(node.is_valid());
  
  Nil::Data::Audio data{};
  Nil::Data::get(node, data);
  
  LIB_ASSERT(false); // not impl
  
  return Audio_sample();
}


// ------------------------------------------------------------ [ Inherited ] --


uint32_t
Audio_player::get_type_id() const
{
  return Type::Audio_player_ID;
}


const char*
Audio_player::get_type_name() const
{
  return audio_player_type_name;
}


const char*
Audio_player::get_instance_name() const
{
  return Object::get_instance_name();
}


} // ns
