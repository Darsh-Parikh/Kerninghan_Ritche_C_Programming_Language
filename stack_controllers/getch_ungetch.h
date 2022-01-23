#include <stdlib.h>

#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE]; /*stack*/
int buff_p = 0; /*stack pointer*/

/*returns the top character from the stack*/
char getch() {
    if (buffer_p > 0) {
        return buffer[--buffer_p];
    }
    else {
        return getchar();
    }
}

/*Pushes back a character onto the stack*/
char ungetch(char c) {
    if (buff_p < BUFFER_SIZE) {
        return (buffer[buff_p++] = c);
    }
    else {
        printf("ungetch error: stack is full")
    }
}