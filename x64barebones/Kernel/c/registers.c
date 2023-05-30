#include <registers.h>

#define MAX_DIGITS 20

uint64_t savedRegisters[REGISTERS_COUNT] = {0};
char* registers[REGISTERS_COUNT] = {"R15  ", "R14  ", "R13  ", "R12  ", "R11  ", "R10  ", "R9   ", "R8   ", "RSI  ", "RDI  ", "RBP  ", "RDX  ", "RCX  ", "RBX  ", "RAX  ", "RIP  ", "CS   ", "FLAGS", "RSP  "};

void saveRegistersState(uint64_t *rsp) {
    for (int i = 0; i < REGISTERS_COUNT; i++) {
        savedRegisters[i] = rsp[i];
    }
}

void getRegistersState(uint64_t *buffer) {
    for (int i = 0; i < REGISTERS_COUNT; i++) {
        buffer[i] = savedRegisters[i];
    }
    printRegistersState(buffer);
}

void printRegistersState(uint64_t * rsp){

	char buffer[MAX_DIGITS] = {0};

	println("Registers state: ", RED);
	for(int i = 0; i < REGISTERS_COUNT; i++){
		print("                  ", BLACK);
		print(registers[i], INDIAN_RED);
		print(": ", INDIAN_RED);
		uintToBaseN(rsp[i], buffer, 16);
		println(buffer, INDIAN_RED);
	}
}