/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *get_time(char **tab)
{
	int pipefd[2];
	ssize_t pid;
	int rd;
	char *buffer = malloc(4096);

	if (pipe(pipefd) == -1)
		my_exit(84);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		execve("/bin/date", tab, NULL);
		close(pipefd[0]);
	}
	else
		wait(NULL);
	rd = read(pipefd[0], buffer, 4096);
	buffer[rd - 1] = '\0';
	return (buffer);
}

int verif_alpha_env(s_exec *t_exec)
{
	int nb = 0;

	for (int i = 0; t_exec->tab[1][i] != '\0'; i++) {
		if (t_exec->tab[1][i] < '0')
			nb = 1;
		if (t_exec->tab[1][i] > '9' && t_exec->tab[1][i] < 'A')
			nb = 1;
		if (t_exec->tab[1][i] > 'Z' && t_exec->tab[1][i] < 'a')
			nb = 1;
		if (t_exec->tab[1][i] > 'z')
			nb = 1;
	}
	if (nb == 1) {
		my_putstr("setenv: Variable name must contain ");
		my_putstr("alphanumeric characters.\n");
		return (t_exec->e_return = 1);
	}
	return (t_exec->e_return = 0);
}

int verif_path(char **path_tab)
{
	int j = 0;

	for (j = 0; path_tab[j] != NULL; j++) {
		if (access(path_tab[j], F_OK) == 0) {
			return (j);
		}
	}
	return (-1);
}

void my_clear(void)
{
	for (int i = 0; i != 60; i++) {
		my_putstr("\n");
	}
}
