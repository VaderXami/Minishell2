/*
** EPITECH PROJECT, 2018
** pipe
** File description:
** pipe execution
*/

#include "shell.h"

void	p_o(int def, char **av, int i, int pfd[2], char **cmd, char **env)
{
	dup2(def, 0);
	if (av[i + 1] != NULL)
		dup2(pfd[1], 1);
	close(pfd[0]);
	exec_cmd(cmd, env, 1);
	exit(1);
}

void	duplicate(int save_in, int save_out)
{
	dup2(save_in, 0);
	dup2(save_out, 1);
	close(save_in);
	close(save_out);
}

void	close_dup(int pipefd[2], int save_in, int save_out)
{
	close(pipefd[0]);
	close(pipefd[1]);
	duplicate(save_in, save_out);
}

void	wait_status(int i, int pipefd[2], int save_in, int save_out)
{
	int	status = 0;

	for (; i >= 0; i--) {
		wait(&status);
		handle_pipe_segf(status);
	}
	close_dup(pipefd, save_in, save_out);

}

pid_t	check_pid(int pipefd[2])
{
	pid_t	pid;

	if (pipe(pipefd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	return (pid);
}
