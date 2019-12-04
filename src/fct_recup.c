/*
** EPITECH PROJECT, 2018
** fct_recup.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void my_show_triple_tabchar(char ***tab)
{
	int z = -1;

	printf("%s", KRED);
	for (int x = 0 ; x < 60 ; x++)
		printf("=");
	printf("%s\n", KGRN);
	while (tab[++z]) {
		for (int x = 0 ; x < 50 ; x++)
			printf("_");
		printf("%s[%d]%s\n", KYEL, z, KNRM);
		my_show_tabchar(tab[z]);
		printf("%s", KGRN);
		for (int x = 0 ; x < 50 ; x++)
			printf("_");
		printf("\n");
	}
	printf("%s", KRED);
	for (int x = 0 ; x < 60 ; x++)
		printf("=");
	printf("%s\n", KNRM);
}

char **create_tab(int x, int y, char c)
{
	int i = -1;
	int k;
	char **tab;

	if ((tab = malloc(sizeof(char *) * (y + 1))) == NULL)
		return (NULL);
	while (++i != y) {
		k = -1;
		if ((tab[i] = malloc(sizeof(char) * (x + 1))) == NULL)
			return (NULL);
		while (++k != x)
			tab[i][k] = c;
		tab[i][k] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

void delim(void)
{
	printf("\n\n\n");
	for (int i = 0 ; i < 3 ; i++) {
	}
	for (int k = 0 ; k < 4 ; k++)
		printf("|||\n");
	printf("~~~\n\n");
}

char *my_alloc_str(int size)
{
	char *str;

	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	my_memset(str, '*', size);
	return (str);
}

char *my_recup(char *name)
{
	int fd = open(name, O_RDONLY);
	char buff[4096];
	char *str;
	int i = -1;

	my_memset(buff, 0, sizeof(buff));
	if (fd == -1) {
		dprintf(2, "prblm d'ouverture\n");
		return (NULL);
	}
	read(fd, &buff, sizeof(buff));
	close(fd);
	str = my_alloc_str(my_strlen(buff));
	while (buff[++i])
		str[i] = buff[i];
	str[i] = '\0';
	return (str);
}
