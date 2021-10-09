#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Updating linear and angular speed...");
  
    // Setting linear and angular speed
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the drive_robot service
    if (!client.call(srv))
        ROS_ERROR("Failed to call service drive_bot");
}


// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    int locate = 300;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    for (int i = 0; i < img.height*img.step; i+=3) 
    {
        if (img.data[i] == white_pixel && img.data[i+1] == white_pixel && img.data[i+2] == white_pixel) 
        {
          locate = i;
        }
    }
     
 
    // Give direction
    if (locate!=300)
    {
          	if ((locate+1)%img.step<=(float)img.step/3)
            {//go left
              drive_robot(0.05,0.15);
            }  
            else if ((locate+1)%img.step>=2*(float)img.step/3)
            {//go right
              drive_robot(0.05,-0.15);
            }
            else
            {//go straight
              drive_robot(0.15,0);
            }
            
     }
      else
      {//keep rotating to keep searching
        drive_robot(0,0.15);
      }
  
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
}

int main(int argc, char** argv)
{

// Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

   // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/drive_bot/ball_chaser/command_robot");

   // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);
  
      // Handle ROS communication events
    ros::spin();

    return 0;
}



