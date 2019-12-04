/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int find_word(char *str, char *word)
{
	int j = 0;
	int i = 0;

	if (word[0] == str[0]) {
		while (word[j + 1] == str[i + 1]) {
			i++;
			j++;
		}
		if (word[j + 1] == '\0')
			return (0);
	}
	return (1);
}

char *find_path(char **env)
{
	char *str = "PATH";
	int i = 0;

	for (; env[i] != NULL; i++) {
		if ((find_word(env[i], str)) == 0)
			break;
	}
	return (env[i]);
}
