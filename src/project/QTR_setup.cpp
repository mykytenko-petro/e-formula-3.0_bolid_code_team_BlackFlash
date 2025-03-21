#include "../includes/QTR_setup.h"
#include "../includes/setup.h"

QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

void calibration() {
    delay(1000);
    for (uint16_t i = 0; i < 200; i++)  {
        qtr.calibrate();
    }
}
