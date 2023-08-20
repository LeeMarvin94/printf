#include"main.h"

/**
 * _printf - produces output to a format + } =
 * @format: a caractere string
 *
 * Return: Number of arguments printed
 */

int _printf(const char *format, ...)
{
va_list argument_list;
va_start(argument_list, format);
int count = 0;
int i = 0;

/* here I iterate through the string to the its exact length */
while (format[i] != '\0')
{
i++;
count++;
}

/* Handling of % specifier */
for (i =0; i < count; i+)
{
if (format[i] == '%')
{
if  (format[i+1] == '%')
_putchar('%');
}
}




}
