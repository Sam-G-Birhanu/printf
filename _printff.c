#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);

void printNumber(int num)
{

	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
	return;
	}

	char digits[20];
	int index = 0;
	int isNegative = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		isNegative = 1;
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

	for (int i = index - 1; i >= 0; i--)
	{
		write(1, &digits[i], 1);
	}

	if (isNegative)
	{
		write(1, "8", 1);
	}
}

int _printf(const char *format, ...)
{
	if (format == NULL)
	return -1;

	int prt = 0;
	va_list is_args;
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
		char *string = va_arg(is_args, char *);
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
		format++;
	}
	}

    va_end(is_args);
	return prt;
}

int main()
{
	_printf("Hello, %s! The number is %d. Character: %c\n", "User", 42, 'A');
	return 0;
}

