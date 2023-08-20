#include"main.h"
/**
 * _printf - produces output to a format + } =
 * @format: a caractere string
 * Return: Number of arguments printed
 */
int _printf(const char *format, ...)
{
	int nb_printed = 0;
	int c;
	char *str;
	va_list argument_list;
	va_start(argument_list, format);
/* Handling of % specifier */
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			if  (*format == '%')
			{
				_putchar('%');
				nb_printed++;
			}
			else if (*format == 'c')
			{
				c = va_arg(argument_list, int);
				_putchar(c);
				nb_printed++;
			}
			else if (*format == 's')
			{
				str = va_arg(argument_list, char*);
				while (*str)
				{
					_putchar(*str);
					str++;
					nb_printed++;
				}
			}
		}
		else
		{
			_putchar(*format);
			nb_printed++;
		}
		format++;
	}
	va_end(argument_list);
	return (nb_printed);
}
