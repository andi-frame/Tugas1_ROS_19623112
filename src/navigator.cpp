// navigator_node.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"
#include <sstream>

#include "../include/tugas1/navigator.hpp"


Navigator::Navigator() : nh("~"), loop_rate(1), count(0), x(0), y(0), z(0), status("takeoff") {
  drone_status_pub = nh.advertise<tugas1::DronePos>("/drone_status", 10);
}


void Navigator::run() {
  while (ros::ok() && count < 1000) {
    tugas1::DronePos msg;
    msg.x = x++;
    msg.y = y++;
    
    if (z >= 1 && z <= 9){
      status = "Takeoff";
    }
    else if (z == 10){
      status = "Fly";
    }
    else if (z == 0){
      status = "land";
    }
    msg.z = z <= 10 ? z++ : z;
    msg.status = status;
    
    ROS_INFO("Navigator: Publish x=%f, y=%f, z=%f, status=%s", msg.x, msg.y, msg.z, msg.status.c_str());
    drone_status_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    count++;
  }
}
