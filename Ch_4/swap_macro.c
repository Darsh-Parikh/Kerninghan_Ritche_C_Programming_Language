/* Define a Macro that interchanges its two int arguments */
#include<stdio.h>

//#define SWAP (a, b) for(int i = 0; i == 1; ++j) { int tmp = a; a = b; b = tmp; }
#define SWAP(a, b, T) do{T swap = a; a = b; b = swap;} while(0)

int main() {
    int x = 1;
    int y = 2;

    SWAP(x, y, int);

    printf("x: %d, y: %d", x, y);
    return 0;
}