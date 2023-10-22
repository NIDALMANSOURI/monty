#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - create node.
 * @num: number
 * Return: pointer to the node and otherwise NULL.
 */
stack_t *create_node(int num)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		err(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = num;
	return (nd);
}

/**
 * free_nodes - free nodes
 */
void free_nodes(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}


/**
 * add_to_queue - Add to queue.
 * @new_n: Pointer to new node.
 * @l: line number
 */
void add_to_queue(stack_t **new_n, __attribute__((unused))unsigned int l)
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
	while (t->next != NULL)
		t = t->next;

	t->next = *new_n;
	(*new_n)->prev = t;

}
