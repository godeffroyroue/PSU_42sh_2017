/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *get_user(char **tab)
{
	int pipefd[2];
	ssize_t pid;
	int rd;
	char *buffer = malloc(4096);

	if (pipe(pipefd) == -1)
		my_exit(84);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		execve("/bin/whoami", tab, NULL);
		close(pipefd[0]);
	}
	else
		wait(NULL);
	rd = read(pipefd[0], buffer, 4096);
	buffer[rd - 1] = '\0';
	return (buffer);
}

char *my_cut_pwd(char *pwd)
{
	char *tampon = malloc(sizeof(char) * (my_strlen(pwd) + 1));
	int i = 0;
	int j = 0;
	int b = 0;

	for (i = 0; pwd[i] != '\0'; i++);
	for (j = i; pwd[j] != '/'; j--);
	for (int a = j; pwd[a] != '\0'; a++) {
		tampon[b] = pwd[a];
		b++;
	}
	tampon[b] = '\0';
	return (tampon);
}

char **take_info_user(char *path)
{
	char **tab = malloc(sizeof(char*) * 3);

	for (int i = 0; i != 3; i++) {
		tab[i] = malloc(150);
		my_memset(tab[i], 0, 150);
	}
	tab[0] = my_strcpy(tab[0], path);
	tab[1] = NULL;
	return (tab);
}

char *cut_time(char *my_time)
{
	char **tab = my_str_word_to_array(my_time, ' ');

	return (tab[3]);
}

void print_my_prompt(int v_return)
{
	char *my_time;
	char *my_user;
	char *pwd = malloc(150);
	char **tab = take_info_user("/bin/date");

	if (v_return == 0)
		printf("%s➤➤%s", KGRN, KNRM);
	else
		printf("%s➤➤%s", KRED, KNRM);
	getcwd(pwd, 150);
	pwd = my_cut_pwd(pwd);
	my_time = get_time(tab);
	my_time = cut_time(my_time);
	tab = take_info_user("/bin/whoami");
	my_user = get_user(tab);
	my_printf("%s+[%s] %s%s@localhost: ", KCYN, my_time, KYEL, my_user);
	my_printf("%s| ~%s |%s", KBLU, pwd, KNRM);
}
