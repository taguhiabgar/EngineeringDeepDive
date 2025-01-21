//
//  HashTableOA.hpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 18.01.25.
//

#ifndef HashTableOA_hpp
#define HashTableOA_hpp

#include <stdio.h>
#include <vector>
#include <optional>

// Hash Table implemented with open addressing
class HashTableOA {
public:
    using HashFunctionPtr = int(*)(int);
    
    HashTableOA(HashFunctionPtr function, std::size_t size);
    
    void insert(int value);
    int search(int value);
    void remove(int value);
    
    double loadFactor();
    
    void rehash(double coefficient);
    
private:
    HashFunctionPtr hashFunction;
    
    std::vector<std::optional<int>> data;
    
    int elementsCount;
};


#endif /* HashTableOA_hpp */
