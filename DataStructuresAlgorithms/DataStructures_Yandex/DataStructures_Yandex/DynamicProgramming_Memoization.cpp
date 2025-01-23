//
//  DynamicProgramming_Memoization.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 21.01.25.
//

#include <iostream>
#include <map>
#include "DynamicProgramming_Memoization.h"

std::map<int, long long> fibValues;

long long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (n % 2 == 0) {
        
    } else {
        
    }
    return n;//todo: delete this line
}


// solve fibonacci the most efficient way
void Problem1() {
    int n;
    std::cin >> n;
    long long fib = fibonacci(n);
    std::cout << "F(" << n << ") = " << fib << std::endl;
}





template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    for (const std::vector<T>& row : matrix) {
        for (const T& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}

// Dynamic Programming Solution
int NumberOfDifferentPaths(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    const size_t rows = matrix.size();
    const size_t columns = matrix[0].size();
    std::vector<std::vector<int>> paths(rows, std::vector<int>(columns, -1)); // each cell will contain the number of paths leading to that cell
    
    // first row
    for (int j = 0; j < columns; ++j) {
        const int i = 0;
        if (matrix[i][j] == '*') {
            for(int k = j; k < columns; ++k) {
                paths[i][k] = 0;
            }
            break;
        } else {
            paths[i][j] = 1;
        }
    }
    
    // first column
    for (int i = 0; i < rows; ++i) {
        const int j = 0;
        if (matrix[i][j] == '*') {
            for(int k = i; k < columns; ++k) {
                paths[k][j] = 0;
            }
            break;
        } else {
            paths[i][j] = 1;
        }
    }
    
    // the rest of the matrix
    for (int i = 1; i < paths.size(); ++i) {
        for (int j = 1; j < paths[i].size(); ++j) {
            if (matrix[i][j] == '*') {
                paths[i][j] = 0;
            } else {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
    }
    
    printMatrix<int>(paths);
    return paths[rows - 1][columns - 1];
}



void Problem2() {
    std::vector<std::vector<char>> matrix = {
        {'.', '*', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '*', '.', '.'}
    };
    
    printMatrix<char>(matrix);
    std::cout << std::endl;
    
    int result = NumberOfDifferentPaths(matrix);
    
    std::cout << std::endl;
    std::cout << "Result: " << result << std::endl;
}


