
#include "main.h"
#include <unistd.h>

/**
 * _putchar - write char c to stdout.
 * @c: char to print.
 * Return: success 1.
 * On error, -1 is returned, & error is set appropriately.
 **/

int _putchar(char c)

{

	return (write(1, &c, 1));

}
