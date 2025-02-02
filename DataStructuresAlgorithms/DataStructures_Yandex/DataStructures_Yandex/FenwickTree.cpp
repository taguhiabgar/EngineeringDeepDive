//
//  FenwickTree.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 01.02.25.
//

#include "FenwickTree.h"
#include <iostream>

FenwickTreePointUpdates::FenwickTreePointUpdates(const std::vector<int>& values) : depth(0) {
    constructTree(values);
}

void FenwickTreePointUpdates::pushBack(int value) {
    
}

void FenwickTreePointUpdates::popBack() {
    
}

void FenwickTreePointUpdates::constructTree(const std::vector<int>& values) {
    tree.clear();
    tree.push_back(values);
    size_t length = values.size();
    int level = 1;
    while (length != 1) {
        tree.push_back({});
        for (int i = 0; i + 1 < length; i += 2) {
            int currentValue = std::max(tree[level - 1][i], tree[level - 1][i + 1]);
            tree[level].push_back(currentValue);
        }
        if (length % 2 == 1) {
            tree[level].push_back(tree[level - 1][length - 1]);
        }
        length = tree[level].size();
        level++;
    }
    depth = level;
}

int FenwickTreePointUpdates::queryInternal(int start, int end, int level) {
    if (level >= tree.size()) {
        return INT_MIN;
    }
    int defaultValue = INT_MIN;
    if () { // left participates
        int left = tree[level][];
        defaultValue = std::max(defaultValue, left);
    }
    if () { // right participates
        defaultValue = std::max(defaultValue, right);
    }
    return std::max(defaultValue, queryInternal(start + 1, end - 1, level + 1));
}

int FenwickTreePointUpdates::query(int start, int end) {
    return queryInternal(start, end, 0);
}

void FenwickTreePointUpdates::print() {
    for (auto& level : tree) {
        for (int elem : level) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    FenwickTreePointUpdates fenwick({21, 14, 9, 8, 16, 31, 4, 2, 5, 6, 22, 26});
    fenwick.print();
}


