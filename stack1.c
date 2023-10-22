#include "monty.h"

/**
 * add_to_stack - Add to the stack
 * @new_n: pointer to new node.
 * @l: number of line
 */
void add_to_stack(stack_t **new_n, __attribute__((unused))unsigned int l)
{
	stack_t *t;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	t = head;
	head = *new_n;
	head->next = t;
	t->prev = head;
}


/**
 * print_stack - print stack.
 * @st: Pointer to stack.
 * @l: line number
 */
void print_stack(stack_t **st, unsigned int l)
{
	stack_t *t;

	(void) l;
	if (st == NULL)
		exit(EXIT_FAILURE);
	t = *st;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * pop_top - Add to the stack.
 * @st: Pointer of stack.
 * @l: line number
 */
void pop_top(stack_t **st, unsigned int l)
{
	stack_t *t;

	if (st == NULL || *st == NULL)
		more_err(7, l);

	t = *st;
	*st = t->next;
	if (*st != NULL)
		(*st)->prev = NULL;
	free(t);
}

/**
 * print_top - print top node
 * @st: Pointer to the stack.
 * @l: line number
 */
void print_top(stack_t **st, unsigned int l)
{
	if (st == NULL || *st == NULL)
		more_err(6, l);
	printf("%d\n", (*st)->n);
}
