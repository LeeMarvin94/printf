#include"main.h"

int print_hex(unsigned int num, unsigned int useUpperCase) 
{
    
    unsigned int hexDigits[8]; // Array to store individual hex digits
    unsigned int i, divisor, sum;
    char diff; // Difference between 'A' or 'a' and ':'
    int digitCount;

    divisor = 268435456; // 16^7

    if (useUpperCase) {
        diff = 'A' - ':';
    } else {
        diff = 'a' - ':';
    }

    // Extract individual hex digits and store them in the array
    hexDigits[0] = num / divisor;
    for (i = 1; i < 8; i++) {
        divisor /= 16;
        hexDigits[i] = (num / divisor) % 16;
    }

    // Print the hex digits, omitting leading zeros
    sum = 0;
    digitCount = 0;

    for (i = 0; i < 8; i++) {
        sum += hexDigits[i];
        if (sum || i == 7) {
            if (hexDigits[i] < 10) {
                putchar('0' + hexDigits[i]);
            } else {
                putchar('0' + diff + hexDigits[i]);
            }
            digitCount++;
        }
    }

    return (digitCount);
}

