//
// Created by jonn on 03.11.16.
//
#include <iostream>
#include "tree.h"

BSTNode::BSTNode(string key, string value)
{
    this->key = key;
    this->value = value;
    this->left = this->right = NULL;
}

string BSTNode::GetKey()
{
    return (std::__cxx11::string) this->key;
}

string BSTNode::GetValue()
{
    return (std::__cxx11::string) this->value;
}

BSTNode *BSTNode::GetLeft()
{
    return this->left;
}

BSTNode *BSTNode::GetRight()
{
    return this->right;
}

void BSTNode::SetLeft(BSTNode *node)
{
    this->left = node;
}

void BSTNode::SetRight(BSTNode *node) {
    this->right = node;
}


BST::BST()
{
    this->BSTsetRoot(NULL);
}

void BST::BSTadd(string key, string value)
{
    if (this->BSTgetRoot() == NULL) {
        this->BSTsetRoot(new BSTNode(key, value));
        return;
    }
    BSTNode *tmp, *parent;
    tmp = parent = this->BSTgetRoot();
    for(; tmp != NULL;) {
        parent = tmp;
        if (key.compare(tmp->GetKey()) < 0)
                tmp = tmp->GetLeft();
        else
                tmp = tmp->GetRight();
    }
    if (key.compare(parent->GetKey()) < 0) {
        parent->SetLeft(new BSTNode(key, value));
    }
    else {
        parent->SetRight(new BSTNode(key, value));
    }
}

void BST::BSTPrint(BSTNode *node)
{
    if (node == NULL)
        return;
    cout << "key: " << node->GetKey() << endl;
    cout << "value: " << node->GetValue() << endl;
    BST::BSTPrint(node->GetLeft());
    BST::BSTPrint(node->GetRight());
}

BSTNode *BST::BSTlookup(string key) {
    BSTNode *node = NULL;
    for (node = this->BSTgetRoot(); node != NULL;) {
        if (key.compare(node->GetKey()) == 0) {
            return node;
        }
        else if (key.compare(node->GetKey()) < 0) {
            node = node->GetLeft();
        }
        else {
            node = node->GetRight();
        }
    }
    cout << "Key: \"" << key << "\" not found!" << endl;
    return node;
}

BSTNode *BST::BSTgetRoot() {
    return this->root;
}

void BST::BSTsetRoot(BSTNode *node) {
    this->root = node;
}
