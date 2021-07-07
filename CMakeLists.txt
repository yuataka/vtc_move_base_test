cmake_minimum_required(VERSION 3.8.3)
project(unreal_robot_sim_2dnav)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -pthread")

find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  # rospy
  move_base_msgs
  cage_ros_bridge
  velodyne_pointcloud
  # cv_bridge
  # pcl library
  # pcl_conversions
  # msgs
  std_msgs
  # sensor_msgs
  geometry_msgs
  move_base_msgs
  # nav_msgs
  # message_generation
  # visualization_msgs
)

#find_package(OpenMP REQUIRED)
#find_package(PCL REQUIRED QUIET)
#find_package(OpenCV REQUIRED QUIET)
#find_package(GTSAM REQUIRED QUIET)
#find_package(Boost REQUIRED COMPONENTS timer)

#add_message_files(
#  DIRECTORY msg
#  FILES
#  cloud_info.msg
#)
#
#add_service_files(
#  DIRECTORY srv
#  FILES
#  save_map.srv
#)

generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs
  nav_msgs
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
  #DEPENDS PCL GTSAM

  CATKIN_DEPENDS
  std_msgs
  #nav_msgs
  geometry_msgs
  #sensor_msgs
  move_base_msgs
  #message_runtime
  #message_generation
  #visualization_msgs
)

# include directories
include_directories(
	include
	${catkin_INCLUDE_DIRS}
	#${PCL_INCLUDE_DIRS}
 	#${OpenCV_INCLUDE_DIRS}
	#${GTSAM_INCLUDE_DIR}
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


