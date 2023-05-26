#include "main.h"

/**
 * _myhistory - This displays the history list.
 * @info: The Structure containing potential arguments.
 *
 *  Return: 0 success
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - The function that sets alias to string
 * @info: The parameter structure
 *  * @str: String alias
 *
 * Return: 0 on success, otherwise 1
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - A function that sets alias to string
 * @info: parameter structure
 * @str: String alias
 *
 * Return: 0 on success, otherwise 1
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This function prints an alias string
 * @node: alias node
 *
 * Return: 0 on success or 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - It mimics the alias builtin function
 * @info: Structure containing potential arguments.
 *
 *  Return: Always 0
 */

int _myalias(info_t *info)
{
	int b = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (b = 1; info->argv[b]; b++)
	{
		p = _strchr(info->argv[b], '=');
		if (p)
			set_alias(info, info->argv[b]);
		else
			print_alias(node_starts_with(info->alias, info->argv[b], '='));
	}

	return (0);
}
