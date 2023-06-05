#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>
#include <colors.h>
#include <videoDriver.h>
#include <naiveConsole.h>

#define REGISTERS_COUNT 19

#define R15 0
#define R14 1
#define R13 2
#define R12 3
#define R11 4
#define R10 5
#define R9 6
#define R8 7
#define RSI 8
#define RDI 9
#define RBP 10
#define RDX 11
#define RCX 12
#define RBX 13
#define RAX 14
#define RIP 15
#define CS 16
#define FLAGS 17
#define RSP 18

void saveRegistersState(uint64_t *rsp);
void getRegistersState(uint64_t *buffer);
void printRegistersState(uint64_t * savedRegisters);

#endif
