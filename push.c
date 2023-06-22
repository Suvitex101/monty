#include "monty.h"

/**
 *push_opc - function to add node to stack
 *@head: head of the stack
 *@num: line number
 */
void push_opc(stack_t **head, unsigned int num)
{
	int n;
	int b = 0;
	int f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			b++;
		for (; bus.arg[b] != '\0'; b++)
		{
			if (bus.arg[b] > 57 || bus.arg[b] < 48)
				f = 1; }
		if (f == 1)
		{
			fprint(stderr, "L%d: usage: push integer\n", num);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
 * pall_opc - prints the stack
 * @head: stack head
 * @num: line
 */

void pall_opc(stack_t **head, unsigned int num)
{
	stack_t *run;
	(void)num;

	run = *head;
	if (run == NULL)
		return;
	while (run)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}
/**
 * nop_opc - nop opcode
 * @head: stack head
 * @num: line_number
 */

void nop_opc(stack_t **head, unsigned int num)
{
	(void) num;
	(void) head;
}
/**
 * sub_opc - sub opcode
 * @head: stack head
 * @num: line
 */

void sub_opc(stack_t **head, unsigned int num)
{
	stack_t *run;
	int sub, nodes;

	run = *head;
	for (nodes = 0; run != NULL; nodes++)
		run = run->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	run = *head;
	sub = run->next->n - run->n;
	run->next->n = sus;
	*head = run->next;
	free(run);
}
