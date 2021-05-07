#include "executor.h"

int	is_notnumber(const char *arg)
{
	char	*tr_str;
	char	*start;

	tr_str = ft_strtrim(arg, " ");
	start = tr_str;
	if (*tr_str == '-' || *tr_str == '+')
		start = tr_str + 1;
	if (ft_foreach_str(((char *)start), ft_isdigit) == 0)
	{
		free(tr_str);
		return (1);
	}
	free(tr_str);
	return (0);
}
