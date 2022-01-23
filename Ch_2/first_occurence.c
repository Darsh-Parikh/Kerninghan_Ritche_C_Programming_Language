#include<stdio.h>

int any(char*, char*);

int main() {
    //TODO Maybe have the string be passed as arguments to the exec
    char string1[] = "alpha";
    char string2[] = "the_alphabets";

    int s1_in_s2 = any(string1, string2);
    printf("result of finding %s in %s: at character %d\n", string1, string2, s1_in_s2);
    if (s1_in_s2 == -1) {
        printf("Implying not found\n");
    }

    return 0;
}

/*checks if a string (s1) occurs inside another string (s2) and returns its location*/
int any(char* s1, char* s2) {
    int spot = -1;
    int i, j, possibly, occured;
    for (i = j = 0; s2[i] != '\0'; ++i) {
        if (s2[i] == s1[j]) {
            if (!possibly) {
                occured = i;
            }
            possibly = 1;
            j++;
        }
        else {
            j = possibly = 0;
        }
        if (possibly && (s1[j] == '\0')) {
            spot = occured + 1; // since humans don't count from 0
            break;
        }
    }
    return spot;
}