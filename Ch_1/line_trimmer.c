#include<stdio.h>
#include".\_my_lib\K_R_CProg_linkedList.h"

void line_trimmer(char* long_line, int cliff) {
    // --cliff;
    int i = 0;
    while ((i < cliff) && (long_line[i] != '\0')) { ++i; }
    if (long_line[i] == '\0' || long_line[i] == ' ') {}
    else {
        while (i > cliff-3) {
            long_line[i] = '.';
            --i;
        }
        long_line[cliff] = '\0';
    }
    
}

int getline_lf(int max, char* new_line) {
    int size = 0; 
    int c;

    while ((size < max-1) && ((c = getchar()) != EOF) && (c != '\n')) {
        new_line[size] = c;
        ++size;
    }
    new_line[size] = '\0';

    return size;
}

int main() {
    // get cliff from input...
    
    printf("####STARTED####\n");

    char next_line[MAXLINE];
    int c;
    while ((c = getline_lf(MAXLINE, next_line)) > 0) {
        line_trimmer(next_line, 20);
        
        node_ch1* another_line = new_node();
        ll_insert(&another_line);
        copyier(another_line, next_line);
    }
    printf("Input was:\n");
    list_printer('\n', 'L');

    list_deleter();

    printf("####ENDED#####\n");
    return 0;
}