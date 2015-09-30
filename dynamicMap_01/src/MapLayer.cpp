
#include "MapLayer.hpp"

#include <iostream>
#include <fstream>

using namespace std;


maplayer::maplayer(const nav_msgs::OccupancyGrid &map)
{
   _width = map.info.width;
   _height = map.info.height;

   for(int i=0; i < _width*_height;i++){
       _data.push_back(map.data[i]);
   }

}




void maplayer::print(std::string path)
{
    cout << "Width: " << _width << "  Height: " << _height << endl;

    ofstream outFile;
    outFile.open(path.c_str());
    outFile << "P2\n" << _width << " " << _height <<"\n100\n";

    for(int i = 0; i < _data.size();i++){
        outFile << (unsigned) _data[i] << " ";
    }

    outFile.close();
    return;
}
