#include "main.h"

/**
 * printNumber - prints numbers
 * @num: is a parameter for decimal number
 * Return: void
 **/

void printNumber(int num)
{
	char digits[20];
	int index = 0;
	int i;
	int isNegative = 0;

	if (num < 0)
	{
	write(1, "-", 1);

	if (num == INT_MIN)
	{
	num++;
	isNegative = 1;
	}
	else
	{
	num = -num;
	}
	}
	if (num == 0)
	{
	write(1, "0", 1);

	return;
	}
	while (num > 0)
	{
	digits[index] = (num % 10) + '0';
	num /= 10;
	index++;
	}
	digits[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
	write(1, &digits[i], 1);
	}
	if (isNegative)
	{
	digits[0] = '8';
	write(1, &digits[0], 1);
}
}

/**
 * _printf - prints arguments passed into it in different formats
 * @format: this is a parameter representing the format
 * Return: returns int
 **/
int _printf(const char *format, ...)
{
	int prt = 0;
	va_list is_args;

	if (format == NULL)
	return (-1);

	va_start(is_args, format);
	while (*format)
	{
	if (*format != '%')
	{
		write(1, format, 1);
		prt++;
	}
	else
	{
	format++;
	if (*format == '\0')
	break;

	if (*format == 's')
	{
		char *string = va_arg(is_args, char*);
		int s_length = 0;

	while (string[s_length] != '\0')
		s_length++;
	write(1, string, s_length);
	prt += s_length;
	}
	else if (*format == 'c')
	{
		char ch = va_arg(is_args, int);

	write(1, &ch, 1);
	prt++;
	}
	else if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(is_args, int);

		printNumber(num);
		prt++;
	}
	else if (*format == '%')
	{
		write(1, format, 1);
		prt++;
	}
	}
	format++;
	}

	va_end(is_args);
	return (prt);
}
