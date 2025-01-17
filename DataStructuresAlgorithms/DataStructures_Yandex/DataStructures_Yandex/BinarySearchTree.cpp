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
        // has 2 subtrees
        BinarySearchTreeNode<T>* successor = node->right;
        while (successor->left) {
            successor = successor->left;
        }
        // Replace target's value with successor's value
        node->_value = successor->_value;
        // Delete the successor node (successor will have at most one child)
        successor->deleteNode(successor->_value);
    }
}

//1) Design and implement algorithm for iterative pre-order traversal. So
//given a node, if finds the pre-order next node.
//Reminder: during preorder traversal,
//• at first we mention root node, then
//• do recursive pre-order traversal of left subtree (if present)
//• do recursive pre-order traversal of right subtree (if present).
template <typename T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::preOrderNextNode(BinarySearchTreeNode<T>* item) {
    if (!item) {
        return nullptr;
    }
    T value = item->value();
    if (item->left) {
        return item->left;
    }
    if (item->right) {
        return item->right;
    }
    // if achieved this point, item is a leaf node
    if (!item->parent) {
        return nullptr;
    }
    if (item->parent->right && item->parent->right != value) {
        return item->parent->right;
    }
    BinarySearchTreeNode<T>* node = item;
    while (node->parent && (!node->parent->right || node->parent->right <= value)) {
        node = node->parent;
    }
    if (node->parent && node->parent->right && node->parent->right > value) {
        return node->parent->right;
    }
    return nullptr;
}

template <typename T>
int BinarySearchTreeNode<T>::minLeafDepthInternal(int depth) {
    if (!left && !right) {
        return depth;
    }
    if (!left) {
        return right->minLeafDepthInternal(depth + 1);
    }
    if (!right) {
        return left->minLeafDepthInternal(depth + 1);
    }
    // left && right
    int leftMinDepth = left->minLeafDepthInternal(depth);
    int rightMinDepth = right->minLeafDepthInternal(depth);
    return std::min(leftMinDepth, rightMinDepth);
}

template <typename T>
int BinarySearchTreeNode<T>::maxLeafDepthInternal(int depth) {
    if (!left && !right) {
        return depth;
    }
    if (!left) {
        return right->maxLeafDepthInternal(depth + 1);
    }
    if (!right) {
        return left->maxLeafDepthInternal(depth + 1);
    }
    // left && right
    int leftMinDepth = left->maxLeafDepthInternal(depth);
    int rightMinDepth = right->maxLeafDepthInternal(depth);
    return std::max(leftMinDepth, rightMinDepth);
}

template <typename T>
int BinarySearchTreeNode<T>::minLeafDepth() {
    return minLeafDepthInternal(1);
}

template <typename T>
int BinarySearchTreeNode<T>::maxLeafDepth() {
    return maxLeafDepthInternal(1);
}

//2) Write a function which will calculate "balanceness" of provided Binary
//tree. Balanceness here is the ratio between depth of the leaf closest to
//root and depth of the leaf farthest from root.
template <typename T>
double balanceness(BinarySearchTreeNode<T>* root) {
    int minDepth = root->minLeafDepth();
    int maxDepth = root->maxLeafDepth();
    return static_cast<double>(minDepth) / maxDepth;
}

template <typename T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::inOrderPredecessor() {
    BinarySearchTreeNode<T>* node = this;
    T val = node->value();
    if (node && node->left) {
        // return maximal element in left subtree
        return findMaximalValue(node->left);
    }
    while (node->parent && node->parent->value() < val) {
        node = node->parent;
    }
    if (node->value() == val) {
        return nullptr;
    }
    return node;
}

template <typename T>
BinarySearchTreeNode<T>* batchConstructionInternal(std::vector<T> values, int start, int end) {
    int medianIndex = (start + end) / 2;
    T median = values[medianIndex];
    BinarySearchTreeNode<T>* root = new BinarySearchTreeNode<T>(median(values));
    root->left = batchConstructionInternal<T>(values, 0, medianIndex);
    root->right = batchConstructionInternal<T>(values, medianIndex + 1, end);
    return root;
}

template <typename T>
BinarySearchTreeNode<T>* batchConstruction(std::vector<T> values) {
    if (values.empty()) {
        return nullptr;
    }
    std::sort(values.begin(), values.end());
    return batchConstructionInternal(values, 0, values.size());
}
