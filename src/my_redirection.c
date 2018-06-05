/*
** EPITECH PROJECT, 2018
** redirection
** File description:
** redirection
*/

#include "shell.h"

char	**rb_epurtab(char **tab)
{
	int	i = 0;

	while (tab && tab[i] != NULL) {
		tab[i] = rb_epurstr(tab[i]);
		i++;
	}
	return (tab);
}

int	check_redi_right(char *s)
{
	int	i = 0;

	while (s && s[i]) {
		if (s[i] == '>' && s[i + 1] != '>')
			return (1);
		i++;
	}
	return (0);
}

int	check_double(char *s)
{
	int	i = 0;

	while (s && s[i] != '\0') {
		if (s[i] == '>' && s[i + 1] == '>')
			return (1);
		i++;
	}
	return (0);
}

void	my_redirection(char *s, char **env)
{
	char	*file = NULL;
	int	fd = 0;
	char	*d = check_redi_right(s) == 1 ? ">>" : ">";
	int	save = dup(1);
	pid_t	pid;
	char	**cmd = NULL;
	int	status;
	char	**argv = my_wordtab_dstr(s, ">>");

	argv = rb_epurtab(argv);
	file = argv[1];
	cmd = my_wordtab_dstr(argv[0], " ");
	fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0777);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0) {
		if (my_strcmp(d, ">>") == 0)
			fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0777);
		else
			fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
		dup2(fd, 1);
		exec_cmd(cmd, env, 0);
		exit(1);
	}
	else {
		waitpid(pid, &status, 0);
		dup2(1, save);
	}
	close(save);
	close(fd);
}
