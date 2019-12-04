/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char **copy_setenv(char *str, char **env, char **envi, int lign)
{
	int a = 0;

	for (a = 0; a != lign; a++) {
		for (int j = 0; envi[a][j] != '\0'; j++) {
			env[a][j] = envi[a][j];
		}
	}
	for (int c = 0; str[c] != '\0'; c++) {
		env[a][c] = str[c];
	}
	return (env);
}

char **my_realloc(int lign, int col, char **envi, char *str)
{
	char **env;
	int i = 0;

	env = malloc(sizeof(char*) * (lign + 2));
	for (i = 0; i != lign; i++) {
		if (envi[i] == NULL)
			break;
		env[i] = malloc(sizeof(char) * (my_strlen(envi[i]) + 1));
		env[i] = my_memset(env[i], 0, my_strlen(envi[i]) + 1);
	}

	env[i] = malloc(sizeof(char) * (col + 1));
	env[i] = my_memset(env[i], 0, (col + 1));
	env[i + 1] = NULL;
	env = copy_setenv(str, env, envi, lign);
	return (env);
}

char *my_new_path(char **command)
{
	char *cmd;

	cmd = my_strcat(command[1], "=");
	cmd = my_strcat(cmd, command[2]);
	return (cmd);
}

int verif_setenv(s_exec *t_exec)
{
	if (t_exec->tab[1] == NULL) {
		my_show_env(t_exec);
		return (t_exec->e_return = 1);
	}
	if (t_exec->tab[3] != NULL) {
		my_putstr("setenv: Too many arguments.\n");
		return (t_exec->e_return = 1);
	}
	if (verif_alpha_env(t_exec) == 1)
		return (t_exec->e_return = 1);
	return (t_exec->e_return = 0);
}

int exec(char **path_tab, s_exec *t_exec)
{
	char **cmd;
	int j = 0;

	count_pipe(t_exec);
	if (t_exec->pipe == 0)
		cmd = my_str_word_to_array(t_exec->e_command, ' ');
	else
		return (my_pipe(t_exec));
	if (cmd[0][0] == '.' || cmd[0][0] == '/' || verif_slash(cmd))
		return (t_exec->e_return = exec_binary(cmd[0], cmd));
	else
		path_tab = verif_cmd(path_tab, cmd);
	for (j = 0; path_tab[j] != NULL; j++) {
		if (access(path_tab[j], F_OK) == 0) {
			t_exec->pid = fork();
			break;
		}
	}
	if (verif_access(path_tab, j, cmd) == 1)
		return (t_exec->e_return = 1);
	return (t_exec->e_return = exec3(path_tab, cmd, t_exec->pid));
}
