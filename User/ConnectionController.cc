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

#include "ConnectionController.h"

Define_Module(ConnectionController);

ConnectionController *ConnectionController::instance = nullptr;

ChannelController::ChannelController()
{
    if (instance)
        throw cRuntimeError("There can be only one ChannelController instance in the network");
    instance = this;
}

ChannelController::~ChannelController()
{
    instance = nullptr;
}

void ConnectionController::initialize()
{
    // TODO - Generated method body
    connectionColor = par("connectionColor").stringValue();
    showConnections = par("showConnections").boolValue();


}

void ConnectionController::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    throw cRuntimeError("This module does not process messages");
}


ChannelController *ChannelController::getInstance()
{
    if (!instance)
        throw cRuntimeError("ChannelController::getInstance(): there is no ChannelController module in the network");
    return instance;
}

void ChannelController::addMobileNode(MobileNode *p)
{
    if (findMobileNode(p) == -1)
        nodeList.push_back(p);
}

void ChannelController::removeMobileNode(MobileNode *p)
{
    int k = findMobileNode(p);
    if (k != -1)
        nodeList.erase(nodeList.begin()+k);
}

int ChannelController::findMobileNode(MobileNode *p)
{
    for (int i = 0; i < (int)nodeList.size(); i++)
        if (nodeList[i] == p)
            return i;

    return -1;
}
