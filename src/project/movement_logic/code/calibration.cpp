#include "../includes/calibration.h"

// TODO: make automatic calibration
int rotation = 0;
Direction side = Direction::LEFT;

void calibration() {
    qtr.calibrate();

    if (side == Direction::LEFT)
    {
        motor_control(50, Direction::RIGHT);
        motor_control(-50, Direction::LEFT);
    }
    
}