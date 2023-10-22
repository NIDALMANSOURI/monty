#include "monty.h"

/**
 * print_char - print char
 * @st: Pointer to stack.
 * @l: line number
 */
void print_char(stack_t **st, unsigned int l)
{
	int c;

	if (st == NULL || *st == NULL)
		string_err(11, l);

	c = (*st)->n;
	if (c < 0 || c > 127)
		string_err(10, l);
	printf("%c\n", c);
}

/**
 * print_str - Print string
 * @st: Pointer to stack.
 * @l: line number
 */
void print_str(stack_t **st, __attribute__((unused))unsigned int l)
{
	int c;
	stack_t *t;

	if (st == NULL || *st == NULL)
	{
		printf("\n");
		return;
	}

	t = *st;
	while (t != NULL)
	{
		c = t->n;
		if (c <= 0 || c > 127)
			break;
		printf("%c", c);
		t = t->next;
	}
	printf("\n");
}

/**
 * rotl - Rotate of the stack
 * @st: Pointer to stack.
 * @l: line number
 */
void rotl(stack_t **st, __attribute__((unused))unsigned int l)
{
	stack_t *t;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	t = *st;
	while (t->next != NULL)
		t = t->next;

	t->next = *st;
	(*st)->prev = t;
	*st = (*st)->next;
	(*st)->prev->next = NULL;
	(*st)->prev = NULL;
}


/**
 * rotr - Rotate of the stack
 * @st: Pointer to stack.
 * @l: line number
 */
void rotr(stack_t **st, __attribute__((unused))unsigned int l)
{
	stack_t *t;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	t = *st;

	while (t->next != NULL)
		t = t->next;

	t->next = *st;
	t->prev->next = NULL;
	t->prev = NULL;
	(*st)->prev = t;
	(*st) = t;
}
