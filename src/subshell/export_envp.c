#include "executor.h"

static int	is_exclude(const char *env_var)
{
	if (ft_memcmp(env_var, "?", 1) == 0)
		return (1);
	if (ft_strchr(env_var, '=') == NULL)
		return (1);
	return (0);
}

static int	get_size_filtered_2arr(const char **src_arr)
{
	int		i;
	int		count_raws;

	i = 0;
	count_raws = 0;
	while (src_arr[i])
	{
		if (is_exclude(src_arr[i]))
		{
			i++;
			continue ;
		}
		count_raws++;
		i++;
	}
	return (count_raws);
}

static char	**dup_2arr_exec(const char *src_arr[])
{
	char	**dst;
	int		count_rows;
	int		i;
	int		j;

	count_rows = get_size_filtered_2arr(src_arr);
	dst = (char **)malloc((count_rows + 1) * sizeof(char *));
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_rows)
	{
		if (is_exclude(src_arr[j]))
		{
			j++;
			continue ;
		}
		dst[i] = ft_strdup(src_arr[j]);
		i++;
		j++;
	}
	dst[i] = NULL;
	return (dst);
}

char	**export_envp(char **envp)
{
	char	**dup_2arr;

	dup_2arr = dup_2arr_exec((const char **)envp);
	if (dup_2arr == NULL)
		return (NULL);
	ft_free_2arr(envp);
	return (dup_2arr);
}
