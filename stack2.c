#include "monty.h"

/**
 * nop - does nothing.
 * @st: Pointer to stack.
 * @l: line number
 */
void nop(stack_t **st, unsigned int l)
{
	(void)st;
	(void)l;
}


/**
 * swap_nodes - Swap the stack.
 * @st: Pointer to stack.
 * @l: line number
 */
void swap_nodes(stack_t **st, unsigned int l)
{
	stack_t *t;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err(8, l, "swap");
	t = (*st)->next;
	(*st)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *st;
	t->next = *st;
	(*st)->prev = t;
	t->prev = NULL;
	*st = t;
}

/**
 * add_nodes - Add to stack.
 * @st: Pointer to stack.
 * @l: line number
 */
void add_nodes(stack_t **st, unsigned int l)
{
	int s;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err(8, l, "add");

	(*st) = (*st)->next;
	s = (*st)->n + (*st)->prev->n;
	(*st)->n = s;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * sub_nodes - sub nodes
 * @st: Pointer to a stack.
 * @l: line number
 */
void sub_nodes(stack_t **st, unsigned int l)
{
	int s;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		more_err(8, l, "sub");


	(*st) = (*st)->next;
	s = (*st)->n - (*st)->prev->n;
	(*st)->n = s;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * div_nodes - div nodes
 * @st: Pointer to stack.
 * @l: line number
 */
void div_nodes(stack_t **st, unsigned int l)
{
	int s;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err(8, l, "div");

	if ((*st)->n == 0)
		more_err(9, l);
	(*st) = (*st)->next;
	s = (*st)->n / (*st)->prev->n;
	(*st)->n = s;
	free((*st)->prev);
	(*st)->prev = NULL;
}
