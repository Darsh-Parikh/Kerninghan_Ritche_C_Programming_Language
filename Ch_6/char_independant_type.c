/* A version of type that is independant of character set*/

/* original type:
    char type(int c) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') { return 'a'; }
        else if (c >= '0' && c <= '9') { return '0'; }
        else { return c; }
    }
*/