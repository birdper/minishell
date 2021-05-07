#include "executor.h"

static int	declare_var(char **var_env, const char *arg, char **envp[])
{
	char	*value;

	if (ft_strchr(arg, '=') == NULL)
	{
		if (var_env)
			return (0);
		if (ft_strcmp(arg, "PWD") == 0)
		{
			value = get_value_by_key("?PWD", *envp);
			insert_key_value("PWD", value, envp);
			free(value);
		}
		else
			*envp = insert_env(*envp, ft_strdup(arg));
		return (0);
	}
	return (1);
}

int	b_export(const char *args[], char **envp[])
{
	char		*key;
	char		**var_env;
	int			ret;
	int32_t		i;

	if (args[1] == NULL)
		return (print_envp(*envp));
	i = 1;
	while (args[i])
	{
		key = get_key(args[i]);
		var_env = get_ptr_env(key, *envp);
		ret = validate_key(key, args[0], args[i]);
		if (!ret)
		{
			if (declare_var(var_env, args[i], envp))
				write_env(args[i], key, var_env, envp);
			ret = 0;
		}
		free(key);
		i++;
	}
	return (ret);
}
