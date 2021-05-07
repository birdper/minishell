#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		ret;

	while (1)
	{
		ret = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (ret || *s1 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (ret);
}
