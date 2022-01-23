#include<stdio.h>

void fun_print() { printf("a\n \tb\n \t\bc\n\"This is fun\"\n"); }

void alignment() {
    int spacer = 2;
    char* str = "boi";

    printf("");
    printf("%2s", str);
    printf("NEXT_STRING");
    printf("\n");

    /*
    char fmt_str[50];
    sprintf(fmt_str, "%%%ds",spacer); //! Syntactically incorrect
    printf(fmr_str, str);  //! "fmt_str is undeclared" error
    */
}

int main () {
    printf("####STARTED####\n");
    fun_print();
    alignment();

    printf("####ENDED#####\n");
    return 0;
}