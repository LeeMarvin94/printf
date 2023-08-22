#include"main.h"
/**
 * _print_int_octal - unsigned integer to octal + } =
 * @: unigned int  to be printed
 * Return: Number of caractere pritned
 */

int _print_int_octal(va_list o) 
{
    unsigned int digits[11];
    unsigned int num = va_arg(o, unsigned int);

    // Extract and store individual octal digits in reverse order
    for (int i = 0; i < 11; i++) {
        digits[10 - i] = num % 8;
        num /= 8;
    }

    int digitCount = 0;
    int printingStarted = 0; // Flag to indicate if printing of digits has started

    for (int i = 0; i < 11; i++) {
        if (digits[i] != 0 || i == 10 || printingStarted) {
            _putchar('0' + digits[i]);
            digitCount++;
            printingStarted = 1;
        }
    }

    return digitCount;
}
