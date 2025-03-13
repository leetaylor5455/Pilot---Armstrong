#include <daq_utils.h>

float roll, pitch, yaw;
int t0, t;

void stepResponse(Servo servo) {
    roll = 0;
    pitch = 0; 
    yaw = 0;

    // Move servo to 0;
    actuate(servo, -3);
    delay(1000);

    startReading();

    t0 = millis();
    t = t0;

    // Print pre-step series

    while (t - t0 < 50) {

        t = millis(); // Get current timestamp
        getOrientation(&roll, &pitch, &yaw); // Get orientation

        Serial.print(t-t0);
        Serial.print(", ");
        Serial.print("0, ");
        Serial.println(pitch);

        
    }

    actuate(servo, 15); // Step input

    while (t - t0 < 500) {

        t = millis(); // Get current timestamp
        getOrientation(&roll, &pitch, &yaw); // Get orientation

        Serial.print(t-t0);
        Serial.print(", ");
        Serial.print("5, ");
        Serial.println(pitch);
        
    }

    endReading();

    delay(1000);
    actuate(servo, -3);
}

void sinConstFreq(Servo servo, int freq) {
    roll = 0;
    pitch = 0; 
    yaw = 0;

    float input = 0;

    // Move servo to 0;
    actuate(servo, 0);
    delay(1000);

    startReading();

    t0 = millis();
    t = t0;

    while (t - t0 < 5000) {

        input = 20*sin(((double)(t-t0)/1000)*2*3.14159f*freq);

        // actuate(servo, 18*sin((t-t0)/1000)); // Step input
        actuate(servo, input-3); // Step input
        t = millis(); // Get current timestamp
        getOrientation(&roll, &pitch, &yaw); // Get orientation
        Serial.print(t-t0);
        Serial.print(", ");
        Serial.print(5*sin(((double)(t-t0)/1000)*2*3.14159f*freq));
        Serial.print(", ");
        Serial.println(pitch);
        
    }

}