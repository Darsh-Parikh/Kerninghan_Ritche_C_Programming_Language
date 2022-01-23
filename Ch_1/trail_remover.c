// Exercise 1_16
// Removes trailing blanks and tabs from input. Deletes empty lines

#include <stdio.h>

#include".\_my_lib\K_R_CProg_linkedList.h" // defines MAXLINE as 1000

/*Returns the size of a line. Stores the line in the supplied character array*/
int getline_1_16(int max, char newline[]) {
    int c, space_occured, space_where;
    int i = 0;

    while ((i < max - 2) && ((c = getchar()) != EOF) && (c != '\n')) {
        if (c == ' ' || c == '\t' || c == '|') {
            space_occured = 1;
            space_where = i;    
        }
        else if (space_occured && (c != ' ' || c != '\t' || c == '|')) {
            space_occured = 0;
            space_where = -1;
        }
        newline[i] = c;
        ++i;
    }
    if (c == '\n') {
        if (space_occured) {
            // for (int j = space_where; j < i; ++j) { newline[j] = ' '; }
            i = space_where;
            newline[i] = '|';
            ++i;
        }
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

    while ((c = getline_1_16(MAXLINE, current_line)) > 0) {
        node_ch1* next_line = new_node();
        ll_insert(next_line);
        copyier(next_line, current_line);
    }
    
    printf("Your input was:\n");
    list_printer('\n');

    list_deleter();

    printf("####ENDED#####\n");
    return 0;
}