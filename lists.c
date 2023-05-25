#include "shell.h"

/**
 * add_node - a function.
 * @h: head of a node.
 * @nf: node field by string
 * @v: node index used by history
 * Return: size of list
 */
list_t *add_node(list_t **h, const char *nf, int v)
{
	list_t *vh;

	if (!h)
		return (NULL);
	vh = malloc(sizeof(list_t));
	if (!vh)
		return (NULL);
	_memset((void *)vh, 0, sizeof(list_t));
	vh->num = v;
	if (nf)
	{
		vh->str = _strdup(nf);
		if (!vh->str)
		{
			free(vh);
			return (NULL);
		}
	}
	vh->next = *h;
	*h = vh;
	return (vh);
}
/**
 * add_node_end - a function.
 * @h: head node to be addressed by pointer
 * @s: node field by a string
 * @n: history use node index
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *s, int n)
{
	list_t *newn, *nn;

	if (!h)
		return (NULL);

	nn = *h;
	newn = malloc(sizeof(list_t));
	if (!newn)
		return (NULL);
	_memset((void *)newn, 0, sizeof(list_t));
	newn->num = n;
	if (s)
	{
		newn->str = _strdup(s);
		if (!newn->str)
		{
			free(newn);
			return (NULL);
		}
	}
	if (nn)
	{
		while (nn->next)
			nn = nn->next;
		nn->next = newn;
	}
	else
		*h = newn;
	return (newn);
}
/**
 * print_list_str - a function.
 * @head: a pointer to the first node
 * Return: a list size
 */
size_t print_list_str(const list_t *head)
{
	size_t count = 0;

	while (head)
	{
		printf("%s\n", head->str ? head->str : "(nil)");
		head = head->next;
		count++;
	}
	return (count);
}

/**
 * delete_node_at_index - deleta function.
 * @head_ptr: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head_ptr, unsigned int index)
{
	list_t *current_node = *head_ptr;
	list_t *previous_node = NULL;
	unsigned int a = 0;

	if (!head_ptr || !*head_ptr)
	{
		return (0);
	}
	if (index == 0)
	{
		*head_ptr = current_node->next;
		free(current_node->str);
		free(current_node);
		return (1);
	}
	while (current_node)
	{
		if (a == index)
		{
			previous_node->next = current_node->next;
			free(current_node->str);
			free(current_node);
			return (1);
		}
		a++;
		previous_node = current_node;
		current_node = current_node->next;
	}
	return (0);
}
/**
 * free_list - a function.
 * @hp:the address of a pinter to ahead node
 * Return: nothing
 */
void free_list(list_t **hp)
{
	list_t *n, *nn, *h;

	if (!hp || !*hp)
		return;
	h = *hp;
	n = h;
	while (n)
	{
		nn = n->next;
		free(n->str);
		free(n);
		n = nn;
	}
	*hp = NULL;
}

