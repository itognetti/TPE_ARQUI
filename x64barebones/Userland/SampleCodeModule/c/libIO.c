#include <libIO.h>

void printIn(char *string, int row, int col, int color){
    write(string, row, col, color);
}

void printf(char *string){
    printIn(string, -1, -1, DEFAULT_COLOR);
}

void println(char *string){
    printf(string);
    printf("\n");
}

void printColored(char *string, int color){
    printIn(string, -1, -1, color);
}

void printlnColored(char * string, int color){
    printColored(string, color);
    printf("\n");
}

char getChar(){
    char c;
    read(&c, 1);
    return c;
}

void putChar(char c) {
    char buffer[2];
    buffer[0] = c;
    buffer[1] = '\0';
    printf(buffer);
}

void deleteChar(){
    printf("\b");
}

void scanf(char *buffer, int bufferSize) {
    char c;
    int bufferDim = 0;
    while(((c = getChar()) != '\n') && bufferDim < bufferSize){
        if(c != 0){
            if(c == '\b'){
                if(bufferDim > 0){
                    buffer[--bufferDim] = 0;
                    deleteChar();
                }
            }else{
                buffer[bufferDim++] = c;
                putChar(c);
            }
        }
    }
    buffer[bufferDim] = '\0';
}

char * reverse(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

char * itoa(int num, char* str) {
    int is_negative = 0;
    int i = 0;

    // Manejo de números negativos
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    // Genero la cadena de caracteres en reversa
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num != 0);

    // Agrego el signo negativo si es necesario
    if (is_negative)
        str[i++] = '-';

    str[i] = '\0';

    // Invierto la cadena para obtener el resultado
    reverse(str, i);
}

void printTime(date currentDate){
    printColored("Local time & date: ", PINK);
    char buffer[3] = {0};

    printf(itoa(currentDate->hour, buffer));
    printf(":");
    printf(itoa(currentDate->minutes, buffer));
    printf(":");
    printf(itoa(currentDate->seconds, buffer));
    printf(" ");
    printf(itoa(currentDate->day, buffer));
    printf("/");
    printf(itoa(currentDate->month, buffer));
    printf("/");
    println(itoa(currentDate->year, buffer));
}

// int rand(int from, int to){

// }
