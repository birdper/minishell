#include "executor.h"

int	b_env(char *envp[])
{
	int32_t		i;

	i = 0;
	while (envp[i])
	{
		if (ft_memcmp(envp[i], "", 1)
			&& ft_memcmp(envp[i], "?", 1))
		{
			if (ft_strchr(envp[i], '='))
				printf("%s\n", envp[i]);
		}
		i++;
	}
	return (0);
}
