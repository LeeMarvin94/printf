#ifndef main_h
#define main_h

#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>


int _putchar(char c);
int _printf(const char *format, ...);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args, int uppercase);
int print_hex(va_list args);
int print_hex_upper(va_list args);


#endif
