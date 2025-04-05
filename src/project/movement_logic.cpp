#include "../includes/movement_logic.h"

// button which change state
State change_state(State current_state) {
    if (digitalRead(button) == LOW) {  
        delay(150);
        if (digitalRead(button) == HIGH) {
            motor_control(Direction::STOP);
            switch (current_state) {
                case State::WAIT:
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
    Serial.println(static_cast<int>(state));

    switch (state) {
        case State::WAIT: 
            LED_signal(300);
            break;
        case State::CALIBRATION:
            calibration();
            break;
        case State::START:
            LED_signal(10);
            break;
    }
}