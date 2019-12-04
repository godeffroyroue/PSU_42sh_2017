/*
** EPITECH PROJECT, 2017
** include
** File description:
** godeffroy.roue
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

#define EXIT -2
#define CD 1
#define ENV 2
#define SETENV 3
#define UNSETENV 4

#define LENGTH_HIST_MAX	512

typedef struct s_exec
{
	char **hist;
	char **paillepeu;
	int status;
	int built;
	char **cmd;
	char **tab;
	pid_t pipe_pid;
	pid_t pid;
	char **e_path_tab;
	char **e_cmd;
	char *e_command;
	char **env;
	int e_return;
	char *old_pwd;
	char *old_cmd;
	char *pwd;
	int pipe;
	int ac;
	int pipefd[2];
} s_exec;

int count_char(char *str, char c);
int is_in_tab(char *str, char **tab);

char *my_strcat_base(char *dest, char *src);
char *my_strcat_pipe(int nb, char *str1, char *str2, ...);
char *cat_path(char *chemin, char *cmmd);
char *get_path_cmd(char *str, char **env);
void status_gest(int status, int *exit_value);

int pre_check2(char *str, char *buff_tab);
char *pre_check(char *str, s_exec *t_exec);
int my_exec_part2(s_exec *t_exec, char *buff);
char *prepar_exec(s_exec *t_exec);
int my_exec(s_exec *t_exec);

void close_exec_exit(int p, s_exec *t_exec, int i);
int close_iplusplus_fd_in(int p, int i, int *fd_in, int p0);
void my_dup(int fd_in, s_exec *t_exec, int p1, int i);
int execute_pipe(s_exec *t_exec, int i);

int exec_part(s_exec *t_exec);

char **epur_tab(char **tab);
int is_a_sep(char c);
int count_sep(char *str);
char **parse_cmd2(char **dest, char *str);
char **parse_cmd(char *str);

int how_many_separat(s_exec *t_exec);

void my_show_struct(s_exec *t_exec);

int find_length_max_on_tab(char **tab);
char **create_tab_alias(char **tab, int int_x, int int_y);
char **create_tab_cmd(char **tab, int int_x, int int_y);

void my_show_triple_tabchar(char ***tab);
void my_show_tabchar(char **tab);
void create_history(s_exec *t_exec);
void update_history(char *cmd, s_exec *t_exec);

char **create_tab(int x, int y, char c);
char *my_alloc_str(int size);
char *my_recup(char *name);
char *check_is_alias(char *command, char *path_alias);
char *change_command_alias(char *command);

int my_put_nbr(long int nb, int base);
int my_putchar(char c);
int my_strlen(char *str);
int my_put_hexa(long int nb, int diff_ascii);
void print_int(char *first, int i, va_list args);
void print_hexa(char *first, int i, va_list args);
void print_octa(char *first, int i, va_list args);
void print_char(char *first, int i, va_list args);
int my_printf(char *first, ...);
void print_hexa(char *first, int i, va_list args);
void print_unsigned_int(char *format, int i, va_list args);
int my_put_nbr_ui(unsigned int nb);
void print_pointer(char *format, int i, va_list args);
void print_binary(char *format, int i , va_list args);
void print_mods(char *str);
void my_cprints(char *str, int i);
void my_flags(char *format, int i, va_list args);

char *clean_input(char *buffer);

int mysh(int ac, char *command, s_exec *t_exec);
char *my_strcat(char *dest, char *src);
int my_strlen(char *str);
int the_execution(int ac, s_exec *t_exec);
int my_setenv(s_exec *t_exec);
char *my_new_path(char **command);
int gest_error(char *buffer, s_exec *t_exec);

int mysh2(int ac, s_exec *t_exec);
int my_perror(char *cmd);
int exec2(char **path_tab, char **cmd, int i);
char **bin_alloc(char **path_tab, char *str);
int my_segfault(int status);

char **copy_setenv(char *str, char **env, char **envi, int lign);
char **my_realloc(int lign, int col, char **envi, char *str);
int my_unsetenv(s_exec *t_exec);
int find_unsetlign(char **env, char *str);
int my_putstr(char *str);
void my_clear(void);

int my_cd(s_exec *t_exec);
int my_cd2(s_exec *t_exec);

int exec3(char **path_tab, char **cmd, pid_t pid);
int verif_access(char **path_tab, int j, char **cmd);
char **verif_cmd(char **path_tab, char **cmd);

char **copy_env(char **envi);

int my_prompt(int ac, char **env, s_exec *t_exec);
int my_exit(int n);

char *find_path(char **env);
int find_word(char *str, char *word);
int count_lign(char *str, char del);
int count_col(char *str, char del);
char *my_memset(char *str, int c, int n);
char **my_str_word_to_array(char *str, char del);
int exec(char **path_tab, s_exec *t_exec);
int my_show_env(s_exec *t_exec);
int my_strcmp(char *s1, char *s2);
char *my_get(char *str, char **env);

int my_pipe(s_exec *t_exec);
char *verif_ligne(char *str);
char **clean_cmd(char **cmd, int secure);
char **find_our_path(char **env);
char *clean_ligne(char *str);
char *clean_l(char *str);
int init_shell(char *command, s_exec *t_exec);
int verif_setenv(s_exec *t_exec);
int my_cd_error(char *command);
int exec_cmd(char **cmd, s_exec *t_exec, char *path_tab, int i);
int exec_parent(void);
int exec_child(int i, s_exec *t_exec, char **cmd, char *path_tab);

char *my_strcpy(char *dest, char *src);
int put_in_file(char *buffer, char *path);
void print_my_prompt(int exit);
char *get_time(char **tab);
char *get_user(char **tab);
int count_pipe(s_exec *t_exec);
int exec_binary(char *path, char **cmd);
int verif_slash(char **cmd);
int verif_path(char **path_tab);
int verif_alpha_env(s_exec *t_exec);

#endif
