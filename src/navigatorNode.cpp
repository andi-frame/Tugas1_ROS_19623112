// navigator_node.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"
#include <sstream>

#include "../include/tugas1/navigator.hpp"


int main(int argc, char **argv) {
    ros::init(argc, argv, "navigator");
    Navigator navigator;
    navigator.run();
    return 0;
}
