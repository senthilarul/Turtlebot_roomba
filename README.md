# Turtlebot Walker - A Roomba like navigation implementation
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

The turtlebot_roomba package implements a simple navigation algorithm for the
turtlebot. The turtlebot move forward until it detects an obstacle and on
detecting an obstacle the turtlebot rotates until it finds a path free of obstacles 
and then moves forward.

The Demo utilizes gazebo for simulation.

## Pre-requisites
1) [ROS kinectic] (http://wiki.ros.org/kinetic/Installation)
2) TurtleBot 
follow instructions to install turtlebot package
```
sudo apt-get install ros-kinetic-turtlebot-gazebo 
ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-rviz-launchers
```
3) Catkin
4) Gazebo 

Demo was developed on Ubuntu 16.04

## Installation
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/senthilarul/Turtlebot_roomba.git
cd ..
catkin_make
```

## Running Demo
To run demo using the launch file follow the step below
```
cd ~/catkin_ws
source devel/setup.bash
roslaunch turtlebot_roomba roomba.launch
```

to close the demo press ctrl + C in the open terminal windows.

to run without using the roomba launch file

open a new terminal and type
```
roscore
```
open a new terminal and launch gazebo turtlebot world 
```
roslaunch turtlebot_gazebo turtlebot_world.launch
```
open a new terminal and type
```
cd ~/catkin_ws
source devel/setup.bash
rosrun turtlebot_roomba roomba
```
to close the program press ctrl+C in all the three terminals.

## ROSbag

A .bag file containing 30 seconds of recording of all topics (except camera related) is available in the results directory.

to enable record during roslaunch follow the instructions below
```
cd ~/catkin_ws
source devel/setup.bash
roslaunch turtlebot_roomba roomba.launch rosbagEnable:=true
```
Note: this will replace the previous .bag file in the results directory.

to inspect the .bag file follow the instructions below (you can see except camera topics 
other topics are recorded)
```
cd ~/catkin_ws/src/turtlebot_roomba/results
rosbag info roombatopics.bag
```

