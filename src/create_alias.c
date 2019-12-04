/*
** EPITECH PROJECT, 2018
** create_alias.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int find_length_max_on_tab(char **tab)
{
	int i = -1;
	int res = 0;
	int tmp;

	while (tab[++i]) {
		tmp = my_strlen(tab[i]);
		((tmp > res) ? res = tmp : 0);
	}
	return (res);
}

char **create_tab_alias(char **tab, int int_x, int int_y)
{
	char **tab_alias = create_tab(int_x, int_y, '*');
	int y = -1;
	int x;
	int cpt = 0;

	while (tab[++y]) {
		x = 5;
		cpt = 0;
		while (tab[y][++x] != '=' && tab[y]) {
			tab_alias[y][cpt] = tab[y][x];
			cpt++;
		}
		tab_alias[y][cpt] = '\0';
	}
	return (tab_alias);
}

char **create_tab_cmd(char **tab, int int_x, int int_y)
{
	char **tab_cmd = create_tab(int_x, int_y, '*');
	int y = -1;
	int x;
	int cpt;

	while (tab[++y]) {
		cpt = 0;
		x = -1;
		while (tab[y][++x] != '"');
		while (tab[y][++x] != '"') {
			tab_cmd[y][cpt] = tab[y][x];
			cpt++;
		}
		tab_cmd[y][cpt] = '\0';
	}
	return (tab_cmd);
}
