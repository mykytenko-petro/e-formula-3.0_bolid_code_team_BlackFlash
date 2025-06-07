#pragma once

#include <Arduino.h>
#include <QTRSensors.h>

// Pin definitions

#define button 3
#define led_on 13

#define AQ1 5
#define AQ2 6
#define BQ1 9
#define BQ2 10

#define STBY 8

extern bool test;

enum class State {
    WAIT,
    CALIBRATION,
    START
};

extern State state;

extern int basespeed;

extern QTRSensors qtr;
extern const uint8_t SensorCount;
extern uint16_t sensorValues[];