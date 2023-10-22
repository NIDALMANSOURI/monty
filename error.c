#include "monty.h"

/**
 * err - print error messages
 * @error_code: error codes are:
 * (1) => user doesn't give any file or more than one file.
 * (2) => file provided is not a file that can be opened or read.
 * (3) => file provided contains an invalid instruction.
 * (4) => program is unable to malloc more memory.
 * (5) => parameter passed to the instruction "push" is not an int.
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list arg;
	char *op;
	int l;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			l = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - more errors
 * @error_code: error codes are:
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list arg;
	char *op;
	int l;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			l = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - errors
 * @error_code: error codes are:
 * (10) => number inside a node is outside ASCII.
 * (11) => stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list arg;
	int l;

	va_start(arg, error_code);
	l = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
