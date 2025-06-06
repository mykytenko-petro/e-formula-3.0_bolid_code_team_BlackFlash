#include "../includes/PID_calculator.h"

int P = 0;
int I = 0;
int D = 0;

float Kp = 1.7;
float Kd = 2.8;

int lastError = 0;

float PID_calculation(uint16_t pos) {

  int error = 3500 - pos;  //3500 is the ideal position (the centre)

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  float delta = (P * Kp + D * Kd)*0.365;

  return delta;
}