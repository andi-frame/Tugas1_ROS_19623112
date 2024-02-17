// commander_node.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"

void droneStatusCallback(const tugas1::DronePos::ConstPtr& msg) {
    ROS_INFO("Commander: Receive x=%f, y=%f, z=%f, status=%s", msg->x, msg->y, msg->z, msg->status.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "commander");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/drone_status", 10, droneStatusCallback);

    ros::spin();
    return 0;
}
