#include <roa/audio_sample.hpp>
#include <roa/foundation/type_ids.hpp>


namespace {


constexpr char audio_sample_name[] = "Audio Sample";


} // anon ns


namespace ROA {


// ------------------------------------------------------------- [ Lifetime ] --


Audio_sample::Audio_sample()
: Object()
{
}


Audio_sample::Audio_sample(const char *filename)
{
}


// ------------------------------------------------------------ [ Inherited ] --


uint32_t
Audio_sample::get_type_id() const
{
  return ROA::Type::Audio_sample_ID;
}


const char*
Audio_sample::get_type_name() const
{
  return audio_sample_name;
}


const char*
Audio_sample::get_instance_name() const
{
  return Object::get_instance_name();
}



} // ns
