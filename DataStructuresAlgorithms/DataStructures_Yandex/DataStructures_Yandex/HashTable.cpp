//
//  HashTable.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 16.01.25.
//

#include <stdio.h>
#include "HashTable.h"

HashTable::HashTable(HashFunctionPtr function, std::size_t size)
    : hashFunction(function), data(size) {}

void HashTable::insert(const Point3D& point) {
    if (!hashFunction) {
        return;
    }
    
    int hash = hashFunction(point);
    int index = hash % data.size();
    data[index].insert(data[index].begin(), point);
}
