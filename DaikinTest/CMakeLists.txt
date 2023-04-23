# CMakeList.txt : CMake project for DaikinTest, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DaikinTest "DaikinTest.cpp" "DaikinTest.h" "control.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DaikinTest PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
