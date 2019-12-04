/*
** EPITECH PROJECT, 2018
** separat.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int is_it_this_separ(char *str, int pos, char *compar)
{
	int i = -1;
	int count = 0;

	while (compar[++i]) {
		if (str[pos + i] != compar[i])
			count++;
	}
	if (count == 0)
		return (1);
	else
		return (-1);
}

int charac_is_sep(char *str, int pos)
{
	printf("POS : %d\n", pos);
	for (int i = pos; str[i] != '\0'; i++) {
		if (str[i] == ' ' && str[i + 1] == '|' && str[i + 2] == ' ')
			return (1);
	}
	return (-1);
}

int how_many_separat(s_exec *t_exec)
{
	int nbr_sep = 0;

	for (int i = 0; t_exec->e_command[i] != '\0'; i++) {
		if (t_exec->e_command[i - 1] == ' '
			&& t_exec->e_command[i] == '|'
			&& t_exec->e_command[i + 1] == ' '
			&& t_exec->e_command[i + 1] != '\0')
			nbr_sep++;
	}
	return (nbr_sep);
}
