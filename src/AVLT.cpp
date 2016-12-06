//
// Created by jonn on 12.11.16.
//

#include "AVLT.h"

AVLNode::AVLNode(string key, string value)
{
    this->SetKey(key);
    this->SetValue(value);
    this->SetHeight(1);
    this->SetParent(NULL);
    this->SetLeft(NULL);
    this->SetRight(NULL);
}

AVLNode::~AVLNode()
{
    this->GetKey().clear();
    this->GetValue().clear();
    this->parent = this->left = this->right = NULL;
}

void AVLNode::SetHeight(int h)
{
    this->height = h;
}

int AVLNode::GetHeight()
{
    return this->height;
}

AVLNode *AVLNode::GetLeft()
{
    return this->left;
}

AVLNode *AVLNode::GetRight()
{
    return this->right;
}

AVLNode *AVLNode::GetParent() {
    return this->parent;
}

void AVLNode::SetLeft(AVLNode *node)
{
    this->left = node;
}

void AVLNode::SetRight(AVLNode *node)
{
    this->right = node;
}

void AVLNode::SetParent(AVLNode *node)
{
    this->parent = node;
}
