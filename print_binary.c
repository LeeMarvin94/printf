#include "main.h"
/**
 * print_binary - Handle %b specifier (binary)
 * @argument_list: va_list containing the arguments
 * Return: the number of character to be printed
 */
int print_binary(va_list argument_list)
{
	unsigned int num = va_arg(argument_list, unsigned int);
	int i, index;
	int binary[32]; /* Max 32-bit integer*/
	int nb_printed = 0;

	if (num < 1)
		return (-1);
	if (num == 0)
	{
		_putchar('0');
		nb_printed++;
		return (1);
	}
	index = 0;

	while (num > 0)
	{
		binary[index] = num % 2;
		num /= 2;
		index++;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		nb_printed++;
	}
	return (nb_printed);
}
