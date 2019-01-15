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

#include "MobileNode.h"
#include "IoTScene.h"
#include "ConnectionController.h"



MobileNode::MobileNode()
{
}

MobileNode::~MobileNode()
{
}

void MobileNode::initialize()
{
    // TODO - Generated method body
    timeStep = par("timeStep");
    trailLength = par("trailLength");
    modelURL = par("modelURL").stringValue();
    showTxRange = par("showTxRange");
    txRange = par("txRange");
    labelColor = par("labelColor").stringValue();
    rangeColor = par("rangeColor").stringValue();
    trailColor = par("trailColor").stringValue();


    ConnectionController::getInstance()->addMobileNode(this);
    //auto scene = IoTScene::getInstance();

    // build up the node representing this module
   // an ObjectLocatorNode allows positioning a model using world coordinates
    getParentModule()->getCanvas()->setAnimationSpeed(10, this);
    // schedule first move
   cMessage *timer = new cMessage("move");
   scheduleAt(par("startTime"), timer);

}

void MobileNode::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    move();

    // schedule next movement
    scheduleAt(simTime() + timeStep, msg);
}

void MobileNode::refreshDisplay() const{
    double modelheading = fmod((360 + 90 + heading), 360) - 180;
   double longitude = getLongitude();
   double latitude = getLatitude();



   // update the position on the 2D canvas, too
   getDisplayString().setTagArg("p", 0, x);
   getDisplayString().setTagArg("p", 1, y);
}


