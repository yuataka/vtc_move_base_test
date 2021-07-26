# vtc_move_base_test
This repository written for testing ros move_base package in [VTC](https://github.com/furo-org/VTC). VTC is a robot simulator working on Unreal Engine 4. This package can move the robot in VTC by nav_goal on rviz.

## Dependency
About VTC install, see this [page](https://github.com/furo-org/VTC/blob/TC2020/docs/editor.md).
 * ROS (tested with Melodic)
 * [cage_ros_stack](https://github.com/furo-org/cage_ros_stack)
 * [VTC](https://github.com/furo-org/VTC) (Install the other Windows-PC)

 ## Install

 ```
 cd ~/catkin_ws/src
 git clone https://github.com/yuataka/vtc_move_base_test.git
 cd ..
 catkin_make
 ```

  ## Run this package
   1. Run VTC in the other windows PC.
   2. Run cage_ros_stack launch file in Linux PC:

   ```
   roslaunch vtc_bringup bringup.launch ip:=[your linux PC IP address]
   ```

   3. Run the launch file including move_base and other packages:

   ```
   roslaunch vtc_move_base_test vtc_map_move.launch 
   ```