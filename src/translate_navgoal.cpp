#include "ros/ros.h"

#include "geometry_msgs/PoseStamped.h"
#include "move_base_msgs/MoveBaseActionGoal.h"

#include "unreal_robot_sim_2dnav/translate_navgoal.h"

namespace translatenavgoal {
class translateNavGoal
{
public:
	bool setup(ros::NodeHandle &node);
	void callback(const geometry_msgs::PoseStamped::ConstPtr& goal_msg)
{
	ros::Publisher move_base_goal_publisher = ;
	move_base_msgs::MoveBaseActionGoal temp_action_goal;
	auto temp_action_goal = new move_base_msgs::MoveBaseActionGoal;
	temp_action_goal->header = goal_msg->header;
	temp_action_goal->goal_id.stamp = goal_msg->header.stamp;
	temp_action_goal->goal.target_pose = goal_msg->pose;


}
	void set(const geometry_msgs::PoseStamped::ConstPtr& goal_msg);
private:
	move_base_msgs::MoveBaseActionGoal action_goal;
};



int main(int argc, char **argv)
{
	ros::init(argc, argv, "navgoealtranslater");
	ros::NodeHandle node;

	ros::Subscriber simple_goal_subscriber = node.subscribe("move_base_simple/goal", 100, callback);
}
} //namepsace translatenavgoal