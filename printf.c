#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Produces output according to a specific format
* @format: A string containing the format specifiers and text
*
* Description:
* This function processes the format string and calls the appropriate
* handler functions based on the format specifiers.
*
* Return: Total number of characters printed
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
if (*format == '%') /* Processing format specifier */
{
format++;
if (*format == '\0') /* If % is at the end of the string */
return (-1); /* Return error */

count += process_format(format, args); /* Call helper function */
}
else
{
count += write(1, format, 1); /* Print normal characters */
}
format++;
}

va_end(args);
return (count);
}
