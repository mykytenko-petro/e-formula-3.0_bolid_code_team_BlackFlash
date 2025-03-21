#include "../includes/motor_control.h"
#include "../includes/setup.h"

void MotorControl(float delta, int base) {
    int motorspeeda = base + int(delta);
    int motorspeedb = base - int(delta);

    if(delta < 150 && delta > -150) {
        motorspeeda += 30;
        motorspeedb += 30;
    }

    if (motorspeeda > 255) {
        motorspeedb = base - int(delta * 2);
        motorspeeda = 255;
    }
    if (motorspeedb > 255) {
        motorspeeda = base + int(delta * 2);
        motorspeedb = 255;
    }
    if (motorspeeda < 0) motorspeeda = 0;
    if (motorspeedb < 0) motorspeedb = 0;

    analogWrite(LM, motorspeeda);
    analogWrite(RM, motorspeedb);
}

void driver_control(int value) {
    digitalWrite(AQ2, value);
    digitalWrite(BQ2, value);
}
