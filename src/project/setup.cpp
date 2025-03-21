#include "../includes/setup.h"
#include "../includes/QTR_setup.h"
#include "../includes/motor_control.h"

int IsStarted;

float Kp = 1.7; //related to the proportional control term; 1.6
                //change the value by trial-and-error (ex: 0.7).
float Ki = 0;   //related to the integral control term;
                //change the value by trial-and-error (ex: 0.0008).
float Kd = 2.8; //related to the derivative control term; 2.69
                //change the value by trial-and-error (ex: 0.8).
int P = 0;
int I = 0;
int D = 0;
int lastError = 0;

int basespeed = 5;//100//120

unsigned long p1Time = 0;
unsigned long p2Time = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button, INPUT_PULLUP);

    pinMode(AQ1, OUTPUT);
    pinMode(AQ2, OUTPUT);
    pinMode(BQ1, OUTPUT);
    pinMode(BQ2, OUTPUT);
    pinMode(STBY, OUTPUT);

    digitalWrite(AQ1, HIGH);
    digitalWrite(BQ1, HIGH);
    digitalWrite(STBY, HIGH);
    digitalWrite(AQ2, LOW);
    digitalWrite(BQ2, LOW);

    qtr.setTypeAnalog();
    qtr.setSensorPins((const uint8_t[]){ A0, A1, A2, A3, A4, A5, A6, A7 }, SensorCount);

    delay(500);
    pinMode(led_on, OUTPUT);
    digitalWrite(led_on, HIGH);

    calibration();
    delay(500);
}
