/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char **parse_cmd2(char **dest, char *str)
{
	int k;
	int i = 0;
	int j = 0;
	int tmp = 0;

	while (str[i]) {
		k = 0;
		if ((dest[j] = malloc(strlen(str))) == NULL)
			return (NULL);
		while (str[i] && is_a_sep(str[i]) == tmp)
			dest[j][k++] = str[i++];
		dest[j++][k] = '\0';
		tmp = (tmp == 0 ? 1 : 0);
	}
	dest[j] = dest[j + 1] = NULL;
	return (dest);
}

char **parse_cmd(char *str)
{
	char **dest;

	if ((dest = malloc(sizeof(char *) *
		(count_sep(str) * 2 + 3))) == NULL)
		return (NULL);
	if (count_sep(str) == 0) {
		dest[0] = strdup(str);
		dest[1] = dest[2] = NULL;
		return (dest);
	}
	parse_cmd2(dest, str);
	return (dest);
}