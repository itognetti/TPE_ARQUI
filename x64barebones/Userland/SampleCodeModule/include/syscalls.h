#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

extern int64_t sys_read(uint64_t fd, const char * buffer, uint64_t count);
extern void sys_write(uint64_t fd, const char * buffer, uint64_t count);

#endif