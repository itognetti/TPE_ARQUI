#include <videoDriver.h>
#include <registers.h>
#include <naiveConsole.h>
#include <colors.h>

#define ZERO_EXCEPTION 0
#define INVALID_OPERATION_CODE 6

static void zeroDivision();
static void invalidOperationCode();
void printSavedRegisters(uint64_t * savedRegisters);

void exceptionDispatcher(int exception, uint64_t * rsp) {
	switch(exception){
		case ZERO_EXCEPTION:
			zeroDivision();
			break;
		case INVALID_OPERATION_CODE:
			invalidOperationCode();
			break;
		}
	printRegistersState(rsp);
}

static void zeroDivision() {
	println("Error - divided by 0 Exception", RED);
}

static void invalidOperationCode(){
	println("Error - invalid operation code Exception", RED);
}

// void printSavedRegisters(uint64_t * savedRegisters){

// 	char buffer[MAX_DIGITS] = {0};

// 	char* registers[REGISTERS_COUNT] = {"R15  ", "R14  ", "R13  ", "R12  ", "R11  ", "R10  ", "R9   ", "R8   ", "RSI  ", "RDI  ", "RBP  ", "RDX  ", "RCX  ", "RBX  ", "RAX  ", "RIP  ", "CS   ", "FLAGS", "RSP  "};
// 	println("Registers state: ", RED);
// 	for(int i = 0; i < REGISTERS_COUNT; i++){
// 		print("                  ", BLACK);
// 		print(registers[i], INDIAN_RED);
// 		print(": ", INDIAN_RED);
// 		uintToBaseN(savedRegisters[i], buffer, 16);
// 		println(buffer, INDIAN_RED);
// 	}
// }
