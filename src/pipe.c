/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int count_pipe(s_exec *t_exec)
{
	t_exec->pipe = 0;

	for (int i = 0; t_exec->e_command[i] != '\0'; i++) {
		if (t_exec->e_command[i] == '|' || t_exec->e_command[i] == ';')
			t_exec->pipe++;
		if (t_exec->e_command[i] == '<' || t_exec->e_command[i] == '>')
			t_exec->pipe++;
	}
	return (t_exec->pipe);
}
