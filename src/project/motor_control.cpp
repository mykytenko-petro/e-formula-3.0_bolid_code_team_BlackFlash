#include "../includes/motor_control.h"

bool is_running = true;

// function which simplify motors control
void motor_control(int velocity, Direction direction) {
    int pwm = abs(velocity);
    if (pwm > 255) pwm = 255;

    // LEFT motor (AQ1/AQ2)
    if (direction == Direction::LEFT) {
        if (velocity >= 0) {
            analogWrite(AQ1, pwm);
            analogWrite(AQ2, 0);
        } else {
            analogWrite(AQ1, 0);
            analogWrite(AQ2, pwm);
        }
    }

    // RIGHT motor (BQ1/BQ2)
    else if (direction == Direction::RIGHT) {
        if (velocity >= 0) {
            analogWrite(BQ1, pwm);
            analogWrite(BQ2, 0);
        } else {
            analogWrite(BQ1, 0);
            analogWrite(BQ2, pwm);
        }
    }
}

// put Direction::STOP
void motor_control(enum Direction direction) {
    if (direction == Direction::STOP) {
        analogWrite(AQ1, 0);
        analogWrite(BQ1, 0);
        analogWrite(AQ2, 0);
        analogWrite(BQ2, 0);
    }
}