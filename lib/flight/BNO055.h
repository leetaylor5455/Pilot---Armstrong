
#ifndef __BNO055__
#define __BNO055__

#include <Wire.h>
#include "Adafruit_Sensor.h"
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "DataStruct.h"

#define BNO055_SAMPLERATE_DELAY_MS (100)

class BNO055
{
private:
    Adafruit_BNO055* sensor;
    void printEvent(sensors_event_t* event);
    void logData(sensors_event_t* event, DataStruct& data);
public:
    BNO055(uint32_t sensor_id, uint8_t address, TwoWire *theWire){
        sensor = new Adafruit_BNO055(sensor_id, address, theWire);
    }
    ~BNO055(){
        delete sensor;
    }
    void sensor_loop(DataStruct& data);
    bool sensor_setup();
};

#endif