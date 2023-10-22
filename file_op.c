#include "monty.h"

/**
 * open_file - open file
 * @file_name: file name
 * Return: void
 */
void open_file(char *file_name)
{
	FILE *f = fopen(file_name, "r");

	if (file_name == NULL || f == NULL)
		err(2, file_name);

	read_file(f);
	fclose(f);
}

/**
 * read_file - read file
 * @f: pointer to file
 * Return: void
 */
void read_file(FILE *f)
{
	int line_num, form = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (line_num = 1; getline(&buffer, &l, f) != -1; line_num++)
	{
		form = parse_line(buffer, line_num, form);
	}
	free(buffer);
}


/**
 * parse_line - Separate each line into tokens
 * @buffer: line from file
 * @line_num: number of line
 * @form: storage format
 * Return: 0 if stack and 1 if queue
 */

int parse_line(char *buffer, int line_num, int form)
{
	char *opcode, *v;
	const char *del = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, del);
	if (opcode == NULL)
		return (form);
	v = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, v, line_num, form);
	return (form);
}

/**
 * find_func - find function for the opcode
 * @opcode: opcode
 * @v: argument
 * @form: storage format
 * @l: number of line
 * Return: void
 */
void find_func(char *opcode, char *v, int l, int form)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_fun(func_list[j].f, opcode, v, l, form);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, l, opcode);
}


/**
 * call_fun - call function
 * @f: pointer to the function
 * @op: opcode
 * @value: numeric value
 * @l: number of line
 * @form: Format specifier
 */
void call_fun(op_func f, char *op, char *value, int l, int form)
{
	stack_t *n;
	int flag;
	int j;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, l);
		for (j = 0; value[j] != '\0'; j++)
		{
			if (isdigit(value[j]) == 0)
				err(5, l);
		}
		n = create_node(atoi(value) * flag);
		if (form == 0)
			f(&n, l);
		if (form == 1)
			add_to_queue(&n, l);
	}
	else
		f(&head, l);
}
