#include "main.h"

/**
 * add_rvar_node - adds a variable.
 * @head: head.
 * @lvar: length.
 * @val: value.
 * @lval: length of the val.
 * Return: add of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temporary;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temporary = *head;

	if (temporary == NULL)
	{
		*head = new;
	}
	else
	{
		while (temporary->next != NULL)
			temporary = temporary->next;
		temporary->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a list.
 * @head: head of the linked.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *temporary;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temporary = curr) != NULL)
		{
			curr = curr->next;
			free(temporary);
		}
		*head = NULL;
	}
}

