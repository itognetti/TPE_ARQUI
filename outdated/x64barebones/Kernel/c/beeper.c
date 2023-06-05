#include<beeper.h>

void beep(uint32_t beepTime){
	_beep_start(1193180 / beepTime);
}

void stopBeep(){
    _beep_stop();
}