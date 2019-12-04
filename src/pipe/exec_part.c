/*
** EPITECH PROJECT, 2018
** exec_part.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char **all_pipe_on_cmmd(s_exec *t_exec, int i)
{
	char **pipe;
	int nb_pipe = 0;
	int backup = i;
	int j = 0;

	while ((t_exec->e_cmd)[i]) {
		if ((t_exec->e_cmd)[i + 1] && (t_exec->e_cmd)[i + 1][0] == '|')
			nb_pipe++;
		else
			break;
		i += 2;
	}
	if ((pipe = malloc(sizeof(char *) * (nb_pipe + 2))) == NULL)
		return (NULL);
	while (j < nb_pipe + 1) {
		pipe[j] = strdup((t_exec->e_cmd)[backup]);
		j++;
		backup += 2;
	}
	pipe[j] = NULL;
	return (pipe);
}

int cmmd_is_good_shell(s_exec *t_exec)
{
	int i = -1;
	int separator = 0;
	int any_one = 0;

	while ((t_exec->e_cmd)[++i])
		if ((t_exec->e_cmd)[i][0] == ';' || (t_exec->e_cmd)[i][0] == '|'
			|| (t_exec->e_cmd)[i][0] == '>' ||
			(t_exec->e_cmd)[i][0] == '<')
			separator++;
		else
			any_one++;
	if (separator + 1 != any_one)
		return (0);
	return (1);
}

int exec_part2(s_exec *t_exec)
{
	int i = 0;
	int tmp;

	while ((t_exec->e_cmd)[i]) {
		(t_exec->e_command) = (t_exec->e_cmd)[i];
		if ((t_exec->e_cmd)[i + 1] &&
			(t_exec->e_cmd)[i + 1][0] == '|') {
			(t_exec->paillepeu) = all_pipe_on_cmmd(t_exec, i);
			if ((tmp = execute_pipe(t_exec, 0)) != -1)
				i += tmp;
			else
				return (-1);
		}
		else {
			my_exec(t_exec);
			i += 2;
		}
	}
	return (0);
}

int exec_part(s_exec *t_exec)
{
	(t_exec->e_cmd) = epur_tab(parse_cmd(t_exec->e_command));
	if (cmmd_is_good_shell(t_exec) == 0)
		return (0);
	return (exec_part2(t_exec));
}
