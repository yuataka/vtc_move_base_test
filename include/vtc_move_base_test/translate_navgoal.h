#ifndef TRANSLATE__NAVGOAL_H
#define TRANSLATE__NAVGOAL_H

#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "move_base_msgs/MoveBaseActionGoal.h"

namespace translatenavgoal {
class translateNavGoal
{
public:
	bool setup(ros::NodeHandle &node);
	void callback(const geometry_msgs::PoseStamped::ConstPtr& goal_msg);
	void set(const geometry_msgs::PoseStamped::ConstPtr& goal_msg, move_base_msgs::MoveBaseActionGoalPtr& pub_goal);
private:
	static int goal_id;
	move_base_msgs::MoveBaseActionGoal action_goal;
	move_base_msgs::MoveBaseActionGoalPtr pub_goal;
	ros::Subscriber simple_goal_subscriber;
	ros::Publisher move_base_goal_publisher;
};
} //namepsace translatenavgoal

#endif //TRANSLATE__NAVGOAL_H