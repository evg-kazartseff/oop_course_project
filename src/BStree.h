//
// Created by jonn on 03.11.16.
//

#ifndef TRANSLETE_BSTREE_H
#define TRANSLETE_BSTREE_H

using namespace std;

#include <string>
#include "tree.h"
#include <iostream>


class BSTNode : public Node {
private:
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode() : parent(NULL), left(NULL), right(NULL) {};
    BSTNode(string key, string value);
    ~BSTNode();
    BSTNode *GetLeft();
    BSTNode *GetRight();
    BSTNode *GetParent();

    void SetLeft(BSTNode *node);
    void SetRight(BSTNode *node);
    void SetParent(BSTNode *node);
};




template <typename T>
class BST : public Tree {
private:
   T *root;
public:
    BST();
    void TsetRoot(T *node);
    T *TgetRoot();
    void Tadd(string key, string value);
    void Tprint(T *node);
    virtual T *Tlookup(string key);
    void Tdelete(string key);
    virtual T *Tmax(T *root);
    virtual T *Tmin(T *root);
    virtual ~BST();
};

template <typename T>
BST<T>::BST()
{
    this->TsetRoot(NULL);
}

template <typename T>
void BST<T>::TsetRoot(T *node)
{
    this->root = node;
}

template <typename T>
T *BST<T>::TgetRoot()
{
    return this->root;
}

template <typename T>
void BST<T>::Tadd(string key, string value)
{
    if (this->TgetRoot() == NULL) {
        this->TsetRoot(new T(key, value));
        return;
    }
    T *tmp, *parent;
    tmp = parent = this->TgetRoot();
    for(; tmp != NULL;) {
        parent = tmp;
        if (key.compare(tmp->GetKey()) < 0)
            tmp = tmp->GetLeft();
        else
            tmp = tmp->GetRight();
    }
    if (key.compare(parent->GetKey()) < 0) {
        parent->SetLeft(new T(key, value));
        parent->GetLeft()->SetParent(parent);
    }
    else {
        parent->SetRight(new T(key, value));
        parent->GetRight()->SetParent(parent);
    }
}

template <typename T>
T *BST<T>::Tlookup(string key)
{
    T *node = NULL;
    for (node = this->TgetRoot(); node != NULL;) {
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
    return node;
}

template <typename T>
void BST<T>::Tprint(T *node)
{
    if (node == NULL)
        return;
    cout << "key: " << node->GetKey() << endl;
    cout << "value: " << node->GetValue() << endl;
    Tprint(node->GetLeft());
    Tprint(node->GetRight());
}



template <typename T>
void BST<T>::Tdelete(string key)
{
    T *node = this->Tlookup(key);
    if (node == NULL)
        return;
    if (node->GetLeft() == NULL && node->GetRight() == NULL) {
        if (node->GetParent()->GetLeft() == node) {
            node->GetParent()->SetLeft(NULL);
            delete node;
        }
        if (node->GetParent()->GetRight() == node) {
            node->GetParent()->SetRight(NULL);
            delete node;
        }
    }
    else if (node->GetLeft() == NULL || node->GetRight() == NULL) {
        if (node->GetParent()->GetLeft() == node) {
            if (node->GetLeft() != NULL) {
                node->GetParent()->SetLeft(node->GetLeft());
                node->GetLeft()->SetParent(node->GetParent());
                delete node;
            }
            else if (node->GetRight() != NULL) {
                node->GetParent()->SetLeft(node->GetRight());
                node->GetRight()->SetParent(node->GetParent());
                delete node;
            }
        }
        else if (node->GetParent()->GetRight() == node) {
            if (node->GetLeft() != NULL) {
                node->GetParent()->SetRight(node->GetLeft());
                node->GetLeft()->SetParent(node->GetParent());
                delete node;
            }
            else if (node->GetRight() != NULL) {
                node->GetParent()->SetRight(node->GetRight());
                node->GetRight()->SetParent(node->GetParent());
                delete node;
            }
        }
    }
    else {
        T *rep = Tmin(node->GetRight());
        if (rep != NULL) {
            string tmpKey = rep->GetKey();
            string tmpValue = rep->GetValue();
            Tdelete(rep->GetKey());
            node->SetKey(tmpKey);
            node->SetValue(tmpValue);
        }
    }

}

template <typename T>
T *BST<T>::Tmax(T *root)
{
    if (root == NULL)
        return  NULL;
    if (root->GetRight() == NULL)
        return root;
    return Tmax(root->GetRight());
}

template <typename T>
T *BST<T>::Tmin(T *root)
{
    if (root == NULL)
        return  NULL;
    if (root->GetLeft() == NULL)
        return root;
    return Tmin(root->GetLeft());
}

template <typename T>
BST<T>::~BST()
{
    T *node = this->Tmin(this->TgetRoot());
    if (node == NULL)
        return;
    this->Tdelete(node->GetKey());
    this->~BST();
}

#endif //TRANSLETE_BSTREE_H