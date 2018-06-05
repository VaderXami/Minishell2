/*
** EPITECH PROJECT, 2018
** puterror
** File description:
** function
*/

#include "shell.h"

void	my_puterr(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_put_error(str[i]);
		i++;
	}
}
