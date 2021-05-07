#include "executor.h"

static int32_t	get_len_args(const char **args, int32_t index)
{
	int32_t		len;

	len = 0;
	while (args[index])
	{
		len += ft_strlen(args[index]);
		index++;
	}
	return (len);
}

static char	*compile_str(const char **args, int count_n)
{
	char		*res;
	int32_t		printable_args;
	int32_t		size;
	int32_t		index;

	printable_args = ft_2arr_get_rows(args) - 1 - count_n;
	if (!printable_args)
		return (NULL);
	index = count_n + 1;
	size = get_len_args(args, index) + printable_args;
	res = (char *)malloc(sizeof(char) * size);
	if (res == NULL)
	{
		print_err("minishell", args[0], NULL, "Error malloc");
		return (NULL);
	}
	*res = '\0';
	while (index < printable_args)
	{
		ft_strlcat(res, args[index], size);
		ft_strlcat(res, " ", size);
		index++;
	}
	ft_strlcat(res, args[index], size);
	return (res);
}

static int32_t	count_n_flags(const char *args[])
{
	int			i;
	int32_t		count_n;

	i = 1;
	count_n = 0;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		i++;
		count_n++;
	}
	return (count_n);
}

int	b_echo(const char *args[])
{
	int32_t		count_n;
	char		*str;

	count_n = count_n_flags(args);
	str = compile_str(args, count_n);
	if (str)
	{
		write(1, str, ft_strlen(str));
		free(str);
	}
	if (!count_n)
		write(1, "\n", 1);
	return (0);
}
