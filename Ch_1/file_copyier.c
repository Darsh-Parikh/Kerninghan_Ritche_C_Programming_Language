#include<stdio.h>

void file_copyier() {                                                           //TODO Write an actual file copier that uses this
    int c;
    while((c = getchar()) != EOF) { putchar(c); }
}

int main() {
    printf("####STARTED####\n");

    file_copyier();

    printf("####ENDED#####\n");
    return 0;
}