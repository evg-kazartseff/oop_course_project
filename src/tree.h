//
// Created by jonn on 03.11.16.
//

#ifndef TRANSLETE_TREE_H
#define TRANSLETE_TREE_H

using namespace std;

#include <string>

class BSTNode {
public:
    string key;
    string value;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode(string key, string value);
    string ReturnKey();
    string ReturnValue();
};


class BST {
public:
   BSTNode *root;
public:
    BST();
    void BSTadd(string key, string value);
    void BSTPrint();
};
#endif //TRANSLETE_TREE_H
