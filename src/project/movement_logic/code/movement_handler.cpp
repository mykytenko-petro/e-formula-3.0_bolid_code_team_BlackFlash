#include "../includes/movement_handler.h"

void movement_handler(float delta, int base) {
    int motorspeeda = base + int(delta);
    int motorspeedb = base - int(delta);

    if (delta < 150 && delta > -150) {
        motorspeeda+=30;
        motorspeedb+=30;
    }

    if (motorspeeda > 255) {
        motorspeedb = base - int(delta*2);
        motorspeeda = 255;
    } 
    if (motorspeedb > 255) {
        motorspeeda = base + int(delta*2);
        motorspeedb = 255;
    } 
    if (motorspeeda < 0) motorspeeda = 0;
    if (motorspeedb < 0) motorspeedb = 0;

    motor_control(motorspeeda, Direction::LEFT);
    motor_control(motorspeedb, Direction::RIGHT);
}