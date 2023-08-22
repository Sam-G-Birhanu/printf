#include "main.h"

int _printf(const char *format, ...);

/**
 * printNumber - prints numbers
 * @num: is a paremeter for decimal number
 * Return: void
 **/

void printNumber(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return;
	}
	char digits[20];
	int index = 0;

	while (num > 0)
	{
		digits[index] = (num % 10) + '0';
		num /= 10;
		index++;
	}
	for (int i = index - 1; i >= 0; i--)
	{
		write(1, &digits[i], 1);
	}
}
/**
 * _printf - prints arguements passed into it in different formats
 * @format: this is a paremeter representing the format
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
			format++;
		}
		else
		{
			format++;
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
				write(1, format, 1);
			else if (*format == '%')
			{
				write(1, format, 1);
				prt++;
			}
			format++;
		}
	}
	va_end(is_args);
	return (prt);
}

