#include "libft.h"

int	ft_copy_2arr(char *dst_arr[], char *src_arr[])
{
	int		i;

	i = 0;
	while (src_arr[i])
	{
		dst_arr[i] = ft_strdup(src_arr[i]);
		if (dst_arr[i] == NULL)
		{
			ft_free_2arr(dst_arr);
			return (EXIT_FAILURE);
		}
		i++;
	}
	dst_arr[i] = NULL;
	return (EXIT_SUCCESS);
}
