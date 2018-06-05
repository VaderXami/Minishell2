/*
** EPITECH PROJECT, 2018
** signals
** File description:
** shell
*/

#include "shell.h"


void	fork_pipe(char *cmd, char **av, char **env)
{
	execve(cmd, av, env);
}

void	display_signals(int wstatus)
{
	if (wstatus == 8)
		my_puterr("Floating exception\n");
	else if (wstatus == 11)
		my_puterr("Segmentation fault\n");
}

void	display_signals2(int wstatus)
{
	if (wstatus == 136)
		my_puterr("Floating exception (core dumped)\n");
	else if (wstatus == 139)
		my_puterr("Segmentation fault (core dumped)\n");
}

void	display_format(char *cmd)
{
	if (errno == ENOEXEC) {
		my_puterr(cmd);
		my_puterr(": Exec format error. Wrong Architecture.\n");
	}
}

void	handle_pipe_segf(int status)
{
	if (status == 139)
		my_puterr("Segmentation fault (core dumped)\n");

}
