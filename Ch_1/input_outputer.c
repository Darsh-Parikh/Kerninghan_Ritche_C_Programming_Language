#include<stdio.h>
#include".\_my_lib\K_R_CProg_linkedList.h" // defines MAXLINE as 1000

/*Returns the size of a line. Stores the line in the supplied character array*/
int getline_io(int max, char newline[]) {
    int c;
    int i = 0;

    while ((i < max - 1) && ((c = getchar()) != EOF) && (c != '\n')) {
        newline[i] = c;
        ++i;
    }
    newline[i] = '\0';

    return i;
}

int main() {
    printf("####STARTED####\n");

    char current_line[MAXLINE];
    int c;
    while ((c = getline_io(MAXLINE, current_line)) > 0) {
        node_ch1* next_line = new_node();
        ll_insert(&next_line);
        copyier(next_line, current_line);
    }
    printf("\nThe input was: \n");
    list_printer('\n');

    list_deleter();

    printf("####ENDED#####\n");
    return 0;
}