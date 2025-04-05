#include "../includes/motor_control.h"

// function which simplify motors control
void motor_control(int velocity, enum Direction direction) {
    if (velocity > 255) {
        velocity = 255;
    }

    switch (direction) {
        case Direction::LEFT:
            analogWrite(LM, velocity);
            break;

        case Direction::RIGHT:
            analogWrite(RM, velocity);
            break;
    }
}

void motor_control(enum Direction direction) {
    analogWrite(LM, 0);
    analogWrite(RM, 0);
}