#include "executor.h"

char	**insert_env(char **old_envp, char *new_var)
{
	int32_t		src_len;
	char		**new_envp;

	src_len = ft_2arr_get_rows((const char **)old_envp);
	new_envp = ft_expand_2arr((const char **)old_envp, src_len, src_len + 1);
	free(new_envp[src_len]);
	new_envp[src_len] = new_var;
	ft_free_2arr(old_envp);
	return (new_envp);
}

void	insert_key_value(char *key, char *value, char **envp[])
{
	int32_t		len;
	char		*new_var;

	len = ft_strlen(key) + ft_strlen(value) + 1;
	new_var = ft_get_alloc_str(len);
	concat(new_var, key, "=", len + 1);
	ft_strlcat(new_var, value, len + 1);
	*envp = insert_env(*envp, new_var);
}
