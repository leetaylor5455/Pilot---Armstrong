/* Declare the Control System here, PID or otherwise*/

#ifndef __CONTROL_SYS__
#define __CONTROL_SYS__

#include "DataStruct.h"

class ControlSys
{
private:
    DataStruct _data;
public:
    ControlSys(DataStruct& data);
    ~ControlSys();
};

ControlSys::ControlSys(DataStruct& data)
{
    _data = data;
}

ControlSys::~ControlSys()
{
}
#endif