/*
** EPITECH PROJECT, 2018
** exec2.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int count_char(char *str, char c)
{
	int i = -1;
	int count = 0;

	while (str[++i])
		((str[i] == c) ? count++ : 0);
	return (count);
}

int is_in_tab(char *str, char **tab)
{
	int i = 0;

	while (tab[i]) {
		if (strncmp(str, tab[i], my_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char *my_str_fus(char *str1, char c, char *str2)
{
	int count = my_strlen(str1) + my_strlen(str2);
	char *str = my_alloc_str(count + 2);
	int i = -1;
	int k = -1;

	while (str1[++i])
		str[i] = str1[i];
	str[i++] = c;
	while (str2[++k])
		str[i + k] = str2[k];
	str[i + k] = '\0';
	return (str);
}

int pre_check2(char *str, char *buff_tab)
{
	if (opendir(buff_tab) == NULL) {
		if (access(buff_tab, X_OK) == 0)
			return (0);
		else {
			my_printf("%e%e", str, "tab_error_2\n");
			return (-1);
		}
	}
	else {
		my_printf("%e%e", str, "tab_error_2\n");
		return (-1);
	}
}

char *pre_check(char *str, s_exec *t_exec)
{
	char buff[256];
	char *buff_tab = get_path_cmd(str, t_exec->env);

	if (buff_tab == NULL) {
		if (access(str, X_OK) == 0) {
			getcwd(buff, sizeof(buff));
			return (my_str_fus(buff, '/', str));
		}
		else {
			(t_exec->e_return) = 1;
			return (NULL);
		}
	}
	if (access(buff_tab, F_OK) == 0 && buff_tab != NULL) {
		if (pre_check2(str, buff_tab) != 0)
			return (NULL);
		else
			return (buff_tab);
	}
	return (NULL);
}