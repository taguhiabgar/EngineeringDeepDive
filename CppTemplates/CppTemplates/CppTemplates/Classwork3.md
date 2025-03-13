#  Classwork 3

Implement the following: 

1. `add_pointer<T>::type`
2. `remove_extent<T>::type`
3. `decay<T>::type`

Also write code so that the following code snippet compiles:
```
std::cout << type_name_printer<int[15]>::name() << std::endl;
std::cout << type_name_printer<float&>::name() << std::endl;
std::cout << type_name_printer<std::vector<float*>>::name() << std::endl;
```

