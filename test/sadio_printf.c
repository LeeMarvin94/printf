#include "sadio.h"
/**
 * process_format -look after format specifier can run right code
 * @format: constant string
 * @args: list of arguments
 * @count: int pointer
 * @type: structure contain format and right function
 */
void process_format(const  char *format, va_list args, int *count, func type[])
{
	int j;

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			j = 0;
			if (type[j].format == NULL)
			{
				_putchar('%');
				_putchar(*format);
				(*count) += 2;
			}

			while (type[j].format != NULL)
			{
				if (*(type[j].format) == *format)
				{
					type[j].function(args);
					(*count)++;
					break;
				}
				j++;
			}
		}
		else
		{
			_putchar(*format);
			(*count)++;
		}
		format++;
	}
}
/**
 * _printf -function that print a given input
 * @format: a constant string
 * Return: 0 if success
 */
int _printf(const char *format, ...)
{
	func type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	int  count;
	va_list args;

	count = 0;

	va_start(args, format);

	process_format(format, args, &count, type);

	va_end(args);
	return (count);
}


