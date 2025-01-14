//
//  BinarySearchTree.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 09.01.25.
//

#include <string_view> // std::swap
#include <algorithm>
#include "BinarySearchTree.h"

template <typename T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(T elem) :
    _value(elem), left(nullptr), right(nullptr), parent(nullptr) {
    
}

template <typename T>
T BinarySearchTreeNode<T>::value() {
    return _value;
}

template <typename T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::insert(T elem, T* parentPtr) {
    if (elem == _value) {
        parent = parentPtr;
        return this;
    } else if (elem < _value) {
        if (!left) {
            left = new BinarySearchTreeNode(elem);
            left->parent = this;
            return left;
        }
        return left->insert(elem, this);
    } else {
        if (!right) {
            right = new BinarySearchTreeNode(elem);
            right->parent = this;
            return right;
        }
        return right->insert(elem, this);
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
void BinarySearchTreeNode<T>::mirror() {
    // Swap the left and right children
    std::swap(left, right);

    // Recursively mirror the left and right subtrees
    if (left) {
        left->mirror();
    }
    if (right) {
        right->mirror();
    }
}

template <typename T>
void BinarySearchTreeNode<T>::deleteNode(T elem) {
    // removal cases:
    // 1. is a leaf
    // 2. has only 1 subtree
    // 3. has 2 subtrees
    
    BinarySearchTreeNode* node = search(elem);
    
    if (!node) {
        return;
    }
    
    if (!node->left && !node->right) {
        // is a leaf
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = nullptr;
            } else {
                node->parent->right = nullptr;
            }
        }
        delete node;
        node = nullptr;
    } else if (!node->left) {
        // has only 1 subtree - right
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = node->right;
            } else {
                node->parent->right = node->right;
            }
        }
        node->right->parent = node->parent;
    } else if (!node->right) {
        // has only 1 subtree - left
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = node->left;
            } else {
                node->parent->right = node->left;
            }
        }
        node->left->parent = node->parent;
        delete node;
        node = nullptr;
    } else {
//        // has 2 subtrees
//        BinarySearchTreeNode<T>* successor = node->right;
//        while (successor->left) {
//            successor = successor->left;
//        }
//        // Replace target's value with successor's value
//        node->_value = successor->_value;
//        // Delete the successor node (successor will have at most one child)
//        successor->deleteNode(successor->_value);
    }
    
    
}


