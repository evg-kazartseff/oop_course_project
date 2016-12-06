//
// Created by jonn on 21.11.16.
//
#include "tree.h"

string Node::GetKey()
{
    return this->key;
}

string Node::GetValue()
{
    return this->value;
}

void Node::SetKey(string key)
{
    this->key = key;
}

void Node::SetValue(string value)
{
    this->value = value;
}