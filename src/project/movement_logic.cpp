#include "../includes/movement_logic.h"
#include "../includes/setup.h"
#include "../includes/motor_control.h"

float PID_calculation(uint16_t pos) {
    int error = 3500 - pos;
    P = error;
    I += error;
    D = error - lastError;
    lastError = error;
    float delta = (P * Kp + D * Kd) * 0.365;
    return delta;
}

int Start() {
    int button1 = digitalRead(button);
    delay(40);
    int button2 = digitalRead(button);
  
    button1 = button1 | button2;
  
    if (button1 == 0)
        return 1;
    else
        return 0;
}

void movement_logic(){
    digitalWrite(led_on, HIGH);
    uint16_t position = qtr.readLineBlack(sensorValues);
    digitalWrite(led_on, LOW);

    if (position <= 400 || position >= 6600) {
        driver_control(HIGH);
    } else {
        driver_control(LOW);
    }


    if (IsStarted == 0) {
        p1Time = millis();
        IsStarted = Start();
    }

    if (IsStarted != 0) {
        float deltaspeed = PID_calculation(position);
        MotorControl(deltaspeed, basespeed);
        p2Time = millis() - p1Time;

        if (p2Time > 200000) IsStarted = 0;
    } else {
        analogWrite(LM, 0);
        analogWrite(RM, 0);
        P = 0;
        I = 0;
        D = 0;
        lastError = 0;    
    }
}