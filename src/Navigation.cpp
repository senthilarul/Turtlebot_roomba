#include "Navigation.hpp"



Navigation::Navigation() {

  velocity = nh.advertise <geometry_msgs::Twist> ("/mobile_base/commands/velocity",
    1000);
  depthBuffer = nh.subscribe <sensor_msgs::LaserScan> ("/scan", 50, &DepthImage::callDepth, &depth);

  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  velocity.publish(msg);
}

Navigation::~Navigation() {

  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  velocity.publish(msg);
}

void Navigation::move() {
  
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    // std::cout<<depth.collisionCheck()<<"\n";
    if (depth.collisionCheck()) {
      msg.linear.x = 0.0;
      msg.angular.z = 1.0;
    } else {
      msg.linear.x = 0.2;
      msg.angular.z = 0.0;
    }
    velocity.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
