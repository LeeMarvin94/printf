#include "main.h"
/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_char - Handle %c specifier
 * @args: va_list containing the arguments
 */
void print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
}

/**
 * print_string - Handle %s specifier
 * @args: va_list containing the arguments
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 * print_percent - Handle %% specifier
 * @args: va_list containing the arguments
 */
void print_percent(va_list args)
{
	(void)args;
	_putchar('%');
}
