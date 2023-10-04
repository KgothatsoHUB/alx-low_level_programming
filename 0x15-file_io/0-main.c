#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 *
 * Description:
 * The main function serves as the entry point for the program. It checks
 * if the correct number of command-line arguments is provided. If not,
 * it prints a usage message to standard error and exits the program with
 * a status code of 1. It then reads the specified filename using the
 * read_textfile function with two different buffer sizes (114 and 1024),
 * and prints the number of characters read for each size.
 *
 * Return:
 * Always returns 0.
 */

int main(int ac, char **av)

{
	ssize_t n;

	if (ac != 2)
	{
	dprintf(2, "Usage: %s filename\n", av[0]);
	exit(1);
	}
	n = read_textfile(av[1], 114);
	printf("\n(printed chars: %li)\n", n);
	n = read_textfile(av[1], 1024);
	printf("\n(printed chars: %li)\n", n);
	return (0);
}

