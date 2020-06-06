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
<pre><span class="anchor" id="line-1-3"></span>Reading from the keyboard  and Publishing to Twist!
<span class="anchor" id="line-2-1"></span>---------------------------
<span class="anchor" id="line-3-1"></span>Moving around:
<span class="anchor" id="line-4-1"></span>   u    i    o
<span class="anchor" id="line-5-1"></span>   j    k    l
<span class="anchor" id="line-6-1"></span>   m    ,    .
<span class="anchor" id="line-7-1"></span>
<span class="anchor" id="line-8-1"></span>q/z : increase/decrease max speeds by 10%
<span class="anchor" id="line-9-1"></span>w/x : increase/decrease only linear speed by 10%
<span class="anchor" id="line-10-1"></span>e/c : increase/decrease only angular speed by 10%
<span class="anchor" id="line-11-1"></span>anything else : stop
<span class="anchor" id="line-12-1"></span>
<span class="anchor" id="line-13-1"></span>CTRL-C to quit</pre>


After moving the robot by teleop command or by setting goal in Rviz, the robot will localize itself.
![alt text](localization.png)