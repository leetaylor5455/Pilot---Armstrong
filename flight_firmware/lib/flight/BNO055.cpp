#include "BNO055.h"
#include <Arduino.h>

bool BNO055::sensor_setup(){
  Serial.println("BNO055 setup start");
  bool sensor_start = sensor->begin();
  // sensor->setExtCrystalUse(true);
  if (!sensor_start)
  {
    Serial.println("Failed to setup BNO055");
    return sensor_start;
  }
  delay(10); // IMPORTANT: GIVE BNO SOME TIME TO START
  return sensor_start;
}

void BNO055::sensor_loop(DataStruct& data){
 
  sensors_event_t  AccelData, GyroData;
  sensor->getEvent(&AccelData, Adafruit_BNO055::VECTOR_ACCELEROMETER);
  sensor->getEvent(&GyroData, Adafruit_BNO055::VECTOR_GYROSCOPE);
  
  logData(&AccelData, data);
  logData(&GyroData, data);

  printEvent(&AccelData);
  printEvent(&GyroData);
  // sensor->getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  // sensor->getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
  // sensor->getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
  // sensor->getEvent(&magnetometerData, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  // sensor->getEvent(&accelerometerData, Adafruit_BNO055::VECTOR_ACCELEROMETER);
  // sensor->getEvent(&gravityData, Adafruit_BNO055::VECTOR_GRAVITY);

  // printEvent(&orientationData);
  // printEvent(&angVelocityData);
  // printEvent(&linearAccelData);
  // printEvent(&magnetometerData);
  // printEvent(&accelerometerData);
  // printEvent(&gravityData);



  delay(BNO055_SAMPLERATE_DELAY_MS); // IMPORTANT; DO NOT POLL AT HIGH FREQUENCY HOWEVER FIND A WAY TO AVOID USING DELAY
}

void BNO055::logData(sensors_event_t* event, DataStruct& data) {
  switch (event->type)
  {
  case SENSOR_TYPE_ACCELEROMETER:
    data.accel_vec = sensor->getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
    break;
  case SENSOR_TYPE_GYROSCOPE:
    data.gyro_vec = sensor->getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
    break;
  default:
    break;
  }
}

void BNO055::printEvent(sensors_event_t* event) {
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  if (event->type == SENSOR_TYPE_ACCELEROMETER) {
    Serial.print("Accl:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_ORIENTATION) {
    Serial.print("Orient:");
    x = event->orientation.x;
    y = event->orientation.y;
    z = event->orientation.z;
  }
  else if (event->type == SENSOR_TYPE_MAGNETIC_FIELD) {
    Serial.print("Mag:");
    x = event->magnetic.x;
    y = event->magnetic.y;
    z = event->magnetic.z;
  }
  else if (event->type == SENSOR_TYPE_GYROSCOPE) {
    Serial.print("Gyro:");
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_ROTATION_VECTOR) {
    Serial.print("Rot:");
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_LINEAR_ACCELERATION) {
    Serial.print("Linear:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_GRAVITY) {
    Serial.print("Gravity:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else {
    Serial.print("Unk:");
  }

  Serial.print("\tx= ");
  Serial.print(x);
  Serial.print(" |\ty= ");
  Serial.print(y);
  Serial.print(" |\tz= ");
  Serial.println(z);
}