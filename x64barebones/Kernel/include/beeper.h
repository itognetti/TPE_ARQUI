#include <stdint.h>

extern void _beep_start(uint32_t);

extern void _beep_stop();

void beep(uint32_t beepTime);

void stopBeep();