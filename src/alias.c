/*
** EPITECH PROJECT, 2018
** alias.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void delim(void);

void gest_error_alias(char **tab)
{
	int i = -1;

	while (tab[++i]) {
		if (strncmp(tab[i], "alias ", 6) == 0)
			printf("good on tab[%d]\n", i);
		else
			printf("false on tab[%d]\n", i);
	}
}

char ***create_ali(char *path_alias)
{
	char ***ali = malloc(sizeof(char **) * 4);
	char *buff = my_recup(path_alias);
	int y = -1;
	int x;

	ali[0] = my_str_word_to_array(buff, '\n');
	x = find_length_max_on_tab(ali[0]);
	while (ali[0][++y]);
	ali[1] = create_tab_alias(ali[0], x, y);
	ali[2] = create_tab_cmd(ali[0], x, y);
	ali[3] = NULL;
	return (ali);
}

char *check_is_alias(char *command, char *path_alias)
{
	char ***ali = create_ali(path_alias);
	int i = -1;

	while (ali[1][++i])
		if (my_strcmp(ali[1][i], command) == 0)
			break;
	if (ali[1][i] == NULL)
		return (command);
	else
		return (ali[2][i]);
}

char *change_command_alias(char *command)
{
	return (command);
}
