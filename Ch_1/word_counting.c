#include<stdio.h>

#define YES 1
#define NO  0

void word_counting_ex() {
    int c, nl, nw, nc, inword;
    inword = NO;
    nl = nw = nc = 0;
    //! Doesnt account for the first line...only counts line changes
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') { ++nl; }
        if(c == ' ' || c == '\n' || c == '\t') { inword = NO; }
        else if(inword == NO) {
            inword = YES;
            ++nw;
        }
    }
    printf("lines: %d; words: %d; characters: %d;\n", nl, nw, nc);
}

void word_counting__1_10() {
    // Prints back all the words...one on each line
    int c, nl, nw, nc, inword;
    inword = NO;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') { ++nl; }
        if(c == ' ' || c == '\n' || c == '\t') { inword = NO; }
        else if(inword == NO) {
            inword = YES;
            ++nw;
        }
    }
    printf("lines: %d; words: %d; characters: %d;\n", nl, nw, nc);
}

void word_counting__1_11() {
    // Conditions for what word seperators are
    int is_number(char c) {
        int int_c = (int)c;
        if (int_c < 10 && int_c >= 0) { return 1; }
        else { return 0; }
    }
    int is_symbol(char c) {
        if (c=='~' || c=='!' || c=='@' || c=='#' || c=='$' || c=='%' || c=='^' || c=='&' || c=='*' || c=='-' || c=='+' || c=='=') { return 1; }
        else { return 0; }
    }
    int is_parenthesis(char c) {
        if (c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']' || c=='<' || c=='>') { return 1; }
        else { return 0; }
    }
    int is_marker(char c) {
        if (c == '`' || c=='_') { return 1; }
        else { return 0; }
    }
    int is_space(char c) {
        if (c==' ' || c=='\n' || c=='\t') { return 1; }
        else { return 0; }
    }

    int c, nl, nw, nc, inword;
    inword = NO;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') { ++nl; }
        if(is_number(c) || is_symbol(c) || is_parenthesis(c) || is_marker(c) || is_space(c)) { inword = NO; }
        else if(inword == NO) {
            inword = YES;
            ++nw;
        }
    }
    printf("lines: %d; words: %d; characters: %d;\n", nl, nw, nc);
}

int main() {
    printf("####STARTED####\n");

    word_counting_ex();
    // word_counting__1_10();
    // word_counting__1_11();

    printf("####ENDED#####\n");
    return 0;
}