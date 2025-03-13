#include <Arduino.h>
#include <Wire.h>

void initMPU();
void startReading();
void endReading();
void getOrientation(float *roll, float *pitch, float *yaw);
void calculate_IMU_error();