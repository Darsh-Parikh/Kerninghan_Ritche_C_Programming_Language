#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 1000

// The almighty Linked List!! Only for ch 1 stuff and stores character arrays
typedef struct linkListNode_ch1 {
    char inputLine[MAXLINE];
    struct linkListNode_ch1* _next_;
} node_ch1;

node_ch1* Head = NULL;
node_ch1* Last = NULL;

/*Dynamically allocates memory for a linked list node and returns the pointer to it*/
node_ch1* new_node() {
    node_ch1* generated_node = (node_ch1*)malloc(sizeof(node_ch1));
    generated_node->_next_ = NULL;
    return generated_node;
}

/*Inserts a new linked list node after the head node
head->new_node->rest*/
void llhead_insert(node_ch1** new_node) {
    (*new_node)->_next_ = Head;
    Head = *new_node;
}

/*Inserts a new linked list node between 2 existing nodes, given pointers to all three
a->new_node->b*/
void llmid_insert(node_ch1** new_node, node_ch1** a, node_ch1** b) {
    (*new_node)->_next_ = *b;
    (*a)->_next_ = *new_node;   
}

/*Inserts a new linked list node at the end of the existing list*/
void ll_insert(node_ch1** new_node) {
    if (!Last) {
        Head = *new_node;
        Last = *new_node;
    }
    else {
        Last->_next_ = *new_node;
        Last = *new_node;
    }
}

/*Returns the size of a linked list when given a pointer to the head node*/
int ll_size() {
    int l_size = 0;
    node_ch1* current_node = Head;
    while(current_node) {
        ++l_size;
        current_node = current_node->_next_;
    }
    return l_size;
}

/*Copies the given character array into the character array in the given reference to the linked list node*/
void copyier(node_ch1* nodeA, char arrayA[]) {
    for (int i = 0; (nodeA->inputLine[i] = arrayA[i]) != '\0'; ++i);
}

/*Prints the character array of the linked list node when given a pointer to the head node
arguments:
end : which character to end the line with
length : pass 'l' to get the length of the string printed right after the line*/
void list_printer(char end, char length) {
    int l = 0;
    node_ch1* current_node = Head;
    while (current_node) {
        if (length == 'L') {
            for (l = 0; current_node->inputLine[l] != '\0'; ++l);
            printf(" %s[%d]%c", current_node->inputLine, l, end);
        }
        else { printf(" %s%c", current_node->inputLine, end); }
        current_node = current_node->_next_;
    }
}

/*deletes a linked list when given a pointer to the head node*/
void list_deleter() {
    node_ch1* current_node = Head;
    while (current_node) {
        node_ch1* tmp = current_node->_next_;
        free(current_node);
        current_node = tmp;
    }
    // free(Head);
}