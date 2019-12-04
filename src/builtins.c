/*
** EPITECH PROJECT, 2018
** builtins.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i]) {
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		write(1, &str[i], 1);
	}
	return (0);
}

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}

int my_show_env(s_exec *t_exec)
{
	for (int i = 0; t_exec->env[i] != NULL; i++) {
		my_putstr(t_exec->env[i]);
		my_putstr("\n");
	}
	return (0);
}
