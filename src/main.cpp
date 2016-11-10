#include <iostream>
#include "tree.h"

int main()
{
    BST *tree;
    tree = new BST();
    tree->BSTadd("key", "value");
    tree->BSTadd("lim", "rer");
    tree->BSTadd("asd", "qeer");
    BSTNode *look = tree->BSTlookup("lim");
    cout << "look: " << look->GetKey() << endl;
    tree->BSTPrint(tree->BSTgetRoot());
    return 0;
}