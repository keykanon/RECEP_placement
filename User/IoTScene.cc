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

#include "IoTScene.h"



Define_Module(IoTScene);

IoTScene *IoTScene::instance = nullptr;

IoTScene::IoTScene()
{
    if (instance)
        throw cRuntimeError("There can be only one IoTScene instance in the network");
    instance = this;
}

IoTScene::~IoTScene()
{
    instance = nullptr;
}

IoTScene *IoTScene::getInstance()
{
    if (!instance)
        throw cRuntimeError("OsgEarthScene::getInstance(): there is no OsgEarthScene module in the network");
    return instance;
}

void IoTScene::initialize()
{
    // TODO - Generated method body
    double centerLongitude = toLongitude(playgroundWidth/2);
    double centerLatitude = toLatitude(playgroundHeight/2);

    scene = getParentModule()->getCanvas();
    //cCanvas *builtinCanvas = getParentModule()->getCanvas();







}

void IoTScene::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    throw cRuntimeError("This module does not handle messages from the outside");

}
