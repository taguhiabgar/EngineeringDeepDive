//
//  HashTableOA.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 18.01.25.
//

#include "HashTableOA.hpp"

HashTableOA::HashTableOA(HashFunctionPtr function, std::size_t size)
: hashFunction(function), data(size), elementsCount(0) {}

double HashTableOA::loadFactor() {
    // TODO: implement later
    return 0.0;
}

void HashTableOA::insert(int value) {
    if (loadFactor() >= 0.85) {
        
    }
    
    if (!hashFunction) {
        return;
    }
    
    int hash = hashFunction(value);
    int index = hash % data.size();
    
    while (index < data.size() && data[index].has_value()) {
        index++;
        index %= data.size();
    }
    data[index] = value;
    elementsCount++;
}

// returns index or -1 if not present
int HashTableOA::search(int value) {
    if (!hashFunction) {
        return -1;
    }
    
    int hash = hashFunction(value);
    int index = hash % data.size();
    
    while (data[index].has_value()) {
        if (data[index] == value) {
            return index;
        }
        index++;
        index %= data.size();
    }
    
    return -1;
}

void HashTableOA::remove(int value) {
    
    
    
    
    elementsCount--;
}

// newSize = oldSize * coefficient
void HashTableOA::rehash(double coefficient) {
    if (!hashFunction) {
        return;
    }
    
    int size = data.size() * coefficient;
    std::vector<std::optional<int>> data2 = std::vector<std::optional<int>>(size, NULL);
    
    for (std::optional<int> elem : data) {
        if (elem.has_value()) {
            int hash = hashFunction(elem.value());
            int indexNew = hash % data2.size();
            while (data2[indexNew].has_value()) {
                ++indexNew;// TODO: cyclic vector
            }
            data2[indexNew] = elem;
        }
    }
    
    data.swap(data2);
}


