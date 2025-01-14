//
//  BinarySearchTree.h
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 09.01.25.
//


/*
 1) Enhance structure of Node of Binary search tree, so that it will keep also pointer to the parent node. For root node that parent should be null. All other nodes should have non-null parent pointer. Make necessary updates of "parent" during insertion.
 2) Finish implementation of removal from Binary search tree. Recall the 3 different cases (removing node with no child nodes, removing node with 1 child node, removing node with 2 child nodes). You can use the "parent" pointer to make removal easier.
 3) Implement mirroring of Binary search tree (horizontal flip). So if previously the tree was storing values in ascending order, after the mirroring it will keep the same values in descending order. Implement mirroring in 2 ways - recursive and iterative.
 */

template <typename T>
class BinarySearchTreeNode {
    
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
    BinarySearchTreeNode *parent;
    T _value;
    
public:
    BinarySearchTreeNode(T elem);
    
    BinarySearchTreeNode* insert(T value, T* parentPtr = nullptr);
    BinarySearchTreeNode* search(T value);
    void mirror();
    bool isBinaryTree();
    
    T findMaximalValue();
    T findMinimalValue();
    void deleteNode(T value);
    
    T value();
    
};
