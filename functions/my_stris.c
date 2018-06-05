/*
** EPITECH PROJECT, 2018
** function
** File description:
** functions
*/

#include "shell.h"

int	my_charis(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_special1(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 33 && str[i] <= 47)
			return (1);
		i++;
	}
	return (0);
}

int	check_special2(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 58 && str[i] <= 64)
			return (1);
		i++;
	}
	return (0);
}

int	check_special3(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 91 && str[i] <= 96)
			return (1);
		i++;
	}
	return (0);
}
