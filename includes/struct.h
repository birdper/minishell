#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

enum e_cmd
{
	e_empty,
	e_echo,
	e_cd,
	e_pwd,
	e_export,
	e_unset,
	e_env,
	e_exit
};

enum e_redirect
{
	input,
	output_rewrite,
	output_append
};

typedef struct s_redirect
{
	enum e_redirect		rd_symbol;
	char				*rd_file;
}	t_redirect;

typedef struct s_2list
{
	char				*content;
	struct s_2list		*next;
	struct s_2list		*prev;
}	t_2list;

typedef struct s_data
{
	enum e_cmd			cmd;
	int					have_pipe;
	char				**args;
	t_list				*redirects;
}	t_data;

#endif
