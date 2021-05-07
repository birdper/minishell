#include "executor.h"

int	b_unset(const char *args[], char *envp[])
{
	char		**line;
	int			ret;
	int32_t		i;

	i = 1;
	while (args[i])
	{
		if (validate_key(args[i], args[0], args[i]))
			ret = EXIT_FAILURE;
		line = get_ptr_env(args[i], envp);
		if (line)
		{
			free(*line);
			*line = ft_strdup("");
			ret = EXIT_SUCCESS;
		}
		i++;
	}
	return (ret);
}
