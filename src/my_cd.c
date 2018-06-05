/*
** EPITECH PROJECT, 2018
** cd
** File description:
** shell
*/

#include "shell.h"

void	check_directory(char **av)
{
	if (errno == ENOENT && my_strcmp(av[1], "-") != 0) {
		my_puterr(av[1]);
		my_puterr(": No such file or directory.\n");
	}
}

void	cd_err(char **av)
{
	if (chdir(av[1]) == -1) {
		if (errno == EACCES) {
			my_puterr(av[1]);
			my_puterr(": Permission denied.\n");
		}
		else if (errno == ENOTDIR) {
			my_puterr(av[1]);
			my_puterr(": Not a directory.\n");
		}
		else
			check_directory(av);
	}
}

char	**set_oldpwd(char **env)
{
	char	*current = NULL;
	char	*old_pwd = NULL;
	char	buff[254];
	char	**argv = malloc(sizeof(*argv) * 4);

	my_bzero(buff, 254);
	current = getcwd(buff, 256);
	old_pwd = my_strdup(current);
	for (int i = 0; i < 4; i++)
		argv[i] = NULL;
	argv[0] = my_strcpy(argv[0], my_strdup("setenv"));
	argv[1] = my_strcpy(argv[1], my_strdup("OLDPWD"));
	argv[2] = my_strcpy(argv[2], my_strdup(old_pwd));
	argv[3] = NULL;
	env = my_setenv(argv, env);
	return (env);
}

char	**free_and_ret(char *oldpwd, char **av, char **env)
{
	free(oldpwd);
	if (count_env(av) == 2)
		cd_err(av);
	return (env);
}

char	**my_cd(char **av, char **env)
{
	char	*home = NULL;
	char	*oldpwd = my_strdup(my_oldpwd(env));

	if (count_env(av) > 2) {
		my_puterr("cd: Too many arguments.\n");
		return (env);
	}
	env = set_oldpwd(env);
	if (count_env(av) == 1) {
		home = my_homedir(env);
		chdir(home);
		return (env);
	}
	if (my_strcmp(av[1], "-") == 0) {
		if (oldpwd == NULL)
			return (env);
		chdir(oldpwd);
	}
	env = free_and_ret(oldpwd, av, env);
	return (env);
}
