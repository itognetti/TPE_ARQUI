#include <string.h>

int strlen(char *string){
    int count = 0;
    while (string[count] != 0) {
        count++;
    }
    return count;
}

int strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    return (str1[i] - str2[i]);
}

