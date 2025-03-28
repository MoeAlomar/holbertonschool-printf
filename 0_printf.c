#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	while (*format != '\0')
{
	if (*format == '%')
	{
	format++;
		if (*format == 'c')
		{
			count += write(1, &(char){va_arg(args, int)}, 1);
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);
			int len = 0;

			while (str[len])
			len++;


			count += write(1, str, len);
			
		}
		else if (*format == '%')
		count += write(1, '%', 1);
		else
		{
		count += write(1, '%', 1);
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
