#include <iostream>
#include "DepthImage.hpp"


DepthImage::DepthImage() {
  collisionStatus = false;  
}

DepthImage::~DepthImage() {

}

void DepthImage::callDepth(const sensor_msgs::LaserScan::ConstPtr& msg) {
  for (int i = 0; i < msg->ranges.size(); i++) {
    //std::cout<<"\nde: "<<msg->ranges[i];
    if (msg->ranges[i] < 0.8) {
      collisionStatus = true;
      return;
    }
  }
  collisionStatus = false;
}

bool DepthImage::collisionCheck() {
  return collisionStatus;
}


