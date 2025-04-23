#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* process_format - Handles the format specifiers
* @format: The format specifier to process
* @args: The list of arguments to handle
*
* Return: Number of characters printed
*/
int process_format(const char *format, va_list args)
{
int count = 0;

switch (*format)
{
case 'c':
count += handle_char(args);
break;
case 's':
count += handle_string(args);
break;
case 'd':
case 'i':
count += handle_integer(args);
break;
case 'u':
count += handle_unsigned(args);
break;
case 'x':
case 'X':
count += handle_hex(args, *format);
break;
case 'o':
count += handle_octal(args);
break;
default:
count += write(1, "%", 1);
count += write(1, format, 1);
break;
}
return (count);
}
