/*
** EPITECH PROJECT, 2018
** arr remove
** File description:
** minishell
*/

#include "shell.h"

int	my_free_env(char **env)
{
	int	i;

	if (env == NULL)
		return (1);
	i = 0;
	while (env[i] != NULL) {
		free(env[i]);
		i++;
	}
	if (env != NULL)
		free (env);
	return (1);
}

char	*clean_mem(char *ptr, int len)
{
	int	i = 0;

	while (i < len) {
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	**my_remove_array(int pos_to_rm, char **env)
{
	int	len = 0;
	char	**new_env = NULL;

	if (env != NULL) {
		len = count_env(env);
		new_env = (char **)malloc(sizeof(*new_env) * (len) + 1);
		new_env = my_copy_arr(pos_to_rm, new_env, env);
		my_free_env(env);
	}
	return (new_env);
}
