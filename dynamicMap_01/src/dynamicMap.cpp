#include <string>

#include "ros/transport_hints.h"
#include "nav_msgs/GetMap.h"
#include "nav_msgs/OccupancyGrid.h"

#include "dynamicMap.hpp"

using namespace std;

dynamicMap::dynamicMap(ros::NodeHandle& n, string &scanTopic, string &positionTopic, string &costMapServiceName)
{
    _node = n;
    ros::TransportHints hint;
    _scanSubscriber = _node.subscribe(scanTopic,100,&dynamicMap::scanCallback,this);
    _positionSubscriber = _node.subscribe(positionTopic,100,&dynamicMap::positionCallback,this);

    ros::ServiceClient client = n.serviceClient<nav_msgs::GetMap>(costMapServiceName);
    nav_msgs::GetMap mapMsg;
    if(!client.call(mapMsg))
    {
        ROS_ERROR("Failed to obtain static map!");
    }
    else
    {
        maplayer newLayer(mapMsg.response.map);
        newLayer.print("/home/martin/Desktop/map.pgm");
        _maps.push_back(newLayer);
    }
}

dynamicMap::~dynamicMap(){

}


void dynamicMap::scanCallback(const sensor_msgs::LaserScan &scanMsg)
{
    //
}

void dynamicMap::positionCallback(const geometry_msgs::Pose &poseMsg)
{

}
