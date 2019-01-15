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

#ifndef __RECEP_PLACEMENT_CONSUMERNODE_H_
#define __RECEP_PLACEMENT_CONSUMERNODE_H_


#include "MobileNode.h"
#include <omnetpp.h>

using namespace omnetpp;

// a structure to store time coded waypoints
struct Waypoint
{
    Waypoint(double x, double y, double timestamp) {
        this->x = x;
        this->y = y;
        this->timestamp = timestamp;
    }
    double x;
    double y;
    double timestamp;
};

typedef std::vector<Waypoint> WaypointVector;
/**
 * TODO - Generated class
 */
class ConsumerNode : public MobileNode
{
  protected:
    // configuration
    WaypointVector waypoints;

    double angularSpeed;
    int targetPointIndex;
    double  waypointProximity;


    virtual void initialize();
    //virtual void handleMessage(cMessage *msg);

    virtual void move() override;
    void readWaypointsFromfile(const char* filename);

  public:
    ConsumerNode();
    virtual ~ConsumerNode();
};

#endif
