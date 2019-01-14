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

#ifndef __RECEP_PLACEMENT_IOTSCENE_H_
#define __RECEP_PLACEMENT_IOTSCENE_H_

#include <omnetpp.h>


using namespace omnetpp;

/**
 * TODO - Generated class
 */
class IoTScene : public cSimpleModule
{
  protected:
    double playgroundLat;
    double playgroundLon;
    double playgroundHeight;
    double playgroundWidth;
    static IoTScene *instance;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

  public:
    IoTScene();
    virtual ~IoTScene();

    static IoTScene *getInstance();

    // latitude from local y coordinate
    virtual double toLatitude(double y) { return playgroundLat - y / 111111; }
    // longitude from local x coordinate
    virtual double toLongitude(double x) { return playgroundLon +  x / 111111 / cos(fabs(playgroundLat/180*M_PI)); }
    // local Y coordinate from latitude
    virtual double toY(double latitude) {  return (playgroundLat - latitude) * 111111; }
    // local X coordinate from longitude
    virtual double toX(double longitude) { return (longitude - playgroundLon) * cos(fabs(playgroundLat/180*M_PI)) * 111111; }

};

#endif
