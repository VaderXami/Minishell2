/*
** EPITECH PROJECT, 2018
** bootcamp
** File description:
** day02
*/

#include "shell.h"

int	check_delim(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	count_chars(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i] != '\0') {
		if (check_delim(str[i]) == 0) {
			count++;
		}
		i++;
	}
	return (count);
}

char	*rb_epurstr(char *str)
{
	int	i = 0;
	int	j = 0;
	int	len = count_word(str, '\t') - 1;
	int	ch = count_chars(str) + 2 + len;
	char	*word = NULL;

	word = malloc((sizeof(*word) * count_word(str, ' ') - 1) + ch);
	for (i = 0; check_delim(str[i]) == 1 && str[i] != '\0'; i++);
	for ( ;str && str[i] != '\0'; i++, j++) {
		if (check_delim(str[i]) == 1) {
			for ( ;check_delim(str[i]) == 1 && str[i] != '\0'; i++);
			if (str[i] != '\0') {
				word[j] = ' ';
				j++;
			}
		}
		word[j] = str[i];
	}
	word[j] = '\0';
	return (word);
}
