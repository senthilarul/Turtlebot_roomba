#include <ros/ros.h>
#include <iostream>
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "DepthImage.hpp"

class Navigation {
  private:
    ros::NodeHandle n;
    geometry_msgs::Twist msg;
    ros::Publisher velocity;
    ros::Subscriber sub;
    DepthImage depth;
  public:
    Navigation();
    ~Navigation();
    void move();
};
