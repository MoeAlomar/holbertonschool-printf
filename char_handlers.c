#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
* handle_char - Prints a single character
* @args: A list of arguments pointing to the character to print
*
* Return: Number of characters printed (always 1)
*/
int handle_char(va_list args)
{
char c = va_arg(args, int);
return (write(1, &c, 1));
}

/**
* handle_string - Prints a string
* @args: A list of arguments pointing to the string to print
*
* Return: Number of characters printed
*/
int handle_string(va_list args)
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
return (write(1, str, strlen(str)));
}
