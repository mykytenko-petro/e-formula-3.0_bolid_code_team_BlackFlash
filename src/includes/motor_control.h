#pragma once

#include "setup.h"

extern bool is_running;

enum class Direction { LEFT, RIGHT, STOP };

void motor_control(int velocity, enum Direction direction);
void motor_control(enum Direction direction);