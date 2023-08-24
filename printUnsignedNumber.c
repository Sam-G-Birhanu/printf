#include "main.h"
int printUnsignedNumber(unsigned int num, int sum)
{
    char digits[20];
    int index = 0;
    int i;

    if (num == 0)
    {
        write(1, "0", 1);
        sum++;
        return sum;
    }
    while (num > 0)
    {
        digits[index] = (num % 10) + '0';
        num /= 10;
        index++;
        sum++;
    }
    for (i = index - 1; i >= 0; i--)
        write(1, &digits[i], 1);
    return sum;
}
