#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ch6_tree.h"

treeNodeT* makeNewNode(char* nodeText) {
    treeNodeT* new_branch = (treeNodeT*)malloc(sizeof(treeNodeT));
    new_branch->text = nodeText;
    new_branch->count = 1;
    new_branch->left = new_branch->right = NULL;
    return new_branch;
}

treeNodeT* addNode(char* text, treeNodeT* root) {
    treeNodeT** node_spot;
    if (node_spot = findSpot(text, &root)) {
        treeNodeT* new_node = makeNewNode(text);
        *node_spot = new_node;
        return new_node;
    }
    else {
        printf("A node with that '%s' already exists under the given node\n", text);
        return NULL;
    }
}

treeNodeT* addUnderNode(treeNodeT* node, int right, char* nodeText) {
    // printf("DB: Adding a node under %p\n", node);
    
    treeNodeT* next_node = makeNewNode(nodeText);
    if (right) { node->right = next_node; }
    else { node->left = next_node; }

    printf("DB: Added Node (%p) to the %s of %p\n", next_node, (right ? "right" : "left"), node);
    return next_node;
}


int increment(treeNodeT* treeNode) {
    if (!treeNode) {
        return 0;
    }
    treeNode->count++;
    return 1;
}


void _deleteNode(treeNodeT* root) {
    printf("Deleting Node @ %p\n", root);
    if (!root) { return; }
    if (root->left) {
        _deleteNode(root->left);
        root->left = NULL;
    }
    if (root->right) {
        _deleteNode(root->right);
        root->right = NULL;
    }
    free(root);
}

void deleteAllBelow(treeNodeT* root) {
    _deleteNode(root->left);
    _deleteNode(root->right);
    root->left = root->right = NULL;
}

void deleteAllLeft(treeNodeT* root) {
    deleteAllBelow(root->left);
    _deleteNode(root->left);
    root->left = NULL;
}

void deleteAllRight(treeNodeT* root) {
    deleteAllBelow(root->right);
    _deleteNode(root->right);
    root->right = NULL;
}


treeNodeT** findSpot(char* text, treeNodeT** root) {
    treeNodeT** spot = _findSpotH(text, root);
    if (spot) {
        printf("Correct spot for node with '%s' (@ %p) : %p ... It currently points to %p\n", text, &spot, spot, *spot);
    }
    return spot;
}

treeNodeT** _findSpotH(char* text, treeNodeT** root) {
    if (!(*root)) { return root; }
    int comparison = strcmp(text, (*root)->text);
    if (comparison < 0) {
        return _findSpotH(text, &((*root)->left));
    }
    else if (comparison > 0) {
        return _findSpotH(text, &((*root)->right));
    }
    else { /*Does this need better handling??*/
        increment(*root);
        return NULL;
    }
}


void printNode(treeNodeT* node, char end) {
    if (node) {
        printf("Node @ %p: '%s' occured %d times%c", node, node->text, node->count, end);
    }
    else {printf("NULL%c", end);}
}

void printLeftBranch(treeNodeT* node, char end) {
    printf("\tLeft Child @ %p:\t", &node->left);
    printNode(node->left, end);
}

void printRightBranch(treeNodeT* node, char end) {
    printf("\tRight Child @ %p:\t", &node->right);
    printNode(node->right, end);
}

void printImmediateChildren(treeNodeT* node, char end) {
    printf("Children of node @ %p:\n", node);
    printLeftBranch(node, end);
    printRightBranch(node, end);
    printf("\n");
}

void printNodeAndChild(treeNodeT* node, char end) {
    printNode(node, end);
    printImmediateChildren(node, end);
}

void printTree(treeNodeT* root) {

}


int treeSort(treeNodeT* root) {
    // Sorts everything below the root
}