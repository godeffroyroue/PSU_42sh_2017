/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char **verif_cmd(char **path_tab, char **cmd)
{
	for (int i = 0; path_tab[i]; i++) {
		path_tab[i] = my_strcat(path_tab[i], "/");
		path_tab[i] = my_strcat(path_tab[i], cmd[0]);
	}
	return (path_tab);
}

int verif_access(char **path_tab, int j, char **cmd)
{
	if (path_tab[j] == NULL) {
		my_perror(cmd[0]);
		return (1);
	}
	return (0);
}

char **bin_alloc(char **path_tab, char *str)
{
	path_tab = malloc(sizeof(char*) * 2);
	for (int i = 0; i != 2; i++)
		path_tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
	for (int i = 0; str[i] != '\0'; i++)
		path_tab[0][i] = str[i];
	path_tab[1] = NULL;
	return (path_tab);
}

int my_segfault(int status)
{
	if (status == 139) {
		my_putstr("Segmentation fault\n");
		return (139);
	}
	return (0);
}

int exec3(char **path_tab, char **cmd, pid_t pid)
{
	int status;
	int nb;

	if (pid == 0)
		nb = exec2(path_tab, cmd, 0);
	else
		wait(&status);
	nb = my_segfault(status);
	return (nb);
}
