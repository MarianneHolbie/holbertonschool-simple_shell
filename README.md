# holbertonschool-simple_shell

 # Simple_shell README
 
### Synopsis: 

This project was made in order to code a simplest version of the shell,  which can be used as an UNIX interpreter.

This project was realized in 10 days, in order to reproduce work conditions, during the second month of apprenticeship with the Holberton School in Toulouse, France.


## About the project

For this project we were mandated to produce a simple shell program, writing a simple UNIX command interpreter.

The project was divided into several tasks in order to implement the program progressively.

At first, the program had to:
* Display a prompt and wait for the user to type a command. A command line always ends with a new line
* The prompt is displayed again each time a command has been executed
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features
* The command lines are made only of one word. No arguments will be passed to programs
* If an executable cannot be found, print an error message and display the prompt again
* Handle the “end of file” condition (Ctrl+D)

At the end our simple shell had to handle:
* errors
* command lines with arguments
* the PATH
* the exit built-in
* the env built-in, that prints the current environment

### Output

Some instructions we had to follow about the output:
* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below).

Example of error with sh:
```$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program hsh:
```$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
### List of allowed functions and system calls

We were allowed to use the following c functions and system calls:
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

Our code was compiled this way :
`$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Testing

Our shell should work like this in interactive mode:
```$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```



### Built with

* Language: C
* Text editor: Vim
* Docker.

## Description of the simple shell





## Usage



## Manual Page

[Manpage](https://github.com/AsiaGrpr/holbertonschool-printf/blob/master/man_3_printf)


## Project Files Description

The projects include 6 files as follows:

* [_printf.c](https://github.com/AsiaGrpr/holbertonschool-printf) - Includes the main function `_printf`.
* [_putchar.c](https://github.com/AsiaGrpr/holbertonschool-printf/blob/master/_putchar.c) - Includes the function `_putchar` that writes the character c to sdout.
* [Fonctions.c](https://github.com/AsiaGrpr/holbertonschool-printf/blob/master/fonctions.c) - Includes the functions `print_char`, `print_string`, `print_integer`, allowing the respective following conversion: %c, %s, %d, %i.
* [Binary.c](https://github.com/AsiaGrpr/holbertonschool-printf/blob/master/binary.c) - Includes the functions allowing the conversion from integer to binary, with %b specifier.
* [Main.h](https://github.com/AsiaGrpr/holbertonschool-printf/blob/master/main.h) - Includes the header containing all the functions prototypes as well as the structure used for the `_printf` function.
* [Man_3_printf](https://github.com/AsiaGrpr/holbertonschool-printf/blob/master/man_3_printf) - Includes the manual page of `_printf` function.


## Acknowledgment

Thanks to [Taieb](https://github.com/taiebchaabini) for reviewing our project !

## Authors

**Marianne Arrué**
GitHub: [@MarianneHolbie](https://github.com/MarianneHolbie)

**Gabriel Coëffier**
GitHub: [@PhYdrogen](https://github.com/PhYdrogen/)

**Asia Groupierre**
GitHub: [@AsiaGrpr](https://github.com/AsiaGrpr)
