/*
** EPITECH PROJECT, 2018
** add_to_array
** File description:
** function
*/

#include "shell.h"

char	*init_name(char *dest, char *name, char *value)
{
	int	len = 0;

	len = my_strlen(name) * my_strlen(value);
	dest = malloc(sizeof(*dest) * (len + 3));
	dest = clean_mem(dest, len);
	dest = my_strcat(dest, name);
	dest = my_strcat(dest, "=");
	dest = my_strcat(dest, value);
	return (dest);
}

char	*init_name2(char *dest, char *name)
{
	int	len = 0;

	len = my_strlen(name);
	dest = malloc(sizeof(*dest) * (len + 3));
	dest = clean_mem(dest, len);
	dest = my_strcat(dest, name);
	dest = my_strcat(dest, "=");
	return (dest);
}

void	display_err_setenv(void)
{
	char	*s1 = NULL;
	char	*s2 = NULL;

	s1 = my_strdup("setenv: Variable name must contain");
	s2 = my_strdup(" alphanumeric characters.\n");
	my_puterr(s1);
	my_puterr(s2);
}

char	**my_add_to_array(char *name, char *value, char **env)
{
	int	i = 0;
	char	*dest = NULL;

	if (my_charis(name[0]) == 1) {
		my_puterr("setenv: Variable name must start with a letter.\n");
		return (env);
	}
	if (my_check_special(name) == 1) {
		display_err_setenv();
		return (env);
	}
	char	**new_env = malloc(sizeof(*new_env) * (count_env(env) + 2));
	for (i = 0; env[i] != NULL; i++)
		new_env[i] = init_new_env(i, new_env, env);
	dest = init_name(dest, name, value);
	new_env[i] = dest;
	new_env[i + 1] = NULL;
	my_free_env(env);
	return (new_env);
}

char	**my_add_to_array2(char *name, char **env)
{
	int	i = 0;
	char	*dest = NULL;

	if (my_charis(name[0]) == 1) {
		my_puterr("setenv: Variable name must start with a letter.\n");
		return (env);
	}
	if (my_check_special(name) == 1) {
		display_err_setenv();
		return (env);
	}
	char	**new_env = malloc(sizeof(*new_env) * (count_env(env) + 2));
	for (i = 0; env[i] != NULL; i++)
		new_env[i] = init_new_env(i, new_env, env);
	dest = init_name2(dest, name);
	new_env[i] = dest;
	new_env[i + 1] = NULL;
	my_free_env(env);
	return (new_env);
}
