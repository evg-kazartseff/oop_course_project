//
// Created by jonn on 12.11.16.
//

#ifndef TRANSLETE_AVLTREE_H
#define TRANSLETE_AVLTREE_H

#include "BStree.h"

class AVLNode : public Node {
private:
    int height;
    AVLNode *parent;
    AVLNode *left;
    AVLNode *right;
public:
    AVLNode() : parent(NULL), left(NULL), right(NULL) {};
    AVLNode(string key, string value);
    ~AVLNode();

    AVLNode *GetLeft();
    AVLNode *GetRight();
    AVLNode *GetParent();

    void SetLeft(AVLNode *node);
    void SetRight(AVLNode *node);
    void SetParent(AVLNode *node);

    void SetHeight(int h);
    int GetHeight();
};

template <typename T>
class AVLT : public BST<T> {
private:
    T *InsertAVLNode(T *root, T *ins);
    T *Balance(T *root);
    T *RotateLeft(T *root);
    T *RotateRight(T *root);
    T * DeleteAVLNode(T *root, string key);
public:
    AVLT();
    int TGetHeight(T *node);
    int TGetBalance(T *node);
    void Tadd(string key, string value);
    void Tdelete(string key);
};

template <typename T>
AVLT<T>::AVLT()
{
    this->TsetRoot(NULL);
}

template <typename T>
int AVLT<T>::TGetHeight(T *node) {
    return (node != NULL) ? node->GetHeight() : -1;
}

template <typename T>
int AVLT<T>::TGetBalance(T *node)
{
    if (node == NULL)
        return (int) INTMAX_MIN;
    return (this->TGetHeight(node->GetLeft()) - this->TGetHeight(node->GetRight()));
}

template <typename T>
T *AVLT<T>::Balance(T *root)
{
    int balance = TGetBalance(root);
    if (balance > 1) {
        if (TGetBalance(root->GetLeft()) < 0)
            root->SetLeft(RotateLeft(root->GetLeft()));
        root = RotateRight(root);
    }
    else if (balance < -1) {
        if (TGetBalance(root->GetRight()) > 0)
            root->SetRight(RotateRight(root->GetRight()));
        root = RotateLeft(root);
    }
    return root;
}

template <typename T>
T *AVLT<T>::InsertAVLNode(T *root, T *ins)
{
    if (ins->GetKey().compare(root->GetKey()) <= 0) {
        if (root->GetLeft() != NULL) {
            InsertAVLNode(root->GetLeft(), ins);
        }
        else {
            root->SetLeft(ins);
            ins->SetParent(root);
        }
    }
    else {
        if (root->GetRight() != NULL) {
            InsertAVLNode(root->GetRight(), ins);
        }
        else {
            root->SetRight(ins);
            ins->SetParent(root);
        }
    }
    return Balance(root);
}

template <typename T>
T *AVLT<T>::RotateLeft(T *root)
{
    T *newroot = root->GetRight();
    root->SetRight(newroot->GetLeft());
    newroot->SetLeft(root);

    if (root->GetParent() == NULL) {
        this->TsetRoot(newroot);
        newroot->SetParent(NULL);
    }
    else {
        if (root->GetParent()->GetLeft() == root) {
            root->GetParent()->SetLeft(newroot);
        }
        else {
            root->GetParent()->SetRight(newroot);
        }
        newroot->SetParent(root->GetParent());
    }
    root->SetParent(newroot);
    return newroot;
}

template <typename T>
T *AVLT<T>::RotateRight(T *root)
{
    T *newroot = root->GetLeft();
    root->SetLeft(newroot->GetRight());
    newroot->SetRight(root);

    if (root->GetParent() == NULL) {
        this->TsetRoot(newroot);
        newroot->SetParent(NULL);
    }
    else {
        if (root->GetParent()->GetLeft() == root) {
            root->GetParent()->SetLeft(newroot);
        }
        else {
            root->GetParent()->SetRight(newroot);
        }
        newroot->SetParent(root->GetParent());
    }
    root->SetParent(newroot);
    return newroot;
}

template <typename T>
void AVLT<T>::Tadd(string key, string value)
{
    T *NewNode = new T(key, value);
    if (this->TgetRoot() == NULL) {
        this->TsetRoot(NewNode);
        return;
    }
    else
        this->TsetRoot(this->InsertAVLNode(this->TgetRoot(), NewNode));
    return;
}

template <typename T>
T *AVLT<T>::DeleteAVLNode(T *root, string key)
{
    if (root == NULL)
        return root;
    T *tmp;
    if (key.compare(root->GetKey()) == 0) {
        if (root->GetLeft() == NULL || root->GetRight() == NULL) {
            if (root->GetLeft() == NULL)
                tmp = root->GetRight();
            else
                tmp = root->GetLeft();
            delete root;
            return tmp;
        }
        else {
            tmp = AVLT<T>::Tmin(root->GetRight());
            root->SetKey(tmp->GetKey());
            root->SetRight(DeleteAVLNode(root->GetRight(), tmp->GetKey()));
            Balance(root);
        }
    }
    if (key.compare(root->GetKey()) < 0)
        root->SetLeft(DeleteAVLNode(root->GetLeft(), key));
    else if (key.compare(root->GetKey()) > 0)
        root->SetRight(DeleteAVLNode(root->GetRight(), key));
    return Balance(root);
}

template <typename T>
void AVLT<T>::Tdelete(string key)
{
    this->TsetRoot(this->DeleteAVLNode(this->TgetRoot(), key));
}
#endif //TRANSLETE_AVLTREE_H
