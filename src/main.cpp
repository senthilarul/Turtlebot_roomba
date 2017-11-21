#include "DepthImage.hpp"
#include "Navigation.hpp"
#include <ros/ros.h>

int main(int argc, char* argv[]) {

  ros::init(argc, argv, "roomba");
  Navigation nav;
  nav.move();
  return 0;
}
