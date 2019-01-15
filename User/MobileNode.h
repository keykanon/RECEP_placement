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

#ifndef __RECEP_PLACEMENT_MOBILENODE_H_
#define __RECEP_PLACEMENT_MOBILENODE_H_

#include <omnetpp.h>

#include "IoTScene.h"


using namespace omnetpp;

/**
 * TODO - Generated class
 */
class MobileNode : public cSimpleModule
{
public:
    double getX() const  { return x; }
   double getY() const  { return y; }
   double getLatitude() const  { return IoTScene::getInstance()->toLatitude(y); }
   double getLongitude() const  { return IoTScene::getInstance()->toLongitude(x); }
   double getTxRange() const  { return txRange; }

   MobileNode();
   virtual ~MobileNode();

  protected:
    double x, y;
    double heading;
    double speed;

    // configuration
    double timeStep;
    unsigned int trailLength;
    std::string labelColor;
    std::string rangeColor;
    std::string trailColor;
    std::string modelURL;
    bool showTxRange;
    double txRange;



    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void refreshDisplay() const override;
    virtual void move() = 0;
};

#endif
