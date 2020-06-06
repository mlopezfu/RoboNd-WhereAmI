#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;
	
    // Call the command_robot service and pass the requested joint angles
    if (!client.call(srv)){
        ROS_ERROR("Failed to call service command_robot");
    }	
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    bool ball=false,command_send=false;
    //drive_robot(0.0, 0.0);
    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
       bool uniform_image = true;

    // Loop through each pixel in the image and check if its equal to the first one
    int n_bytes=img.step/img.width;
    for (int i = 0; i < img.height;i++){

        int firstPixel=0, lastPixel=0,heightPixel=-1;
        for(int j=0;j<img.step; j += n_bytes) {
            int pixel_index=i*img.step+j;
            // Check Red Green and Blue bytes
            if (img.data[pixel_index] == white_pixel && img.data[pixel_index + 1] == white_pixel && img.data[pixel_index + 2] == white_pixel) {
                ball=true;
                if(firstPixel=0)
                {
                    firstPixel=j;
                    lastPixel=j;
                }
                else
                {
                    lastPixel=j;
                }              
            }     
        }
        if (ball && !command_send)
        {
            command_send=true;
            int position_index = (lastPixel+firstPixel)/2;
            if (i>250)
            {
                //i % (img.step) / n_bytes;
                ROS_INFO("White pixel in index:%d, height:%d", position_index,i);
                if(position_index<420)
                { // First third rotate left
                    drive_robot(0.0, 0.15);        
                }
                else if(position_index>500)
                { //Third third rotate right
                    drive_robot(0.0, -0.15);  
                }
                else
                {
                    drive_robot(0.3, 0.0);  
                }
            }
            else
            {
                ROS_INFO("Ball too close. White pixel in index:%d, height:%d", position_index,i);
                drive_robot(0.0, 0.0);
            }
        }

    }
    if (!ball)
        drive_robot(0.0, 0.0);
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 5, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}