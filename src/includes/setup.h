#ifndef SETUP_H
#define SETUP_H

#include <Arduino.h>

// Pin definitions
#define button 12
#define led_on 13
#define AQ1 5
#define AQ2 4
#define BQ1 7
#define BQ2 8
#define STBY 6
#define LM 9
#define RM 3

extern int IsStarted;
extern float Kp, Ki, Kd;
extern int P, I, D, lastError;
extern int basespeed;
extern unsigned long p1Time, p2Time;

#endif
