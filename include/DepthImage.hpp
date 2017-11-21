#pragma once

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"



class DepthImage {
 private:
  bool collisionStatus = false;

 public:
  DepthImage();
  ~DepthImage();
  void callDepth(const sensor_msgs::LaserScan::ConstPtr& msg);
  bool collisionCheck();
};

