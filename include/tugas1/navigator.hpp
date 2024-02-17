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
  Navigator() : nh("~"), loop_rate(1), count(0), x(0), y(0), z(0), status("takeoff") {
      drone_status_pub = nh.advertise<tugas1::DronePos>("/drone_status", 10);
  }

  void run();
};


#endif