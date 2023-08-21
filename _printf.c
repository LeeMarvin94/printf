#include"main.h"
/**
 * _printf - produces output to a format + } =
 * @format: a caractere string
 * Return: Number of arguments printed
 */
int _printf(const char *format, ...)
{
	int nb_printed = 0;
	int c, num, index;
	char *str;
	char digits[10];
	va_list argument_list;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(argument_list, format);
/* Handling of % specifier */
	while (*format != 0)
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
				c = va_arg(argument_list, int);
				_putchar(c);
				nb_printed++;
			}
			else if (*format == 's')
			{
				str = va_arg(argument_list, char*);
				if (str == NULL)
					return (6);
				while (*str)
				{
					_putchar(*str);
					str++;
					nb_printed++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(argument_list, int);

				if (num < 0)
				{
					_putchar('-');
					num = -num;
					nb_printed++;
				}
				if (num == 0)
				{
					_putchar('0');
					nb_printed++;
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
	va_end(argument_list);
	return (nb_printed);
}
