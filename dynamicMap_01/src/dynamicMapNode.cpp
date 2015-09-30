#include <iostream>
#include <string>

#include <ros/ros.h>
#include <nav_msgs/GetMap.h>
#include <nav_msgs/OccupancyGrid.h>

#include "dynamicMap.hpp"


using namespace std;


int main(int argc, char **argv)
{
    ros::init(argc, argv, "dynamicMapServer");
    ros::NodeHandle n("~"); //private
    cout << "init done" << endl;
    // Subscribe to scan, position
    string scan = "/scan";
    string pose = "/robot_pose";
    string map = "/static_map";
       cout << "create dynmap" << endl;
    dynamicMap dynMap(n,scan,pose,map);
    // Retrieve cost map

    while(ros::ok())
    {
        ros::spinOnce();
    }
}
