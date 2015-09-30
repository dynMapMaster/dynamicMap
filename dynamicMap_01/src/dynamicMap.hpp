#ifndef _DYNAMICMAP_HPP
#define _DYNAMICMAP_HPP

#include <string>
#include <vector>
#include <queue>

#include <nav_msgs/GetMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/GetMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <ros/ros.h>

#include "MapLayer.hpp"

struct point{
    float x, y;

    point(float X, float Y){x=X;y=Y;}
};

class dynamicMap
{
public:
    dynamicMap(ros::NodeHandle& n, std::string &scanTopic, std::string &positionTopic, std::string &costMapServiceName );
    ~dynamicMap();

private:
    ros::NodeHandle _node;
    ros::Subscriber _scanSubscriber, _positionSubscriber;
    ros::ServiceClient _costMapServiceClient;

    std::vector<maplayer> _maps;
    std::queue<point> _observationQ;


    void scanCallback(const sensor_msgs::LaserScan& scanMsg);
    void positionCallback(const geometry_msgs::Pose& poseMsg);


};

#endif
