#include "../includes/LED_debug.h"

void LED_signal(int time) {
    digitalWrite(led_on, HIGH);
    delay(time);
    digitalWrite(led_on, LOW);
    delay(time);
}