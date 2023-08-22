#include"main.h"
/**
 * _print_u_int - Handles %u format specifier + } =
 * @u: serves a specifier
 * Return: A integer that represents  printed numbers
 */
int _print_u_int(va_list u) 
{
    unsigned int digits[10];
    unsigned int num = va_arg(u, unsigned int);

    // Extract and store individual digits in reverse order
    for (int i = 0; i < 10; i++) {
        digits[9 - i] = num % 10;
        num /= 10;
    }

    int digitCount = 0;
    int printingStarted = 0; // Flag to indicate if printing of digits has started

    for (int i = 0; i < 10; i++) {
        if (digits[i] != 0 || i == 9 || printingStarted) {
            _putchar('0' + digits[i]);
            digitCount++;
            printingStarted = 1;
        }
    }

    return digitCount;
}
