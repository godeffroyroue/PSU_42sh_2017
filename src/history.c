/*
** EPITECH PROJECT, 2018
** history.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void my_show_tabchar(char **tab)
{
	int i = -1;

	while (tab[++i])
		my_printf("%stab[%d] %s:%s %s\n", KCYN, i, KMAG, KNRM, tab[i]);
}

void create_history(s_exec *t_exec)
{
	(t_exec->hist) = malloc(sizeof(char *) * LENGTH_HIST_MAX);
	(t_exec->hist)[0] = malloc(sizeof(char) * 1);
	(t_exec->hist)[1] = NULL;
	(t_exec->hist)[0][0] = '*';
	(t_exec->hist)[0][1] = '\0';
}

void update_history(char *cmd, s_exec *t_exec)
{
	int y_hist = -1;
	int cmd_length = my_strlen(cmd);
	int x = -1;

	while ((t_exec->hist)[++y_hist] != NULL);
	(t_exec->hist)[y_hist + 1] = NULL;
	(t_exec->hist)[y_hist] = malloc(sizeof(char) * cmd_length);
	my_memset((t_exec->hist)[y_hist], '*', cmd_length);
	while (cmd[++x])
		(t_exec->hist)[y_hist][x] = cmd[x];
}
