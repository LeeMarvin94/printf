#include "main.h"
/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
	int len1, len2;

	len1 =  _printf("Let's try to printf a simple sentence.\n");
	printf("Number of characters printed: %d\n", len1);
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Number of characters printed: %d\n", len2);
	printf("Hello, %s! This is a %c, and a %%.\n", "World", 'C');
	_printf("Hello, %s! This is a %c, and a %%.\n", "World", 'C');
	return (0);
}
