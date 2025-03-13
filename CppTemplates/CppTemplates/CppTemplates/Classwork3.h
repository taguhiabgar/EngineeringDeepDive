//
//  Classwork3.h
//  CppTemplates
//
//  Created by Taguhi Abgar on 12.03.25.
//

#ifndef Classwork3_h
#define Classwork3_h

#include <vector>

// add_pointer

template <typename T>
struct add_pointer {
    typedef T* type;
};

// remove_extent

template <typename T>
struct remove_extent {
    typedef T type;
};

template <typename T, size_t size>
struct remove_extent<T[size]> {
    typedef T type;
};

// decay

template <typename T>
struct decay {
    typedef T type;
};

template <typename T>
struct decay<T*> {
    typedef typename decay<T>::type type;
};

template <typename T>
struct decay<T&> {
    typedef typename decay<T>::type type;
};
template <typename T>
struct decay<const T> {
    typedef typename decay<T>::type type;
};

// type_name_printer

template <typename T>
struct type_name_printer {
    static std::string name() {
        return "";
    }
};

template <typename T>
struct type_name_printer<T&> {
    static std::string name() {
        return type_name_printer<T>::name() + "&";
    }
};

template <typename T>
struct type_name_printer<T*> {
    static std::string name() {
        return type_name_printer<T>::name() + "*";
    }
};

template <>
struct type_name_printer<int> {
    static std::string name() {
        return "int";
    }
};

template <>
struct type_name_printer<float> {
    static std::string name() {
        return "float";
    }
};

template <typename T>
struct type_name_printer<std::vector<T>> {
    static std::string name() {
        return "std::vector<" + type_name_printer<T>::name() + ">";
    }
};

template <typename T, size_t size>
struct type_name_printer<T[size]> {
    static std::string name() {
        return type_name_printer<T>::name() + "[" + std::to_string(size) + "]";
    }
};

void Classwork3_DriverProgram() {
    // test add_pointer
    static_assert(std::is_same<add_pointer<float>::type, float*>::value == true);
    static_assert(std::is_same<add_pointer<char>::type, char*>::value == true);
    static_assert(std::is_same<add_pointer<char>::type, int*>::value == false);
    
    // test remove_extent
    static_assert(std::is_same<remove_extent<char[30]>::type, char>::value == true);
    static_assert(std::is_same<remove_extent<int[20][50]>::type, int[50]>::value == true);
    
    // test decay
    static_assert(std::is_same<decay<const char******>::type, char>::value == true);
    
    // test type_name_printer
    std::cout << type_name_printer<int[15]>::name() << std::endl;
    std::cout << type_name_printer<float&>::name() << std::endl;
    std::cout << type_name_printer<std::vector<float*>>::name() << std::endl;
}


#endif /* Classwork3_h */
