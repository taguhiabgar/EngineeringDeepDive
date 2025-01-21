//
//  main.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 09.01.25.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "HashTable.h"
#include "DynamicProgramming_Memoization.h"

void printHashTableContent(const HashTable& hashTable);

void BSTDriverProgram() {
//    BinarySearchTreeNode<int>* root = new BinarySearchTreeNode<int>(10);
//    root->insert(5, nullptr);
//    root->insert(15, nullptr);
//    root->insert(3, nullptr);
//    root->insert(7, nullptr);
//    root->insert(12, nullptr);
//    root->insert(18, nullptr);
//
//    root->deleteNode(5); // Deletes node with value 5
//    root->deleteNode(15); // Deletes node with value 15
}

void HashTableDriverProgram() {
    HashTable hashTable(hashPoint3D, 20);
    
    hashTable.insert(Point3D(1, 2, 3));
    hashTable.insert(Point3D(1, 1, 3));
    hashTable.insert(Point3D(1, 1, 4));
    hashTable.insert(Point3D(10, 1, 4));
}

void DynamicProgrammingDriverProgram() {
    Problem1();
}


int main(int argc, const char * argv[]) {


    
    DynamicProgrammingDriverProgram();
    
    
    
    return 0;
}
