#include "libft.h"

char	*ft_get_alloc_str(int32_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}
