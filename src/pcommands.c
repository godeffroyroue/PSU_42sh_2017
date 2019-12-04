/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char **find_our_path(char **env)
{
	char *path = find_path(env);
	char **tab_path = my_str_word_to_array(path, ':');

	tab_path[0] += 5;
	return (tab_path);
}

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

char *clean_l(char *str)
{
	char *str2 = malloc(sizeof(char) * (my_strlen(str) + 2));
	int j = 0;

	memset(str2, 0, my_strlen(str) + 2);
	for (int i = 0; str[i] != '\0'; i++)
		(str[i] == '\t') ? str[i] = ' ': 0;
	str = clean_ligne(str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\0') {
			str2[j] = '\0';
			return (str2);
		}
		if (str[i] == ' ' && str[i + 1] == ' ')
			i = i;
		else {
			str2[j] = str[i];
			j++;
		}
	}
	(str2[j - 1] == ' ') ? str2[j - 1] = '\0' : 0;
	return (str2);
}

char *clean_ligne(char *str)
{
	char *str2;
	int i = 0;
	int j = 0;

	if (str == NULL)
		return (NULL);
	str2 = malloc(sizeof(char) * (my_strlen(str) + 2));
	my_memset(str2, 0, my_strlen(str) + 2);
	if (str[0] <= ' ' || str[0] >= 127) {
		for (i = 0; str[i] <= ' ' || str[i] >= 127; i++);
		for (i = i; str[i] != '\0'; i++) {
			str2[j] = str[i];
			j++;
		}
		str2[j] = '\0';
		return (str2);
	}
	return (str);
}

char **clean_cmd(char **cmd, int secure)
{
	if (secure == 0) {
		for (int i = 0; cmd[i]; i++) {
			cmd[i] = clean_ligne(cmd[i]);
		}
		return (cmd);
	}
	for (int i = 0; cmd[i]; i++)
		(cmd[i][0] <= ' ' || cmd[i][0] >= 127) ? cmd[i] = NULL : 0;
	return (cmd);
}
