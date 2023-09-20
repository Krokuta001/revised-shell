#include "shell.h"

/**
printEnvironment - prints the current environment variables
@info: the structure containing potential arguments (used for function prototype)
Return: Always returns 0
*/
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
getEnvironmentValue - retrieves the value of an environment variable
@info: the structure containing potential arguments
@name: the name of the environment variable
Return: the value of the environment variable
*/
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *m;

	while (node)
	{
		m = starts_with(node->str, name);
		if (m && *m)
			return (m);
		node = node->next;
	}
	return (NULL);
}

/**
setEnvironmentVariable - Initializes a new environment variable or modifies an existing one
@info: the structure containing potential arguments
Return: Always returns 0
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
unsetEnvironmentVariable - Removes an environment variable
@info: the structure containing potential arguments (used for function prototype)
Return: Always returns 0
*/
int _myunsetenv(info_t *info)
{
	int z;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (z = 1; z <= info->argc; z++)
		_unsetenv(info, info->argv[z]);

	return (0);
}

/**
populateEnvironmentList - populates the environment linked list
@info: the structure containing potential arguments
Return: Always returns 0
*/
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t z;

	for (z = 0; environ[i]; z++)
		add_node_end(&node, environ[z], 0);
	info->env = node;
	return (0);
}
