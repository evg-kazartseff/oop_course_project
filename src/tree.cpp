//
// Created by jonn on 03.11.16.
//
#include <iostream>
#include "tree.h"

BSTNode::BSTNode(string key, string value)
{
    this->key = key;
    this->value = value;
}

string BSTNode::ReturnKey()
{
    return  this->key;
}

string BSTNode::ReturnValue()
{
    return this->value;
}


BST::BST()
{
    this->root = NULL;
}

void BST::BSTadd(string key, string value)
{
    if (this->root == NULL) {
        this->root = new BSTNode(key, value);
        return;
    }
    BSTNode *tmp;
    for(tmp = this->root; tmp != NULL;) {
        if (key < tmp->key)
            if (tmp->left == NULL)
                tmp->left = new BSTNode(key, value);
            else
                tmp = tmp->left;
        else
            if (tmp->right == NULL)
                tmp->right = new BSTNode(key, value);
            else
                tmp = tmp->right;
    }
}

void BST::BSTPrint()
{
    cout << this->root->ReturnKey() << endl;
    cout << this->root->ReturnValue() << endl;
}