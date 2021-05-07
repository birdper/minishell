/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:49:13 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:06:23 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "subshell.h"
# include <term.h>
# include <termios.h>
# include <signal.h>

typedef struct s_reader
{
	size_t			i;
	size_t			len;
	int				first;
	char			*backup;
	char			*str;
	struct termios	*term;
}	t_reader;

int				parser(t_list **list, char *line, char **env[]);
void			make_backup(t_reader *data);
int				check_read(char *buf, int res);
int				tputchar(int c);
void			tgetterm(struct termios *term);
void			signals_off(struct termios *term);
void			signals_on(struct termios *term);
int				eof_signal(char *str, struct termios *term);
int				intr_signal(t_reader *data, char *buf, char ***envp);
int				signals_isig(char *buf, struct termios *term,
					         t_reader *data);
char			*create_cmd_line(t_2list **history, char ***envp,
					         struct termios *term);

int				backspace_button(t_reader *data, char *buf);
int				left_right_button(char *buf);
int				up_button(t_2list **tmp_lst, t_reader *data, char *buf);
int				down_button(t_2list **tmp_lst, t_reader *data, char *buf);

int				pre_parse_copy_ecranization(char **line, char *str, int *i);
int				pre_parse_copy_single_quotes(char **line, char *str, int *i);
int				pre_parse_copy_env_quotes(char **line, char *str,
					char **env, int *i);
int				pre_parse_copy_env(char **line, char *str, char **env, int *i);
int				pre_parse_copy_quotes(char **line, char *str,
					char **env, int *i);
int				pre_parce_skip_env(char **line, int *count, char **env);
int				pre_parce_skip_env(char **line, int *count, char **env);
int				pre_parse_validate(char *line, char **envp);
int				pre_parse_skip_quotes(char **line, int *count, char **env);
int				pre_parse_env_size(char *line, char **env);
int				pre_parse_size(char *line, char **env);
char			*pre_parse(char *line, char **env, int size);
int				check_redirs(char *line, char **env);

int				is_printable_env(char c);
int				is_valid_env(char *line);
int				is_flag_n(char *str);
int				is_empty(char *str);
int				skip_valid_env(char **line, char *str);
void			skip_spaces(char **str);
int				skip_spec_symbols(char **line);
int				spaces_count(char *line);
int				quotes_count(char *line);
int				ecranization_count(char *line);
int				single_quotes_count(char *line);
int				skip_quotes(char **line);
int				skip_ecraniztion(char **line);
int				skip_single_quotes(char **line);
int				single_quotes_count(char *line);
int				spec_symbol_count(char *line);
int				env_name_size(char *line);
int				env_value_size(char *line);

int				validate_cmd(char *line);
int				validate_redirects(t_data *data, char *parsed_cmd,
					  char **envp[]);

int				file_name_size(char *str);
char			*get_file_name(char *str);
void			delete_comments(char *line);
char			*delete_redirection(char *line);
t_list			*get_redirects(char *line);
int				get_pipe(char *line);
int				parse_get_args(char *line, t_list **args_holder, t_data **data);
enum e_cmd		comparator(char *command);
int				parse_get_cmd(char *line, t_data *data);

void			clear_data(t_data *data);
int				clear_cmd(t_list **list);

void			sig_interrupt(int status);
void			sig_quit(int status);

int				copy_env(char *line, char **env, char *str);
int				brake_end_line(char **line);
int				check_symbol(char **line);
int				add_spec_symbol(char **line, char *str, int *i);
int				add_double_quotes(char **line, char *str, int *i);
int				add_single_quotes(char **line, char *str, int *i);
int				add_ecranization(char **line, char *str, int *i);
char			**split_cmd(char *line);
int				split_arguments(t_list **list, char **cmd_arr, char **env[]);
char			**get_cmd_arr(char *line, char **envp[]);
int				cmd_loop(t_list **list, char **cmd_arr, char ***envp);

void			ft_lstclear_no_content(t_list **lst);
size_t			ft_strncat(char *dst, const char *src, size_t dstsize, int n);
t_2list			*ft_dbl_lstnew(char *content);
void			ft_dbl_lstadd_front(t_2list **dbl_lst,
					t_2list *new);

#endif
