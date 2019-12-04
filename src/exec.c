/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int the_execution(int ac, s_exec *t_exec)
{
	char **tab_path;
	char *path;

	if (t_exec->env[1] == NULL) {
		my_perror(t_exec->tab[0]);
		return (t_exec->e_return = 1);
	}
	path = find_path(t_exec->env);
	tab_path = my_str_word_to_array(path, ':');
	t_exec->ac = ac;
	tab_path[0] += 5;
	exec(tab_path, t_exec);
	return (0);
}

char *my_strcat(char *dest, char *src)
{
	int j = 0;
	int i = 0;
	int len = my_strlen(dest) + my_strlen(src);
	char *tmp = malloc(sizeof(char) * (len + 1));

	while (dest[j] != '\0') {
		tmp[j] = dest[j];
		j++;
	}
	while (src[i] != '\0') {
		tmp[j] = src[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int exec2(char **path_tab, char **cmd, int i)
{
	while (path_tab[i] != NULL) {
		if ((execve(path_tab[i], cmd, NULL)) == -1)
			i++;
		else
			break;
	}
	return (0);
}

int exec_binary(char *path, char **cmd)
{
	pid_t pid;
	int status;
	struct stat sts;

	if (access(path, F_OK) == -1) {
		my_perror(cmd[0]);
		return (1);
	}
	stat(path, &sts);
	if (S_ISDIR(sts.st_mode)) {
		my_putstr(path);
		my_putstr(": Permission denied.\n");
		return (1);
	}
	pid = fork();
	if (pid == 0)
		execve(cmd[0], cmd, NULL);
	else
		wait(&status);
	return (0);
}

int verif_slash(char **cmd)
{
	for (int i = 0; cmd[0][i] != '\0'; i++) {
		if (cmd[0][i] == '/')
			return (1);
	}
	return (0);
}
