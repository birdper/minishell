#include "subshell.h"

static char	**search_key(char **map, const char *key, uint32_t len)
{
	int32_t		i;

	i = 0;
	while (map[i])
	{
		if (ft_memcmp(key, map[i], len) == 0)
			return (&map[i]);
		i++;
	}
	return (NULL);
}

char	**get_ptr_env(const char *key, char **envp)
{
	uint32_t	len;
	char		**var_env;
	char		*newkey;

	len = ft_strlen(key);
	var_env = search_key(envp, key, len + 1);
	if (var_env)
		return (var_env);
	newkey = ft_strjoin(key, "=");
	var_env = search_key(envp, newkey, len + 1);
	free(newkey);
	if (var_env)
		return (var_env);
	return (NULL);
}
