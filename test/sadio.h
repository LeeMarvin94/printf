#ifndef SADIO_H
#define SADIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct format_handle: a struct that store a string and a function pointer's
 * @format: a string that contain characters
 * @function: pointer function
 */
typedef struct format_handle
{
	char *format;
	void (*function)(va_list args);
} func;


int _printf(const char *format, ...);
int _putchar(char c);
void print_char(va_list args);
void print_string(va_list args);
void print_percent(va_list args);


#endif
