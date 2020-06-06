# RoboNd-WhereAmI
Robotics Engineer Nanodegree Program

---
## Basic Build Instructions
Create catkin workspace
mkdir -p catkin_ws/src
cd catkin_ws/src
catkin_init_workspace
clone this repo
cd ..
catkin_make
source devel/setup.bash


## Basic Instructions
Run world with command:
roslaunch my_robot world.launch
Then run montecarlo localization with:
roslaunch my_robot amcl.launch
This will also run teleop, tha will move robot with these commands.

Moving around:
   u    i    o
   j    k    l
   m    ,    .

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%
anything else : stop

After moving the robot by teleop command or by setting goal in Rviz, the robot will localize itself.
![alt text](localization.png)