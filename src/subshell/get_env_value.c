#include "subshell.h"

char	*get_value_by_varenv(const char *var_env)
{
	char		*value;
	int32_t		len;
	int32_t		index;

	value = NULL;
	if (var_env)
	{
		index = ft_indexof(var_env, '=');
		if (index < 0)
			return (NULL);
		len = ft_strlen(var_env + index);
		value = ft_substr(var_env, index + 1, len);
	}
	return (value);
}

char	*get_value_by_key(char *key, char **envp)
{
	char	**var_env;
	char	*value;

	var_env = get_ptr_env(key, envp);
	if (var_env)
	{
		value = get_value_by_varenv(*var_env);
		if (value)
			return (value);
	}
	return (NULL);
}
