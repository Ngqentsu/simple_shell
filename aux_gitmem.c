#include "main.h"

/**
 * _memcpy - copies information.
 * @newptr: dest pointer.
 * @ptr: source pointer.
 * @size: size of new ptr.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int j;

	for (j = 0; j < size; j++)
		char_newptr[j] = char_ptr[j];
}

/**
 * _realloc - realloc a memry block.
 * @ptr: ptr to the memry previously allocated.
 * @old_size: size, in bytes.
 * @new_size: new size, in bytes, of the recent mem block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr with no changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - reallo a mem block of a double ptr.
 * @ptr: double ptr to the mem previously allocated.
 * @old_size: size, in bytes.
 * @new_size: new size, in bytes.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr with no changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (j = 0; j < old_size; j++)
		newptr[j] = ptr[j];

	free(ptr);

	return (newptr);
}

