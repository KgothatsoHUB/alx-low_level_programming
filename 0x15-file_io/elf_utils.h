#ifndef ELF_UTILS_H
#define ELF_UTILS_H

#include <elf.h>

/* Function declarations */
void process_elf_file(char *filename);
Elf64_Ehdr *read_elf_header(int file_descriptor);
void print_elf_info(Elf64_Ehdr *header);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(uint16_t e_type, unsigned char *e_ident);
void print_entry(Elf64_Addr e_entry, unsigned char *e_ident);
void cleanup(int file_descriptor, Elf64_Ehdr *header);

#endif /* ELF_UTILS_H */
