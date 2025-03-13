#include <servo_utils.h>

const int maxServoAngle = 50;

float saturate(float x, float min, float max) {
  if (x < min) {
    return min;
  }
  if (x > max) {
    return max;
  }
  return x;
}

int deg2us(float deg) {
  return (int)map(saturate(deg, -maxServoAngle, maxServoAngle), -maxServoAngle, maxServoAngle, 1000, 2000);
}

void actuate(Servo servo, float angle) {
    servo.writeMicroseconds(deg2us(saturate(angle, -19, 19))); // Gimbal actuates fully across 38deg arm actuation
}