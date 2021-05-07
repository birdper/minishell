#include "libft.h"

char	**ft_expand_2arr(const char *src_arr[], int src_len, int dst_len)
{
	char		**dst_arr;

	dst_arr = (char **)malloc((dst_len + 1) * sizeof(char *));
	if (dst_arr == NULL)
		return (NULL);
	ft_copy_2arr(dst_arr, (char **)src_arr);
	while (src_len < dst_len)
	{
		dst_arr[src_len] = ft_strdup("");
		src_len++;
	}
	dst_arr[src_len] = NULL;
	return (dst_arr);
}
