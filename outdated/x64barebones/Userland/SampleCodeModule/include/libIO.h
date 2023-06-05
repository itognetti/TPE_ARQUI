#ifndef LIBIO_H
#define LIBIO_H

#include <stdint.h>
#include "../include/syscalls.h"
#include <date.h>
#include <stdlib.h>
#include <colors.h>

#define DEFAULT_COLOR 0xFFFFFF //WHITE

void printIn(char *string, int row, int col, int color);
void printf(char *string);
void println(char *string);
void printColored(char *string, int color);
void printlnColored(char * string, int color);
char getChar();
void putChar(char c);
void deleteChar();
void scanf(char *buffer, int bufferSize);
char * reverse(char* str, int length);
char * itoa(int num, char* str);
void printTime(date currentDate);
// int rand(int from, int to);

#endif
