/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *epur_str(char *str)
{
	char *res;
	int j = 0;

	if (str == NULL)
		return (NULL);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if ((res = malloc(strlen(str) + 1)) == NULL)
		return (NULL);
	while (*str) {
		if (*str != ' ' && *str != '\t')
			res[j++] = *str;
		else if (*(str + 1) &&
			(*str == ' ' || *str == '\t') &&
			*(str + 1) != ' ' && *(str + 1) != '\t')
			res[j++] = ' ';
		str++;
	}
	res[j] = '\0';
	return (res);
}

char **epur_tab(char **tab)
{
	int i = -1;

	while (tab[++i])
		tab[i] = epur_str(tab[i]);
	return (tab);
}

int is_a_sep(char c)
{
	if (c == '|' || c == ';' || c == '>' || c == '<')
		return (1);
	return (0);
}

int count_sep(char *str)
{
	int i = -1;
	int count = 0;

	while (str[++i])
		if (is_a_sep(str[i]) == 1)
			count++;
	return (count);
}