#include "executor.h"

static char	*get_wrap_str(const char *key)
{
	int32_t		len;
	char		*wrapper;

	len = ft_strlen(key) + 3;
	wrapper = (char *)malloc(sizeof(char) * len);
	wrapper[0] = '`';
	wrapper[1] = '\0';
	ft_strlcat(wrapper, key, len);
	wrapper[len - 2] = '\'';
	wrapper[len - 1] = '\0';
	return (wrapper);
}

static int	check(int err, const char *arg, const char *name_cmd,
					const char *msg)
{
	char	*wrapper;

	if (err)
	{
		wrapper = get_wrap_str(arg);
		print_err("minishell", name_cmd, wrapper, msg);
		free(wrapper);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	validate_key(const char *key, const char *name_cmd, const char *arg)
{
	int			err;

	if (key == NULL)
		return (EXIT_SUCCESS);
	err = (key[0] == '!');
	if (check(err, arg, name_cmd, "event not found"))
		return (EXIT_FAILURE);
	err = (ft_isempty_str(key) || ft_isdigit(key[0]));
	if (check(err, arg, name_cmd, "not a valid identifier"))
		return (EXIT_FAILURE);
	if (!ft_foreach_str(key, ft_isalnum))
		return (check(1, arg, name_cmd, "not a valid identifier"));
	return (EXIT_SUCCESS);
}
