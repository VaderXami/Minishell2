/*
** EPITECH PROJECT, 2018
** my_env
** File description:
** minishell1
*/

#include "shell.h"

char	*my_oldpwd(char **env)
{
	int	i;
	char	*oldpwd;

	oldpwd = my_strdup("OLDPWD=");
	if ((i = my_getenv(oldpwd, env)) >= 0) {
		free(oldpwd);
		return (env[i] + 7);
	}
	free(oldpwd);
	return (NULL);
}

char	*my_homedir(char **env)
{
	int	i;
	char	home[5] = "HOME";

	if ((i = my_getenv(home, env)) >= 0) {
		return (env[i] + 5);
	}
	return (NULL);
}

int	cmd_err(char *cmd)
{
	if (my_strcmp(cmd, "exit") == 0) {
		my_putstr("exit\n");
		return (0);
	}
	my_puterr(cmd);
	my_puterr(": Command not found.\n");
	return (1);
}

char	**my_unsetenv(char **args, char **env)
{
	int	i = 0;;
	char	*name = args[1];

	if ((i = my_getenv(name, env)) >= 0) {
		env = my_remove_array(i, env);
	}
	return (env);
}
