
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*Function declarations*/
void process_elf_file(char *filename);
Elf64_Ehdr *read_elf_header(int file_descriptor);
void print_elf_info(Elf64_Ehdr *header);
void cleanup(int file_descriptor, Elf64_Ehdr *header);

/* ... (other functions remain unchanged)*/

/**
 * main - Entry point of the program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers leading to the arguments.
 * Return: 0 on success.
 * Description: If the file is not an ELF File
 * or the function fails - exit code 98.
 **/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <filename>\n", argv[0]);
		exit(98);
	}

	process_elf_file(argv[1]);

	return (0);
}

/**
 * process_elf_file - Process the ELF file and print its information.
 * @filename: The name of the ELF file.
 **/
void process_elf_file(char *filename)
{
	int file_descriptor;
	Elf64_Ehdr *header;

	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", filename);
		exit(98);
	}

	header = read_elf_header(file_descriptor);
	print_elf_info(header);
	cleanup(file_descriptor, header);
}

/**
 * read_elf_header - Read and return the ELF header.
 * @file_descriptor: The file descriptor of the ELF file.
 * Return: A pointer to the ELF header.
 **/
Elf64_Ehdr *read_elf_header(int file_descriptor)
{
	Elf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));

	if (header == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Unable to allocate memory\n");
		exit(98);
	}

	if (read(file_descriptor, header, sizeof(Elf64_Ehdr)) == -1)
	{
		free(header);
		dprintf(STDERR_FILENO, "Error: Unable to read ELF header\n");
		exit(98);
	}

	return (header);
}

/**
 * print_elf_info - Print information about the ELF file.
 * @header: A pointer to the ELF header.
 **/
void print_elf_info(Elf64_Ehdr *header)
{
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
}

/**
 * cleanup - Clean up resources.
 * @file_descriptor: The file descriptor of the ELF file.
 * @header: A pointer to the ELF header.
 **/
void cleanup(int file_descriptor, Elf64_Ehdr *header)
{
	free(header);

	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n",
				file_descriptor);
		exit(98);
	}
}

