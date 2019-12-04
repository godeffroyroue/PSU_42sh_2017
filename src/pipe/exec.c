/*
** EPITECH PROJECT, 2017S
** exec.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strcat_base(char *dest, char *src)
{
	int i = -1;
	int j = -1;
	char *res;

	if ((res = malloc(my_strlen(dest) +
		my_strlen(src) + 1)) == NULL)
		return (NULL);
	while (dest[++i])
		res[i] = dest[i];
	while (src[++j]) {
		res[i] = src[j];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *my_strcat_pipe(int nb, char *str1, char *str2, ...)
{
	int i = 1;
	char *dest = my_strcat_base(str1, str2);
	va_list ap;

	if (nb <= 1)
		return (NULL);
	if (nb == 2)
		return (dest);
	else {
		va_start(ap, str2);
		while (++i < nb)
			dest = my_strcat_base(dest, va_arg(ap, char*));
		va_end(ap);
	}
	return (dest);
}

char *cat_path(char *chemin, char *cmmd)
{
	if (chemin[strlen(chemin) - 1] == '/')
		return (my_strcat_pipe(2, chemin, cmmd));
	return (my_strcat_pipe(3, chemin, "/", cmmd));
}

char *get_path_cmd(char *str, char **env)
{
	int i;
	char **path;

	if ((i = is_in_tab("PATH=", env)) == -1)
		return (NULL);
	if (count_char(str, '/') != 0)
		return (NULL);
	path = my_str_word_to_array(env[i] + 5, ':');
	i = -1;
	while (path[++i])
		if (access(cat_path(path[i], str), X_OK) == 0)
			return (cat_path(path[i], str));
	return (NULL);
}

void status_gest(int status, int *exit_value)
{
	int signal;

	if (WIFEXITED(status))
		*exit_value = WEXITSTATUS(status);
	if (WIFSIGNALED(status)) {
		*exit_value = signal = WTERMSIG(status);
		*exit_value += 128;
	}
	else
		return;
	dprintf(2, "%s\n", "Segfauft");
}