/*
** EPITECH PROJECT, 2018
** exec2.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_exec_part2(s_exec *t_exec, char *buff)
{
	if (execve(buff, t_exec->cmd, t_exec->env) == -1) {
		dprintf(2, "%s%s", t_exec->cmd[0], " : command introuvalble\n");
		return (-1);
	}
	return (0);
}

char *prepar_exec(s_exec *t_exec)
{
	char *buff;

	(t_exec->cmd) = my_str_word_to_array(t_exec->e_command, ' ');
	if ((buff = pre_check((t_exec->cmd)[0], t_exec)) == NULL)
		return (NULL);
	return (buff);
}

int my_exec(s_exec *t_exec)
{
	int tmp;
	char *buff;

	if ((buff = prepar_exec(t_exec)) == NULL)
		return (-1);
	if ((t_exec->pipe_pid = fork()) == -1)
		return (-1);
	if (t_exec->pipe_pid == 0) {
		if ((tmp = my_exec_part2(t_exec, buff)) != 0)
			return (0);
		else
			return (1);
	}
	else {
		waitpid(t_exec->pipe_pid, &(t_exec->status), 0);
		status_gest(t_exec->status, &(t_exec->e_return));
		return (0);
	}
}