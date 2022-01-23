#ifndef SCIENCE_TO_FLOATS_H
    #define SCIENCE_TO_FLOATS_H

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>

    #define bool int
    #define true 1
    #define false 0

    bool negativeNumber, negativeExponent, inMantisa, inExponent; 
    bool floating, mantisaFloat, exponentFloat, error;
    double mantisa, base, exponent, number;
    int floatDepth;

    void callError(char* error_type) {
        error = 1;
        printf("\nERROR: %s\n", error_type);
    }

    void turn_negative() {
        if (inMantisa) {
            if (negativeNumber) {
                callError("2 negative signs in mantisa");
                return;
            }
            negativeNumber = true;
        } else if (inExponent) {
            if (negativeExponent) {
                callError("2 negative signs in exponent");
                return;
            }
            negativeExponent = true;
        }
    }

    void switch_to_exponent() {
        if (inExponent) {
            callError("Too many 'E' in input");
            return;
        }
        inMantisa = false;
        inExponent = true;
        floating = false;
        floatDepth = 0;
    }

    void store_into(double* container, bool isFloat, int number) {
        // printf("\nAdding %d to %lf\n", number, (*container));
        if (isFloat) {
            (*container) += (number / pow(10, floatDepth));
            floatDepth++;
        }
        else {
            (*container) = ((*container) * 10) + number;
        }
        // printf("Turned it into: %lf\n", (*container));
    }

    void store(char c) {
        if (!(c >= '0' && c <= '9')) {
            if (c == '.') {
                if (floating) { callError("Too many '.' in input"); }
                else { 
                    floating = true; 
                    floatDepth = 1;
                }
            }
            else {
                printf("Unknown character: '%c'", c);
                callError("Invalid character in input. Permisible characters: any digit, 'E', '.', '-'");
            }
            return;
        }
        int curr_d = c - '0';
        if (inMantisa) {
            store_into(&mantisa, floating, curr_d);
            // printf("Added %d to make New MANTISA: %lf\n", curr_d, mantisa);
        }
        else if (inExponent) {
            store_into(&exponent, floating, curr_d);
            // printf("Added %d to make New EXPONENT: %lf\n", curr_d, exponent);
    }
    }

    /*Converts string of scientific notation into a floating point number and returns it*/
    double sc_atof(char* string, char* input_base, bool details) {
        //! NEEDS MORE ERROR HANDLING
        negativeExponent = negativeNumber = inExponent = error = mantisaFloat = exponentFloat = false;
        inMantisa = true;
        mantisa = exponent = number = 0.00;
        base = atof(input_base); //! Detect Errors
        floatDepth = 0;

        char c;
        //? why does it work when not checking for '\0'? If error then it should've printed
        while ((c = *(string++))) {
            // printf("%c", c);
            if (error) {break;}
            
            // ? Somthing for '+'??
            switch (c) {
                case 'E':
                    switch_to_exponent();
                    break;
                case '-':
                    turn_negative();
                    break;
                default:
                    store(c);
                    break;
            }
        }

        exponent = negativeExponent ? -1 * exponent : exponent;
        number = mantisa * pow(base, exponent);
        if (details) {
            printf("\nmantisa: %lf  base: %lf  exponent: %lf  finally: %lf\n", mantisa, base, exponent, number);
        }

        if (negativeNumber) {-1 * number;}
        return number;
    }
#endif