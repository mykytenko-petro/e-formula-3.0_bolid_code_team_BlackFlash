#ifndef QTR_SETUP_H
#define QTR_SETUP_H

#include <QTRSensors.h>

extern QTRSensors qtr;
extern const uint8_t SensorCount;
extern uint16_t sensorValues[];

void calibration();

#endif
