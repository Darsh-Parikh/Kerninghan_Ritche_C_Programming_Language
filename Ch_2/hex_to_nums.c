#include<stdio.h>
#include<math.h>

char* string;
int dg, f, d, man, get_arguements(int, char*[]);
void hton_man();

char type(char c) {
        if (c >= 'a' && c <= 'f') { return 'a'; }
        if (c >= 'A' && c <= 'F') { return 'A'; }
        if (c >= '0' && c <= '9') { return '0'; }
        if (c == 'x' || c == 'X') { return 'x'; }
        else { return c; }
}

// convert hexadecimal to double. Allowable are 0-9, a-f, A-F, '.' (for decimal)
double htod(char* hexadecimal) {
    double number, new;
    int float_depth, floating, error;
    number = new = 0.00;
    floating = float_depth = error = 0;

    char c, form;
    while (c = *(hexadecimal++)) {
        if (c == '0' && type((*hexadecimal)) == 'x') {
            hexadecimal++;
            continue;
        }
        form = type(c);
        switch (form) {
            case '0':
                new = c - '0';
                break;
            case 'a':
                new = (c - 'a') + 10; // c-'W'
                break;
            case 'A':
                new = (c - 'A') + 10; // c-'7'
                break;
            case '.':
                if (floating) {
                    printf("ERROR: Too many '.' in hex string\n");
                    error = 1;
                }
                else { floating = 1; }
                break;
            default :
                printf("ERROR: Encountered invalid character: %c\n", c);
                error = 1;
                break;
        }
        if (error) { break; }

        if (floating) {
            ++float_depth;
            number += new / pow(16, float_depth);
        }
        else {
            number = (number * 16) + new;
        }
    }
    if (error) {
        printf("NOTE: Returning garbage value -1\n");
        return -1;
    }
    return number;
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Incorrect usage. Use only 1 hex string and, if needed, 1 flag\n");
        printf("Possible flags: -f for float OR -d for double");
        return 1;
    }
    dg = 1;
    if (!get_arguements(argc, argv)) {
        if (man) {
            hton_man();
        }
        return 1;
    }

    double value = htod(string);
    if (dg) {
        printf("%s -> %d\n", string, (int)value);
    } else if (f) {
        printf("%s -> %.3f\n", string, (float)value);
    } else if (d) {
        printf("%s -> %.5lf\n", string, value);
    }

    return 0;
}

int get_arguements(int n, char* args[]) {
    //? what if input was: <hex> <gibberish>  rather than: <hex> -<gibberish> ??
    int main_arg_idx = 1;
    for (int j = 1; j < n; ++j) {
        char first_char = *args[j];
        char* curr_arg = args[j];
        // printf("Arguement: %s\n", args[j]);
        if ((curr_arg[0] == '-')) {
            if (curr_arg[2] == '\0') {
                main_arg_idx = (j==1) ? 2 : 1;
                char flag_type = curr_arg[1];
                if (flag_type == 'd') {
                    printf("wants double\n");
                    d = 1;
                    dg = f = 0;
                } else if (flag_type == 'f') {
                    printf("wants float\n");
                    f = 1;
                    dg = d = 0;
                }
                else {
                    printf("Invalid flag character\n");
                    return 0;
                }
            }
            else {
                printf("Invalid flag usage\n");
                return 0;
            }
        } else if (curr_arg[0] == 'm' || curr_arg[0] == 'M') {
            if (
            (curr_arg[1] == 'a' && curr_arg[2] == 'n') || 
            (curr_arg[1] == 'A' && curr_arg[2] == 'N') ) {
                printf("Requested Usage instructions\n");
                man = 1;
            }
            return 0;
        }
    }
    string = args[main_arg_idx];
    return 1;
}

void hton_man() {
    printf("SHOWS USAGE INSTRUCTIONS\n");
}