//
// Created by jonn on 03.11.16.
//

#ifndef TRANSLETE_TREE_H
#define TRANSLETE_TREE_H

using namespace std;

#include <string>

class BSTNode {
private:
    string key;
    string value;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode() : key("") , value(""), left(NULL), right(NULL) {};
    BSTNode(string key, string value);
    BSTNode *GetLeft();
    BSTNode *GetRight();
    void SetLeft(BSTNode *node);
    void SetRight(BSTNode *node);
    string GetKey();
    string GetValue();
};


class BST {
private:
   BSTNode *root;
public:
    BST();
    void BSTsetRoot(BSTNode *node);
    BSTNode *BSTgetRoot();
    void BSTadd(string key, string value);
    void BSTPrint(BSTNode *node);
    BSTNode *BSTlookup(string key);
};
#endif //TRANSLETE_TREE_H
