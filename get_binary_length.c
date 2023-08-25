#include "main.h"

/**
 * get_binary_length - Calculate the number of binary digits in a number.
 * @num: The number for which binary length is calculated.
 * Return: The length of the binary representation.
 */
unsigned int get_binary_length(unsigned int num)
{
    size_t binaryDigits = 0;

    while (num != 0)
    {
        num /= 2;
        binaryDigits++;
    }
    return (binaryDigits);
}

/**
 * _print_binary - Print an unsigned integer as binary.
 * @args: The argument list containing the number to print.
 * Return: The total number of characters printed.
 */
int _print_binary(va_list args)
{
    unsigned int number, numDigits, digit, j, powTwo;
    int totalCount;

    number = va_arg(args, unsigned int);
    numDigits = get_binary_length(number);
    powTwo = 1;
    totalCount = 0;

    if (number != 0)
    {
        for (j = 1; j < numDigits; j++)
            powTwo *= 2;

        while (numDigits > 0)
        {
            digit = number / powTwo;
            _putchar(digit + '0');
            totalCount++;
            number -= digit * powTwo;
            powTwo /= 2;
            numDigits--;
        }
    }
    else
    {
        _putchar('0');
        return (1);
    }

    return (totalCount);
}
