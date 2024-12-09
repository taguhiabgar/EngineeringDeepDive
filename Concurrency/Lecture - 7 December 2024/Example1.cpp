#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <iostream>

// Assignment 0: Multiple Fork calls

int main() {
    std::cout << "Main Process ID: " << getpid();
    
    fork();
    
    std::cout << "Process ID: " << getpid();
    std::cout << ", Parent Process ID: " << getppid() << std::endl;
    
    fork();
    
    std::cout << "Process ID: " << getpid();
    std::cout << ", Parent Process ID: " << getppid() << std::endl;
    
    fork();
    
    std::cout << "Process ID: " << getpid();
    std::cout << ", Parent Process ID: " << getppid() << std::endl;

    const unsigned int second = 1000000;
    usleep(second * 60); // one minute
    
    return 0;
}

