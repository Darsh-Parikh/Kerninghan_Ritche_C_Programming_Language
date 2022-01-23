#include<stdio.h>

/*copies s into t, while converting all escape characters into actual characters*/
void expand(char* s, char* t) {
    int i = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[i] = '\\';
                ++i;
                t[i] = 'n';
                break;
            case '\t':
                t[i] = '\\';
                ++i;
                t[i] = 't';
                break;
            default:
                t[i] = s[i];
                break;
        }
        ++i;
    }
    t[i] = '\0';
}

int main() {
    char my_string[] = "blue_blah \t, aaa\n";
    char copy[20];

    expand(my_string, copy);
    printf("%s", copy);

    return 0;
}