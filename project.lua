#!lua

--[[
  Republic of Almost Project Description
]]--

table.insert(
  projects,
  {
    name     = "ROA",
    kind     = "StaticLib",
    language = "C++",
    location = make.get_proj_root(),

    src_files = {
      make.add_headers(make.get_proj_root()),
      make.add_src(make.get_proj_root()),
      make.add_doc(make.get_proj_root()),
    },

    project_dependencies = {
      "Nil",
      "Utilities",
      "Math",
      "Aspects",
    },

    inc_dirs = {
      make.get_proj_root() .. "include/",
      make.get_proj_root() .. "src/",
    },
  }
)
