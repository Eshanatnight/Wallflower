-- premake5.lua
workspace "WallflowerApp"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "WallflowerApp"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "WallflowerExternal.lua"
include "WallflowerApp"