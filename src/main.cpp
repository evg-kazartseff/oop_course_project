#include <iostream>
#include "tree.h"

int main()
{
    BST *tree;
    tree = new BST();
    tree->BSTadd("key", "value");
    tree->BSTPrint();
    return 0;
}