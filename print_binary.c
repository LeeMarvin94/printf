#include "main.h"
/**
 * print_binary - Handle %b specifier (binary)
 * @argument_list: va_list containing the arguments
 * Return: the number of character to be printed
 */
int print_binary(va_list argument_list)
{
	unsigned int num = va_arg(argument_list, unsigned int);
	char *binary;
	int temp, size, i;
	int nb_printed = 0;

	if (num == 0)
	{
		_putchar('0');
		nb_printed++;
		return (1);
	}
	size = 0;
	temp = num;

	while (temp > 0)
	{
		temp = temp / 2;
		size++;
	}
	binary = malloc((size + 1) * sizeof(char *));

	if (binary == NULL)
	{
		exit(1);
	}
	binary[size] = '\0';

	for (i = size - 1; i >= 0; i--)
	{
		binary[i] = (num % 2) + '0';
		num = num / 2;
	}
	for (i = 0; binary[i] != '\0'; i++)
	{
		_putchar(binary[i]);
		nb_printed++;
	}
	free(binary);
	return (nb_printed);
}
