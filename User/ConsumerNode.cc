//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "ConsumerNode.h"

Define_Module(ConsumerNode);

ConsumerNode::ConsumerNode(){

}
ConsumerNode::~ConsumerNode(){

}

void ConsumerNode::initialize()
{
    // TODO - Generated method body
    // fill the track
        readWaypointsFromfile(par("trackFile"));
       // initial location
       targetPointIndex = 0;
       x = waypoints[targetPointIndex].x;
       y = waypoints[targetPointIndex].y;
       speed = par("speed");
       waypointProximity = par("distance");
       heading = 0;
       angularSpeed = 0;
}

//void ConsumerNode::handleMessage(cMessage *msg)
//{
    // TODO - Generated method body

//}


void ConsumerNode::readWaypointsFromfile(const char *fileName)
{
    std::ifstream inputFile(fileName);
    while (true) {
       double longitude, latitude;
       inputFile >> longitude >> latitude;
       if (!inputFile.fail())
           waypoints.push_back(Waypoint(IoTScene::getInstance()->toX(latitude), IoTScene::getInstance()->toY(longitude), 0.0));
       else
           break;
    }
}

void ConsumerNode::move()
{
    Waypoint target = waypoints[targetPointIndex];
    double dx = target.x - x;
    double dy = target.y - y;
    if (dx*dx + dy*dy < waypointProximity*waypointProximity)  // reached so change to next (within the predefined proximity of the waypoint)
        targetPointIndex = (targetPointIndex+1) % waypoints.size();

    double targetDirection = atan2(dx, -dy) / M_PI * 180;
    double diff = targetDirection - heading;
    while (diff < -180)
        diff += 360;
    while (diff > 180)
        diff -= 360;

    angularSpeed = diff*5;

    // move
    heading += angularSpeed * timeStep;
    double distance = speed * timeStep;
    x += distance * sin(M_PI * heading / 180);
    y += distance * -cos(M_PI * heading / 180);
}
