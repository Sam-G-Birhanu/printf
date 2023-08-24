#include "main.h"
/**
 * printNumber - a function that prints decimals
 * @num: parameter to be printed
 * Return: void
 **/

void printNumber(int num)
{
	char digits[20];
	int index = 0;
	int i;

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
	while (num > 0)
	{
		digits[index] = (num % 10) + '0';
		num /= 10;
		index++;
	}
	for (i = index - 1; i >= 0; i--)
		write(1, &digits[i], 1);
}
/**
 * print_string - a function tha prints string
 * @string: parameter
 * @prt: parameter
 * Return: void
 **/

void print_string(const char *string, int *prt)
{
	int s_length = 0;

	while (string[s_length] != '\0')
		s_length++;
	write(1, string, s_length);
	*prt += s_length;
}

/**
 * print - prints
 * @prt: int pointer
 * @format: char pointer
 * Return: return void
 **/

void print(int *prt, const char *format)
{
	write(1, format, 1);
	(*prt)++;
}

/**
 * _printf - a function that prints its arguements
 * @format: a parameter
 * Return: returns int count of printed characters
 **/

int _printf(const char *format, ...)
{
	int prt = 0;
	va_list is_args;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(is_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			print(&prt, format);
			format++;
		}
		else
		{
			format++;
			if (*format == 's')
			{
				char *string = va_arg(is_args, char*);

				print_string(string, &prt);
			}
			else if (*format == 'c')
			{
				char ltr = char(va_arg(is_args, char)); /** type casting **/

				write(1, &ltr, 1);
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
				print(&prt, format);
			}
			format++;
		}
	}
	va_end(is_args);
	return (prt);
}

