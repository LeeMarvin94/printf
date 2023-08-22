#include"main.h"

/**
 * _print_char - Dispays a char and return 1 + } =
 * @c: caractere
 * Return: return 1
 */

int _print_char(va_list c)
{
char var_c;

var_c =(char)va_arg(c, int);
_putchar(var_c);

return (1);

}


