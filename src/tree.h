//
// Created by jonn on 20.11.16.
//

#ifndef TRANSLETE_TREE_H
#define TRANSLETE_TREE_H

#include <string>

using namespace std;

class Node {
private:
    string key;
    string value;
public:
    Node() : key(""), value("") {};
    void SetKey(string key);
    void SetValue(string value);
    string GetKey();
    string GetValue();
};

class Tree {
public:
    virtual void Tadd(string, string) = 0;
    virtual void Tdelete(string) = 0;
};


#endif //TRANSLETE_TREE_H
