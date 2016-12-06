//
// Created by jonn on 03.11.16.
//
#include <iostream>
#include "BStree.h"

BSTNode::BSTNode(string key, string value)
{
    this->SetKey(key);
    this->SetValue(value);
    this->SetParent(NULL);
    this->SetLeft(NULL);
    this->SetRight(NULL);
}


BSTNode::~BSTNode()
{
    this->GetKey().clear();
    this->GetValue().clear();
    this->parent = this->left = this->right = NULL;
}


BSTNode *BSTNode::GetLeft()
{
    return this->left;
}


BSTNode *BSTNode::GetRight()
{
    return this->right;
}


BSTNode *BSTNode::GetParent()
{
    return this->parent;
}


void BSTNode::SetLeft(BSTNode *node)
{
    this->left = node;
}

void BSTNode::SetRight(BSTNode *node)
{
    this->right = node;
}

void BSTNode::SetParent(BSTNode *node)
{
    this->parent = node;
}