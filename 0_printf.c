#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int count;
	va_list args;
	va_start(args, format);
	count = 0;

	while (*format != '\0')
{
	if (*format == '%')
	{
	format++;
		if (*format == 'c')
		{
		  char ch;
		  ch = (char)va_arg(args, int);
			count += write(1, &ch, 1);
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);
			int len = 0;

			if (!str)
			str = "(null)";


			while (str[len])
			len++;


			count += write(1, str, len);
			
		}
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
