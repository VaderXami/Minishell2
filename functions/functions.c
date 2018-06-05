/*
** EPITECH PROJECT, 2018
** functions
** File description:
** minishell1
*/

#include "shell.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_put_error(char c)
{
	write(2, &c, 1);
}

int	my_putstr(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

char	*my_strcpy(char *dest, char const *src)
{
	int	i = 0;

	if (dest == NULL)
		dest = malloc(sizeof(*dest) * (my_strlen(src) + 1));
	while (src && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
