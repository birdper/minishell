#include "subshell.h"

char	*get_key(const char *var_env)
{
	int32_t		index;
	int32_t		len;

	len = ft_strlen(var_env);
	index = ft_indexof(var_env, '=');
	if (index > 0)
	{
		len = index;
		if (var_env[index - 1] == '+')
			len--;
	}
	return (ft_substr(var_env, 0, len));
}
