#include "../includes/square_movement.h"

void square_movement() {
    motor_control(100, Direction::LEFT);
    motor_control(100, Direction::RIGHT);
}