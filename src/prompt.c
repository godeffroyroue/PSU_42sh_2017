/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_exit(int n)
{
	my_putstr("exit\n");
	exit(n);
}

char *clean_input(char *buffer)
{
	for (int i = 0; buffer[i] != '\0'; i++)
		buffer[i] == '\n' ? buffer[i] = '\0' : 0;
	return (buffer);
}

char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t rd;

	while ((rd = getline(&line, &len, stdin)) != -1)
		return (line);
	return (NULL);
}

int my_prompt(int ac, char **env, s_exec *t_exec)
{
	char *buffer;

	t_exec->env = copy_env(env);
	t_exec->old_pwd = NULL;
	signal(SIGQUIT, SIG_IGN);
	t_exec->e_return = 0;
	while (1) {
		if (isatty(0) == 1)
			print_my_prompt(t_exec->e_return);
		buffer = get_line();
		if (buffer != NULL && buffer[0] != '\n') {
			buffer = clean_input(buffer);
			mysh(ac, buffer, t_exec);
		}
		gest_error(buffer, t_exec);
	}
	return (t_exec->e_return);
}

int main(int ac, char **av, char **env)
{
	struct s_exec *t_exec = malloc(sizeof(struct s_exec));

	(void)av;
	if (ac != 1)
		return (84);
	my_prompt(ac, env, t_exec);
	return (42);
}
