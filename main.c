/*
** EPITECH PROJECT, 2018
** main
** File description:
** minishell
*/

#include "shell.h"

int	check_built(cmd_t *cmd, char *s)
{
	char	**args = NULL;
	int	i = 0;

	args = my_str_wordtab(s, ' ');
	while (cmd[i].cmd != NULL) {
		if (args && args[0] && my_strcmp(args[0], cmd[i].cmd) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_start(int s, char **args, char **env, int *r_value)
{
	int	line = 0;
	if (s == 0 && exec_cmd(args, env, 0) == 1)
		*r_value = cmd_err(args[0]);
	for (line = 0; args[line] != NULL; line++)
		free(args[line]);
	free(args);
}

char	**builtin(cmd_t *cmd, char *s, char **env, int *ret_value)
{
	char	**av = NULL;
	int	i = 0;
	int	start = 0;
	char	**cmds = my_str_wordtab(s, ';');;
	int	j = 0;

	while (cmds[j] != NULL) {
		av = my_str_wordtab(cmds[j], ' ');
		start = 0;
		while (cmd[i].cmd != NULL && start == 0) {
			if (av && av[0] && my_strcmp(av[0], cmd[i].cmd) == 0) {
				env = cmd[i].fnc(av, env);
				start = 1;
			}
			i++;
		}
		check_start(start, av, env, ret_value);
		j++;
	}
	return (env);
}

char	**init_main(char *s, cmd_t *cmd, char **env, int r)
{
	char	**cenv = my_copy_env(env);

	if (s && check_for_pipe(s) == 1)
		exec_pipe(env, s);
	else if ((s && check_redi_right(s) == 1) || check_double(s) == 1)
		my_redirection(s, env);
	else if (s && my_strlen(s) > 0)
		cenv = builtin(cmd, s, cenv, &r);
	return (env);
}

int	main(int ac, char **av, char **env)
{
	int	ret_value = 0;
	char	*s = my_strdup("home");
	cmd_t	*cmd;

	(void)ac;
	(void)av;
	cmd = malloc(sizeof(*cmd) * 5);
	init_cmd(cmd);
	while (42) {
		display_prompt();
		s = get_next_line(0);
		if (s == NULL || (s && my_strcmp(s, "exit") == 0)) {
			my_putstr("exit\n");
			return (0);
		}
		init_main(s, cmd, env, ret_value);
	}
	return (ret_value);
}
