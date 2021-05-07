#include "executor.h"

void	set_status(char *envp[], int status)
{
	char	*value;

	value = ft_itoa(status);
	set_value_by_key("?", value, envp);
	free(value);
}
