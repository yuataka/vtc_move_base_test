cmake_minimum_required(VERSION 3.8.3)
project(unreal_robot_sim_2dnav)


find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  move_base_msgs
  cage_ros_bridge
  velodyne_pointcloud
  std_msgs
  geometry_msgs
  move_base_msgs
)

find_package(Boost REQUIRED COMPONENTS
  system
)


generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
  std_msgs
  geometry_msgs
  move_base_msgs
)

# include directories
include_directories(
	include
  ${BOOST_INCLUDE_DIRS}
	${catkin_INCLUDE_DIRS}
)

## link directories
#link_directories(
#	include
#	#${PCL_LIBRARY_DIRS}
#  	#${OpenCV_LIBRARY_DIRS}
# 	#${GTSAM_LIBRARY_DIRS}
#)

###########
## Build ##
###########

# Range Image Projection
add_executable(${PROJECT_NAME}_translateNavGoal src/translate_navgoal.cpp)
target_link_libraries(${PROJECT_NAME}_translateNavGoal ${catkin_LIBRARIES} )

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE)
