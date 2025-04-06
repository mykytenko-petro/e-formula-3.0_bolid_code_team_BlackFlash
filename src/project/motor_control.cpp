#include "../includes/motor_control.h"

// function which simplify motors control
void motor_control(int velocity, Direction direction) {
    int pwm = abs(velocity);
    if (pwm > 255) pwm = 255;

    int pin1, pin2, motorPWM;

    if (direction == Direction::LEFT) {
        pin1 = AQ1;
        pin2 = AQ2;
        motorPWM = LM;
    } else {
        pin1 = BQ1;
        pin2 = BQ2;
        motorPWM = RM;
    }

    // Set motor direction
    if (velocity >= 0) {
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }

    analogWrite(motorPWM, pwm);
}

void motor_control(enum Direction direction) {
    analogWrite(LM, 0);
    analogWrite(RM, 0);
}