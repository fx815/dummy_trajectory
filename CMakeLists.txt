cmake_minimum_required(VERSION 2.8.3)
project(dummy_trajectory)

find_package(catkin REQUIRED COMPONENTS roscpp mavros mavros_msgs mavros_extras std_msgs geometry_msgs nav_msgs)
include_directories(include ${catkin_INCLUDE_DIRS})

find_package(cmake_modules REQUIRED)


#add_message_files(
#  FILES
#)

#add_service_files(
 # FILES
  #PlannerService.srv
  #PolygonService.srv
#)

#generate_messages(
#  DEPENDENCIES std_msgs
#)

catkin_package(
  CATKIN_DEPENDS roscpp mavros_msgs std_msgs
)

add_executable(dummy_trajectory src/dummy_trajectory.cpp)
target_link_libraries(dummy_trajectory ${catkin_LIBRARIES})