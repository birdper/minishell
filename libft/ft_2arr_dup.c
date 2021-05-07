#include "libft.h"

char	**ft_2arr_dup(const char *src_arr[])
{
	char	**dst_arr;
	int		len;
	int		i;

	len = ft_2arr_get_rows(src_arr);
	dst_arr = (char **)malloc((len + 1) * sizeof(char *));
	if (dst_arr == NULL)
		return (NULL);
	i = 0;
	while (src_arr[i])
	{
		dst_arr[i] = ft_strdup(src_arr[i]);
		if (dst_arr[i] == NULL)
		{
			ft_free_2arr(dst_arr);
			return (NULL);
		}
		i++;
	}
	dst_arr[i] = NULL;
	return (dst_arr);
}
