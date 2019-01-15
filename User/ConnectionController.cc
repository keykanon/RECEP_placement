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

ConnectionController::ConnectionController()
{
    if (instance)
        throw cRuntimeError("There can be only one ConnectionController instance in the network");
    instance = this;
}

ConnectionController::~ConnectionController()
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


ConnectionController *ConnectionController::getInstance()
{
    if (!instance)
        throw cRuntimeError("ConnectionController::getInstance(): there is no ConnectionController module in the network");
    return instance;
}

void ConnectionController::addMobileNode(MobileNode *p)
{
    if (findMobileNode(p) == -1)
        nodeList.push_back(p);
}

void ConnectionController::removeMobileNode(MobileNode *p)
{
    int k = findMobileNode(p);
    if (k != -1)
        nodeList.erase(nodeList.begin()+k);
}

int ConnectionController::findMobileNode(MobileNode *p)
{
    for (int i = 0; i < (int)nodeList.size(); i++)
        if (nodeList[i] == p)
            return i;

    return -1;
}

void ConnectionController::refreshDisplay() const{
    if (!showConnections)
           return;

    cPathFigure* fig = new cPathFigure();
    for (int i = 0; i < (int)nodeList.size(); ++i) {
        for (int j = i+1; j < (int)nodeList.size(); ++j) {
            MobileNode *pi = nodeList[i];
            MobileNode *pj = nodeList[j];
            double ix = pi->getX(), iy = pi->getY(), jx = pj->getX(), jy = pj->getY();
            if (pi->getTxRange()*pi->getTxRange() > (ix-jx)*(ix-jx)+(iy-jy)*(iy-jy)) {
                fig->addLineRel(ix, iy);
                fig->addLineRel(jx, jy);
                IoTScene::getInstance()->getCanvas()->addFigure(fig);
            }
        }
    }
}
