#ifndef CH6_TREEDATATYPE_H
    #define CH6_TREEDATATYPE_H

    typedef struct treenode {
        char* text;
        int count;
        struct treenode* left;
        struct treenode* right;
    } tree6node;

    typedef tree6node treeNodeT;
    typedef char* treeDataType;

#endif