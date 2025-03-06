//
//  StackTemplate.h
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 05.03.25.
//

#ifndef StackTemplate_h
#define StackTemplate_h

#include <iostream>

template <typename T>
class Stack {
private:
    T _data[200];
    size_t _size;
    
public:
    
    Stack() : _size(0) {}
    
    void push(const T& val) {
        _data[_size++] = val;
    }
    
    void pop() {
        if (empty()) {
            return;
        }
        --_size;
    }
    
    T& top() {
        return _data[_size - 1];
    }
    
    const T& top() const {
        return _data[_size - 1];
    }
    
    size_t size() {
        return _size;
    }
    
    bool empty() {
        return _size == 0;
    }
};

template <>
class Stack<bool> {
private:
    unsigned char _data[200/8+1];
    size_t _size;
    
public:
    
    void push(bool val) {
        _size++;
        size_t indexByte = _size / 8;
        size_t indexBit = 8 - _size % 8;
        if (val) {
            _data[indexByte] = _data[indexByte] | (1 << indexBit);
        } else {
            _data[indexByte] = _data[indexByte] & ~(1 << indexBit);
        }
    }
    
    void pop() {
        if (empty()) {
            return;
        }
        --_size;
    }
    
    // TODO: change so that it can also be lvalue
    bool top() {
        size_t indexByte = _size / 8;
        size_t indexBit = 8 - _size % 8;
        return (_data[indexByte] & (1 << indexBit)) == 0 ? 0 : 1;
    }
    
    const bool top() const {
        size_t indexByte = _size / 8;
        size_t indexBit = 8 - _size % 8;
        return (_data[indexByte] & (1 << indexBit)) == 0 ? 0 : 1;
    }
    
    size_t size() {
        return _size;
    }
    
    bool empty() {
        return _size == 0;
    }
};

#endif /* StackTemplate_h */
