#ifndef __DATA_STRUCT__
#define __DATA_STRUCT__

#include <utility/imumaths.h>

struct DataStruct{
        imu::Vector<3> accel_vec;
        imu::Vector<3> gyro_vec;
        imu::Vector<3> mag_vec;
};
#endif