/*
** EPITECH PROJECT, 2018
** my_setenv
** File description:
** minishell1
*/

#include "shell.h"

int	count_env(char **env)
{
	int	i = 0;

	while (env[i])
		i++;
	return (i);
}

char	**my_copy_env(char **env)
{
	char	**copy_env;
	int	i = 0;

	copy_env = malloc(sizeof(*copy_env) * (count_env(env) + 1));
	while (env[i] != NULL) {
		copy_env[i] = my_strdup(env[i]);
		i++;
	}
	copy_env[i] = NULL;
	return (copy_env);
}

char	**env_display(char **args, char **env)
{
	int	i = 0;

	(void)args;
	while (env && env[i] != NULL) {
		my_putstr(env[i]);
		my_putchar('\n');
		i++;
	}
	return (env);
}
