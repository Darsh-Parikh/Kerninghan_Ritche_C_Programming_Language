// Exercise 1_15
// Prints out all lines over 80 characters. And also if over 998 characters (due to MAXLINE = 1000)

#include <stdio.h>
#include"..\_my_lib\K_R_CProg_linkedList.h" // defines MAXLINE as 1000

#define CHAR_LIMIT 78 // Accounting for \n and \0

/*Returns the size of a line. Stores the line in the supplied character array*/
int getline_1_15(int max, char newline[]) {
    int c;
    int i = 0;

    while ((i < max - 2) && ((c = getchar()) != EOF) && (c != '\n')) {
        newline[i] = c;
        ++i;
    }
    newline[i] = '\0';

    return i;
}

int main() {
    printf("####STARTED####\n");

    int c;
    char current_line[MAXLINE];

    while ((c = getline_1_15(MAXLINE, current_line)) > 0) {
        if (c >= CHAR_LIMIT) {
            node_ch1* a_long_line = new_node();
            ll_insert(a_long_line);
            copyier(a_long_line, current_line);
        }
    }
    printf("The line that crossed the %d character limit are:\n", CHAR_LIMIT);
    list_printer('\n');

    list_deleter();

    printf("####ENDED#####\n");
    return 0;
}