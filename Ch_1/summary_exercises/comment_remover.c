// 1_22
// Don't forget to handle quotes strings and character constants properly

#include <stdio.h>
#include "..\_my_lib\K_R_CProg_linkedList.h"

int getline_cr(int max, char* new_line) {
    int size, c, possible_comment;
    size = c = possible_comment = 0;

    while ((size < max-1) && ((c = getchar()) != EOF) && (c != '\n')) {
        if (possible_comment && (c == '/')) {
            new_line[size-1] = '\n';
            while ((c = getchar()) != EOF && (c != '\n'));
            c = 0;
            break;
        }
        else if (possible_comment) {
            possible_comment = 0;
        }
        else if (c == '/') {
            possible_comment = 1;
        }
        new_line[size] = c;
        ++size;
    }
    new_line[size] = '\0';

    return size;
}

int main() {
    printf("####STARTED####\n");
    
    char input_line[MAXLINE];
    int c;

    while ((c = getline_cr(MAXLINE, input_line)) > 0) {
        // if (c == 1) { continue; }
        node_ch1* another_line = new_node();
        ll_insert(&another_line);
        copyier(another_line, input_line);
    }
    printf("\nThe input was: \n");
    list_printer('\n');

    list_deleter();

    printf("####ENDED#####\n");
    return 0;
}