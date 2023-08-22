#include"main.h"

int print_x(va_list x)
{
        return (print_hex(va_arg(x, unsigned int), 0));
}
