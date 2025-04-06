#pragma once

#include <Arduino.h>
#include <QTRSensors.h>

// Pin definitions

// button pin
#define button 12

// LED pin
#define led_on 13

#define AQ1 5
#define AQ2 4
#define BQ1 7
#define BQ2 8
#define STBY 6

// Motor pins
#define LM 3
#define RM 9

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