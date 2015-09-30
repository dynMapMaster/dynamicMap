#ifndef _MAPLAYER_HPP
#define _MAPLAYER_HPP

#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/Pose.h>

#include <vector>
#include <string>

class maplayer
{
public:
    maplayer(const nav_msgs::OccupancyGrid &map);

    uint8_t height(){return _height;}
    uint8_t width(){return _width;}
    float resolution(){return _resolution;}
    void print(std::string path);

private:
   unsigned _width, _height;
   float _resolution;
    geometry_msgs::Pose _pose;
    std::vector<uint8_t> _data;
};


#endif
