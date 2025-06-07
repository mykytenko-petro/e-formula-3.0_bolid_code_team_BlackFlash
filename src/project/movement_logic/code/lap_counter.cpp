#include "../includes/lap_counter.h"

int lap = 0;

void lap_counter(int position) {
    if (position) {
        lap += 1;
    }
    if (lap > 2) {
        state = State::WAIT;
    }
}