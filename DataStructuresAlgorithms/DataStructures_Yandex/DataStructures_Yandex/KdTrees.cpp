////
////  KdTrees.cpp
////  DataStructures_Yandex
////
////  Created by Taguhi Abgar on 04.02.25.
////
//
//#include "KdTrees.h"
//
//bool Point::lessThanHorizontally(const Point& other) {
//    return x < other.x;
//}
//
//bool Point::lessThanVertically(const Point& other) {
//    return y < other.y;
//}
//
//bool operator==(const Point& a, const Point& b) {
//    return a.x == b.x && a.y == b.y;
//}
//
//KdTreeNode* KdTreeNode::insert(Point elem, Point* parentPtr) {
//    int level = 0;
//    
//    KdTreeNode* node = this;
//    
//    while (node->left && node->right) {
//        if (level % 2 == 0) {
//            if (node->less) {}
//        }
//    }
//    
//    if (left == nullptr && right = nullptr) {}
//    
//    if (elem == _value) {
//        parent = parentPtr;
//        return this;
//    } else if (elem < _value) {
//        if (!left) {
//            left = new BinarySearchTreeNode(elem);
//            left->parent = this;
//            return left;
//        }
//        return left->insert(elem, this);
//    } else {
//        if (!right) {
//            right = new BinarySearchTreeNode(elem);
//            right->parent = this;
//            return right;
//        }
//        return right->insert(elem, this);
//    }
//}
//
//
