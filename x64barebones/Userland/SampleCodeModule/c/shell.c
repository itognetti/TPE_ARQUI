#include <shell.h>

extern void sys_write();

void initShell(){
    sys_write(STDOUT, "hola", 4);
}