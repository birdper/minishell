#ifndef MINISHELL_H
# define MINISHELL_H

# include "executor.h"
# include "parser.h"

void			exec_args(t_list **list, int argc, char *argv[], char **envp[]);

#endif
