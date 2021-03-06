//
// Generated file, do not edit! Created by nedtool 5.2 from message/Event.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __EVENT_M_H
#define __EVENT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>message/Event.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message Event
 * {
 *     bool marker;
 *     int time;
 *     int vehicleID;
 *     double speed;
 *     string laneID;
 * }
 * </pre>
 */
class Event : public ::omnetpp::cMessage
{
  protected:
    bool marker;
    int time;
    int vehicleID;
    double speed;
    ::omnetpp::opp_string laneID;

  private:
    void copy(const Event& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Event&);

  public:
    Event(const char *name=nullptr, short kind=0);
    Event(const Event& other);
    virtual ~Event();
    Event& operator=(const Event& other);
    virtual Event *dup() const override {return new Event(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getMarker() const;
    virtual void setMarker(bool marker);
    virtual int getTime() const;
    virtual void setTime(int time);
    virtual int getVehicleID() const;
    virtual void setVehicleID(int vehicleID);
    virtual double getSpeed() const;
    virtual void setSpeed(double speed);
    virtual const char * getLaneID() const;
    virtual void setLaneID(const char * laneID);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Event& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Event& obj) {obj.parsimUnpack(b);}


#endif // ifndef __EVENT_M_H

