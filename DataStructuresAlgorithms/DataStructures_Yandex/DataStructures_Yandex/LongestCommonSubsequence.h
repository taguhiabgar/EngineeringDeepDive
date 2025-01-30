//
//  LongestCommonSubsequence.h
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 25.01.25.
//

#ifndef LongestCommonSubsequence_h
#define LongestCommonSubsequence_h

#include <string>
#include <vector>

class LongestCommonSubsequence {
public:
    int LCS_DynamicProgramming(const std::string& a, const std::string& b);
    int LCS_Memoization(const std::string& a, const std::string& b);
    
    void PrintMatrix();
    
private:
    std::vector<std::vector<int>> data;
};

void LCS_DriverProgram();


#endif /* LongestCommonSubsequence_h */
