//
//  Homework1.h
//  CppTemplates
//
//  Created by Taguhi Abgar on 09.03.25.
//

#pragma once

#include <string>
#include <utility>

template <typename T>
void printSingleElement(const T& elem) {
    std::cout << elem;
}

// Specialization for printing characters
template <>
void printSingleElement(const char& elem) {
    std::cout << '\'' << elem << '\'';
}

// Specialization for printing strings
template <>
void printSingleElement(const std::string& elem) {
    std::cout << '\"' << elem << '\"';
}

// Specialization for printing pairs
template <typename A, typename B>
void printSingleElement(const std::pair<A, B>& elem) {
    std::cout << '(' << elem.first << ":" << elem.second << ')';
}

template <typename T>
void print(const std::vector<T>& vec) {
    if (vec.empty()) {
        std::cout << "[]";
        return;
    }
    std::cout << "[";
    printSingleElement(*vec.begin());
    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
        std::cout << ", ";
        printSingleElement(*it);
    }
    std::cout << "\b\b]";
}

void Homework1_DriverProgram() {
    std::vector<int> integers = {5, 32, 14, 6};
    print(integers);
    std::cout << std::endl;
    
    std::vector<char> characters = {'f', 'h', 'Z', 'X'};
    print(characters);
    std::cout << std::endl;
    
    std::vector<std::string> strings = {"hello", "kitty", "move", "on"};
    print(strings);
    std::cout << std::endl;
    
    std::vector<std::pair<std::string, int>> pairs = {{"h", 22}, {"ptr", 7}, {"key", 84}};
    print(pairs);
    std::cout << std::endl;
}

