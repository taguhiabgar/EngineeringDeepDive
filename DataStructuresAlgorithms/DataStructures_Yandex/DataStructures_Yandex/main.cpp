//
//  main.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 09.01.25.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "HashTable.h"

void printHashTableContent(const HashTable& hashTable);

int main(int argc, const char * argv[]) {
//    BinarySearchTreeNode<int>* root = new BinarySearchTreeNode<int>(10);
//    
//    root->insert(5, nullptr);
//    root->insert(15, nullptr);
//    root->insert(3, nullptr);
//    root->insert(7, nullptr);
//    root->insert(12, nullptr);
//    root->insert(18, nullptr);
//
//    root->deleteNode(5); // Deletes node with value 5
//    root->deleteNode(15); // Deletes node with value 15
    
    HashTable hashTable(hashPoint3D, 20);
    
    hashTable.insert(Point3D(1, 2, 3));
    hashTable.insert(Point3D(1, 1, 3));
    hashTable.insert(Point3D(1, 1, 4));
    hashTable.insert(Point3D(10, 1, 4));
    
    
    
    return 0;
}
