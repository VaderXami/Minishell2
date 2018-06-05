/*
** EPITECH PROJECT, 2018
** functions
** File description:
** minishell1
*/

#include "shell.h"

char	*my_strdup(char *str)
{
	char	*str2;
	int	i = 0;
	int	len = 0;

	if (str == NULL)
		return (NULL);
	len = my_strlen(str);
	str2 = malloc(sizeof(*str2) * (len + 1));
	while (str && str[i] != '\0') {
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int	my_strcmp(char *str1, char *str2)
{
	int	i = 0;

	while (str1[i] == str2[i] && (str1[i] != '\0') && (str2[i] != '\0'))
		i++;
	return (str1[i] - str2[i]);
}

void	my_bzero(char *s, int n)
{
	int	i = 0;

	while (i < n) {
		s[i] = '\0';
		i++;
	}
}

int	my_strncmp(char *str1, char *str2, int len)
{
	int	i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && i < len) {
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

char	*my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	len = 0;

	len = my_strlen(dest);
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0') {
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
