/*
** EPITECH PROJECT, 2018
** function
** File description:
** str word to tab
*/

#include "shell.h"

int	count_word_dstr(char *str, char *d)
{
	int	count = 0;
	int	i = 0;

	if (str == NULL || d == NULL)
		return (0);
	if (d[i] == '\0')
		return (1);
	while (str[i] != '\0') {
		if (my_strncmp(d, &str[i], my_strlen(d)) == 0)
			count = count + 1;
		i = i + 1;
	}
	return (count + 1);
}

char	*get_word_dstr(char *str, int *i, char *d)
{
	char	*word;
	int	j = 0;

	word = malloc(sizeof(*word) * (my_strlen(str) + 1));
	while (str[*i] != '\0' && my_strncmp(d, &str[*i], my_strlen(d)) != 0) {
		word[j] = str[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

char	**word_get(char *str, char **word)
{
	word[0] = my_strdup(str);
	word[1] = NULL;
	return (word);
}

char	**my_wordtab_dstr(char *str, char *d)
{
	char	**word;
	int	nb;
	int	line = 0;
	int	i = 0;

	str = rb_epurstr(str);
	nb = count_word_dstr(str, d);
	word = malloc(sizeof(*word) * (nb + 1));
	if (nb == 1)
		word = word_get(str, word);
	while (str[i] != '\0') {
		word[line] = get_word_dstr(str, &i, d);
		line++;
		if (my_strncmp(d, &str[i], my_strlen(d)) == 0) {
			i = i + my_strlen(d);
		}
	}
	word[line] = NULL;
	return (word);
}
