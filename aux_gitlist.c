#include "main.h"

/**
 * add_sep_node_end - adds a separator.
 * @head: head.
 * @sep: separator found (; | &).
 * Return: address.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temporary;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
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
 * free_sep_list - frees a list
 * @head: head.
 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temporary;
	sep_list *curr;

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

/**
 * add_line_node_end - adds a command line..
 * @head: head.
 * @line: cd line.
 * Return: address.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temporary;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_line_list - free
 * @head: head.
 * Return: no return.
 */
void free_line_list(line_list **head)
{
	line_list *temporary;
	line_list *curr;

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

