# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GUIZork-MM_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GUIZork-MM_autogen.dir\\ParseCache.txt"
  "GUIZork-MM_autogen"
  )
endif()
