#include <Arduino.h>
#include <Wire.h>

#include <servo_utils.h>
#include <imu_utils.h>
#include <daq_utils.h>

// Servos
Servo servoX;
Servo servoY;

int servoXPin = DD3;
int servoYPin = DD5;


void setup() {
  Serial.begin(115200);
  servoX.attach(servoXPin);
  initMPU();
}

void loop() {

  delay(1000);
  // calculate_IMU_error();
  

  while(true) {

    delay(10000);
    // actuate(servoX, -3); // Step input
    stepResponse(servoX);
    // sinConstFreq(servoX, 3);

  }
}