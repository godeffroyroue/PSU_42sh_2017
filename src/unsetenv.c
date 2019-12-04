/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_perror(char *cmd)
{
	my_putstr(cmd);
	my_putstr(": Command not found.\n");
	return (0);
}

int find_unsetlign(char **env, char *str)
{
	int i = 0;

	for (; env[i] != NULL; i++) {
		if ((find_word(env[i], str)) == 0) {
			break;
		}
	}
	if (env[i] == NULL)
		return (-1);
	return (i);
}

char **copy_unsetenv(char **envi, char **env, int del, int lign)
{
	int a = 0;
	int b = 0;

	for (a = 0; a != del; a++) {
		for (int j = 0; envi[b][j] != '\0'; j++) {
			env[a][j] = envi[b][j];
		}
		b++;
	}
	b++;
	for (a = del; a != lign - 1; a++) {
		for (int j = 0; envi[b][j] != '\0'; j++) {
			env[a][j] = envi[b][j];
		}
		b++;
	}
	return (env);
}

char **my_dealloc(int del, char **envi, int lign)
{
	char **env;
	int i = 0;
	int j = 0;

	env = malloc(sizeof(char *) * (lign + 2));
	for (i = 0; j != lign; i++) {
		if (envi[i] == NULL)
			break;
		if (i == del)
			j++;
		env[i] = malloc(sizeof(char) * (my_strlen(envi[j]) + 1));
		env[i] = my_memset(env[i], 0, my_strlen(envi[j]) + 1);
		j++;
	}
	env[i] = NULL;
	env = copy_unsetenv(envi, env, del, lign);
	return (env);
}

int my_unsetenv(s_exec *t_exec)
{
	int del;
	int lign = 0;

	if (t_exec->tab[1] == NULL) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (t_exec->e_return = 1);
	}
	if ((del = find_unsetlign(t_exec->env, t_exec->tab[1])) == -1)
		return (t_exec->e_return = 1);
	for (int i = 0; t_exec->env[i] != NULL; i++)
		lign++;
	if (del == lign - 1)
		t_exec->env[lign - 1] = NULL;
	else if (del != lign - 1)
		t_exec->env = my_dealloc(del, t_exec->env, lign);
	return (t_exec->e_return = 0);
}
