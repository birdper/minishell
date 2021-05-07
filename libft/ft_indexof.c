#include "libft.h"

int	ft_indexof(const char *str, int c)
{
	int		index;
	char	*find_char;

	find_char = ft_strchr(str, c);
	if (find_char == NULL)
		return (-1);
	index = find_char - str;
	return (index);
}
