#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_integer - Print an integer to stdout
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int print_integer(int n)
{
	char buffer[20];
	int is_negative = 0;
	int length = 0;
	unsigned int num;

	if (n == 0)
	{
		buffer[length++] = '0';
	}
	else
	{
		if (n < 0)
		{
			is_negative = 1;
			num = -n;
		}
		else
		{
			num = n;
		}

		while (num > 0)
		{
			buffer[length++] = (num % 10) + '0';
			num /= 10;
		}

		if (is_negative)
		{
			buffer[length++] = '-';
		}

		/* Reverse the string */
		reverse_string(buffer, length);
	}

	return (write(1, buffer, length));
}

/**
 * reverse_string - Reverse a string in-place
 * @str: String to reverse
 * @length: Length of the string
 */
void reverse_string(char *str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * _printf - Custom printf function that mimics standard printf
 * @format: Format string containing conversion specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
			case 'i':
				count += print_integer(va_arg(args, int));
				break;
			case '%':
				count += write(1, "%", 1);
				break;
			default:
				count += write(1, "%", 1);
				count += write(1, format, 1);
				break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (count);
}
