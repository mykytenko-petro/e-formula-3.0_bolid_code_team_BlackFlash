#include "../includes/calibration.h"

// TODO: make automatic calibration
int step = -1;
int rotation = 0;
int rotation_speed = 255;
int calibration_count = 0;
Direction side = Direction::LEFT;

void calibration() {
    if (calibration_count < 10){
        qtr.calibrate();

        rotation += step;

        if (rotation < -3) {
            side = Direction::RIGHT;
            step = 1;
        } else if (rotation > 3) {
            side = Direction::LEFT;
            step = -1;
        }

        if (side == Direction::RIGHT && rotation == 0) {
           calibration_count += 1;
        }

        // Serial.println(rotation);

        if (side == Direction::LEFT) {
            motor_control(rotation_speed, Direction::RIGHT);
            motor_control(-rotation_speed, Direction::LEFT);
        } else {
            motor_control(-rotation_speed, Direction::RIGHT);
            motor_control(rotation_speed, Direction::LEFT);
        }
    } else {
        motor_control(Direction::STOP);
    }
}