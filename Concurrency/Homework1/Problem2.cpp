#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <iostream>

// Assignment 1: Simple Fork and Exec

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "fork failed" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execl("/usr/bin/ls", "ls", NULL) == -1) {
            std::cerr << "execl failed" << std::endl;
            return 1;
        }
    } else {
        // Parent process
        
//        // wait for child to finish
//        int status;
//        while (-1 == waitpid(pid, &status, 0));
//        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
//            std::cerr << "Process with pid " << pid << " have failed" << std::endl;
//            return 1;
//        }
        
        printf("Parent process finished/n");
    }
    
    return 0;
}

