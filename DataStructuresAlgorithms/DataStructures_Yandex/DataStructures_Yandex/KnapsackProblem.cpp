//
//  KnapsackProblem.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 23.01.25.
//

#include "KnapsackProblem.h"

// Formula:
// B[k][x] = max(B[k-1][x], B[k-1][x-w(k)] + b(k))
std::vector<std::pair<int, int>> Knapsack_0_1(std::vector<int> weights, std::vector<int> bonuses, int W) {
    if (weights.empty() || weights.size() != bonuses.size()) {
        return {};
    }
    
    const size_t N = weights.size();
    std::vector<std::vector<int>> matrix(N+1, std::vector<int>(W+1, 0));
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[i].size(); ++j) {
            matrix[i][j] = matrix[i - 1][j];
            if (j >= weights[i]) {
                int b = matrix[i - 1][j - weights[i]] + bonuses[i];
                if (b > matrix[i][j]) {
                    matrix[i][j] = b;
                }
            }
        }
    }
    std::vector<std::pair<int, int>> result;
    for (int i : matrix[N]) {}
    
    return result;
}


