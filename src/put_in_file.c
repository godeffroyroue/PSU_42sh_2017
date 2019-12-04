/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int put_in_file(char *buffer, char *path)
{
	int fd = open(path, O_RDWR | O_CREAT);

	write(fd, buffer, my_strlen(buffer));
	return (0);
}

char *take_of_file(char *path)
{
	char *buffer;
	struct stat sts;
	int fd;

	stat(path, &sts);
	if (S_ISDIR(sts.st_mode)) {
		my_putstr(path);
		my_putstr(": Permission denied.\n");
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (sts.st_size + 1));
	if (S_ISREG(sts.st_mode)) {
		fd = open(path, O_RDWR);
		write(fd, buffer, my_strlen(buffer));
	}
	return (buffer);
}
