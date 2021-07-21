#include "string"
#include "memory"
#include "boost/bind.hpp"
#include "boost/pointer_cast.hpp"
#include "ros/ros.h"

#include "geometry_msgs/PoseStamped.h"
#include "move_base_msgs/MoveBaseActionGoal.h"

#include "unreal_robot_sim_2dnav/translate_navgoal.h"

namespace translatenavgoal {
int translatenavgoal::translateNavGoal::goal_id;

bool translateNavGoal::setup(ros::NodeHandle &node)
{
	simple_goal_subscriber = node.subscribe<geometry_msgs::PoseStamped>("move_base_simple/goal", 20, boost::bind(&translateNavGoal::callback, this, _1));
	move_base_goal_publisher = node.advertise<move_base_msgs::MoveBaseActionGoal>("move_base/move/goal", 20);
}

void translateNavGoal::callback(const geometry_msgs::PoseStamped::ConstPtr& goal_msg)
{
	boost::shared_ptr<move_base_msgs::MoveBaseActionGoal> pub_goal = boost::make_shared<move_base_msgs::MoveBaseActionGoal>(action_goal);
	ROS_INFO("callbak start. Goal_ID %d", goal_id);
	translateNavGoal::set(goal_msg, pub_goal);
	//pub_goal->header = goal_msg->header;
	//pub_goal->goal_id.stamp = goal_msg->header.stamp;
	//pub_goal->goal_id.id = std::to_string(translateNavGoal::goal_id);
	//translateNavGoal::goal_id++;
	//pub_goal->goal.target_pose = *goal_msg;
	ROS_INFO("set finish. Goal_ID %d", goal_id);

	move_base_goal_publisher.publish(pub_goal);
	ROS_INFO("publsih finish. Goal_ID %d", goal_id);
}

void translateNavGoal::set(const geometry_msgs::PoseStamped::ConstPtr& goal_msg, move_base_msgs::MoveBaseActionGoalPtr& pub_goal)
{
	//boost::shared_ptr<geometry_msgs::PoseStamped> goal_msg_ptr = boost::const_pointer_cast<geometry_msgs::PoseStamped>(goal_msg);
	//pub_goal->header = goal_msg_ptr->header;
	//pub_goal->goal_id.stamp = goal_msg_ptr->header.stamp;
	pub_goal->goal_id.id = std::to_string(goal_id);
	goal_id++;
	
	//pub_goal->goal.target_pose = *goal_msg_ptr;
}



} //namepsace translatenavgoal



int main(int argc, char **argv)
{
	ros::init(argc, argv, "navgoealtranslater");
	ros::NodeHandle node;
	translatenavgoal::translateNavGoal transNavGoal;
	transNavGoal.setup(node);

	ros::Rate looprate(5);
	while (ros::ok())
	{
		ros::spinOnce();
		looprate.sleep();
	}

	return 0;

}