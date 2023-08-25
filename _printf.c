#include "main.h"
/**
 * printNumber - a function that prints decimals
 * @num: parameter to be printed
 * @sum: parameter keeping count
 * Return: void
 **/

int printNumber(int num, int sum)
{
	char digits[20];
	int index = 0;
	int i;
	
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		sum += 11;
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		sum++;
	}
	if (num == 0)
	{
		write(1, "0", 1);
		sum++;
		return (sum);
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
	return (sum);
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

	if (format == NULL || !format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(is_args, format);
	while (*format)
	{
		if (*format == '%' && !_strchr("sdi%cu", format[1]))
		{
			print(&prt, format);
			format++;
		}
		if (*format != '%')
		{
			print(&prt, format);
			format++;
		}
		else
		{
			format++;
			format = check_format(format, &prt, is_args);
			return (prt);
		}
	}
	va_end(is_args);
	return (prt);
}

/**
 * check_format - check format specifiers
 * @format: The format string
 * @prt: Pointer to character count
 * @is_args: The variable argument list
 * Return: Pointer to the character after the processed specifier
 **/

const char *check_format(const char *format, int *prt, va_list is_args)
{
	int sum = 0;

	if (*format == 's')
	{
		char *string = va_arg(is_args, char*);

		if (string == NULL)
		{
			write(1, "(null)", 6);
			*prt += 6;
		}
		else
		{
			print_string(string, prt);
		}
	}
	else if (*format == 'c')
	{
		char ltr = (char)va_arg(is_args, int);

		write(1, &ltr, 1);
		(*prt)++;
	}
	else if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(is_args, int);

		sum = printNumber(num, sum);
		(*prt) = sum;
	}
	else if (*format == 'u')
	{
		unsigned int num = va_arg(is_args, unsigned int);

		sum = printUnsignedNumber(num, sum);
		(*prt) = sum;
	}
	else if (*format == '%')
	{
		print(prt, format);
	}
	return (format + 1);
}

