#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "BNO055.h"
#include "DataStruct.h"
// #define BNO055_SAMPLERATE_DELAY_MS (100)

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
// Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);
BNO055 bno = BNO055(-1, 0x28, &Wire);

void setup() {
  Serial.begin(115200);

  while (!Serial) delay(10);  // wait for serial port to open!

  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");

  /* Initialise the sensor */
  while(!bno.sensor_setup()){delay(1);};
  // while (!bno.begin())
  // {
  //   Serial.println("Failed to setup bno");
  // }
  

  delay(1000);

  /* Display the current temperature */
  // int8_t temp = bno.getTemp();
  // Serial.print("Current Temperature: ");
  // Serial.print(temp);
  // Serial.println(" C");
  // Serial.println("");

  

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
}

void loop() {
  DataStruct data;
  bno.sensor_loop(data);
  // imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  // /* Display the floating point data */
  // Serial.print("X: ");
  // Serial.print(euler.x());
  // Serial.print(" Y: ");
  // Serial.print(euler.y());
  // Serial.print(" Z: ");
  // Serial.print(euler.z());
  // Serial.print("\t\t");

  //  uint8_t system, gyro, accel, mag = 0;
  // bno.getCalibration(&system, &gyro, &accel, &mag);
  // Serial.print("CALIBRATION: Sys=");
  // Serial.print(system, DEC);
  // Serial.print(" Gyro=");
  // Serial.print(gyro, DEC);
  // Serial.print(" Accel=");
  // Serial.print(accel, DEC);
  // Serial.print(" Mag=");
  // Serial.println(mag, DEC);

  // delay(BNO055_SAMPLERATE_DELAY_MS);
}
