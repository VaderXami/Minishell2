/*
** EPITECH PROJECT, 2018
** function
** File description:
** str word to tab
*/

#include "shell.h"

int	count_word(char *str, char d)
{
	int	count = 0;
	int	i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == d)
			count = count + 1;
		i = i + 1;
	}
	return (count + 1);
}

char	*get_word(char *str, int *i, char d)
{
	char	*word;
	int	j = 0;

	word = malloc(sizeof(*word) * (my_strlen(str) + 1));
	while (str[*i] != d && str[*i] != '\0') {
		word[j] = str[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

char	**my_str_wordtab(char *str, char d)
{
	char	**word;
	int	nb;
	int	line = 0;
	int	i = 0;

	str = rb_epurstr(str);
	nb = count_word(str, d);
	word = malloc(sizeof(*word) * (nb + 1));
	while (str[i] != '\0') {
		word[line] = get_word(str, &i, d);
		line++;
		if (str[i] == d) {
			i++;
		}
	}
	word[line] = NULL;
	return (word);
}
