//
//  LongestCommonSubsequence.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 25.01.25.
//

#include "LongestCommonSubsequence.h"
#include <iostream>
#include <algorithm>

int LongestCommonSubsequence::LCS_DynamicProgramming(const std::string& a, const std::string& b) {
    data = std::vector<std::vector<int>>(a.size(), std::vector<int>(b.size(), 0));
    for (int i = 1; i <= data.size(); ++i) {
        for (int j = 1; j <= data[i].size(); ++j) {
            if (a[i-1] == b[j-1]) {
                data[i][j] = data[i - 1][j - 1] + 1;
            } else {
                data[i][j] = std::max(data[i - 1][j], data[i][j - 1]);
            }
        }
    }
    return data[a.size()][b.size()];
}

int Memoization(const std::string& a, const std::string& b, int x, int y, std::vector<std::vector<int>>& matrix) {
    if (matrix[x][y] != -1) {
        return matrix[x][y];
    }
    if (x == 0 || y == 0) {
        matrix[x][y] = 0;
        return 0;
    }
    if (a[x-1] == b[y-1]) {
        return matrix[x][y] = 1 + Memoization(a, b, x-1, y-1, matrix);
    } else {
        Memoization(a, b, x-1, y, matrix);
        Memoization(a, b, x, y-1, matrix);
        return matrix[x][y] = std::max(matrix[x-1][y], matrix[x][y-1]);
    }
}

int LongestCommonSubsequence::LCS_Memoization(const std::string& a, const std::string& b) {
    data = std::vector<std::vector<int>>(a.size(), std::vector<int>(b.size(), -1));
    data[a.size()][b.size()] = Memoization(a, b, a.size(), b.size(), data);
    return data[a.size()][b.size()];
}

void LongestCommonSubsequence::PrintMatrix() {
    for (auto& row : data) {
        for (int cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

void LCS_DriverProgram() {
    LongestCommonSubsequence lcs;
    lcs.LCS_DynamicProgramming("ctgaat", "acatgt");
    
}


