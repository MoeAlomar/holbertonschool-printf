#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_int - this method handles the specifier i and d  for the integers
 * @args: is the arguments list provided by the _printf
 * Return: this method returns the bytes printed by _printf.
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int i = 0, len = 0, temp;

	if (num == 0)
	return (write(1, "0", 1));

	if (num < 0)
	{
	buffer[len++] = '-';
	num = -num;
	}
	temp = num;
	while (temp)
	{
	temp /= 10;
	i++;
	}
	buffer[len + i] = '\0';
	while (num)
	{
	buffer[--i + len] = (num % 10) + '0';
	num /= 10;
	}
	return (write(1, buffer, len + i));
}
/**
 * print_char - Prints a character
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	return (write(1, str, len));
}

/**
 * _printf - Prints formatted output to stdout.
 * @format: The format string containing directives.
 *
 * Description: A simplified version of printf that supports:
 *              %c for characters, %s for strings, and %% for '%'.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == 'd')
			count += print_int(args);
			else if (*format == 'i')
			count += print_int(args);
			else if (*format == '%')
				count += write(1, "%", 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
