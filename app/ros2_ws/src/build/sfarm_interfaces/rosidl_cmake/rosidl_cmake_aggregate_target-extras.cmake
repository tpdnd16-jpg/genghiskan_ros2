# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target sfarm_interfaces::sfarm_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${sfarm_interfaces_TARGETS}.
if(sfarm_interfaces_TARGETS AND NOT TARGET sfarm_interfaces::sfarm_interfaces)
  add_library(sfarm_interfaces::sfarm_interfaces INTERFACE IMPORTED)
  set_target_properties(sfarm_interfaces::sfarm_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${sfarm_interfaces_TARGETS}")
endif()
