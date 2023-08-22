#include "main.h"
/**
 * print_unsigned - Handle %u to print unsigned
 * @args: va_list argument's list
 * Return: the number of char printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int index, i;
	int nb_printed = 0;

	if (num == 0)
	{
		_putchar('0');
		nb_printed++;
		return (1);
	}

	index = 0;

	while (num > 0)
	{
		buffer[index] = '0' + (num % 10);
		num /= 10;
		index++;
	}
	for (i = index - 1; i >= 0; i--)
	{
		if (_putchar(buffer[i]) == -1)
			return (-1);
		nb_printed++;
	}
	return (nb_printed);
}
/**
 * print_octal - Handle %o to print int octal version
 * @args: list of argument
 * Return: number of  char printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int index = 0;
	int i;
	int nb_printed = 0;

	if (num == 0)
	{
		_putchar('0');
		nb_printed++;
		return (1);
	}

	while (num > 0)
	{
		buffer[index] = '0' + (num % 8);
		num /= 8;
		index++;
	}

	for (i = index - 1; i >= 0; i--)
	{
		if (_putchar(buffer[i]) == -1)
			return (-1);
		nb_printed++;
	}
	return (nb_printed);
}
/**
 * print_hexadecimal -to print hexadecimal in uppercase/lowercase
 * @args: list of argument
 * @uppercase: letter in uppercase
 * Return: number of char printed
 */
int print_hexadecimal(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int index = 0;
	int remainder, i;
	int nb_printed = 0;

	if (num == 0)
	{
		_putchar('0');
		nb_printed++;
		return (1);
	}

	while (num > 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			buffer[index] = '0' + remainder;
		else
			buffer[index] = (uppercase ? 'A' : 'a') + remainder - 10;
		num /= 16;
		index++;
	}
	for (i = index - 1; i >= 0; i--)
	{
		if (_putchar(buffer[i]) == -1)
			return (-1);
		nb_printed++;
	}
	return (nb_printed);
}
/**
 * print_hex - handle %x to print hexadecimal
 * @args: list of argument
 * Return: the number of char printed
 */
int print_hex(va_list args)
{
	int nb_printed = print_hexadecimal(args, 0); /*O for print in lowercase*/

	return (nb_printed);
}
/**
 * print_hex_upper -handle %X to print hexadecimal in uppercase
 * @args: list of argument
 * Return: number of char printed
 */
int print_hex_upper(va_list args)
{
	int nb_printed = print_hexadecimal(args, 1); /*1 for print in uppercase*/

	return (nb_printed);
}
