#include"main.h"
/**
 * _print_str - prints a string
 *
 * @s: the string to be printed
 *
 * Return: nb char printed
 */

int print_s(va_list s)
{
int nb = 0;

        char *str = va_arg(s, char *);

        if (str)
        {
            for (nb = 0; str[nb]; nb++)
            {
                    _putchar(str[nb]);
            }
        }
        else
        {
                str = "NULL";
        }

        return (nb);
}
