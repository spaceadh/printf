#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
    char fmt;                    // The format specifier character (e.g., 'c', 's', 'd', etc.)
    int (*fn)(va_list, char[], int, int, int, int); // The function pointer representing the associated printing function
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/* Function Prototypes */
int _printf(const char *format, ...); // Custom printf function
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size); // Handle the format specifier and call appropriate printing functions

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a single character
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a string of characters
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size); // Print the '%' character

/* Functions to print numbers */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size); // Print an integer
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a binary number
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size); // Print an unsigned integer
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size); // Print an octal number
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a hexadecimal number
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a hexadecimal number in uppercase format

int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size); // Print a hexadecimal number

/* Function to print non-printable characters */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size); // Print non-printable characters

/* Function to print memory address */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a memory address

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i); // Extract flags from the format string
int get_width(const char *format, int *i, va_list list); // Extract width from the format string
int get_precision(const char *format, int *i, va_list list); // Extract precision from the format string
int get_size(const char *format, int *i); // Extract size from the format string

/* Function to print string in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a string in reverse

/* Function to print a string in rot 13 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size); // Print a string in ROT13

/* Width handler */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size); // Handle writing a character to the buffer with width
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size); // Write a number to the buffer
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c); // Write a number with padding and width
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start); // Write a memory address with padding

int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size); // Write an unsigned number with padding

/****************** UTILS ******************/
int is_printable(char); // Check if a character is printable
int append_hexa_code(char, char[], int); // Append a hexadecimal code
int is_digit(char); // Check if a character is a digit

long int convert_size_number(long int num, int size); // Convert a number to a different size
long int convert_size_unsgnd(unsigned long int num, int size); // Convert an unsigned number to a different size

#endif /* MAIN_H */
