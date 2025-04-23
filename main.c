#include "main.h"
#include <stddef.h>

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percentage: %%\n");
    _printf("NULL String: %s\n", NULL);
    _printf("Signed integer: %d\n", -123);
    _printf("Unsigned integer: %u\n", 123);
    _printf("Octal: %o\n", 255);
    _printf("Hexadecimal: %x\n", 255);
    _printf("Hexadecimal uppercase: %X\n", 255);

    return (0);
}
