/*
** EPITECH PROJECT, 2018
** init
** File description:
** display
*/

#include "shell.h"

void	display_prompt(void)
{
	int	size = 1024;
	char	buffer[size];
	char	*pwd;
	char	**tab = NULL;
	int	len = 0;
	int	n_len = 0;

	my_bzero(buffer, size);
	pwd = getcwd(buffer, size);
	tab = my_str_wordtab(pwd, '/');
	len = count_env(tab);
	n_len = my_strlen(tab[len - 1]);
	if (isatty(0)) {
		write(1, "[", 1);
		write(1, "\e[1;32mTHC@shell \e[0m", 22);
		write(1, tab[len - 1], n_len);
		write(1, "]# ",3);
	}
}

void	init_cmd(cmd_t *cmd)
{
	cmd[0].cmd = "env";
	cmd[0].fnc = &env_display;
	cmd[1].cmd = "setenv";
	cmd[1].fnc = &my_setenv;
	cmd[2].cmd = "unsetenv";
	cmd[2].fnc = &my_unsetenv;
	cmd[3].cmd = "cd";
	cmd[3].fnc = &my_cd;
	cmd[4].cmd = NULL;
	cmd[4].fnc = NULL;
}

char	*init_new_env(int i, char **new_env, char **env)
{
	new_env[i] = malloc(sizeof(**new_env) * (my_strlen(env[i]) + 1));
	new_env[i] = my_strcpy(new_env[i], env[i]);
	return (new_env[i]);
}

char	**my_copy_arr(int pos_to_rm, char **new_env, char **env)
{
	int	i = 0;
	int	j = 0;
	int	n = 0;

	while (env[i] != NULL) {
		if (i != pos_to_rm) {
			n = my_strlen(env[i]) + 2;
			new_env[j] = malloc(sizeof(**new_env) * n);
			my_strcpy(new_env[j], env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

void	display_err_cmd(char *cmd)
{
	my_puterr(cmd);
	my_puterr(": Permission denied.\n");
}
