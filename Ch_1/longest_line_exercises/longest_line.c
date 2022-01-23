#include<stdio.h>

#define MAX_SIZE 1000

void copyier(char arrayB[], char arrayA[]) {
    // from arrayA --> arrayB
    int i = 0;
    while ((arrayB[i] = arrayA[i]) != '\0') { ++i; }
}

int getline_ex(int max, char newline[]) {
    int i = 0;
    int c;

    while ((i < max - 1) && ((c = getchar()) != EOF) && (c != '\n')) {
        newline[i] = c;
        ++i;
    }
    if (c == '\n') { 
        ++i;
        newline[i] = c;
        ++i; 
    }
    newline[i] = '\0';

    return i;
}


int main() {
    printf("####STARTED####\n");

    char curr_line[MAX_SIZE];
    int curr_size;
    char longest_line[MAX_SIZE];
    int longest_size = 0;

    // Gets the line. Always true since \n counts as line
    while ((curr_size = getline_ex(MAX_SIZE, curr_line)) > 0) {
        if (curr_size > longest_size) {
            longest_size = curr_size;
            copyier(longest_line, curr_line);
        }
    }

    printf("Longest line was %d characters long\n", longest_size);
    printf("The line was:\n");
    printf("\t\"%s\"\n", longest_line);

    printf("####ENDED#####\n");
    return 0;
}