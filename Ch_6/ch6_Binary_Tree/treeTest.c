#include<stdio.h>
#include"ch6_tree.h"

int main() {
    treeNodeT* root = makeNewNode("Root");
    treeNodeT* left = addUnderNode(root, 0, "LRoot");
    treeNodeT* right = addUnderNode(root, 1, "SRoot");
    treeNodeT* left1 = addUnderNode(left, 0, "LeftLeft");
    treeNodeT* right1 = addUnderNode(left, 1, "LeftRight");
    // Test for addNode and findSpot
    treeNodeT* leftleft2 = addNode("AA", root);

    // Tree state
    printf("\nRoot: \n");
    printNodeAndChild(root, '\n');
    printf("Left Side (1): \n");
    printNodeAndChild(left, '\n');
    printf("Right Side (1): \n");
    printNodeAndChild(right, '\n');
    printf("Left Side of Left (2): \n");
    printNodeAndChild(left1, '\n');
    printf("Right Side of Left (2): \n");
    printNodeAndChild(right1, '\n');
    printf("And the newest: \n");
    printNodeAndChild(leftleft2, '\n');

    deleteAllBelow(root);
    _deleteNode(root);
    return 0;
}
