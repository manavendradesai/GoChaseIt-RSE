#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
ball_chaser::DriveToTarget::Response& res)
{
  ROS_INFO("DriveToTargetRequest received - lin_x:%1.2f, ang_z:%1.2f", (float)req.linear_x, (float)req.angular_z);
  
// This function should publish the requested linear x and angular velocities to the robot wheel joints
    
    // Create a motor_command object of type geometry_msgs::Twist
    geometry_msgs::Twist motor_command;
    // Request wheel velocities
    motor_command.linear.x = (float)req.linear_x;
    motor_command.angular.z = (float)req.angular_z;
  
    // Publish angles to drive the robot
    motor_command_publisher.publish(motor_command);
  
  
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
    res.msg_feedback = "Linear speed set - lin_x: " + std::to_string(motor_command.linear.x) + " , ang_z: " +  std::to_string(motor_command.angular.z);
  
    ROS_INFO_STREAM(res.msg_feedback);
 
    return true;
  
}


int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
   ros::ServiceServer service = n.advertiseService("/drive_bot/ball_chaser/command_robot", handle_drive_request);
  
    ROS_INFO("Ready to send linear and angular speed commands");


    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}
