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





void MobileNode::initialize()
{
    // TODO - Generated method body
    showTxRange = par("showTxRange");
    txRange = par("txRange");

    ConnectionController::getInstance()->addMobileNode(this);
}

void MobileNode::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void MobileNode::refreshDisplay() const{

}

void MobileNode::move(){

}
