#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *root;
    struct Node *left;
    struct Node *right;
}Node;