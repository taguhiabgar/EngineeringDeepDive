//
//  FenwickTree.hpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 01.02.25.
//

#ifndef FenwickTree_h
#define FenwickTree_h

#include <vector>

/*
Fenwick tree for max (point updates)
    - use vector of vectors
    - construction/query
    - push back/pop back
*/

class FenwickTreePointUpdates {
public:
    
    FenwickTreePointUpdates(const std::vector<int>& values);
    
    void pushBack(int value);
    
    void popBack();
    
    int query(int start, int end); // [start, end)
    
    void print();
    
private:
    int queryInternal(int start, int end, int level);
    int getValue(int indexLevel0, int level);
    void constructTree(const std::vector<int>& values);
    int depth;
    std::vector<std::vector<int>> tree;
};


/*
Fenwick tree for range updates
    - use vector of vectors
    - range update/point query
    - push back/pop back
*/

class FenwickTreeRangeUpdates {
public:
    
private:
    
};


#endif /* FenwickTree_h */
