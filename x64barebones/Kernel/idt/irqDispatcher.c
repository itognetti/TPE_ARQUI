#include <time.h>
#include <stdint.h>

static void int_20();

void irqDispatcher(uint64_t irq) {
	switch (irq) {
		case 0:
			int_20();	//Timer
			break;
		case 1:
			int_21();	//Teclado
			break;
	}
	return;
}

void int_20() {
	timer_handler();
}

void int_21(){
	keyboardHandler();
}
