#include<stdio.h>

void character_counter() {
    long c; // Could even use double for larger is_numbers
    while((c = getchar()) != '\n') { ++c; }
    /* for (c = 0; getchar() != '\n'; ++c); */
    printf("length: %ld", c); printf("\n"); //? Why is this always 10?
}

int main() {
    printf("####STARTED####\n");

    character_counter();

    printf("####ENDED#####\n");
    return 0;
}