#include <time.h>

static unsigned long ticks = 0;

void timerHandler() {
	ticks++;
}

int ticksElapsed() {
	return ticks;
}

int secondsElapsed() {
	return ticks / 18;
}

void holder(int milliseconds) {
	int startTicks = ticksElapsed();
    int endTicks = startTicks + milliseconds / 18;
    while (ticksElapsed() < endTicks) {
        _hlt();
    }
}
