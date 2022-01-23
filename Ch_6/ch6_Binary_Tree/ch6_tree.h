#ifndef CH6_TREE
    #define CH6_TREE
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include"ch6_treeDatatype.h" // contains treeNodeT


    /*Dynamically creates a new node and initializes it with the given string.
    Returns a pointer to that string.
    Should usually be used for creating roots of trees only*/
    treeNodeT* makeNewNode(char*);
    /*Creates a node immediately under the arguement node. Can overwrite existing nodes.
    2nd Arguement should be 0 to add to the left branch, 1 to add to the right.
    Returns a pointer to the newly created node.*/
    treeNodeT* addUnderNode(treeNodeT*, int, char*);
    /*Creates a node and places it in its right place respective to the arguement node.
    Returns a poinnter to that created node.
    Returns NULL if a node with that text already exists.*/
    treeNodeT* addNode(char*, treeNodeT*);


    /*Deletes a node and everything under it
    Should only be called on roots usually, once everything below the root is also deleted*/
    void _deleteNode(treeNodeT*);
    /*Deletes everything under a certain node.*/
    void deleteAllBelow(treeNodeT*);
    /*Deletes a tree structure under the left side of a tree*/
    void deleteAllLeft(treeNodeT*);
    /*Deletes a tree structure under the right side of a tree*/
    void deleteAllRight(treeNodeT*);


    /*Increments the counter in the given node. 
    Returns 1 if successful, 0 if not.*/
    int increment(treeNodeT*);


    /*The actual algorithm for finding spots. To be used by findSpot*/
    treeNodeT** _findSpotH(char*, treeNodeT**);
    /*Finds the exact spot (exactly which branch) of a node from text input. 
    Takes the address of some root node, and returns the address where the new 
    node belongs. 
    Returns NULL if a node with that text exists.*/
    treeNodeT** findSpot(char*, treeNodeT**);


    /*Prints info about a particular node.
    Also takes a character to end the print with.*/
    void printNode(treeNodeT*, char);
    /*Prints info about a particluar node.
    Also takes a character to end the print with.*/
    void printLeftBranch(treeNodeT*, char);
    /*Prints info about the right child of a particular node.
    Also takes a character to end the print with.*/
    void printRightBranch(treeNodeT*, char);
    /*Prints info about the immediate children of a particular node.
    Also takes a character to end the print with.*/
    void printImmediateChildren(treeNodeT*, char);
    /*Prints info about a node and its immediate children. 
    Also takes a character which it uses to end the print with.*/
    void printNodeAndChild(treeNodeT*, char);
    /*Prints info about the entire tree structure under the arguement node.*/
    void printTree(treeNodeT*);


    /*Sorts the tree structure under the root, modifying the arguement as well if necessary.*/
    int treeSort(treeNodeT*);

#endif