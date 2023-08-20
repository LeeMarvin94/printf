#include"main.h"

/**
 * _printf - produces output to a format + } =
 * @format: a caractere string
 *
 * Return: Number of arguments printed
 */

int _printf(const char *format, ...)
{

va_list argument_list;
va_start(argument_list, format);
int nb_printed = 0; // count the number of printed caracteres
int c;
char *str;


/* Handling of % specifier */
while (*format != 0)
{
    if (*format == '%')
    {
        *format++;

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

        else if (*format == 's') //if after % is s so it's string  + } =
        {
              str = va_arg(argument_list, char*);//start the variable which holding the string
              while (*str) //looping over the string to print all charaters
              {
                  _putchar(*str);
                  str++;
                  nb_printed;
              }      
        }
     
    }
    else
    {
        _putchar(*format);
        nb_printed;
    }

    format++;
}
va_end(argument_list);

return (nb_printed);

}
