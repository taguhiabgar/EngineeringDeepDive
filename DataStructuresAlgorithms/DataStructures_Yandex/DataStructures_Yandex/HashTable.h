//
//  HashTable.h
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 16.01.25.
//

#include "HashTable_3DPoints.h"
#include <vector>
#include <list>

class HashTable {
public:
    using HashFunctionPtr = int(*)(const Point3D&);
    
    void insert(const Point3D& point);
    
    HashTable(HashFunctionPtr function, std::size_t size);
    
    
    
private:
    HashFunctionPtr hashFunction;
    
    std::vector<std::list<Point3D>> data; //fwd list
};

