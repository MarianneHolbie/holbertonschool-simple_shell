# holbertonschool-simple_shell

 # Simple_shell README

Synopsis: This project was made in order to code a simplest version of the shell,  which can be used as an UNIX interpreter.
This project was realized in 10 days, in order to reproduce work conditions, during the second month of apprenticeship with the Holberton School in Toulouse, France.


## About the project

For this project we were mandated to produce a simple shell program, writing a simple UNIX command interpreter.

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


We were allowed to use our home-made function _putchar and the following c functions:
* Write (man 2 write)
* Malloc (man 3 malloc)
* Free (man 3 free)
* Va_start (man 3 va_start)
* Va_arg (man 3 va_arg)
* Va_end (man 3 va_end)
* Va_copy (man 3 va_copy)

Our code was compiled this way :
`$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`

More instructions were:
* You don’t have to reproduce the buffer handling of the C library printf function
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers


### Built with

* Language: C
* Text editor: Vim
* Docker.

## Description of the function _printf

This custom _printf version permits outputs according to a format specifier which is described below.
This function writes output to the stdout, the standard output stream.
It returns the number of counted printed characters when the function is successful and -1 when it fails.

### Function prototype

Our prototype was `int _printf(const char *format, …)` and in order to successfully make this project, we made a main.h header to organize the different sub-functions prototypes created to write outputs.


### Options


| Option | Description                                     |
|----------|-----------------------------------------------|
|  %c     |  Prints a character          |
|  %s     |  Prints a string                |
|  %%    |  Prints the % symbol      |
|  %d     |  Prints a float number     |
|  %i      |  Prints an integer            |
|  %b     |  Converts to a binary number |




## Usage
Below are examples of how the custom ```_printf``` function can be used:

### With %c option: prints character

**Input**

`_printf("Print a character %c\n, ‘C’');`

**Output**
```sh
`Print a character C`
```

### With %s option: prints string

**Input**

`_printf("%s\n", 'Holberton School.');`

**Output**
```sh
Holberton School.
```

### Integer %d or %i options: prints decimal or integer

**Input**

`_printf("Print an integer %i\n, ‘1354’');`

**Output**
```sh
Print an integer 1354
```

### With %b option: prints in binary

**Input**

`_printf("There is %b bytes in %b KB\n", 1024, 1’');`

**Output**
```sh
There is 10000000000 bytes in 1 KB\n
```



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

**Asia Groupierre**
GitHub: [@AsiaGrpr](https://github.com/AsiaGrpr)

**Sonia Nguyen**
GitHub: [@soniangn](https://github.com/soniangn)

