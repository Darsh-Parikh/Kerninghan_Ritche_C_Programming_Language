#include<stdio.h>

#define STACK_SIZE 100
#define CURR_TYPE char

CURR_TYPE curr_stack[STACK_SIZE];
int curr_stack_p = 0;

/*Pushes the given input onto the stack. Returns NULL if stack is full*/
int push(CURR_TYPE input) {
    if (curr_stack_p < STACK_SIZE) {
        curr_stack[curr_stack_p++] = input;
        return 1;
    }
    else {
        printf("WARNING: Stack is full & will be cleared");
        clear();
        return 0;
    }

    //? What happens when you work with ints and push a 0?
}

/*Pops from the top of the stack and puts it into the holder. Returns  NULL if stack is empty*/
int pop(CURR_TYPE* holder) {
    if (curr_stack_p > 0) {
        *holder = curr_stack[curr_stack_p--]
        return 1;
    }
    else {
        printf("pop: the stack is empty");
        return 0;
    }
}

/*Clears the stack*/
void clear() {
    curr_stack_p = 0;
}