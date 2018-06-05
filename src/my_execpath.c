/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** minishell1
*/

#include <errno.h>
#include "shell.h"

void	my_fork(char *cmd, char **av, char **env)
{
	pid_t	pid;
	int	ret = 0;
	int	wstatus;

	if ((pid = fork()) == 0) {
		ret = execve(cmd, av, env);
		if (ret == -1) {
			display_format(cmd);
			exit(-1);
		}
	}
	else {
		waitpid(pid, &wstatus, 0);
		if (WIFSIGNALED(wstatus)) {
			display_signals(wstatus);
			display_signals2(wstatus);
		}
	}
}

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env && env[i] != NULL) {
		if (my_strncmp(env[i], "PATH", 4) == 0)
			return (env[i]);
		i++;
	}
	return NULL;
}

char	*concat_cmd(int i, char *cmd, char *the_cmd, char **av)
{
	int	len = 0;

	len = my_strlen(av[i]) + my_strlen(cmd) + 2;
	the_cmd = malloc(sizeof(*the_cmd) * len);
	my_bzero(the_cmd, len);
	my_strcat(the_cmd, av[i]);
	my_strcat(the_cmd, "/");
	my_strcat(the_cmd, cmd);
	return (the_cmd);
}

int	is_dir(char *path)
{
	struct stat statbuf;

	stat(path, &statbuf);
	if (S_ISDIR(statbuf.st_mode) == 0)
		return (0);
	return (1);
}

char	*find_path(char *cmd, char **av)
{
	char	*cm = NULL;

	if (is_dir(cmd) == 1)
		display_err_cmd(cmd);
	else if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
		return (cmd);
	else {
		for (int i = 0; av[i] != NULL; ) {
			cm = concat_cmd(i, cmd, cm, av);
			if (access(cm, F_OK) == 0 && access(cm, X_OK) == 0)
				return (cm);
			i++;
			if (cmd == NULL)
				return (NULL);
			free(cm);
		}
	}
	return (NULL);
}
