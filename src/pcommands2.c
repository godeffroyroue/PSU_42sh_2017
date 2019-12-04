/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void my_tab_free(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
}

int my_pipe(s_exec *t_exec)
{
	char **cmd = my_str_word_to_array(t_exec->e_command, '|');
	char **an_cmd;
	int j = 0;
	char **path_tab;

	if (pipe(t_exec->pipefd) == -1)
		my_exit(84);
	cmd = clean_cmd(cmd, 0);
	for (int i = 0; cmd[i]; i++) {
		path_tab = find_our_path(t_exec->env);
		an_cmd = my_str_word_to_array(cmd[i], ' ');
		an_cmd = clean_cmd(an_cmd, 1);
		path_tab = verif_cmd(path_tab, an_cmd);
		j = verif_path(path_tab);
		if (j == -1)
			return (1);
		if (verif_access(path_tab, j, an_cmd) == 1)
			return (1);
		exec_cmd(an_cmd, t_exec, path_tab[j], i);
	}
	return (0);
}

int exec_child(int i, s_exec *t_exec, char **cmd, char *path_tab)
{
	if (i == 0) {
		dup2(t_exec->pipefd[1], 1);
		close(t_exec->pipefd[1]);
		execve(path_tab, cmd, NULL);
		close(t_exec->pipefd[0]);
	}
	else {
		dup2(t_exec->pipefd[0], 0);
		close(t_exec->pipefd[0]);
		dup2(t_exec->pipefd[1], 1);
		execve(path_tab, cmd, NULL);
		close(t_exec->pipefd[1]);
	}
	return (0);
}

int exec_parent(void)
{
	wait(NULL);
	return (0);
}

int exec_cmd(char **cmd, s_exec *t_exec, char *path_tab, int i)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		exit(84);
	if (pid == 0)
		exec_child(i, t_exec, cmd, path_tab);
	if (pid != 0)
		exec_parent();
	close(t_exec->pipefd[1]);
	close(t_exec->pipefd[0]);
	return (0);
}
