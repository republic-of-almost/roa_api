#include <roa/application.hpp>
#include <roa/foundation/type_ids.hpp>
#include <data/data.hpp>
#include <nil/node.hpp>
#include <nil/data/window.hpp>
#include <utilities/logging.hpp>
#include <utilities/assert.hpp>
#include <math/general/general.hpp>
#include <string.h>


namespace {


constexpr char app_msg_no_win_data[]  = "No window data found";
constexpr char app_msg_no_duplicate[] = "Cannot create two applications";
constexpr char app_node_name[]        = "roa-ctx";
constexpr char app_input_node_name[]  = "roa-input";
constexpr char app_mice_node_name[]   = "roa-mice";
constexpr char app_kb_node_name[]     = "roa-kbs";
constexpr char app_gp_node_name[]     = "roa-gps";
constexpr char app_type_name[]        = "Application";


} // anon ns


namespace ROA {



Application::Application()
: Object()
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  /*
    If not setup else log an error as we don't support two apps
  */
  if(ctx_node.is_valid() && strcmp(ctx_node.get_name(), app_node_name) != 0)
  {
    ctx_node.set_name(app_node_name);
    
    Nil::Data::Window win_data{};
    Nil::Data::set(ctx_node, win_data);
    
    // Setup some other nodes.
    Nil::Node input_node;
    input_node.set_name(app_input_node_name);
    input_node.set_parent(ctx_node);
    
    ROA_detail::get_mice_node().set_parent(input_node);
    ROA_detail::get_mice_node().set_name(app_mice_node_name);
    
    ROA_detail::get_keyboards_node().set_parent(input_node);
    ROA_detail::get_keyboards_node().set_name(app_kb_node_name);
    
    ROA_detail::get_gamepads_node().set_parent(input_node);
    ROA_detail::get_gamepads_node().set_name(app_gp_node_name);
  }
  else
  {
    LOG_ERROR(app_msg_no_duplicate);
  }
  
  set_instance_id(ctx_node.get_id());
}


Application::~Application()
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());

  if(ctx_node.is_valid())
  {
    ctx_node.destroy();
  }
}


// ------------------------------------------------------------- [ Settings ] --


const char*
Application::get_title() const
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
    
    static char title[32];
    memcpy(title, win_data.title, math::min(sizeof(title), sizeof(win_data.title)));
    
    return title;
  }
  
  LOG_FATAL(app_msg_no_win_data);
  return "";
}


void
Application::set_title(const char *title)
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
    
    memcpy(win_data.title, title, math::min(sizeof(title), sizeof(win_data.title)));
    
    Nil::Data::set(ctx_node, win_data);
    
    return;
  }
  
  LOG_FATAL(app_msg_no_win_data)
}


uint32_t
Application::get_width() const
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
  
    return win_data.width;
  }
  
  LOG_FATAL(app_msg_no_win_data)
  
  return 0;
}


void
Application::set_width(const uint32_t width)
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
  
    win_data.width = width;
    
    Nil::Data::set(ctx_node, win_data);
    
    return;
  }
  
  LOG_FATAL(app_msg_no_win_data)
}


uint32_t
Application::get_height() const
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
    
    return win_data.height;
  }
  
  LOG_FATAL(app_msg_no_win_data)
  
  return 0;
}


void
Application::set_height(const uint32_t height)
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
  
    win_data.height = height;
    
    Nil::Data::set(ctx_node, win_data);
    
    return;
  }
  
  LOG_FATAL(app_msg_no_win_data)
}


bool
Application::is_fullscreen() const
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
  
    return win_data.fullscreen;
  }
  
  LOG_FATAL(app_msg_no_win_data)
  
  return false;
}


void
set_fullscreen(const bool set)
{
  Nil::Node ctx_node = ROA_detail::get_context_node();
  LIB_ASSERT(ctx_node.is_valid());
  
  if(Nil::Data::has_window(ctx_node))
  {
    Nil::Data::Window win_data{};
    Nil::Data::get(ctx_node, win_data);
  
    win_data.fullscreen = set;
    
    Nil::Data::set(ctx_node, win_data);
    
    return;
  }
  
  LOG_FATAL(app_msg_no_win_data)
}


// ------------------------------------------------------------ [ Inherited ] --
  
  
uint32_t
Application::get_type_id() const
{
  return ROA::Type::Application_ID;
}


const char*
Application::get_type_name() const
{
  return app_type_name;
}


const char*
Application::get_instance_name() const
{
  return app_node_name;
}


} // ns
