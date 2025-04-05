#include "../includes/calibration.h"

// TODO: make automatic calibration
int rotation = 0;
Direction side = Direction::LEFT;

void calibration() {
    qtr.calibrate();

    if (rotation <= 0)
    {
        motor_control(50, Direction::RIGHT);
    }
    
}