#include "executor.h"

void	concat(char *dst, const char *s1, const char *s2, uint32_t size)
{
	if (s1 && s2)
	{
		ft_strlcat(dst, s1, size);
		ft_strlcat(dst, s2, size);
	}
}

static uint32_t	get_len(const char *shell, const char *command, const char *arg,
						const char *msg)
{
	uint32_t	len;

	len = 0;
	if (shell)
		len += ft_strlen(shell) + 2;
	if (command)
		len += ft_strlen(command) + 2;
	if (arg)
		len += ft_strlen(arg) + 2;
	len += ft_strlen(msg) + 2;
	return (len);
}

int	print_err(const char *shell, const char *command, const char *arg,
					const char *msg)
{
	char		*res;
	uint32_t	len;

	len = get_len(shell, command, arg, msg);
	res = (char *)malloc(sizeof(char) * len);
	*res = '\0';
	concat(res, shell, ": ", len);
	concat(res, command, ": ", len);
	concat(res, arg, ": ", len);
	concat(res, msg, "\n", len);
	write(2, res, len);
	free(res);
	return (1);
}
