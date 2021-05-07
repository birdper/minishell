#include "executor.h"

static int	key_compare(char *key1, char *key2)
{
	int		ret;

	ret = ft_memcmp(key1, key2, ft_strlen(key1) + 1);
	free(key1);
	free(key2);
	return (ret);
}

static void	sort_arr(char *arr[])
{
	char		*tmp;
	int32_t		i;
	int32_t		j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (key_compare(get_key(arr[i]), get_key(arr[j])) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	format_var(const char *var_env)
{
	char	*key;
	char	*value;

	key = get_key(var_env);
	value = get_value_by_varenv(var_env);
	printf("declare -x %s=", key);
	printf("\"%s\"\n", value);
	free(value);
	free(key);
}

static char	**copy_2arr(const char *src_arr[])
{
	char	**dst;
	int		count_raws;
	int		i;

	count_raws = ft_2arr_get_rows(src_arr);
	dst = (char **)malloc((count_raws + 1) * sizeof(char *));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < count_raws)
	{
		dst[i] = (char *)src_arr[i];
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

int	print_envp(char *envp[])
{
	char		**copy_envp;
	int32_t		i;

	copy_envp = copy_2arr((const char **)envp);
	sort_arr(copy_envp);
	i = 0;
	while (copy_envp[i])
	{
		if (ft_memcmp(copy_envp[i], "", 1)
			&& ft_memcmp(copy_envp[i], "?", 1))
		{
			if (ft_strchr(copy_envp[i], '='))
				format_var(copy_envp[i]);
			else
				printf("declare -x %s\n", copy_envp[i]);
		}
		i++;
	}
	free(copy_envp);
	return (0);
}
