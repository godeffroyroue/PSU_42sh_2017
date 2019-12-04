/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int gest_error(char *buffer, s_exec *t_exec)
{
	if (buffer == NULL && isatty(0) == 1)
		my_exit(t_exec->e_return);
	else if (buffer == NULL)
		exit(t_exec->e_return);
	return (0);
}

int my_cd_error(char *command)
{
	my_putstr(command);
	my_putstr(": Not a directory.\n");
	return (1);
}

char *my_get(char *str, char **env)
{
	int i = 0;
	char *path;

	for (; env[i] != NULL; i++) {
		if ((find_word(env[i], str)) == 0)
			break;
	}
	if (env[i] == NULL)
		return (NULL);
	(my_strcmp(str, "HOME") == 0 ? path = env[i] += 5 : 0);
	(my_strcmp(str, "PWD") == 0 ? path = env[i] += 9 : 0);
	return (path);
}

int my_cd2(s_exec *t_exec)
{
	if (t_exec->old_pwd == NULL) {
		my_putstr(": Not a directory.\n");
		return (t_exec->e_return = 1);
	}
	if ((chdir(t_exec->old_pwd)) == -1) {
		my_printf("error\n");
		return (t_exec->e_return = my_cd_error(t_exec->old_pwd));
	}
	t_exec->old_pwd = t_exec->pwd;
	return (t_exec->e_return = 0);
}

int my_cd(s_exec *t_exec)
{
	char *pwd;

	if (t_exec->tab[1] == NULL || my_strcmp(t_exec->tab[1], "~") == 0) {
		pwd = my_get("HOME", t_exec->env);
		if (pwd == NULL)
			return (t_exec->e_return = 0);
		if ((chdir(pwd)) == -1)
			return (t_exec->e_return = my_cd_error(t_exec->tab[1]));
		t_exec->old_pwd = t_exec->pwd;
		return (t_exec->e_return = 0);
	}
	if (my_strcmp(t_exec->tab[1], "-") == 0)
		return (t_exec->e_return = my_cd2(t_exec));
	if (chdir(t_exec->tab[1]) == -1)
		return (t_exec->e_return = my_cd_error(t_exec->tab[1]));
	t_exec->old_pwd = t_exec->pwd;
	return (t_exec->e_return);
}
