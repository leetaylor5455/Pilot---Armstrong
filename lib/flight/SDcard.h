

#ifndef __SD_CARD__
#define __SD_CARD__

#include "Arduino.h"
#include "SD.h"
#include "DataStruct.h"

class SDcard
{
private:
    uint8_t _SD_pin;
    File log_file;
    uint32_t lastLogTime;
    uint32_t currentLogTime;
    bool setupOK = false;

    bool log_data(DataStruct& log_data);
public:
    SDcard(uint8_t SD_pin);
    ~SDcard();
    bool sys_setup();
    void sys_loop();
    
    
};

SDcard::SDcard(uint8_t SD_pin)
{
    _SD_pin = SD_pin;
    lastLogTime = millis();
}

SDcard::~SDcard()
{
}


#endif