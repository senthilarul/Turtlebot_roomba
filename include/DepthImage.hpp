#pragma once

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"



class DepthImage {
 private:
  // Declare a varible to detect possible collisions
  bool collisionStatus = false;

 public:
  DepthImage();
  ~DepthImage();
  void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
  bool collisionCheck();
};

