 # Homework 1
 
 Write a function template, which will print content of provided
 `std::vector<>` to the console. If it is vector of integers, an example
 output is:
 ```
 [5, 32, 14, 6]
 ```
 Write its specialization for printing vector of strings, so every string will
 be double-quoted. Example output is:
 ```
 ["hello", "kitty", "move", "on"]
 ```
 Write another specialization for printing vector of characters, which will
 print every character in single quotes. Example:
 ```
 ['f', 'h', 'Z', 'X']
 ```
 Finally, write a specialization for printing vector of `std::pair<>` objects.
 In that case, each pair should appear in brackets. If the vector consists
 of pairs of strings and integers, then example output is:
 ```
 [(h:22), (ptr:7), (key:84)]
 ```
