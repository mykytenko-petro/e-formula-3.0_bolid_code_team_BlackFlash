#include "../includes/movement_logic.h"

// button which change state
State change_state(State current_state) {
    Serial.println(digitalRead(button));
    if (digitalRead(button) == LOW) {  
        delay(200);
        if (digitalRead(button) == HIGH) {
            motor_control(Direction::STOP);
            switch (current_state) {
                case State::WAIT:
                    calibration_count = 0;
                    return State::CALIBRATION;
                case State::CALIBRATION: 
                    return State::START;
                case State::START: 
                    return State::WAIT;
            }
        }
    }
    return current_state;
}

void movement_logic() {
    uint16_t position = qtr.readLineBlack(sensorValues);

    // emergency_break(position);

    state = change_state(state);

    // Serial.println(static_cast<int>(state));

    if (test) {
        switch (state) {
            case State::WAIT: 

                break;
            case State::CALIBRATION:
                qtr.calibrate();

                break;
            case State::START:
                Serial.println(static_cast<int>(position));

                int delta = PID_calculation(position);
                movement_handler(delta, basespeed);
                break;
        }
    } else {
        switch (state) {
            case State::WAIT: 
                break;
            case State::CALIBRATION:
                calibration();
                break;
            case State::START:
                Serial.println(static_cast<int>(position));

                int delta = PID_calculation(position);
                movement_handler(delta, basespeed);

                break;
        }
    }
}