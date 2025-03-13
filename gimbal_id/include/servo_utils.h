#include <Servo.h>
#include <Arduino.h>

float saturate(float x, float min, float max);
int deg2us(float deg);
void actuate(Servo servo, float angle);