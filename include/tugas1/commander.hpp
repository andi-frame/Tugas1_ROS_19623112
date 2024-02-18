#ifndef __commander_hpp__
#define __commander_hpp__


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"
#include <sstream>

class Commander{
  private:
    ros::NodeHandle nh;
    ros::Subscriber sub;


  public:
    Commander();
    void droneStatusCallback(const tugas1::DronePos::ConstPtr& msg);
};


#endif