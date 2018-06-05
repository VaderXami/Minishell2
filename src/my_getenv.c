/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** my_getenv
*/

#include <string.h>
#include "shell.h"


int	check_argv(char **argv)
{
	int	i = 0;
	int	count = 0;

	while (argv[i] != NULL) {
		i++;
		count++;
	}
	return (count);
}

int	check_key(char *keyword, char **env)
{
	int	i = 0;

	while (env[i] != NULL) {
		if (my_strncmp(env[i], keyword, my_strlen(keyword)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	my_getenv(char *argv, char **env)
{
	int	i = 0;
	char	*home = NULL;
	int	name_len = 0;

	name_len = my_strlen(argv);
	home = malloc(sizeof(*home) * name_len + 2);
	if (home != NULL) {
		my_strcpy(home, argv);
		my_strcat(home, "=");
		i = 0;
		while (env[i] != NULL) {
			if (my_strncmp(env[i], home, name_len) == 0) {
				free(home);
				return (i);
			}
			i++;
		}
		free(home);
	}
	return (-1);
}

char	**init_word(int i, char *word, char **argv, char **env)
{
	my_strcpy(word, argv[1]);
	my_strcat(word, "=");
	my_strcat(word, argv[2]);
	free(env[i]);
	env[i] = word;
	return (env);
}
