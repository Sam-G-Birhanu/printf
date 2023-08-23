#include "main.h"

/**
 * convert_bin - prints an unsigned number to binary
 * @v_args: list of arguments
 * @buffer: contain character array
 * @flag: flag modifier
 * @wide: insert width
 * @lng: insert length
 *
 * Return: Total number of char printed
 */

int convert_bin(va_list v_args, char *buffer[],
	int flag, int wide, int lng)
{
	unsigned int a, b, d, X;
	unsigned int i[32];
	int tally;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wide);
	UNUSED(lng);

	a = va_arg(v_args, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	i[0] = a / b;
	for (d = 1; d < 32; d++)
	{
		b /= 2;
		i[d] = (a / b) % 2;
	}
	for (d = 0, X = 0, tally = 0; d < 32; d++)
	{
		X += i[d];
		if (X || d == 31)
		{
			char C = '0' + i[d];

			write(1, &C, 1);
			tally++;
		}
	}
	return (tally);
}

