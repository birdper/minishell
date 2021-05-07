#include "subshell.h"

int	set_var_env(char **var_env, char *new_var)
{
	if (var_env == NULL)
		return (1);
	free(*var_env);
	*var_env = new_var;
	return (0);
}

int	set_value_by_key(char *key, const char *value, char **envp)
{
	char	**var_env;
	char	*var;
	char	*new_key;

	var_env = get_ptr_env(key, envp);
	new_key = ft_strjoin(key, "=");
	var = ft_strjoin(new_key, value);
	free(new_key);
	if (set_var_env(var_env, var))
	{
		free(var);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
