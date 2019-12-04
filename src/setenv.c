/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int inenv(s_exec *t_exec)
{
	int i = 0;

	for (i = i; t_exec->env[i]; i++) {
		if (find_word(t_exec->env[i], t_exec->tab[1]) == 0)
			break;
	}
	if (t_exec->env[i] == NULL)
		return (-1);
	return (i);
}

char *copy_old_value(s_exec *t_exec, int i)
{
	char *tampon;
	int j = 0;

	tampon = malloc(sizeof(char) * (my_strlen(t_exec->env[i])) + 1);
	my_memset(tampon, 0, my_strlen(t_exec->env[i]) + 1);
	for (j = 0; t_exec->env[i][j] != '\0'; j++) {
		tampon[j] = t_exec->env[i][j];
		if (t_exec->env[i][j] == '=')
			break;
	}
	return (tampon);
}

char *destroy_value(s_exec *t_exec, int i)
{
	int j = 0;

	for (j = 0; t_exec->env[i][j] != '\0'; j++) {
		if (t_exec->env[i][j] == '=')
			break;
	}
	t_exec->env[i][j + 1] = '\0';
	return (t_exec->env[i]);

}

int verif_inenv(s_exec *t_exec)
{
	int i = inenv(t_exec);
	char *tampon;
	int nb = 0;
	int b;

	if (i == -1)
		return (1);
	if (t_exec->tab[2] == NULL) {
		t_exec->env[i] = destroy_value(t_exec, i);
		return (0);
	}
	tampon = copy_old_value(t_exec, i);
	nb = my_strlen(tampon) + my_strlen(t_exec->tab[2]) + 1;
	t_exec->env[i] = malloc(sizeof(char) * nb);
	my_memset(t_exec->env[i], 0, nb);
	for (b = 0; tampon[b] != '\0'; b++)
		t_exec->env[i][b] = tampon[b];
	for (int a = 0; t_exec->tab[2][a] != '\0'; a++, b++)
		t_exec->env[i][b] = t_exec->tab[2][a];
	return (0);
}

int my_setenv(s_exec *t_exec)
{
	int col = 0;
	char *new_line;
	int lign = 0;

	if (verif_setenv(t_exec))
		return (t_exec->e_return);
	if (verif_inenv(t_exec) == 0)
		return (t_exec->e_return = 0);
	if (t_exec->tab[1] != NULL && t_exec->tab[2] == NULL)
		new_line = my_strcat(t_exec->tab[1], "=");
	if (t_exec->tab[1] != NULL && t_exec->tab[2] != NULL)
		new_line = my_new_path(t_exec->tab);
	col = my_strlen(new_line);
	for (int i = 0; t_exec->env[i] != NULL; i++)
		lign++;
	t_exec->env = my_realloc(lign, col, t_exec->env, new_line);
	return (t_exec->e_return);
}
