/*
** EPITECH PROJECT, 2018
** exec_pipe.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void close_exec_exit(int p, s_exec *t_exec, int i)
{
	close(p);
	(t_exec->e_command) = (t_exec->paillepeu)[i];
	my_exec(t_exec);
	exit(t_exec->e_return);
}

int close_iplusplus_fd_in(int p, int i, int *fd_in, int p0)
{
	close(p);
	*fd_in = p0;
	return (i + 1);
}

void my_dup(int fd_in, s_exec *t_exec, int p1, int i)
{
	dup2(fd_in, 0);
	if (t_exec->paillepeu[i + 1])
		dup2(p1, 1);

}

int execute_pipe(s_exec *t_exec, int i)
{
	int p[2];
	pid_t pid;
	int fd_in = 0;
	int status;

	while ((t_exec->paillepeu)[i]) {
		pipe(p);
		if ((pid = fork()) == -1)
			return (-1);
		else if (pid == 0) {
			my_dup(fd_in, t_exec, p[1], i);
			close_exec_exit(p[0], t_exec, i);
		}
		else {
			wait(&status);
			i = close_iplusplus_fd_in(p[1], i, &fd_in, p[0]);
		}
	}
	status_gest(status, &(t_exec->e_return));
	return (2 * i);
}
