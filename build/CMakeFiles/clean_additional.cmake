# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtExceptions_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtExceptions_autogen.dir\\ParseCache.txt"
  "QtExceptions_autogen"
  "test\\CMakeFiles\\QtExceptionsTest_autogen.dir\\AutogenUsed.txt"
  "test\\CMakeFiles\\QtExceptionsTest_autogen.dir\\ParseCache.txt"
  "test\\QtExceptionsTest_autogen"
  )
endif()
