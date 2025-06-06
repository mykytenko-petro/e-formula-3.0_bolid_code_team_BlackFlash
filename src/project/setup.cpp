/*
setup the project
adding important variables and setup arduino pins
*/
#include "../includes/setup.h"

bool test = false;

//speed
int basespeed = 150;

//QTR sensors
QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

State state;

void setup() {
    //conection between arduino and PC
    Serial.begin(9600);

    //button pin setup
    pinMode(button, INPUT_PULLUP);

    //motor pin setup
    pinMode(AQ1, OUTPUT);
    pinMode(AQ2, OUTPUT);
    pinMode(BQ1, OUTPUT);
    pinMode(BQ2, OUTPUT);
    pinMode(STBY, OUTPUT);

    //setup motors
    digitalWrite(STBY, HIGH);

    //setup sensors
    qtr.setTypeAnalog();
    qtr.setSensorPins((const uint8_t[]){ A0, A1, A2, A3, A4, A5, A6, A7 }, SensorCount);

    //setup led
    pinMode(led_on, OUTPUT);

    delay(500);
}
