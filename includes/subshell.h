#ifndef SUBSHELL_H
# define SUBSHELL_H

# include "struct.h"

char			**get_ptr_env(const char *key, char **envp);
char			*get_key(const char *var_env);
char			*get_value_by_key(char *key, char **envp);

char			*get_value_by_varenv(const char *var_env);
int				set_value_by_key(char *key, const char *value, char **envp);
int				set_var_env(char **var_env, char *new_var);

#endif
