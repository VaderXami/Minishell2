/*
** EPITECH PROJECT, 2018
** exec
** File description:
** path
*/

#include "shell.h"

int	check_for_pipe(char *s)
{
	int	i = 0;

	while (s[i] != '\0') {
		if (s[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	exec_cmd(char **tab_cmd, char **env, int is_pipe)
{
	char	*tmp = NULL;
	char	**av = NULL;
	char	*path = NULL;

	path = get_path(env);
	if (path == NULL) {
		my_putstr("exit\n");
		return (0);
	}
	av = my_str_wordtab(path + 5, ':');
	tmp = find_path(tab_cmd[0], av);
	if (tmp == NULL)
		return (1);
	tab_cmd[0] = tmp;
	if (is_pipe == 1) {
		fork_pipe(tab_cmd[0], tab_cmd, env);
	}
	else
		my_fork(tab_cmd[0], tab_cmd, env);
	return (0);
}

void	exec_pipe(char **env, char *s)
{
	int	def_in = 0;
	int	save_in = dup(0);
	int	save_out = dup(1);
	int	i = 0;
	int	pipefd[2];
	char	**cmd = NULL;
	char	**argv = my_str_wordtab(s, '|');

	for (i = 0; argv[i]; ) {
		cmd = my_str_wordtab(argv[i], ' ');
		pid_t	pid = check_pid(pipefd);
		if (pid == 0)
			p_o(def_in, argv, i, pipefd, cmd, env);
		else{
			close(pipefd[1]);
			def_in = pipefd[0];
			i++;
		}
	}
	wait_status(i, pipefd, save_in, save_out);
}
