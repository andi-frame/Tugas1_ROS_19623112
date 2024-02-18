#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"

#include "../include/tugas1/commander.hpp"


Commander::Commander() : nh("~") {
  sub = nh.subscribe("/drone_status", 10, &Commander::droneStatusCallback, this);
}


void Commander::droneStatusCallback(const tugas1::DronePos::ConstPtr& msg) {
  ROS_INFO("Commander: Receive x=%f, y=%f, z=%f, status=%s", msg->x, msg->y, msg->z, msg->status.c_str());
}