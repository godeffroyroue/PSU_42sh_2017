/*
** EPITECH PROJECT, 2018
** my_show.c
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void my_show_struct(s_exec *t_exec)
{
	printf("%s e_command :%s %s\n%s\n", KRED,
		KBLU, t_exec->e_command, KNRM);
}
