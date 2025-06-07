#include "../includes/emergency_break.h"

bool is_emergency = false;

// Function to control the emergency break signal based on the sensor signal
void emergency_break(uint16_t position) {
    if (position) {
        if (is_emergency)
        is_running = false;
    } else {
        is_running = true;
    }
}