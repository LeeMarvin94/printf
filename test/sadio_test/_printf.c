#include"main.h"
/**
 * print_percent - print a pourcentage
 * @argument_list: list of argument
 * Return: number of char printed
 */
int print_percent(va_list argument_list)
{
	int nb_printed = 0;
	(void)argument_list;

	_putchar('%');
	nb_printed++;
	return (nb_printed);

}
/**
 * print_char - Handle %c specifier
 * @args: va_list containing the arguments
 * Return: nulber of character printed
 */
int  print_char(va_list args)
{
	char c = (char)va_arg(args, int);
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
 * @args: va_list containing the arguments
 * Return: nulber of character printed
 */

int print_integer(va_list args)
{
	int nb_printed = 0;
	int num = va_arg(args, int);
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
 * format_checker- function that check for format and function corresponding
 * @format: constant char contain string
 * @argument_list: list of argument
 * Return: nulber of character printed
 */
int format_checker(const char *format, va_list argument_list)
{
	int nb_printed = 0;

	while (*format != '\0') /*we forgot to make a null character*/
				 /* we had put 0 before*/
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);

			if  (*format == '%')
			{
				nb_printed = print_percent(argument_list);
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
/* Handling of % specifier */
	nb_printed = format_checker(format, argument_list);

	va_end(argument_list);
	return (nb_printed);
}
