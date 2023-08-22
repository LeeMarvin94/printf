#ifndef main_h
#define main_h

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _print_u_int(va_list u);
int _print_int_octal(va_list o);
int print_x(va_list x);
int print_hex(unsigned int num, unsigned int useUpperCase);
int print_binary(va_list argument_list);


#endif
