#include <shell.h>
#include <libIO.h>
#include "../include/syscalls.h"

char * v = (char*)0xB8000 + 79 * 2;

int main() {
	initShell();
	return 0;
}
