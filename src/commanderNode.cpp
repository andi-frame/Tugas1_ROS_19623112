// commander_node.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tugas1/DronePos.h"

#include "../include/tugas1/commander.hpp"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "commander");
    Commander commander;

    ros::spin();
    return 0;
}
