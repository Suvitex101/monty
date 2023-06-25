#include "monty.h"

/**
 * add_nd - add node
 * @head: head of the stack
 * @n: new_value
 * Return: always return 0
 *
 */

void add_nd(stack_t **head, int n)
{

	stack_t *new, *run;

	run = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (run)
		aux->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
/**
 * f_queue - display top
 * @head: stack head
 * @num: line_number
 * Return: no return
 */

void f_queue(stack_t **head, unsigned int num)
{
	(void)head;
	(void)num;
	opc.lf = 1;
}

/**
 * add_queue - add node to the tail
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */

void add_queue(stack_t **head, int n)
{
	stack_t *new, *run;

	run = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (run)
	{
		while (run->next)
			run = run->next;
	}
	if (!run)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		run->next = new;
		new->prev = run;
	}
}
