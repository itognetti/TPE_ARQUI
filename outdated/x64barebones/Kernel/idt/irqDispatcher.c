#include <time.h>
#include <stdint.h>
#include <keyboardDriver.h>

static void int_20();
static void int_21(uint64_t *rsp);

void irqDispatcher(uint64_t irq, uint64_t *rsp) {
	switch (irq) {
		case 0:
			int_20();	//Timer
			break;
		case 1:
			int_21(rsp);	//Teclado
			break;
	}
	return;
}

void int_20() {
	timerHandler();
}

void int_21(uint64_t *rsp){
	keyboardHandler(rsp);
}
