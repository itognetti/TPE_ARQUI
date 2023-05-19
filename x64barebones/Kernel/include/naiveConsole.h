#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>

void ncPrint(const char * string);
void ncPrintChar(char character);
void ncNewline();
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();
void printCharColor(uint8_t character, uint8_t attribute);
void printStringColor(const char * string, uint16_t attribute);
void getRTC();
// void convertToGMT3(int * hours, int * days, int * month, int * year);
void ncScanf();
void timerTickIDT();

#endif