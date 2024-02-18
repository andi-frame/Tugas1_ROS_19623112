#ifndef __navigator_hpp__
#define __navigator_hpp__


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"
#include <sstream>


class Navigator {
private:
  ros::NodeHandle nh;
  ros::Publisher drone_status_pub;
  ros::Rate loop_rate;
  int count;
  double x, y, z;
  std::string status;

public:
  Navigator();

  void run();
};


#endif