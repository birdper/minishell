#include "executor.h"

static char	*arr2_to_str(const char *arr[], int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	i = 0;
	while (arr[i])
	{
		ft_strlcat(str, arr[i], len + 1);
		i++;
	}
	return (str);
}

static char	**get_arr2_newvar(const char *arg, const char *key, char **var_env)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 5);
	if (arr == NULL)
		return (NULL);
	arr[0] = ft_strdup(key);
	arr[1] = ft_strdup("=");
	arr[2] = get_value_by_varenv(*var_env);
	arr[3] = get_value_by_varenv(arg);
	arr[4] = NULL;
	return (arr);
}

static char	*check_append_key(const char *arg, const char *key, char **var_env,
						  char *append_key)
{
	char		*new_var;
	int			len;
	int			i;
	char		**arr;

	if (ft_strnstr(arg, append_key, ft_strlen(append_key)))
	{
		arr = get_arr2_newvar(arg, key, var_env);
		i = 0;
		len = 0;
		while (arr[i])
		{
			len += ft_strlen(arr[i]);
			i++;
		}
		new_var = arr2_to_str((const char **)arr, len);
		ft_free_2arr(arr);
		return (new_var);
	}
	return (NULL);
}

static char	*get_append_var(const char *arg, const char *key, char **var_env)
{
	char	*append_key;
	char	*new_var;

	append_key = ft_strjoin(key, "+=");
	new_var = check_append_key(arg, key, var_env, append_key);
	free(append_key);
	return (new_var);
}

int	write_env(const char *arg, const char *key,
						char **var_env, char **envp[])
{
	char	*new_var;
	char	**empty_var;

	if (ft_strchr(arg, '='))
	{
		new_var = get_append_var(arg, key, var_env);
		if (new_var == NULL)
			new_var = ft_strdup(arg);
		if (set_var_env(var_env, new_var))
		{
			empty_var = get_ptr_env("", *envp);
			if (set_var_env(empty_var, new_var))
				*envp = insert_env(*envp, new_var);
		}
	}
	return (0);
}
