/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** setenv
*/

#include "shell.h"

char	**err_setenv(int len_ac, char **env)
{
	if (len_ac > 3)
		my_puterr("setenv: Too many arguments.\n");
	return (env);
}

char	**my_setenv(char **argv, char **env)
{
	int	len_ac = check_argv(argv);
	int	i = -1;

	err_setenv(len_ac, env);
	if (argv[1] == NULL && argv[2] == NULL) {
		env = env_display(argv, env);
		return (env);
	}
	else if (argv[1] != NULL && argv[2] == NULL) {
		env = my_add_to_array2(argv[1], env);
		return (env);
	}
	int	total_len = my_strlen(argv[1]) + my_strlen(argv[2]) + 2;
	char	*word = malloc(sizeof(*word) * total_len);
	if (word != NULL && (i = check_key(argv[1], env)) != -1)
		env = init_word(i ,word, argv, env);
	else
		env = my_add_to_array(argv[1], argv[2], env);
	return (env);
}
