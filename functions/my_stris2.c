/*
** EPITECH PROJECT, 2018
** stris2
** File description:
** functions
*/

#include "shell.h"

int	check_special4(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (check_special1(str) == 1 || check_special2(str) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_special5(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (check_special4(str) == 1 || check_special3(str) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_special6(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 123 && str[i] <= 126)
			return (1);
		i++;
	}
	return (0);
}

int	my_check_special(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (check_special6(str) == 1 || (check_special5(str) == 1))
			return (1);
		i++;
	}
	return (0);
}
