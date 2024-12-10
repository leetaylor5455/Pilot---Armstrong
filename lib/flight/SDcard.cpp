#include "SDcard.h"

bool SDcard::sys_setup(){
    if (SD.begin(_SD_pin))
    {
        Serial.println("SD card initialised");
    } else {
        Serial.println("SD card initialisation failed");
        return false;
    }

    // FROM MRAS codebase
    char log_filename[8] = "";
    // pick an appropriate file name
    for (int i = 0; i < 9999; i++) {
        snprintf(log_filename, 8, "%d.csv", i);
        if (!SD.exists(log_filename)) {
            break;
        }
    }

    Serial.printf("SD log filename: %s", log_filename);

    log_file = SD.open(log_filename, FILE_WRITE);
    setupOK = true;
}


