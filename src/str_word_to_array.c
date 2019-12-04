/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int count_lign(char *str, char del)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == del)
			count++;
	}
	return (count + 2);
}

int count_col(char *str, char del)
{
	int count = 0;
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == del && j > count) {
			count = j;
			j = 0;
		}
		j++;
	}
	return (count + 1);
}

char *my_memset(char *str, int c, int n)
{
	for (int i = 0; i != n; i++) {
		str[i] = c;
	}
	return (str);
}

char **str_word_to_malloc(char **tab, int lign, int col)
{
	tab = malloc(sizeof(char*) * (lign + 1));
	for (int i = 0; i != lign + 1; i++) {
		tab[i] = malloc(sizeof(char) * (col + 4));
		tab[i] = my_memset(tab[i], 0, col + 4);
	}
	tab[lign - 1] = NULL;
	return (tab);
}

char **my_str_word_to_array(char *str, char del)
{
	char **tab = NULL;
	int lign;
	int col;
	int a = 0;
	int b = 0;

	lign = count_lign(str, del);
	col = count_col(str, del);
	tab = str_word_to_malloc(tab, lign, col);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == del) {
			a++;
			b = 0;
		}
		else {
			tab[a][b] = str[i];
			b++;
		}
	}
	return (tab);
}
