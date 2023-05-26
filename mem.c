#include "main.h"

/**
 * bfree - it frees a pointer and NULLs the address
 * @ptr: the address of the pointer to free
 *
 * Return: 1 if freed, otherwise return 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
