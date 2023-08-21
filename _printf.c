#include "main.h"
/**
 * print_char - Handle %c specifier
 * @argument_list: va_list containing the arguments
 * Return: nulber of character printed
 */
int  print_char(va_list argument_list)
{
	char c = (char)va_arg(argument_list, int);
	int nb_printed = 0;

	if (c == '\0')
		return (-1);
	_putchar(c);
	nb_printed++;

	return (nb_printed);
}
/**
 * print_string -function that print string
 * @argument_list: list of argument
 * Return: nulber of character printed
 */
int print_string(va_list argument_list)
{
	int nb_printed = 0;

	char *s = va_arg(argument_list, char*);

	if (s == NULL)
		return (-1);
	while (*s)
	{
		_putchar(*s);
		s++;
		nb_printed++;
	}
	return (nb_printed);
}
/**
 * print_integer -handle %i and print integer
 * @argument_list: va_list containing the arguments
 * Return: nulber of character printed
 */

int print_integer(va_list argument_list)
{
	int nb_printed = 0;
	int num = va_arg(argument_list, int);
	char digits[10];
	int index;

	if (num < 0)
	{
		_putchar('-');
		nb_printed++;
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		nb_printed++;
		return (1);
	}

	index = 0;

	while (num > 0)
	{
		digits[index++] = '0' + (num % 10);
		num /= 10;
	}

	while (index > 0)
	{
		_putchar(digits[--index]);
		nb_printed++;
	}
	return (nb_printed);
}
/**
 * checker -checker format specifier and apply right function
 * @argument_list: list of argument
 * @format: string contain character to check
 * Return: number of character to be printed
 */
int checker(const char *format, va_list argument_list)
{
	int nb_printed = 0;

	while (*format != '\0') /*we change 0 to '\0'*/
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);

			if  (*format == '%')
			{
				_putchar('%');
				nb_printed++;
			}
			else if (*format == 'c')
			{
				nb_printed = print_char(argument_list);
			}
			else if (*format == 's')
			{
				nb_printed = print_string(argument_list);
			}
			else if (*format == 'd' || *format == 'i')
			{
				nb_printed = print_integer(argument_list);
			}
			else if (*format == 'b')
			{
				nb_printed = print_binary(argument_list);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				nb_printed += 2;
			}
		}
		else
		{
			_putchar(*format);
			nb_printed++;
		}
		format++;
	}
	return (nb_printed);
}
/**
 * _printf - produces output to a format + } =
 * @format: a caractere string
 * Return: Number of arguments printed
 */
int _printf(const char *format, ...)
{
	int nb_printed = 0;
	va_list argument_list;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(argument_list, format);

	nb_printed = checker(format, argument_list);
/* Handling of % specifier */
	va_end(argument_list);
	return (nb_printed);
}
