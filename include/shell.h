/*
** EPITECH PROJECT, 2018
** header
** File description:
** matchstick
*/

#ifndef	__SHELL_H_
#define	__SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct	cmd_s
{
	char	*cmd;
	char	**(*fnc)(char **av, char **env);
}		cmd_t;

char	*my_oldpwd(char **env);
void	my_put_error(char c);
char	*get_next_line(int fd);
void	my_putchar(char c);
void	my_puterr(char *str);
int	my_putstr(char const *str);
int	my_strlen(char const *str);
char	*my_strcpy(char *dest, char const *src);
char	*my_strcat(char *dest, char const *src);
char	*my_strdup(char *str);
int	my_strcmp(char *str1, char *str2);
char	*clean_mem(char *str, int len);
int	my_strncmp(char *str1, char *str2, int len);
int	my_getenv(char *args, char **env);
char	**env_display(char **args, char **env);
char	**my_str_wordtab(char *str, char d);
char	**my_env(char **av, char **env);
char	**my_setenv(char **av, char **env);
char	**my_unsetenv(char **av, char **env);
int	count_env(char **env);
char	*my_homedir(char **env);
char	**my_add_to_array(char *name, char *value, char **env);
char	**my_add_to_array2(char *name, char **env);
char	**my_cd(char **av, char **env);
int	my_pwd(char **av, char **env);
void	my_bzero(char *s, int n);
int	my_cd_tilt(char **av, char **env);
char	**my_copy_env(char **env);
char	**my_remove_array(int	i, char **env);
int	my_free_env(char **env);
int	exec_cmd(char **cmd_tab, char **env, int is_pipe);
int	cmd_err(char *cmd);
int	my_exit(char **args, char **env);
char	*rb_epurstr(char *str);
int	count_word(char *str, char d);
char	**my_copy_arr(int pos_to_rm, char **new_env, char **env);
int	my_charis(char c);
char	*get_oldpwd(char **env);
int	my_check_special(char *str);
char	**cd_prev(char **argv, char **env);
void	display_prompt(void);
void	init_cmd(cmd_t *cmd);
int	check_for_pipe(char *s);
void	exec_pipe(char **env, char *s);
char	*init_new_env(int i, char **argv, char **env);
int	check_special1(char *str);
int	check_special2(char *str);
int	check_special3(char *str);
char	*find_path(char *cmd, char **env);
char	*get_path(char **env);
void	fork_pipe(char *tab_cmd, char **cmd, char **env);
void	my_fork(char *tab_cmd, char **cmd, char **env);
int	check_argv(char **argv);
int	check_key(char *argv, char **env);
char	**init_word(int i, char *word, char **argv, char **env);
void	my_redirection(char *s, char **env);
int	check_redi_right(char *s);
int	check_double(char *s);
char	**my_wordtab_dstr(char *s, char *d);
void	display_signals(int status);
void	display_signals2(int status);
void	display_format(char *cmd);
void	display_err_cmd(char *cmd);
void	handle_pipe_segf(int status);
pid_t	check_pid(int pipefd[2]);
void	p_o(int d, char **av, int i, int pfd[2], char **cmd, char **env);
void	wait_status(int i, int pipefd[2], int save_in, int save_out);
#endif //shell.h
