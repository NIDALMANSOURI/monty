#include "monty.h"

/**
 * mul_nodes - multiplie nodes
 * @st: Pointer to stack.
 * @l: line number
 */
void mul_nodes(stack_t **st, unsigned int l)
{
	int s;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err(8, l, "mul");

	(*st) = (*st)->next;
	s = (*st)->n * (*st)->prev->n;
	(*st)->n = s;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * mod_nodes - modulo nodes
 * @st: Pointer to stack.
 * @l: line number
 */
void mod_nodes(stack_t **st, unsigned int l)
{
	int s;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		more_err(8, l, "mod");


	if ((*st)->n == 0)
		more_err(9, l);
	(*st) = (*st)->next;
	s = (*st)->n % (*st)->prev->n;
	(*st)->n = s;
	free((*st)->prev);
	(*st)->prev = NULL;
}
