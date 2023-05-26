#include "main.h"

/**
 * _myenv - A function that prints the current environ
 * @info: Structure containing potential arguments.
 *
 * Return: 0 on success
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ var
 * @info: Structure containing potential arguments
 * @name: env var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment var, or modify an existing one
 * @info: Structure containing potential arguments.
 *
 * Return: 0 success
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment var
 * @info: Structure containing potential arguments.
 *
 * Return: 0 success
 */

int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - populates environment linked list
 * @info: Structure containing potential arguments.
 *
 * Return: on success 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
