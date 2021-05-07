#ifndef EXECUTOR_H
# define EXECUTOR_H

# define CHILD 0
# define READ_END 0
# define WRITE_END 1

# include "subshell.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <stdio.h>

typedef struct s_redir_fds
{
	int			dup_in;
	int			dup_out;
	int			redir_in;
	int			redir_out;
}	t_redir_fds;

typedef struct s_pipeline
{
	int			pipe_fds[2];
	int			*ends_prev_pipe;
	uint32_t	number_cmd;
	t_redir_fds	redir_fds;
}	t_pipeline;

int32_t			executor(t_list *list_commands, char **envp[]);
int				run_pipeline(t_list *list_commands, char *envp[], int size);
int				simple_command(t_data *command, char **envp[]);

int				outer_exec(char *filename, char *args[], char *envp[]);
char			**get_paths(char *envp[]);
char			*concat_path(char *path, char *filename);

/** REDIRECTION FUNCTIONS **/
void			set_redirections(t_redir_fds *redir_fds);
int				find_redirections(t_list *list_redirections,
					   t_redir_fds *redir_fds);

int				builtins(enum e_cmd command, const char *args[], char **envp[]);
int				b_cd(const char **args, char ***envp);
int				b_echo(const char *args[]);
int				b_export(const char *args[], char **envp[]);
int				b_env(char *envp[]);
int				b_pwd(char *envp[]);
int				b_unset(const char *args[], char *envp[]);
int				b_exit(const char *args[]);

/** ENVP FUNCTIONS **/
int				print_envp(char *envp[]);
int				write_env(const char *arg, const char *key,
					   char **var_env, char **envp[]);
int				validate_key(const char *key, const char *name_cmd,
					   const char *arg);
void			update_pwd(const char *dst_path, char **envp[]);

/** SUBSHELL FUNCTIONS **/
char			**init_subshell(const char *args[], char **in_envp);
void			update_shlvl(char **envp[]);
void			set_status(char *envp[], int status);
char			**export_envp(char **envp);
char			*get_cwd(const char *command_name, const char *arg);
char			**insert_env(char **old_envp, char *new_var);
void			insert_key_value(char *key, char *value, char **envp[]);

/** UTILS FUNCTIONS **/
void			dup2close(int32_t oldfd, int32_t newfd);
int				print_err(const char *shell, const char *command,
					   const char *arg, const char *msg);
void			concat(char *dst, const char *s1, const char *s2,
					   uint32_t size);
int				is_notnumber(const char *arg);
char			*get_cwd_pwd(char **envp);

#endif
