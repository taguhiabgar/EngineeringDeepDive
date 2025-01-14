//
//  BinarySearchTree.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 09.01.25.
//

#include "BinarySearchTree.h"

template <typename T>
T BinarySearchTreeNode<T>::value() {
    return _value;
}

template <typename T>
void BinarySearchTreeNode<T>::insert(T elem) {
    if (elem < _value) {
        if (!left) {
            left = new BinarySearchTreeNode(elem);
            return;
        }
        return left->insert(elem);
    } else {
        if (!right) {
            right = new BinarySearchTreeNode(elem);
            return;
        }
        return right->insert(elem);
    }
}

template <typename T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::search(T elem) {
    if (elem == _value) {
        return this;
    } else if (elem < _value) {
        if (!left) {
            return nullptr;
        }
        return left->search(elem);
    } else {
        if (!right) {
            return nullptr;
        }
        return right->search(elem);
    }
}

template <typename T>
bool BinarySearchTreeNode<T>::isBinaryTree() {
    if (left) {
        if (left->value() > _value) {
            return false;
        }
    }
    if (right && right->value() < _value) {
        return false;
    }
    
    bool isLeftBST = left->isBinaryTree();
    bool isRightBST = right->isBinaryTree();
    
    
    return isLeftBST && isRightBST;
}

template <typename T>
T BinarySearchTreeNode<T>::findMaximalValue() {
    if (!right) {
        return _value;
    }
    return right->findMaximalValue();
}

template <typename T>
T BinarySearchTreeNode<T>::findMinimalValue() {
    if (left) {
        return _value;
    }
    return left->findMinimalValue();
}

template <typename T>
void BinarySearchTreeNode<T>::deleteNode(T elem) {
    // removal cases:
    // 1. is a leaf
    // 2. has only 1 subtree
    // 3. has 2 subtrees
    
    
    
    BinarySearchTreeNode* node = elem < _value ? this->left : this->right;
    while(true) {
        if (_value < node->value()) {
            
        }
    }
    
    if (!node->left && !node->right) {
        // is a leaf
        delete node;
        node = nullptr;
    } else if (!node->left) {
        // has only 1 subtree
        node = right;
    } else if (!node->right) {
        // has only 1 subtree
        node = left;
    } else {
        // has 2 subtrees
        
    }
    
    
}


