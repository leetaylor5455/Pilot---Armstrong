
#ifndef __BNO055__
#define __BNO055__

#include <Wire.h>
#include "Adafruit_Sensor.h"
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


class BNO055
{
private:
    Adafruit_BNO055* sensor;
    void printEvent(sensors_event_t* event);
public:
    BNO055(uint32_t sensor_id, uint8_t address, TwoWire *theWire){
        sensor = new Adafruit_BNO055(sensor_id, address, theWire);
    }
    ~BNO055(){
        delete sensor;
    }
    void sensor_loop();
    bool begin(){
        printf("Enters \n");
        return sensor->begin();
    }
    
};

#endif