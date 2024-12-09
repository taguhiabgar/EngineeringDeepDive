# Homework 1
6 December, 2024

## Reading

Book Robert Love, "Linux System Programming"
https://github.com/wuzhouhui/misc2/blob/master/%5BLinux.System.Programming(2nd%2C2013.5)%5D.Robert.Love.pdf

Read chapter 5, pages 137-145 (included)

## Coding

### Assignment 0: Multiple Fork calls

**Objective:** Understand the process hierarchy when multiple sequential `fork` syscalls are invoked.

1. Write a program that:
    - Calls multiple  `fork` syscalls one after another. Check what the process tree looks like.
    - Pay attention to the hierarchy of processes, how many parents and children are created

Sample code:
```
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    fork();
    fork();
    fork();
    return 0;
}
```

If you used the sample code add necessary checkings (check the codes from the lecture and book)

### Assignment 1: Simple Fork and Exec

**Objective:** Understand the creation of a child process using `fork` and how to replace it with a new program using `execl`.
1. Write a program that:
    - Uses `fork` to create a child process.
    - In the child process, use `execl` to run the `ls` command to list the contents of the current directory.
    - The parent process should print "Parent process done" after the child process is created.
**Expected Output:** The directory listing should be printed, followed by the parent's message.

### Assignment 2: Multiple Forks and Execs

**Objective:** Work with multiple child processes created using `fork` and run different commands using `execl`.
1. Write a program that:
    - Creates two child processes using `fork`.
    - The first child process should use `execl` to run the `ls` command.
    - The second child process should use `execl` to run the `date` command.
    - The parent process should print "Parent process done" after creating both child processes.
**Expected Output:** The output of the `ls` command followed by the output of the `date` command, and finally the parent's message.

### Assignment 3: `fork` and Exec with Arguments

**Objective:** Understand how to pass arguments to programs executed with `execl`.
1. Write a program that:
    - Uses `fork` to create a child process.
    - The child process should use `execl` to run the `echo` command with an argument (e.g., "Hello from the child process").
    - The parent process should print "Parent process done" after the child process is created.
**Expected Output:** The message from the `echo` command followed by the parent's message.

### Assignment 4: `fork` and Exec with Command-Line Arguments

**Objective:** Use `fork` and `execl` to run a command with multiple arguments.
1. Prepare a `test.txt` file with some text.
2. Write a program that:
    - Uses `fork` to create a child process.
    - The child process should use `execl` to run the `grep` command to search for a specific word (e.g., "main") in a text file (e.g., `test.txt`).
    - The parent process should print "Parent process completed".
**Expected Output:** The lines in the file `test.txt` that contain the word "main" followed by "Parent process completed".
