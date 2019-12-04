/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** mysh.c
*/

#include "my.h"

int mysh2(int ac, s_exec *t_exec)
{
	if (my_strcmp(t_exec->tab[0], "cd") == 0) {
		my_cd(t_exec);
		return (t_exec->e_return);
	}
	else if (my_strcmp(t_exec->tab[0], "exit") == 0)
		my_exit(0);
	else if (my_strcmp(t_exec->tab[0], "unsetenv") == 0) {
		my_unsetenv(t_exec);
		return (t_exec->e_return);
	}
	else if (my_strcmp(t_exec->tab[0], "clear") == 0)
		my_clear();
	else
		the_execution(ac, t_exec);
	return (t_exec->e_return);
}

int init_shell(char *command, s_exec *t_exec)
{
	char *m_buff = malloc(sizeof(char) * 100);

	free(t_exec->e_command);
	t_exec->e_command = clean_l(command);
	t_exec->tab = my_str_word_to_array(t_exec->e_command, ' ');
	t_exec->e_return = 0;
	t_exec->pwd = getcwd(m_buff, 100);
	return (0);
}

int mysh(int ac, char *command, s_exec *t_exec)
{
	init_shell(command, t_exec);
	if (how_many_separat(t_exec) > 0)
		return (exec_part(t_exec));
	if (my_strcmp(t_exec->tab[0], "env") == 0) {
		if (t_exec->tab[1] == NULL)
			my_show_env(t_exec);
		else {
			my_printf("env: '%s':", t_exec->tab[1]);
			my_printf(" No such file or directory\n");
		}
		return (t_exec->e_return);
	}
	else if (my_strcmp(t_exec->tab[0], "setenv") == 0) {
		my_setenv(t_exec);
		return (t_exec->e_return);
	}
	mysh2(ac, t_exec);
	return (t_exec->e_return);
}

char **copy_env(char **envi)
{
	int lign = 0;
	char **env;

	if (envi == NULL)
		return (NULL);
	for (int i = 0; envi[i] != NULL; i++)
		lign++;
	env = malloc(sizeof(char*) * (lign + 1));
	for (int i = 0; i < lign; i++) {
		env[i] = malloc(sizeof(char) * (my_strlen(envi[i]) + 1));
		env[i] = my_memset(env[i], 0, my_strlen(envi[i]) + 1);
	}
	env[lign] = NULL;
	for (int i = 0; envi[i] != NULL; i++) {
		for (int j = 0; envi[i][j] != '\0'; j++) {
			env[i][j] = envi[i][j];
		}
	}
	return (env);
}
