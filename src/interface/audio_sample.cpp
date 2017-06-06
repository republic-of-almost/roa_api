#include <roa/audio_sample.hpp>
#include <roa/foundation/type_ids.hpp>
#include "../data/data.hpp"
#include <nil/data/data.hpp>
#include <nil/node.hpp>
#include <lib/logging.hpp>
#include <lib/assert.hpp>
#include <stdlib.h>
#include <string.h>


namespace {


constexpr char audio_sample_name[]      = "Audio Sample";
constexpr char audio_node_name[]        = "roa-audio";


} // anon ns


namespace ROA {


// ------------------------------------------------------------- [ Lifetime ] --


Audio_sample::Audio_sample()
: Object(nullptr)
{
}


Audio_sample::Audio_sample(const char *name)
: Object(nullptr)
{
  // Search for child with name that matches.
  // This is really crappy but unsure whats the best from API point
  Nil::Node audio_node = ROA_detail::get_audio_sample_node();
  
  const size_t children = audio_node.get_child_count();
  
  for(size_t i = 0; i < children; ++i)
  {
    Nil::Node child_node = audio_node.get_child(i);
    
    if(strcmp(name, child_node.get_name()) == 0)
    {
      LIB_ASSERT(Nil::Data::has_audio_resource(child_node));
    
      set_instance_id(child_node.get_id());
      break;
    }
  }
}


Audio_sample::Audio_sample(const char *name, const char *filename)
: Object(nullptr)
{
  Nil::Node audio_node = ROA_detail::get_audio_sample_node();

  if(strcmp(audio_node.get_name(), audio_node_name) != 0)
  {
    audio_node.set_name(audio_node_name);
  }

  // Check to see if this node exists
  const size_t child_count = audio_node.get_child_count();
  
  for(size_t i = 0; i < child_count; ++i)
  {
    Nil::Node child = audio_node.get_child(i);
    
    if(strcmp(child.get_name(), name) == 0)
    {
      LOG_WARNING("This sample was already loaded");
      set_instance_id(child.get_id());
      return;
    }
  }
  
  Nil::Node new_audio_sample;
  new_audio_sample.set_name(name);
  new_audio_sample.set_parent(audio_node);
  set_instance_id(new_audio_sample.get_id());
  
  Nil::Data::Audio_resource data{};
  
  const size_t sizeof_filename = sizeof(char) * strlen(filename);
  
  LOG_TODO("Leak");
  
  data.filename = (char*)malloc(sizeof_filename);
  memset(data.filename, 0, sizeof(sizeof_filename));
  
  data.id = new_audio_sample.get_id();
  strcat(data.filename, filename);
  
  Nil::Data::set(new_audio_sample, data);
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
